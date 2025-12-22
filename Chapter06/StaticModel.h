#include "StaticMesh.h"
#ifndef STATICMODEL_H  // Header guards prevent multiple inclusions
#define STATICMODEL_H

class StaticModel {
 public:
  std::vector<StaticMesh> meshes;
  std::string directory;
  void LoadModel(std::string const &path);
  void Draw(unsigned int shaderID);

 private:
  void processNode(aiNode *node, const aiScene *scene);
  StaticMesh processMesh(aiMesh *mesh, const aiScene *scene);
  
  
};

#endif
