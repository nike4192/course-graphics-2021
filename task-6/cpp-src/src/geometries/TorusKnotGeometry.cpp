
#include "TorusKnotGeometry.h"

TorusKnotGeometry::TorusKnotGeometry(float radius, float tube, float tubularSegments, float radialSegments, float p, float q)
{
    glm::vec3 P1, P2, B, T, N;

    auto sample = [radius, p, q](float u, glm::vec3 *position)
    {
        float cu = cos(u);
        float su = sin(u);
        float quOverP = q / p * u;
        float cs = cos(quOverP);
        position->x = radius * (2 + cs) * 0.5 * cu;
        position->y = radius * (2 + cs) * su * 0.5;
        position->z = radius * sin(quOverP) * 0.5;

        // https://en.wikipedia.org/wiki/Torus_knot#Geometrical_representation
        // position->x = (2 + cos(q * u)) * cos(p * u);
        // position->y = (2 + cos(q * u)) * sin(p * u);
        // position->z = -sin(q * u);
    };

    for (int i = 0; i <= tubularSegments; ++i)
    {
        float u1 = i / tubularSegments * p * 2 * M_PI;
        float u2 = (i + 1) / tubularSegments * p * 2 * M_PI;

        sample(u1, &P1);
        sample(u2, &P2);

        T = P2 - P1;
        N = P2 + P1;
        B = glm::normalize(glm::cross(T, N));
        N = glm::normalize(glm::cross(B, T));

        for (int j = 0; j <= radialSegments; ++j)
        {
            float v = j / radialSegments * 2 * M_PI;

            float px = -tube * cos(v);
            float py =  tube * sin(v);

            glm::vec3 p = N * px + B * py + P1;

            vertices.push_back(p);
        }
    }

    for (int j = 1; j <= tubularSegments; j++)
    {
        for (int i = 1; i <= radialSegments; i++)
        {
            int a = (radialSegments + 1) * j + (i - 1);
            int b = (radialSegments + 1) * j + i;
            int d = (radialSegments + 1) * (j - 1) + i;
            int c = (radialSegments + 1) * (j - 1) + (i - 1);

            // a - c
            // | \ |
            // b - d

            indices.push_back(a);
            indices.push_back(b);
            indices.push_back(d);

            indices.push_back(a);
            indices.push_back(d);
            indices.push_back(c);
    	}
    }
};
