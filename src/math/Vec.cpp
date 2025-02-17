#include "Vec.h"

namespace Joy 
{
    float Cross(const Vec2& vec1, const Vec2& vec2)
    {
        return vec1.x * vec2.y - vec1.y * vec2.x;
    }

	Vec3 Cross(const Vec3& vec1, const Vec3& vec2)
    {
        Vec3 ret{};
        ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
        ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
        ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
        return ret;
    }
}