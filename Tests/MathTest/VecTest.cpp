
#include "Math/Vec.h"
#include <gtest/gtest.h>

namespace Joy
{
    namespace UnitTest
    {
        TEST(MathTest, VecCommontTest)
        {
            Vec3f vec{Vec3f::Zero()};
            EXPECT_EQ(SqrNorm(vec), 0.f);
            EXPECT_EQ(Normalized(vec), Vec3f::Zero());
        }

        TEST(MathTest, VecOperatorTest2)
        {
            Vec3f vec1{2.f, 1.f,  -7.f};
            Vec3f vec2{0.f, -1.1f,  6.f};
            EXPECT_EQ(vec1 + vec2, Vec3f(2.f, -0.1f, -1.f));
        }
    }   // namespace UnitTest

}   // namespace Joy