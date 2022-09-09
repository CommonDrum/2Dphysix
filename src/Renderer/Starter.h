#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderClass.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"



#define DEFAULT_WIDTH 800.0f
#define DEFAULT_HIGHT 800.0f

class Starter // This class is cutting GLFW boilerplate and automates the deletion of data when program ends
{
public:
	Starter(std::string title, int sizeX = DEFAULT_WIDTH, int sizeY = DEFAULT_HIGHT);
	~Starter();
	void window_maximize_callback();
	GLFWwindow* window;
	// Create matrix to project objects to 2D screen
	glm::mat4 proj = glm::ortho(0.0f, DEFAULT_WIDTH, 0.0f, DEFAULT_HIGHT, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	glm::mat4 MVP = proj * view;
	int maximized = glfwGetWindowAttrib(window, GLFW_MAXIMIZED);

};

