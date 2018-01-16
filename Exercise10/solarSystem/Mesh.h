/*
 * The Mesh class should contain at least:
 *
 * member variables:
 *      -a GLuint VAO
 *      -a GLuint VBO
 *      -a GLuint EBO
 *
 *      -a std::vector<Vertex> vertices
 *      -a std::vector<GLuint> indices
 *
 *      -a std::string path
 *
 * member methods:
 *      -a constructor
 *      -a destructor
 *      -a function to upload the attributes to the gpu
 *      -a function to draw the mesh
 */

#ifndef SOLARSYSTEM_MESH_H
#define SOLARSYSTEM_MESH_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// GL Includes
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include <assimp/types.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

/* The vertex struct should contain at least:
 *      -a glm::vec3 position
 *      -a glm::vec3 texCoords
 */
struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 tangent;
	glm::vec3 bitangent;
};

struct Texture {
	GLuint id;
	string type;
	string path;
};

class Mesh {
private:
	GLuint VAO, VBO, EBO;

	void setupMesh();
public:

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	std::string path;

	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	void draw(Shader shader);
	GLuint getVAO();

};


#endif //SOLARSYSTEM_MESH_H
