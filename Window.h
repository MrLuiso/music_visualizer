#pragma once

#include "gl.h"
#include <GLFW/glfw3.h>

class Renderer;

class Window {
	// reads width/height, size_changed, mouse
	// writes size_changed
	friend class Renderer;
public:
	Window(int width, int height);
	~Window();

	void swap_buffers();
	bool is_alive();

	void window_size_callback(int width, int height);
	void cursor_position_callback(double xpos, double ypos);
	void mouse_button_callback(int button, int action, int mods);
	void keyboard_callback(int key, int scancode, int action, int mods);

private:
	GLFWwindow* window;
	int width;
	int height;
	bool size_changed;
	struct {
		float x;
		float y;
		bool down;
	} mouse;
};

#include "Renderer.h"
