
#include "Math/Vec.h"
#include "Math/Mat.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <iostream>

namespace Joy
{
    namespace UnitTest
    {
        TEST(MathTest, VecOperatorTest)
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

        TEST(MathTest, MatOperationTest)
        {
            // 矩阵加减法运算
            Mat<2, 3, float> mat23_1{};
            mat23_1[0][0] = 1;
            mat23_1[0][1] = 2;
            mat23_1[1][0] = 3;
            mat23_1[1][1] = 4;
            mat23_1[2][0] = 5;
            mat23_1[2][1] = 6;
            Mat<2, 3, float> mat23_2{};
            mat23_2[0][0] = 9;
            mat23_2[0][1] = 8;
            mat23_2[1][0] = 7;
            mat23_2[1][1] = 6;
            mat23_2[2][0] = 5;
            mat23_2[2][1] = 4;
            Mat<2, 3, float> mat23_plus_ret{};
            mat23_plus_ret[0][0] = 10;
            mat23_plus_ret[0][1] = 10;
            mat23_plus_ret[1][0] = 10;
            mat23_plus_ret[1][1] = 10;
            mat23_plus_ret[2][0] = 10;
            mat23_plus_ret[2][1] = 10;
            Mat<2, 3, float> mat23_reduce_ret{};
            mat23_reduce_ret[0][0] = -8;
            mat23_reduce_ret[0][1] = -6;
            mat23_reduce_ret[1][0] = -4;
            mat23_reduce_ret[1][1] = -2;
            mat23_reduce_ret[2][0] = 0;
            mat23_reduce_ret[2][1] = 2;
            EXPECT_EQ(mat23_1 + mat23_2, mat23_plus_ret);
            EXPECT_EQ(mat23_1 - mat23_2, mat23_reduce_ret);
            // 矩阵乘法运算
            Mat<3, 2, float> mat32_1{};
            mat32_1[0][0] = 9;
            mat32_1[0][1] = 8;
            mat32_1[0][2] = 7;
            mat32_1[1][0] = 6;
            mat32_1[1][1] = 5;
            mat32_1[1][2] = 4;
            Mat<2, 2, float> mat22_multi_ret{};
            mat22_multi_ret[0][0] = 68;
            mat22_multi_ret[0][1] = 92;
            mat22_multi_ret[1][0] = 41;
            mat22_multi_ret[1][1] = 56;
            EXPECT_EQ(mat23_1 * mat32_1, mat22_multi_ret);
            Mat<3, 3, float> mat33_multi_ret{};
            mat33_multi_ret[0][0] = 21;
            mat33_multi_ret[0][1] = 18;
            mat33_multi_ret[0][2] = 15;
            mat33_multi_ret[1][0] = 51;
            mat33_multi_ret[1][1] = 44;
            mat33_multi_ret[1][2] = 37;
            mat33_multi_ret[2][0] = 81;
            mat33_multi_ret[2][1] = 70;
            mat33_multi_ret[2][2] = 59;
            EXPECT_EQ(mat32_1 * mat23_1, mat33_multi_ret);
            EXPECT_EQ(mat33_multi_ret * MAT3X3F_IDENTITY, mat33_multi_ret);
            EXPECT_EQ(mat33_multi_ret * MAT3X3F_ZERO, MAT3X3F_ZERO);
            // 矩阵标量乘法除法运算
            Mat<2, 3, float> mat23_multi_ret{};
            mat23_multi_ret[0][0] = 2;
            mat23_multi_ret[0][1] = 4;
            mat23_multi_ret[1][0] = 6;
            mat23_multi_ret[1][1] = 8;
            mat23_multi_ret[2][0] = 10;
            mat23_multi_ret[2][1] = 12;
            EXPECT_EQ(mat23_1 * 2.f, mat23_multi_ret);
            EXPECT_EQ(2.f * mat23_1, mat23_multi_ret);
            EXPECT_EQ(mat23_multi_ret / 2.f, mat23_1);
            // 矩阵转置运算
            Mat<3, 2, float> mat23_transpose{};
            mat23_transpose[0][0] = 1;
            mat23_transpose[0][1] = 3;
            mat23_transpose[0][2] = 5;
            mat23_transpose[1][0] = 2;
            mat23_transpose[1][1] = 4;
            mat23_transpose[1][2] = 6;
            EXPECT_EQ(mat23_1.Transpose(), mat23_transpose);
            EXPECT_EQ(mat23_transpose.Transpose(), mat23_1);
        }
    }   // namespace UnitTest

}   // namespace Joy