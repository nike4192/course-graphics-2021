#ifndef OCTAHEDRON_GEOMETRY_H
#define OCTAHEDRON_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "PolyhedronGeometry.h"

// https://github.com/mrdoob/three.js/blob/master/src/geometries/OctahedronGeometry.js
class OctahedronGeometry : public PolyhedronGeometry
{
public:
	OctahedronGeometry(float radius, int detail) {

		float q = sqrt(2);

		vertices = {
			glm::vec3( 0, -q,  0),
			glm::vec3( 1,  0,  1),
			glm::vec3( 1,  0, -1),
			glm::vec3(-1,  0, -1),
			glm::vec3(-1,  0,  1),
			glm::vec3( 0,  q,  0)
		};

		indices = {
			0, 2, 1,
			0, 3, 2,
			0, 4, 3,
			0, 1, 4,
			5, 4, 1,
			5, 1, 2,
			5, 2, 3,
			5, 3, 4
		};

		applyVertices(radius, detail);

	};
};

#endif
