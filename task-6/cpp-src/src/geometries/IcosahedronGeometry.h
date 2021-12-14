#ifndef ICOSAHEDRON_GEOMETRY_H
#define ICOSAHEDRON_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "PolyhedronGeometry.h"

// https://github.com/mrdoob/three.js/blob/master/src/geometries/IcosahedronGeometry.js
class IcosahedronGeometry : public PolyhedronGeometry
{
public:
	IcosahedronGeometry(float radius, int detail) {

		float t = (1 + sqrt(5)) / 2;

		vertices = {
			glm::vec3(-1,  t,  0),
			glm::vec3( 1,  t,  0),
			glm::vec3(-1, -t,  0),
			glm::vec3( 1, -t,  0),
			glm::vec3( 0, -1,  t),
			glm::vec3( 0,  1,  t),
			glm::vec3( 0, -1, -t),
			glm::vec3( 0,  1, -t),
			glm::vec3( t,  0, -1),
			glm::vec3( t,  0,  1),
			glm::vec3(-t,  0, -1),
			glm::vec3(-t,  0,  1)
		};

		indices = {
			0, 11, 5, 	0, 5, 1, 	0, 1, 7, 	0, 7, 10, 	0, 10, 11,
			1, 5, 9, 	5, 11, 4,	11, 10, 2,	10, 7, 6,	7, 1, 8,
			3, 9, 4, 	3, 4, 2,	3, 2, 6,	3, 6, 8,	3, 8, 9,
			4, 9, 5, 	2, 4, 11,	6, 2, 10,	8, 6, 7,	9, 8, 1
		};

		applyVertices(radius, detail);

	};
};

#endif
