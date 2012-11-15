#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>

#include "RGB.h"
#include "triangle.h"
#include "vertex.h"

#pragma once

using namespace std;

void readInputFile(string& filename, int numTriangles, int numVertices, vector<triangle>& triangleTable, vector<vertex>& vertexTable);
void readVolumetricTexture(string& filename, RGB volumetricTexture[128 * 128 * 128]);
void readPPMTexture(string& filename, RGB texture[], int& resX, int& resY);