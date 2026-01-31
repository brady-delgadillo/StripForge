#include "../headers/StripUI.h"

void StripUI::RenderStrip(Strips::Strip strip, int index){

    ImGui::PushID(index);

    ImGui::BeginChild("Strip", ImVec2(0, 90), true);

    ImGui::Text("%s", strip.callsign.c_str());
    ImGui::Text("%s → %s", strip.from.c_str(), strip.to.c_str());
    ImGui::Text("ALT %s", strip.altitude.c_str());


    ImGui::EndChild();
    ImGui::PopID();
}

void StripUI::RenderStripRail(std::vector<Strips::Strip> strips) {
    int index = 0;
    for (int i = 0; i < NUM_RACKS; i++) {
        int MinX =  (RACK_LENGTH * i) + (RACK_PADDING * i);
        int MaxX = (RACK_LENGTH * (i + 1)) + (RACK_PADDING * (i + 1));
        if (!(MinX < ImGui::GetMainViewport()->WorkSize.x) || !(MaxX < ImGui::GetMainViewport()->WorkSize.x)) {
            //std::cerr << "Error Rendering " << NUM_RACKS << " Racks, Could only render " << i << " Racks." << std::endl;
            return;
        }

        ImGui::SetNextWindowSize(
            ImVec2(RACK_LENGTH + RACK_PADDING, ImGui::GetMainViewport()->WorkSize.y - (RACK_PADDING  * 2)),
            ImGuiCond_Always    
        );
        std::string windowName = "Strip Bay " + std::to_string(i);
        ImGui::Begin(windowName.c_str(), 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
        ImGui::SetWindowPos(ImVec2((RACK_LENGTH * i) + (RACK_PADDING * i), RACK_PADDING + 10));

        ImGui::BeginChild("Rail", ImVec2(RACK_LENGTH, 0), true);
        for (int ii = 0; ii < strips.size(); ii++) {
            if (strips[ii].currentRack == i) {
                RenderStrip(strips[ii], index);
                index++;
            }
        }
        ImGui::EndChild();
        ImGui::End();
    }
}
