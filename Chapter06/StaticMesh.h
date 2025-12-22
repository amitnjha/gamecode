#ifndef STATICMESH_H  // Header guards prevent multiple inclusions
#define STATICMESH_H
#include <glm/glm.hpp>

struct StaticVertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type; // e.g., "texture_diffuse"
    std::string path;
};
class StaticMesh {
 public:
   std::vector<StaticVertex> vertices;
   std::vector<unsigned int> indices;
   std::vector<Texture> textures;
   unsigned int VAO;

   StaticMesh(std::vector<StaticVertex> v, std::vector<unsigned int> i, std::vector<Texture> t) ;
    
   void Draw(unsigned int shaderID);
private:
  void setupMesh();
};
#endif
