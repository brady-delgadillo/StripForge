#include "../headers/Menu.h"

void MenuUI::RenderMenu(bool& running, int& racks)
{
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("File")) {
			ImGui::Separator();
			if (ImGui::MenuItem("Exit")) { running = false; }
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Settings")) {
			if (ImGui::BeginMenu("Strip Racks")) {
				if (ImGui::MenuItem("1")) { racks = 1; }
				if (ImGui::MenuItem("2")) { racks = 2; }
				if (ImGui::MenuItem("3")) { racks = 3; }
				ImGui::EndMenu();
			}
			ImGui::EndMenu();
		}
	}
	ImGui::EndMainMenuBar();
}