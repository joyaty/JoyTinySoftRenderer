/**
 * @brief 向量模板定义
 *
 */

#include <cassert>
#include <cmath>
#include <ostream>

namespace Joy
{
    /**
     * @brief N维向量模板
     *
     * @tparam N
     * @tparam T
     */
    template<int N, typename T> struct Vec
    {
        static_assert(N > 0, "Vec dimension must be greater than 0.");

    public:
        constexpr Vec()
        {
            for (int i = 0; i < N; ++i)
            {
                m_Data[i] = 0.f;
            }
        }

    public:
        /**
         * @brief 获取N维向量指定维度的值 - 只读取版本
         *
         * @param index
         * @return const T&
         */
        const T& operator[](const int index) const
        {
            assert(index >= 0 && index < DIMENSION);
            return m_Data[index];
        }

        /**
         * @brief 获取N维向量指定维度的值 - 可写入版本
         *
         * @param index
         * @return T&
         */
        T& operator[](const int index)
        {
            assert(index >= 0 && index < DIMENSION);
            return m_Data[index];
        }

    protected:
        /**
         * @brief N维向量源数据
         *
         */
        T m_Data[N];

    public:
        constexpr static Vec<N, T> Zero() { return Vec(); }

    public:
        /**
         * @brief 向量维度层级
         *
         */
        constexpr static int DIMENSION = N;
    };

    /**
     * @brief 判断两个向量是否相等
     * 
     * @tparam N 
     * @tparam T 
     * @param lhs 
     * @param rhs 
     * @return true 
     * @return false 
     */
    template<int N, typename T> constexpr bool operator==(const Vec<N, T>& lhs, const Vec<N, T>& rhs)
    {
        for (int i = 0; i < N; ++i)
        {
            if (std::abs(lhs[i] - rhs[i]) >= 1e-5f)
            {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief 向量加法
     *
     * @tparam N
     * @tparam T
     * @param lhs
     * @param rhs
     * @return constexpr Vec<N, T>
     */
    template<int N, typename T> constexpr Vec<N, T> operator+(const Vec<N, T>& lhs, const Vec<N, T>& rhs)
    {
        Vec<N, T> ret = lhs;
        for (int i = 0; i < N; ++i)
        {
            ret[i] += rhs[i];
        }
        return ret;
    }

    /**
     * @brief 向量减法
     *
     * @tparam N
     * @tparam T
     * @param lhs
     * @param rhs
     * @return constexpr Vec<N, T>
     */
    template<int N, typename T> constexpr Vec<N, T> operator-(const Vec<N, T>& lhs, const Vec<N, T>& rhs)
    {
        Vec<N, T> ret = lhs;
        for (int i = 0; i < N; ++i)
        {
            ret[i] -= rhs[i];
        }
        return ret;
    }

    /**
     * @brief 分量乘法
     *
     * @tparam N
     * @tparam T
     * @param lhs
     * @param rhs
     * @return constexpr Vec<N, T>
     */
    template<int N, typename T> constexpr Vec<N, T> operator*(const Vec<N, T>& lhs, const Vec<N, T>& rhs)
    {
        Vec<N, T> ret = lhs;
        for (int i = 0; i < N; ++i)
        {
            ret[i] *= rhs[i];
        }
        return ret;
    }

    /**
     * @brief 标量后置乘法
     *
     * @tparam N
     * @tparam T
     * @param lhs
     * @param scale
     * @return constexpr Vec<N, T>
     */
    template<int N, typename T> constexpr Vec<N, T> operator*(const Vec<N, T>& lhs, const T& scale)
    {
        Vec<N, T> ret = lhs;
        for (int i = 0; i < N; ++i)
        {
            ret[i] *= scale;
        }
        return ret;
    }

    /**
     * @brief 标量前置乘法
     *
     * @tparam N
     * @tparam T
     * @param scale
     * @param rhs
     * @return constexpr Vec<N, T>
     */
    template<int N, typename T> constexpr Vec<N, T> operator*(const T& scale, const Vec<N, T>& rhs)
    {
        return rhs * scale;
    }

    /**
     * @brief 后置标量除法
     *
     * @tparam N
     * @tparam T
     * @param lhs
     * @param scale
     * @return constexpr Vec<N, T>
     */
    template<int N, typename T> constexpr Vec<N, T> operator/(const Vec<N, T>& lhs, const T& scale)
    {
        assert(scale != 0.f);
        Vec<N, T> ret = lhs;
        for (int i = 0; i < N; ++i)
        {
            ret[i] /= scale;
        }
        return ret;
    }

    /**
     * @brief 向量点积
     *
     * @tparam N
     * @tparam T
     * @param lhs
     * @param rhs
     * @return constexpr T
     */
    template<int N, typename T> constexpr T Dot(const Vec<N, T>& lhs, const Vec<N, T>& rhs)
    {
        T ret = 0;
        for (int i = 0; i < N; ++i)
        {
            ret += lhs[i] * rhs[i];
        }
        return ret;
    }

    /**
     * @brief 向量模长平方
     *
     * @tparam N
     * @tparam T
     * @param vec
     * @return constexpr T
     */
    template<int N, typename T> constexpr T SqrNorm(const Vec<N, T>& vec)
    {
        return Dot(vec, vec);
    }

    /**
     * @brief 获取向量模长
     *
     * @tparam N
     * @tparam T
     * @param vec
     * @return constexpr T
     */
    template<int N, typename T> constexpr T Norm(const Vec<N, T>& vec)
    {
        return std::sqrt(SqrNorm(vec));
    }

    /**
     * @brief 归一化向量
     *
     * @tparam N
     * @tparam T
     * @param vec
     * @return constexpr Vec<N, T>
     */
    template<int N, typename T> constexpr Vec<N, T> Normalized(const Vec<N, T>& vec)
    {
        T norm = Norm(vec);
        if (norm == 0.f)
        {
            return Vec<N, T>::Zero();
        }
        return vec / norm;
    }

    /**
     * @brief 打印N维向量
     *
     * @tparam N
     * @tparam T
     * @param out
     * @param vec
     * @return std::ostream&
     */
    template<int N, typename T> std::ostream& operator<<(std::ostream& out, const Vec<N, T>& vec)
    {
        out << "(";
        for (int i = 0; i < N; ++i)
        {
            out << vec[i];
            if (i < N - 1)
            {
                out << ",";
            }
        }
        out << ")";
        return out;
    }

    /**
     * @brief 2维浮点向量模板特化
     *
     * @tparam
     */
    template<> struct Vec<2, float>
    {
    public:
        constexpr Vec(float x = 0.f, float y = 0.f)
            : x(0.f)
            , y(0.f)
        {}

    public:
        const float& operator[](const int index) const
        {
            assert(index >= 0 && index < DIMENSION);
            return index == 0 ? x : y;
        }
        float& operator[](const int index)
        {
            assert(index >= 0 && index < DIMENSION);
            return index == 0 ? x : y;
        }

    public:
        float x = 0.f;
        float y = 0.f;

    public:
        constexpr static Vec<2, float> Zero() { return Vec<2, float>(); }
        constexpr static Vec<2, float> Left() { return Vec<2, float>(-1.f, 0.f); }
        constexpr static Vec<2, float> Right() { return Vec<2, float>(1.f, 0.f); }
        constexpr static Vec<2, float> Bottom() { return Vec<2, float>(0.f, -1.f); }
        constexpr static Vec<2, float> Up() { return Vec<2, float>(0.f, 1.f); }

    public:
        constexpr static int DIMENSION = 2;
    };

    /**
     * @brief 3维浮点向量模板特化
     *
     * @tparam
     */
    template<> struct Vec<3, float>
    {
    public:
        constexpr Vec(float x = 0.f, float y = 0.f, float z = 0.f)
            : x(x)
            , y(y)
            , z(z)
        {}

    public:
        const float& operator[](const int index) const
        {
            assert(index >= 0 && index < DIMENSION);
            return index == 0 ? x : index == 1 ? y : z;
        }
        float& operator[](const int index)
        {
            assert(index >= 0 && index < DIMENSION);
            return index == 0 ? x : index == 1 ? y : z;
        }

    public:
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;

    public:
        constexpr static Vec<3, float> Zero() { return Vec<3, float>(); }
        constexpr static Vec<3, float> Left() { return Vec<3, float>(-1.f, 0.f, 0.f); }
        constexpr static Vec<3, float> Right() { return Vec<3, float>(1.f, 0.f, 0.f); }
        constexpr static Vec<3, float> Bottom() { return Vec<3, float>(0.f, -1.f, 0.f); }
        constexpr static Vec<3, float> Up() { return Vec<3, float>(0.f, 1.f, 0.f); }
        constexpr static Vec<3, float> Backward() { return Vec<3, float>(0.f, 0.f, -1.f); }
        constexpr static Vec<3, float> Forward() { return Vec<3, float>(0.f, 0.f, 1.f); }

    public:
        constexpr static int DIMENSION = 3;
    };

    /**
     * @brief 4维浮点向量模板特化
     *
     * @tparam
     */
    template<> struct Vec<4, float>
    {
    public:
        constexpr Vec(float x = 0.f, float y = 0.f, float z = 0.f, float w = 0.f)
            : x(x)
            , y(y)
            , z(z)
            , w(w)
        {}

    public:
        const float& operator[](const int index) const
        {
            assert(index >= 0 && index < DIMENSION);
            return index == 0 ? x : index == 1 ? y : index == 2 ? z : w;
        }
        float& operator[](const int index)
        {
            assert(index >= 0 && index < DIMENSION);
            return index == 0 ? x : index == 1 ? y : index == 2 ? z : w;
        }

    public:
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
        float w = 0.f;

    public:
        constexpr static int DIMENSION = 4;
    };

    /**
     * @brief 二维浮点向量别名
     *
     */
    using Vec2f = Vec<2, float>;

    /**
     * @brief 三维浮点向量别名
     *
     */
    using Vec3f = Vec<3, float>;

    /**
     * @brief 四维浮点向量别名
     *
     */
    using Vec4f = Vec<4, float>;
}   // namespace Joy