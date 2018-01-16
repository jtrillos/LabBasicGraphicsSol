/*
 * The shader class should contain at least:
 *
 * member variables:
 *      -a GLuint program
 *      -a std::string path
 *
 * member methods:
 *      -a constructor
 *      -a destructor
 *      -a function to read shader source code from a text file
 *      -a function to create a shader from a string
 *      -a function to link the shader programs
 *      -a function to create a final shader program
 *      -a function to print errors during shader compilation
 *
 *      -a function to activate a shader
 *      -a function to update special uniforms in the shader (model, view, projection matrices)
 */

#ifndef SHADER_H
#define SHADER_H


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
	unsigned int ID;
	// constructor generates the shader on the fly
	// ------------------------------------------------------------------------
	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	// activate the shader
	// ------------------------------------------------------------------------
	void use();
	// utility uniform functions
	// ------------------------------------------------------------------------
	void setBool(const std::string &name, bool value) const;
	// ------------------------------------------------------------------------
	void setInt(const std::string &name, int value) const;
	// ------------------------------------------------------------------------
	void setFloat(const std::string &name, float value) const;
	// ------------------------------------------------------------------------
	void setVec2(const std::string &name, const glm::vec2 &value) const;
	void setVec2(const std::string &name, float x, float y) const;
	// ------------------------------------------------------------------------
	void setVec3(const std::string &name, const glm::vec3 &value) const;
	void setVec3(const std::string &name, float x, float y, float z) const;
	// ------------------------------------------------------------------------
	void setVec4(const std::string &name, const glm::vec4 &value) const;
	void setVec4(const std::string &name, float x, float y, float z, float w);
	// ------------------------------------------------------------------------
	void setMat2(const std::string &name, const glm::mat2 &mat) const;
	// ------------------------------------------------------------------------
	void setMat3(const std::string &name, const glm::mat3 &mat) const;
	// ------------------------------------------------------------------------
	void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	void checkCompileErrors(GLuint shader, std::string type);
};
#endif