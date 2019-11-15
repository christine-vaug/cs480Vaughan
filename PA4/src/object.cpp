#include <fstream>

#include "object.h"

Object::Object(char* path, float baseSc, float baseOS, float baseSS)
{  
  /*
    # Blender File for a Cube
    o Cube
    v 1.000000 -1.000000 -1.000000
    v 1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 -1.000000
    v 1.000000 1.000000 -0.999999
    v 0.999999 1.000000 1.000001
    v -1.000000 1.000000 1.000000
    v -1.000000 1.000000 -1.000000
    s off
    f 2 3 4
    f 8 7 6
    f 1 5 6
    f 2 6 7
    f 7 8 4
    f 1 4 8
    f 1 2 4
    f 5 8 6
    f 2 1 6
    f 3 2 7
    f 3 7 4
    f 5 1 8
  */

  /*Vertices = {
    {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
    {{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},
    {{1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},
    {{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
  };

  Indices = {
    2, 3, 4,
    8, 7, 6,
    1, 5, 6,
    2, 6, 7,
    7, 8, 4,
    1, 4, 8,
    1, 2, 4,
    5, 8, 6,
    2, 1, 6,
    3, 2, 7,
    3, 7, 4,
    5, 1, 8
  };

  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }*/

  //object loader code taken from https://github.com/opengl-tutorials/ogl/blob/master/tutorial07_model_loading/tutorial07.cpp
  bool res = loadOBJ(path, Vertices, Indices);
  std::cout << "Finished loading." << std::endl;

  angleOrbit = 0.0f;
  angleSelf = 0.0f;

  pausedOrbit = false;
  pausedSpin = false;
  reversedOrbit = false;
  reversedSpin = false;
  position = glm::mat4(1.0f);

  baseScale = baseSc;
  scaleMult = 1.0f; //scales up/down 0.25 w/ each keypress
  maxScale = 3.0f;
  minScale = 0.25f;

  baseOrbitSpeed = baseOS;
  baseSpinSpeed = baseSS;
  orbitSpeedMult = 1.0f;  //scales up/down 0.25 w/ each keypress
  spinSpeedMult = 1.0f;  //scales up/down 0.25 w/ each keypress
  maxSpeed = 3.0f;
  minSpeed = 0.25f;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt, glm::mat4 orbitOrigin)
{
  // if(!pausedOrbit)
  // {
  //   if(reversedOrbit)
  //     angleOrbit -= dt * M_PI/(baseOrbitSpeed / orbitSpeedMult); //the angle of the object's orbit
  //   else
  //     angleOrbit += dt * M_PI/(baseOrbitSpeed / orbitSpeedMult); //the angle of the object's orbit
  // }
  // if(!pausedSpin)
  // {
  //   if(reversedSpin)
  //     angleSelf -= dt * M_PI/(baseSpinSpeed / spinSpeedMult); //the angle of the object's orbit
  //   else
  //     angleSelf += dt * M_PI/(baseSpinSpeed / spinSpeedMult); //the angle of the object's orbit
  // }

  /*position = glm::translate(orbitOrigin, glm::vec3((5.0f * sin(angleOrbit)), 0.0f, (5.0f * cos(angleOrbit)))); //translates cube about the designated orbitOrigin
  glm::mat4 rotSelf = glm::rotate(glm::mat4(1.0f), (angleSelf), glm::vec3(0.0, 1.0, 0.0)); //sets the cube's rotation about its center y-axis
  glm::mat4 scaleMat = glm::scale(glm::vec3((scaleMult * baseScale), (scaleMult * baseScale), (scaleMult * baseScale))); //set the scale of the object

  model = position * rotSelf * scaleMat; //multiply matrices to apply effects to the model*/
  //angleSelf += dt * M_PI/1000;
  //model = glm::rotate(model, (angleSelf), glm::vec3(0.0, 1.0, 0.0));
}

glm::mat4 Object::GetModel()
{
  return model;
}

glm::mat4 Object::GetPosition()
{
  return position;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);

  //rendering code taken from https://github.com/opengl-tutorials/ogl/blob/master/tutorial07_model_loading/tutorial07.cpp
  /*glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : UVs
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, UVB);
		glVertexAttribPointer(
			1,                                // attribute
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, vertices.size() );

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);*/
}

void Object::SetScale(bool scalar)
{
  if(scalar) //if increasing
  {
    if(scaleMult + 0.25f > maxScale) //be sure not to go over the max limit
      scaleMult = maxScale;
    else
      scaleMult += 0.25f;
  }
  else //if decreasing
  {
    if(scaleMult - 0.25f < minScale) //be sure not to go under the min limit
      scaleMult = minScale;
    else
      scaleMult -= 0.25f;
  }
}

void Object::SetOrbitSpeed(bool scalar)
{
  if(scalar) //if increasing
  {
    if(orbitSpeedMult + 0.25f > maxSpeed) //be sure not to go over the max limit
      orbitSpeedMult = maxSpeed;
    else
      orbitSpeedMult += 0.25f;
  }
  else //if decreasing
  {
    if(orbitSpeedMult - 0.25f < minSpeed) //be sure not to go under the min limit
      orbitSpeedMult = minSpeed;
    else
      orbitSpeedMult -= 0.25f;
  }
}

void Object::SetSpinSpeed(bool scalar)
{
  if(scalar) //if increasing
  {
    if(spinSpeedMult + 0.25f > maxSpeed) //be sure not to go over the max limit
      spinSpeedMult = maxSpeed;
    else
      spinSpeedMult += 0.25f;
  }
  else //if decreasing
  {
    if(spinSpeedMult - 0.25f < minSpeed) //be sure not to go under the min limit
      spinSpeedMult = minSpeed;
    else
      spinSpeedMult -= 0.25f;
  }
}

//object loader code taken and modified from 
bool Object::loadOBJ(char* path, std::vector<Vertex> & out_vertices, std::vector<unsigned int> & out_indices)
{
  //std::vector<unsigned int> vertexIndices;
	std::vector<Vertex> temp_vertices; 
	std::vector<unsigned int> temp_indices;
  bool blenderFormat = 1; //if first format works, blenderFormat = 1, else blenderFormat = 0;

	FILE * file = fopen(path, "r");
	if( file == NULL ){
		printf("There was an error opening the object file!\n");
		getchar();
		return false;
	}

	while( 1 ){

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		
		if ( strcmp( lineHeader, "v" ) == 0 ){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
			if (matches != 9){
				printf("File can't be read by our simple parser :-( Try exporting with other options\n");
				fclose(file);
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
		}else{
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}

	}

	// For each vertex of each triangle
	for( unsigned int i=0; i<vertexIndices.size(); i++ ){

		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
		
		// Get the attributes thanks to the index
		glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
		
		// Put the attributes in buffers
		out_vertices.push_back(vertex);
	
	}
	fclose(file);
	return true;
}