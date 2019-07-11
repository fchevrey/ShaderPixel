#ifndef TERRAIN_HPP
# define TERRAIN_HPP

# include "Model.hpp"

class Terrain : public Model
{

public: 
/*  constructors / Destructor   */
    Terrain(unsigned int x, unsigned int z); 
    Terrain(unsigned int x, unsigned int z, const std::string &filename); 
    Terrain(Terrain const & src); 
    ~Terrain(void); 
/*  functions   */
    //virtual void Draw(const Shader &shader);
    virtual bool LoadTexture(const std::string &filename);
	Terrain &		operator=(Terrain const & rhs);

protected:
/*  constructors    */
    Terrain();
/*  variables   */
    unsigned int _x;
    unsigned int _z;
    static const unsigned int _size;
    static const unsigned int _nbVertex;
/*  functions   */
	Mesh       _GenerateTerrain(unsigned int x, unsigned int z);
};

#endif


