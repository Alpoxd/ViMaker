#include "../ViMaker.h"
#include "property_panel.h"

namespace nui
{
  std::vector<nelems::Camera> cameraSaves;

  void Property_Panel::render(nui::SceneView* scene_view)
  {
    auto mesh = scene_view->get_mesh();
    auto camera = scene_view->get_camera();

    static bool DeleteButton = false;
    static int DeleteIndex = 0;

    ImGui::Begin("Properties");
    if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen))
    {
      
      if (ImGui::Button("Open..."))
      {
        mFileDialog.Open();
      }
      ImGui::SameLine(0, 5.0f);
      ImGui::Text(mCurrentFile.c_str());
    }

    if (ImGui::CollapsingHeader("Material") && mesh)
    {
      ImGui::ColorPicker3("Color", (float*)&mesh->mColor, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
      ImGui::SliderFloat("Roughness", &mesh->mRoughness, 0.0f, 1.0f);
      ImGui::SliderFloat("Metallic", &mesh->mMetallic, 0.0f, 1.0f);
    }

    if (ImGui::CollapsingHeader("Light"))
    {

      ImGui::Separator();
      ImGui::Text("Position");
      ImGui::Separator();
      nimgui::draw_vec3_widget("lightPosition", scene_view->get_light()->mPosition, 80.0f);
      ImGui::Separator();
    }

    if (ImGui::CollapsingHeader("Camera", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::Separator();
        ImGui::Text("Position");
        ImGui::Separator();
        nimgui::draw_vec3_widget("CameraPosition", scene_view->get_camera()->mPosition, 80.0f);
        ImGui::Separator();
        if (ImGui::Button("Save")) {
            cameraSaves.push_back(*scene_view->get_camera());
        }
        ImGui::Separator();
        ImGui::PushItemWidth(-1);
        ImGui::BeginListBox("Saved Cameras");
        for (int camIndex = 0; auto & i : cameraSaves) {
            std::string str = std::to_string(camIndex + 1) + " " + glm::to_string(i.mPosition) + " " + glm::to_string(i.get_view_projection());
            if (ImGui::Selectable(str.c_str(), ImGuiTreeNodeFlags_Selected, ImGuiSelectableFlags_AllowDoubleClick)) {
                DeleteButton = true;
                DeleteIndex = camIndex;
            }
            if (ImGui::IsItemHovered()) {
                if (ImGui::IsMouseDoubleClicked(0)) {
                    scene_view->get_camera()->setCamera(i);
                }
            }
            camIndex++;
        }
        ImGui::EndListBox();

        if (DeleteButton) {
            if (ImGui::Button("Delete")) {
                std::vector<nelems::Camera> result;
                for (int i = 0; i < cameraSaves.size(); i++) {
                    if (i != DeleteIndex) result.push_back(cameraSaves[i]);
                }
                cameraSaves.swap(result);
                DeleteButton = false;
            }
        }
    }

    ImGui::End();

    mFileDialog.Display();
    if (mFileDialog.HasSelected())
    {
      auto file_path = mFileDialog.GetSelected().string();
      mCurrentFile = file_path.substr(file_path.find_last_of("/\\") + 1);

      mMeshLoadCallback(file_path);

      mFileDialog.ClearSelected();
    }

  }
}
