
#ifndef SOLARSYSTEM_PLANET_H
#define SOLARSYSTEM_PLANET_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include "Shader.h"
#include "Mesh.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "stb_image.h"

GLint TextureFromFile(const char *path, const string &directory, bool gamma = false);

class Planet {
public:
	/*  Functions   */
	Planet(string const &path, bool gamma = false) : gammaCorrection(gamma)
	{
		loadPlanet(path);
	}
	void Draw(Shader shader);
	vector<Texture> getLoadedTextures();
	vector<Mesh> getMeshes();
private:
	/*  Planet Data  */
	vector<Mesh> meshes;
	string directory;
	bool gammaCorrection;
	vector<Texture> textures_loaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
										/*  Functions   */
	void loadPlanet(string const &path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};
#endif //SOLARSYSTEM_PLANET_H

