#pragma once

#include <GL/gl3w.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"

class MenuUI {
public:
	void RenderMenu(bool& running, int& racks);
};