# CMakeList.txt: проект CMake для ViMaker; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (ViMaker "ViMaker.cpp" "ViMaker.h" "application.h" "application.cpp" "3rdparty/plugins/imgui/ImFileBrowser.h"
"window/jgl_window.cpp" "window/jgl_window.h" "window/window.h" "utils/imgui_widgets.h" "utils/str_utils.h"
"ui/automatics_panel.cpp" "ui/automatics_panel.h" "ui/property_panel.h" "ui/property_panel.cpp" "ui/scene_view.h" "ui/scene_view.cpp"
"shader/shader_util.cpp" "shader/shader_util.h" "render/opengl_buffer_manager.cpp" "render/opengl_buffer_manager.h" "render/opengl_context.h" "render/opengl_context.cpp"
"render/render_base.h" "render/ui_context.cpp" "render/ui_context.h" "mesh_import/import_base.h" "mesh_import/import_obj.cpp" "mesh_import/import_obj.h"
"elems/camera.h" "elems/element.h" "elems/input.h" "elems/light.h" "elems/mesh.h" "elems/mesh.cpp" "elems/vertex_holder.h")

find_package(glm CONFIG REQUIRED)
target_link_libraries(ViMaker PRIVATE glm::glm)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(ViMaker PRIVATE glfw)
find_package(GLEW REQUIRED)
target_link_libraries(ViMaker PRIVATE GLEW::GLEW)
find_package(assimp CONFIG REQUIRED)
target_link_libraries(ViMaker PRIVATE assimp::assimp)
find_package(imgui CONFIG REQUIRED)
target_link_libraries(ViMaker PRIVATE imgui::imgui)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ViMaker PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
