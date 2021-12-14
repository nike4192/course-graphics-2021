
#include "BufferGeometry.h"

class BoxGeometry : public BufferGeometry
{
public:
	BoxGeometry(float width, float height, float depth, int widthSegments, int heightSegments, int depthSegments);
};
