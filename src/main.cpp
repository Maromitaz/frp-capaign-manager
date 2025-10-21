#include <external/fix_win32_compatibility.h>
#include <raylib.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

int main(void)
{
    InitWindow(1200, 800, "Hello world!");

    GLFWwindow *window = GetGLFWwindowHandle();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    io.ConfigFlags |= ImGuiConfigFlags_None;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    bool show = true;

    // SetWindowState(FLAG_VSYNC_HINT);

    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground({ 0xff, 0xff, 0x00, 0xff });

            DrawFPS(10, 10);

            // ::DrawRectangle(::GetScreenWidth() / 4, ::GetScreenHeight() / 4, ::GetScreenWidth() / 2, ::GetScreenHeight() / 2, (Color){0xff, 0x00, 0x00, 0xff});

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::SetNextWindowSize({400, 400});
            ImGui::Begin("Hello world!", nullptr, 0);
            ImGui::Text("Liviu este gei");
            ImGui::End();
            
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        EndDrawing();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    ::RLCloseWindow();
    return 0;
}
