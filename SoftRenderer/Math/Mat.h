/**
 * @file Mat.h
 * @author JoyatY
 * @brief 矩阵模板定义
 * @version 0.1
 * @date 2025-12-02
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "Vec.h"
#include <cassert>

namespace Joy
{
    /**
     * @brief 矩阵模板
     *
     * @tparam NRows 矩阵行数
     * @tparam NCols 矩阵列数
     * @tparam T 矩阵元素类型
     */
    template<int NRows, int NCols, typename T> struct Mat
    {
    public:
        constexpr Mat()
        {
            for (int i = 0; i < NCols; ++i)
            {
                m_RawData[i] = Vec<NRows, T>{};
            }
        }

    public:
        /**
         * @brief 获取矩阵指定列 - 只读
         *
         * @param index
         * @return const Vec<NRows, T>&
         */
        constexpr const Vec<NRows, T>& operator[](int index) const { return m_RawData[index]; }

        /**
         * @brief 获取矩阵指定列 - 可写入
         *
         * @param index
         * @return Vec<NRows, T>&
         */
        constexpr Vec<NRows, T>& operator[](int index) { return m_RawData[index]; }

    public:
        /**
         * @brief 获取转置矩阵
         *
         * @return Mat<NCols, NRows, T>
         */
        constexpr Mat<NCols, NRows, T> Transpose() const
        {
            Mat<NCols, NRows, T> ret{};
            for (int col = 0; col < NCols; ++col)
            {
                for (int row = 0; row < NRows; ++row)
                {
                    ret[row][col] = this[col][row];
                }
            }
            return ret;
        }

    public:
        /**
         * @brief 零矩阵
         *
         * @return constexpr Mat
         */
        constexpr static Mat Zero() { return Mat<NRows, NCols, T>(); }

        /**
         * @brief 单位矩阵
         *
         * @return constexpr Mat
         */
        constexpr static Mat Identity()
        {
            static_assert(NRows == NCols, "Identity Matrix must be a Square Matrix.");
            Mat<NRows, NCols, T> ret{};
            for (int col = 0; col < NCols; ++col)
            {
                for (int row = 0; row < NRows; ++row)
                {
                    ret[col][row] = col == row ? 1 : 0;
                }
            }
            return ret;
        }

    protected:
        /**
         * @brief 矩阵源数据(列优先存储)
         *
         */
        Vec<NRows, T> m_RawData[NCols];
    };

    /**
     * @brief 矩阵加法运算
     *
     * @tparam NRows 矩阵行数
     * @tparam NCols 矩阵列数
     * @tparam T 矩阵元素类型
     * @param lhs 左侧矩阵
     * @param rhs 右侧矩阵
     * @return Mat<NRows, NCols, T>
     */
    template<int NRows, int NCols, typename T>
    constexpr Mat<NRows, NCols, T> operator+(const Mat<NRows, NCols, T>& lhs, const Mat<NRows, NCols, T>& rhs)
    {
        Mat<NRows, NCols, T> ret{lhs};
        for (int col = 0; col < NCols; ++col)
        {
            for (int row = 0; row < NRows; ++row)
            {
                ret[col][row] += rhs[col][row];
            }
        }
        return ret;
    }

    /**
     * @brief 矩阵减法运算
     *
     * @tparam NRows 矩阵行数
     * @tparam NCols 矩阵列数
     * @tparam T 矩阵元素类型
     * @param lhs 左侧矩阵
     * @param rhs 右侧矩阵
     * @return Mat<NRows, NCols, T>
     */
    template<int NRows, int NCols, typename T>
    constexpr Mat<NRows, NCols, T> operator-(const Mat<NRows, NCols, T>& lhs, const Mat<NRows, NCols, T>& rhs)
    {
        Mat<NRows, NCols, T> ret{lhs};
        for (int col = 0; col < NCols; ++col)
        {
            for (int row = 0; row < NRows; ++row)
            {
                ret[col][row] -= rhs[col][row];
            }
        }
        return ret;
    }

    /**
     * @brief 矩阵乘法
     *
     * @tparam NLRows 左侧矩阵行数
     * @tparam N 左侧矩阵列数，右侧矩阵行数
     * @tparam NRCols 右侧矩阵列数
     * @tparam T 矩阵元素类型
     * @param lhs 左侧矩阵
     * @param rhs 右侧矩阵
     * @return Mat<NLRows, NRCols, T>
     */
    template<int NLRows, int N, int NRCols, typename T>
    constexpr Mat<NLRows, NRCols, T> operator*(const Mat<NLRows, N, T>& lhs, const Mat<N, NRCols, T>& rhs)
    {
        Mat<NLRows, NRCols, T> ret{};
        for (int lrow = 0; lrow < NLRows; ++lrow)
        {
            for (int index = 0; index < N; ++index)
            {
                for (int rcol = 0; rcol < NRCols; ++rcol)
                {
                    ret[lrow][rcol] += lhs[index][lrow] * rhs[rcol][index];
                }
            }
        }
        return ret;
    }

    /**
     * @brief 矩阵右乘向量
     *
     * @tparam NRows 矩阵行数
     * @tparam N 矩阵列数 | 向量维度
     * @tparam T 矩阵/向量的元素类型
     * @param mat 左侧矩阵
     * @param vec 右侧向量
     * @return Vec<N, T>
     */
    template<int NRows, int N, typename T> constexpr Vec<N, T> operator*(const Mat<NRows, N, T>& mat, const Vec<N, T>& vec)
    {
        Vec<N, T> ret{};
        for (int col = 0; col < N; ++col)
        {
            ret += mat[col] * vec[col];
        }
        return ret;
    }

    /**
     * @brief 矩阵与标量乘法
     *
     * @tparam NRows 矩阵行数
     * @tparam NCols 矩阵列数
     * @tparam T 矩阵元素类型
     * @param mat 矩阵
     * @param value 标量系数
     * @return Mat<NRows, NCols, T>
     */
    template<int NRows, int NCols, typename T> constexpr Mat<NRows, NCols, T> operator*(const Mat<NRows, NCols, T>& mat, const T& value)
    {
        Mat<NRows, NCols, T> ret{};
        for (int col = 0; col < NCols; ++col)
        {
            ret[col] = mat[col] * value;
        }
        return ret;
    }

    /**
     * @brief 矩阵与标量乘法
     *
     * @tparam NRows 矩阵行数
     * @tparam NCols 矩阵列数
     * @tparam T 矩阵元素类型
     * @param value 标量系数
     * @param mat 矩阵
     * @return Mat<NRows, NCols, T>
     */
    template<int NRows, int NCols, typename T> constexpr Mat<NRows, NCols, T> operator*(const T& value, const Mat<NRows, NCols, T>& mat)
    {
        return mat * value;
    }

    /**
     * @brief 矩阵与标量除法
     *
     * @tparam NRows 矩阵行数
     * @tparam NCols 矩阵列数
     * @tparam T 矩阵元素类型
     * @param mat 矩阵
     * @param value 标量系数
     * @return Mat<NRows, NCols, T>
     */
    template<int NRows, int NCols, typename T> constexpr Mat<NRows, NCols, T> operator/(const Mat<NRows, NCols, T>& mat, const T& value)
    {
        Mat<NRows, NCols, T> ret{};
        for (int col = 0; col < NCols; ++col)
        {
            ret[col] = mat[col] / value;
        }
        return ret;
    }

    /**
     * @brief 三维矩阵别名
     *
     */
    using Mat3x3f = Mat<3, 3, float>;

    /**
     * @brief 三维矩阵零矩阵
     *
     */
    constexpr Mat3x3f MAT3X3F_ZERO = Mat3x3f();

    /**
     * @brief 三维矩阵单位矩阵
     *
     */
    constexpr Mat3x3f MAT3X3F_IDENTITY = Mat3x3f::Identity();

    /**
     * @brief 四维矩阵别名
     *
     */
    using Mat4x4f = Mat<4, 4, float>;

    /**
     * @brief 四维矩阵零矩阵
     *
     */
    constexpr Mat4x4f MAT4X4F_ZERO = Mat4x4f();

    /**
     * @brief 四维矩阵单位矩阵
     *
     */
    constexpr Mat4x4f MAT4X4F_IDENTITY = Mat4x4f::Identity();
}   // namespace Joy