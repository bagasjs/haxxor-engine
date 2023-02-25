#include "Haxxor/Core/Common.h"
#include "Haxxor/Core/Input.h"
#include "Haxxor/Application.h"
#include <GLFW/glfw3.h>

namespace Haxxor {
	bool Input::IsKeyPressed(const KeyCode key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeHandle());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS;
	}

	bool Input::IsMouseButtonPressed(const MouseCode button)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeHandle());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}

	float Input::GetMouseX()
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeHandle());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return xpos;
	}

	float Input::GetMouseY()
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeHandle());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return ypos;
	}

}