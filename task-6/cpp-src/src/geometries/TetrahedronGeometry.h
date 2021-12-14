#ifndef TETRAHEDRON_GEOMETRY_H
#define TETRAHEDRON_GEOMETRY_H

#define _USE_MATH_DEFINES

#include <math.h>
#include "PolyhedronGeometry.h"

// https://github.com/mrdoob/three.js/blob/master/src/geometries/TetrahedronGeometry.js
class TetrahedronGeometry : public PolyhedronGeometry
{
public:

	TetrahedronGeometry(float radius, int detail) {

		vertices = {
			glm::vec3( 1,  1,  1),
			glm::vec3(-1, -1,  1),
			glm::vec3(-1,  1, -1),
			glm::vec3( 1, -1, -1)
		};

		indices = {
			0, 2, 1,
			0, 3, 2,
			0, 1, 3,
			1, 2, 3
		};

		applyVertices(radius, detail);

	};
};

#endif
