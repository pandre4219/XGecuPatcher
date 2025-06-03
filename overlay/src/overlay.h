#pragma once
#define d_toggle_bind 0x2D /* VK_INSERT */
#include "imconfig.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include "imstb_rectpack.h"
#include "imgui_internal.h"

namespace overlay
{
	void draw_gui();
	void render();
	inline bool done = false;
	inline bool enabled = true;
}
