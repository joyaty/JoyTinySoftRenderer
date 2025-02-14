/*
 * 简单实现的向量类模板
*/

#include <cmath>

namespace Joy
{
	/// <summary>
	/// N维向量模板
	/// </summary>
	/// <typeparam name="N"></typeparam>
	template<int N> class Vec
	{
	public:
		/// <summary>
		/// 获取向量指定维度值 - 只读
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		const float& operator[](int index) const
		{
			return m_Data[index];
		}
		
		/// <summary>
		/// 获取向量指定维度值 - 可写入赋值
		/// </summary>
		float& operator[](int index)
		{
			return m_Data[index];
		}

		/// <summary>
		/// 获取向量的模长
		/// </summary>
		/// <returns></returns>
		float Norm() const
		{
			return sqrtf(SqrNorm());
		}

		/// <summary>
		/// 获取向量的模长平方
		/// </summary>
		/// <returns></returns>
		float SqrNorm() const
		{
			return (*this) * (*this);
		}
		
	private:
		float m_Data[N] = { 0 };
	};

	/// <summary>
	/// 重载两个向量*操作符
	/// </summary>
	/// <typeparam name="N"></typeparam>
	/// <param name="vec1"></param>
	/// <param name="vec2"></param>
	/// <returns></returns>
	template<int N> float operator* (const Vec<N>& vec1, const Vec<N>& vec2)
	{
		float ret = 0;
		for (int i = 0; i < N; ++i)
		{
			ret += vec1[i] * vec2[i];
		}
		return ret;
	}
}