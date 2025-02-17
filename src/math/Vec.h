/*
 * 简单实现的向量类模板
 */

#include <cmath>
#include <cassert>

#pragma once

namespace Joy
{
	/// <summary>
	/// N维向量模板
	/// </summary>
	/// <typeparam name="N"></typeparam>
	template<int N> class Vec
	{
	public:
		const float& operator[](int index) const
		{
			assert(index >=0 && index < N);
			return m_Data[index];
		}
		
		float& operator[](int index)
		{
			assert(index >=0 && index < N);
			return m_Data[index];
		}

		float Norm() const
		{
			return sqrtf(SqrNorm());
		}

		float SqrNorm() const
		{
			return (*this) * (*this);
		}
		
	private:
		float m_Data[N] = { 0 };
	};

	template<int N> Vec<N> operator+ (const Vec<N>& vec1, const Vec<N>& vec2)
	{
		Vec<N> ret = vec1;
		for(int i = 0; i < N; ++i)
		{
			ret[i] += vec2[i];
		}
		return ret;
	}

	template<int N> Vec<N> operator- (const Vec<N>& vec1, const Vec<N>& vec2)
	{
		Vec<N> ret = vec1;
		for (int i = 0; i < N; ++i)
		{
			ret[i] -= vec2[i];
		}
		return ret;
	}

	template<int N> Vec<N> operator* (const Vec<N>& vec, float value)
	{
		Vec<N> ret = vec;
		for (int i = 0; i < N; ++i) 
		{
			ret[i] *= value;
		}
		return ret;
	}

	template<int N> Vec<N> operator* (float value, const Vec<N>& vec)
	{
		return vec * value;
	}

	template<int N> float operator* (const Vec<N>& vec1, const Vec<N>& vec2)
	{
		float ret = 0;
		for (int i = 0; i < N; ++i)
		{
			ret += vec1[i] * vec2[i];
		}
		return ret;
	}

	template<int N> Vec<N> operator/ (const Vec<N>& vec, float value)
	{
		Vec<N> ret = vec;
		for (int i = 0; i < N; ++i)
		{
			ret[i] /= value;
		}
		return ret;
	}

	template<int N> float Dot(const Vec<N>& vec1, const Vec<N>& vec2)
	{
		return vec1 * vec2;
	}
	
	template<int N1, int N2> Vec<N1> Embed(const Vec<N2>& vec, float fill = 1)
	{
		Vec<N1> ret;
		for(int i = 0; i < N1; ++i)
		{
			ret[i] = i < N2 ? vec[i] : fill;
		}
		return ret;
	}

	template<> class Vec<2> 
	{
	public:
		const float& operator[] (int index) const
		{
			assert(index >=0 && index < 2);
			return index == 0 ? x : y;
		}

		float& operator[] (int index)
		{
			assert(index >=0 && index < 2);
			return index == 0 ? x : y;
		}

		float Norm() const
		{
			return sqrtf(SqrNorm());
		}

		float SqrNorm() const
		{
			return (*this) * (*this);
		}

		Vec<2> Normalize() const 
		{
			return (*this) / Norm();
		}

	public:
		float x = 0, y = 0;
	};

	template<> class Vec<3>
	{
	public:
		const float& operator[] (int index) const
		{
			assert(index >=0 && index < 3);
			return index == 0 ? x : ((index == 1) ? y : z);
		}

		float& operator[] (int index)
		{
			assert(index >=0 && index < 3);
			return index == 0 ? x : ((index == 1) ? y : z);
		}

		float Norm() const
		{
			return sqrtf(SqrNorm());
		}

		float SqrNorm() const
		{
			return (*this) * (*this);
		}

		Vec<3> Normalize() const
		{
			return (*this) / Norm();
		}
	
	public:
		float x = 0, y = 0, z = 0;
	};

	template<> class Vec<4>
	{
	public:
		const float& operator[] (int index) const
		{
			assert(index >=0 && index < 4);
			switch(index)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
			default:
				return w;
			}
		}

		float& operator[] (int index)
		{
			assert(index >=0 && index < 4);
			switch(index)
			{
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
			default:
				return w;
			}
		}

		float Norm() const
		{
			return sqrtf(SqrNorm());
		}

		float SqrNorm() const
		{
			return (*this) * (*this);
		}

		Vec<4> Normalize() const
		{
			return (*this) / Norm();
		}
	
	public:
		float x = 0, y = 0, z = 0, w = 0;
	};

	typedef Vec<2> Vec2;
	typedef Vec<3> Vec3;
	typedef Vec<4> Vec4;
	
	float Cross(const Vec2& vec1, const Vec2& vec2);
	Vec3 Cross(const Vec3& vec1, const Vec3& vec2);
}