/**
 * @brief 向量模板定义
 *
 */

#include <cassert>

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
        /**
         * @brief 获取N维向量指定维度的值 - 只读取版本
         *
         * @param index
         * @return const T&
         */
        const T& operator[](const int index) const
        {
            assert(index >= 0 && index < DIMENSIONS);
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
            assert(index >= 0 && index < DIMENSIONS);
            return m_Data[index];
        }

    protected:
        /**
         * @brief N维向量源数据
         *
         */
        T m_Data[N];

    public:
        /**
         * @brief 向量维度层级
         *
         */
        constexpr static int DIMENSIONS = N;
    };

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
            assert(index >= 0 && index < DIMENSIONS);
            return index == 0 ? x : y;
        }
        float& operator[](const int index)
        {
            assert(index >= 0 && index < DIMENSIONS);
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
        constexpr static int DIMENSIONS = 2;
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
            assert(index >= 0 && index < DIMENSIONS);
            return index == 0 ? x : index == 1 ? y : z;
        }
        float& operator[](const int index)
        {
            assert(index >= 0 && index < DIMENSIONS);
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
        constexpr static int DIMENSIONS = 3;
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
            assert(index >= 0 && index < DIMENSIONS);
            return index == 0 ? x : index == 1 ? y : index == 2 ? z : w;
        }
        float& operator[](const int index)
        {
            assert(index >= 0 && index < DIMENSIONS);
            return index == 0 ? x : index == 1 ? y : index == 2 ? z : w;
        }

    public:
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
        float w = 0.f;

    public:
        constexpr static int DIMENSIONS = 4;
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