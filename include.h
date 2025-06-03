#pragma once
#include <windows.h>
#include <d3d11.h>
#include <tchar.h>
#include <string>
#include <sstream>
#include <iostream>
#include "overlay/src/overlay.h"
#define ImGui_ImplWin32_WndProcHandler



namespace gui
{
	void Setup(HINSTANCE);
	void Render();
	inline bool open = true;
	
}