/*
 * ��ʵ�ֵ�������ģ��
*/

#include <cmath>

namespace Joy
{
	/// <summary>
	/// Nά����ģ��
	/// </summary>
	/// <typeparam name="N"></typeparam>
	template<int N> class Vec
	{
	public:
		/// <summary>
		/// ��ȡ����ָ��ά��ֵ - ֻ��
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		const float& operator[](int index) const
		{
			return m_Data[index];
		}
		
		/// <summary>
		/// ��ȡ����ָ��ά��ֵ - ��д�븳ֵ
		/// </summary>
		float& operator[](int index)
		{
			return m_Data[index];
		}

		/// <summary>
		/// ��ȡ������ģ��
		/// </summary>
		/// <returns></returns>
		float Norm() const
		{
			return sqrtf(SqrNorm());
		}

		/// <summary>
		/// ��ȡ������ģ��ƽ��
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
	/// ������������*������
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