#include "pch.h"
#include "Renderer.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

unsigned int Renderer::CompileShader(const std::string& source, unsigned int type) {

	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {

		int lenght;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)alloca(lenght * sizeof(char));
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "shader") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;

	}


	return id;

}

unsigned int Renderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {

	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(vertexShader, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(fragmentShader, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;

}

