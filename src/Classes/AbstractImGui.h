#pragma once
#include "../Vendor/imgui/imgui_impl_glfw.h"
#include "../Vendor/imgui/imgui.h"
#include "../Vendor/imgui/imgui_impl_opengl3.h"


class ImGuiInterface
{
public:
	ImGuiInterface(GLFWwindow* window);
	~ImGuiInterface();
	void ImGuiRender();
	void ImGuiNewFrame();


private:
	const char* glsl_version = "#version 330";

};
