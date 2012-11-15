#include "IOstuff.h"

void readInputFile(string& filename, int numTriangles, int numVertices, vector<triangle>& triangleTable, vector<vertex>& vertexTable)
{
	// Open the input file
	ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		cout << "Error reading from " << filename << endl;
		exit(1);
	}

	// Read the number of triangles and vertices
	inFile >> numTriangles >> numVertices;

	// Read the vertex IDs for each triangle
	// Triangle soup: Each line contains 3 vertices that define a triangle
	for (int i = 0; i < numTriangles; ++i)
	{
		int v1, v2, v3;
		inFile >> v1 >> v2 >> v3;
		triangleTable.push_back(triangle(v1, v2, v3));
	}

	// Read vertex coordinates for all vertices
	for (int i = 0; i < numVertices; ++i)
	{
		double x, y, z;
		inFile >> x >> y >> z;
		vertexTable.push_back(vertex(x, y, z));
	}

	inFile.close();
}

void readVolumetricTexture(string& filename, RGB volumetricTexture[128 * 128 * 128])
{
	// Open the texture file
	ifstream inFile(filename.c_str(), ios::binary);
	if (!inFile.is_open())
	{
		cout << "Error reading from " << filename << endl;
		exit(1);
	}
	// Load the texture
	inFile.read((char*) volumetricTexture, 128 * 128 * 128 * sizeof(RGB));
	inFile.close();
}

void readPPMTexture(string& filename, RGB texture[], int& resX, int& resY)
{
	// Open the texture file
	ifstream inFile(filename.c_str(), ios::binary );
	if (!inFile.is_open())
	{
	  cout << "Error reading from " << filename << endl;
	  exit(1);
	}
	// Binary PPMs start with 'P6'
	char c;
	inFile >> c;
	assert(c == 'P');
	inFile >> c;
	assert(c == '6');
	inFile >> resX >> resY;
	// All images we'll use have 255 color levels
	int i;
	inFile >> i;
	assert(i == 255);
	// Need to skip one more byte
	inFile.get();
	// Allocate space
	texture = new RGB[resX * resY];
	inFile.read((char*) texture, resX * resY * sizeof(RGB));
	inFile.close();
}