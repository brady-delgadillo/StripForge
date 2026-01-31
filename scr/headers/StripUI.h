#pragma once

#include "../headers/Strip.h"
#include "../headers/StripManager.h"
#include <vector>
#include <iostream>
#include <string>

#include <GL/gl3w.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

class StripUI {
public:
	int NUM_RACKS = 3;

	void RenderStrip(Strips::Strip strip, int index);
	void RenderStripRail(std::vector<Strips::Strip> strips);
private:
	int RACK_LENGTH = 500; //In px
	int RACK_HIGHT = 700; //In px
	int RACK_PADDING = 10; //In px

};
