// StripForge.cpp : Defines the entry point for the application.
//

#include "Main.h"
#include "scr/headers/Strip.h"
#include "scr/headers/StripUI.h"
#include "scr/headers/Utils.h"
#include "scr/headers/Menu.h"
#include "scr/headers/Core.h"
#include "scr/commands/commands.h"

#include <GL/gl3w.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <string>
#include <vector>

using namespace std;
using namespace Strips;

int SDL_main(int, char**) {
    AppCore coreTest = AppCore();

    coreTest.addCommand(std::make_unique<AddCommand>());

    cout << coreTest.isRendering() << endl;
    cout << coreTest.isRunning() << endl;

    coreTest.setRendering(1);
    coreTest.setRunning(0);

    cout << coreTest.isRendering() << endl;
    cout << coreTest.isRunning() << endl;

    // ------------------------------
    // SDL + OpenGL setup
    // ------------------------------
    SDL_Init(SDL_INIT_VIDEO);

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    SDL_Window* window = SDL_CreateWindow(
        "StripForge Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        DM.w / 2, DM.h / 2, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // VSync

    if (gl3wInit()) {
        printf("Failed to initialize OpenGL loader!\n");
        return -1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 330");

    ImGui::StyleColorsDark();

    // ------------------------------
    // Flight strip data
    // ------------------------------
    std::vector<Strip> strips;
    static StripUI stripRenderer;
    static MenuUI menuRenderer;

    bool show_demo = true;

    // Main loop
    bool running = true;
    bool render_ui = true;

    cout << sizeof(running) << endl;
    cout << sizeof(render_ui) << endl;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                running = false;

        }
        //std::cout << "New Frame." << std::endl;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        //if (ImGui::GetMainViewport()->WorkSize.x <)

        menuRenderer.RenderMenu(running, stripRenderer.NUM_RACKS);
        stripRenderer.RenderStripRail(strips);

    
        //OmniBar
        
        ImGuiViewport* vp = ImGui::GetMainViewport();

        ImVec2 pos = vp->Pos;
        ImVec2 size = vp->Size;

        float barHeight = ImGui::GetFrameHeightWithSpacing() + 6;

        ImGui::SetNextWindowPos(
            ImVec2(pos.x, pos.y + size.y - barHeight)
        );
        ImGui::SetNextWindowSize(
            ImVec2(size.x, barHeight)
        );

        ImGui::Begin("##omnibar_frame",
            nullptr,
            ImGuiWindowFlags_NoTitleBar |
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoSavedSettings);

        static char command[256] = "";

        // autofocus when shown
        if (ImGui::IsWindowAppearing())
            ImGui::SetKeyboardFocusHere();

        ImGui::PushItemWidth(-1);

        if (ImGui::InputTextWithHint(
            "##omnibar",
            "Type command...",
            command,
            256,
            ImGuiInputTextFlags_EnterReturnsTrue))
        {
            cout << "Command: " << command << endl;
            if (coreTest.findCommand(command) != nullptr) {
                coreTest.findCommand(command)->run();
            }
            else {
                cout << "No Command Found." << endl;
            }
            command[0] = 0;
            ImGui::SetKeyboardFocusHere(-1);
        }

        if (ImGui::IsKeyDown(ImGuiKey_Slash))
        {
            ImGui::SetKeyboardFocusHere(-1);
        }

        ImGui::End();
        // ------------------------------
        // Rendering
        // ------------------------------

        ImGui::Render();
        glViewport(0, 0, 1280, 720);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(window); 
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
