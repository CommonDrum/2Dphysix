#include"Starter.h"
#include <iostream>



Starter::Starter(std::string title, int sizeX , int sizeY)
{
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Create a GLFWwindow object
	window = glfwCreateWindow(sizeX, sizeY, title.c_str(), NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, sizeX, sizeY);
	// Enable vsync
	glfwSwapInterval(1); 

}



Starter::~Starter()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}



void Starter::window_maximize_callback()
{
	maximized = glfwGetWindowAttrib(window, GLFW_MAXIMIZED);

	if (maximized)
	{
		int width, height;
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);
		proj = glm::ortho(0.0f, (float)width, 0.0f, (float)height, -1.0f, 1.0f);
	}
	else
	{
		glViewport(0, 0, DEFAULT_WIDTH, DEFAULT_HIGHT);
		proj = glm::ortho(0.0f, DEFAULT_WIDTH, 0.0f, DEFAULT_HIGHT, -1.0f, 1.0f);
	}
}

