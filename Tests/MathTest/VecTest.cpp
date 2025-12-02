
#include "Math/Vec.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <iostream>

namespace Joy
{
    namespace UnitTest
    {
        TEST(MathTest, VecOperatorTest2)
        {
            // 向量加减法、分量乘法
            Vec3f vec1{2.f, 1.f, -7.f};
            Vec3f vec2{0.f, -1.1f, 6.f};
            EXPECT_EQ(vec1 + vec2, Vec3f(2.f, -0.1f, -1.f));
            EXPECT_EQ(vec1 - vec2, Vec3f(2.f, 2.1f, -13.f));
            EXPECT_EQ(vec1 * vec2, Vec3f(0.f, -1.1f, -42.f));
            // 标量乘法
            float scale1 = 3.f;
            float scale2 = 0.f;
            EXPECT_EQ(vec1 * scale1, Vec3f(6.f, 3.f, -21.f));
            EXPECT_EQ(scale1 * vec2, Vec3f(0.f, -3.3f, 18.f));
            EXPECT_EQ(vec1 / scale1, Vec3f(0.66666f, 0.333333f, -2.3333333f));
            // EXPECT_EQ(vec2 / scale2, Vec3f::Zero()); // 除零触发assert
            // 点积操作
            EXPECT_EQ(Dot(vec1, vec2), -43.1f);
            EXPECT_EQ(Dot(vec1, vec1), SqrNorm(vec1));
            EXPECT_EQ(Norm(vec1), 7.348469228f);
            EXPECT_EQ(Normalized(vec1), Vec3f(0.2721655269759f, 0.136082763487954f, -0.95257934441568f));
            EXPECT_NEAR(Norm(Vec3f(0.2721655269759f, 0.136082763487954f, -0.95257934441568f)), 1.f, 1e-7f);
            // 叉积操作
            EXPECT_EQ(Cross(Vec3f::Right(), Vec3f::Up()), Vec3f::Forward());
            EXPECT_EQ(Cross(Vec3f::Up(), Vec3f::Right()), Vec3f::Backward());
            EXPECT_EQ(Cross(Vec3f::Forward(), Vec3f::Right()), Vec3f::Up());
            EXPECT_EQ(Cross(Vec3f::Up(), Vec3f::Forward()), Vec3f::Right());

            std::cout << "vec1 = " << vec1 << std::endl;
            std::cout << "vec2 = " << vec2 << std::endl;
        }
    }   // namespace UnitTest

}   // namespace Joy