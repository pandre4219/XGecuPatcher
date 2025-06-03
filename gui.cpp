#include "include.h"
const auto exeBase = reinterpret_cast<std::uintptr_t>(GetModuleHandle(nullptr));


std::uintptr_t g_targetOffset = 0x4fa13;
char g_offsetBuffer[32] = "0x4fa13";

void WriteMemory(BYTE value) {

	DWORD oldProtect;
	void* address = reinterpret_cast<void*>(exeBase + g_targetOffset);
	if (VirtualProtect(address, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &oldProtect)) {
		*reinterpret_cast<BYTE*>(address) = value;
		VirtualProtect(address, sizeof(BYTE), oldProtect, &oldProtect);
	}
}
BYTE ReadMemory() {
	return *reinterpret_cast<BYTE*>(exeBase + g_targetOffset);
}

void UpdateAddress() {
	std::string input(g_offsetBuffer);
	std::uintptr_t newAddress = 0;

	std::stringstream ss;
	ss << std::hex << input;
	ss >> newAddress;

	if (newAddress != 0) {
		g_targetOffset = newAddress;
	}
}




void overlay::draw_gui()
{
	
	ImGui::SetNextWindowSize(ImVec2(600, 400));

	ImGui::Begin("Xgpro Patcher", &overlay::enabled, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	if(ImGui::BeginTabBar("tabBar")){
		static bool memoryEnabled = false;
		if (ImGui::BeginTabItem("adapter"))
		{
			
			if (ImGui::Checkbox("Enable 'I have the right adapter'", &memoryEnabled)) {
				WriteMemory(memoryEnabled ? 0x1 : 0x0);
			}

			

			ImGui::Separator();
			ImGui::Text("press INSERT to toggle menu");
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("advanced"))
		{
			ImGui::Text("Memory Address:");
			if (ImGui::InputText("##Address", g_offsetBuffer, IM_ARRAYSIZE(g_offsetBuffer), ImGuiInputTextFlags_CharsHexadecimal)) {
				UpdateAddress();
			}
			BYTE currentMem = ReadMemory();
			ImGui::Text("Current Memory Value: 0x%X", currentMem);

			if (ImGui::Button("Force Write Memory")) {
				WriteMemory(memoryEnabled ? 0x1 : 0x0);
			}



			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("settings"))
		{
			if (ImGui::Button("Unload")) {
				overlay::done = true;
			}
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::End();
}
