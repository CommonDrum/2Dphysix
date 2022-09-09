#include "src/Test/ArraySorting.h"
#include "src/Core/MyOpenGLRenderer.h"


int main()
{


    /* INITIALIZATION */

    // Starter class used to hide OpenGL boilerplate and decrease amount of code in Main.cpp
    // Default size is changeable
    Starter starter("MyWindow");
    Shader shader("C:/Users/Karol/source/repos/Glad Test/Glad Test/src/Shaders/default.vert", "C:/Users/Karol/source/repos/Glad Test/Glad Test/src/Shaders/default.frag");
    ImGuiInterface GuiInterface(starter.window);
    Renderer renderer(&shader);



    /* APPLICATION SPECIFIC CODE */
    // (maybe move some initialization stuff here as someone might want to specific shaders, GUI, etc.)
    ArraySorting sorter(1000);



    renderer.SetVBLayout(*sorter.getLayout());

    int* list = (int*)sorter.getIndicies();

    renderer.SetVertexBuffer( sorter.getVBsize(), sorter.getVertices());
    renderer.SetIndexBuffer(  sorter.getIBsize(), sorter.getIndicies());

    // Coordinates for moving the scene
    static float x_cord = 0.0f;
    static float y_cord = 0.0f;

    /* MAIN WINDOW LOOP */
    while (!glfwWindowShouldClose(starter.window))
    {
        starter.window_maximize_callback();
        renderer.Clear();
        GuiInterface.ImGuiNewFrame();

        if (true)

            // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            ImGui::Begin("Control Panel");                          // Create a window and append into it.
            // Scene movement
            ImGui::SliderFloat("DistanceX", &x_cord, 0.f, 10000.f);
            ImGui::SliderFloat("DistanceY", &y_cord, 0.f, 10000.f);
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);	// Application benchmark
            ImGui::End();	// Terminate ImGui
        }

        starter.view = glm::translate(glm::mat4(1.0f), glm::vec3(x_cord, y_cord, 0));
        starter.MVP = starter.proj * starter.view;
        shader.SetUniformMat4f("u_MVP", starter.MVP);



        renderer.Draw(sorter.getIBsize()*4);
        GuiInterface.ImGuiRender();

        // Swap the back buffer with the front buffer
        glfwSwapBuffers(starter.window);
        // Take care of all GLFW events
        glfwPollEvents();
    }

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");






    return 0;
}