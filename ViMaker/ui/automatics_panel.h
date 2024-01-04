#pragma once

#include "../elems/light.h"
#include "../ui/scene_view.h"

#include "imgui.h"
#include "../utils/imgui_widgets.h"

namespace nui {
	class Automatics_Panel {
	public:
		void render(nui::SceneView* mScene);
	};
}