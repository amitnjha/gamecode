#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "StaticModel.h"
#include "StaticMesh.h"
#include <iostream>

//class StaticModel {
//public:
//   std::vector<StaticMesh> meshes;
//  std::string directory;

void StaticModel::LoadModel(std::string const &path) {
        Assimp::Importer importer;
        // Optimization: aiProcess_PreTransformVertices can bake scales/rotations directly
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);

        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
	  std:: cout << "model load failed " << importer.GetErrorString() << "\n";
	  return;
	}
        
        directory = path.substr(0, path.find_last_of('/'));
        processNode(scene->mRootNode, scene);
    }

void StaticModel::Draw(unsigned int shaderID) {
  //  std::cout<< "In draw " << meshes.size() << "\n";
	
        for(auto &mesh : meshes) mesh.Draw(shaderID);
    }

//private:
void StaticModel::processNode(aiNode *node, const aiScene *scene) {
        for(unsigned int i = 0; i < node->mNumMeshes; i++) {
            aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(mesh, scene));
        }
        for(unsigned int i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene);
        }
    }

StaticMesh StaticModel::processMesh(aiMesh *mesh, const aiScene *scene) {
        std::vector<StaticVertex> vertices;
        std::vector<unsigned int> indices;
        
        for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
            StaticVertex vertex;
            vertex.Position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
            vertex.Normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
            vertex.TexCoords = mesh->mTextureCoords[0] ? glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y) : glm::vec2(0.0f);
            vertices.push_back(vertex);
        }

        for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
            for(unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
                indices.push_back(mesh->mFaces[i].mIndices[j]);
        }
        
        // Return a mesh without the bone data overhead
        return StaticMesh(vertices, indices, {}); 
    }
//};
