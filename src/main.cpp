#include <raylib.h>
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include "imgui_interaction.hpp"

int main(void)
{
    InitWindow(800, 800, "Hello world!");

    HWND hwnd = static_cast<HWND>(GetWindowHandle());

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    io.ConfigFlags |= ImGuiConfigFlags_None;

    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplOpenGL3_Init("#version 330");

    bool show = true;

    // SetWindowState(FLAG_VSYNC_HINT);

    while(!WindowShouldClose())
    {
        imgui_interaction();
        
        BeginDrawing();
            ::ClearBackground(DARKGRAY);

            ::DrawFPS(0, 0);

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();

            ImGui::SetNextWindowSize((const ImVec2){400, 400});
            ImGui::Begin("Hello world!", nullptr, 0);
            ImGui::Text("Liviu este gei");
            ImGui::End();
            
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        ::EndDrawing();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    ::CloseWindow();
    return 0;
}