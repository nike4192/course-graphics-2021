
#include "ConicalSpiralGeometry.h"

ConicalSpiralGeometry::ConicalSpiralGeometry(float radius,float tube, float height, float radialSegments, float tubularSegments, float m)
{
	glm::vec3 P1, P2, B, T, N;
	float z0 = -(float)height / 2;

	auto sample = [m, height](float z0, float r, float t, glm::vec3 &position)
	{
		float phi = t * 2 * M_PI;

		position.x = r * t * cos(m * phi);
		position.y = z0 + height * (1 - t);
		position.z = r * t * sin(m * phi);
	};

	for (int i = 0; i <= radialSegments; ++i)
	{
		float t = (float)i / radialSegments;

		sample(z0, radius, t, P1);
		sample(z0, radius, t + 0.01, P2);

		T = P2 - P1;
		N = P2 + P1;
		B = glm::normalize(glm::cross(T, N));
		N = glm::normalize(glm::cross(B, T));
	
		for (int j = 0; j <= tubularSegments; ++j)
		{
			float v = j / tubularSegments * 2 * M_PI;

			float px = t * tube * cos(v);
			float py = t * tube * sin(v);

			glm::vec3 p = N * px + B * py + P1;

			vertices.push_back(p);
		}
	}
	for (int i = 1; i <= radialSegments; ++i)
	{
		for (int j = 1; j <= tubularSegments; ++j)
		{
            int a = (tubularSegments + 1) * i + (j - 1);
            int b = (tubularSegments + 1) * i + j;
            int d = (tubularSegments + 1) * (i - 1) + j;
            int c = (tubularSegments + 1) * (i - 1) + (j - 1);

            // a - c
            // | \ |
            // b - d

            if (i > 1)
            {
	            indices.push_back(a);
	            indices.push_back(c);
	            indices.push_back(d);
            }

            indices.push_back(a);
            indices.push_back(d);
            indices.push_back(b);

		}
	}

};
