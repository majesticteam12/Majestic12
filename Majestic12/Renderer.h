#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <string>

class Renderer
{
public:
	Renderer();
	~Renderer();
    unsigned int CompileShader(const std::string& source, unsigned int type);
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	struct  ShaderProgramSource
	{
		std::string vertexShader;
		std::string fragmentShader;
	};
    ShaderProgramSource ParseShader(const std::string& filePath);

};

