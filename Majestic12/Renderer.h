#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer
{
public:
	Renderer();
	~Renderer();
	static unsigned int CompileShader(const std::string& source, unsigned int type);
	static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
};

