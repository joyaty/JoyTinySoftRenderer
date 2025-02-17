
#include "Vec.h"

#pragma once

namespace Joy
{
    template<int NRows, int NCols> class Mat
    {
    public:
        static Mat<NRows, NCols> Identity()
        {
            Mat<NRows, NCols> ret;
            for (int i = 0; i < NRows; ++i)
            {
                for (int j = 0; j < NCols; ++j)
                {
                    ret[i][j] = (i == j);
                }
            }
            return ret;
        }

    public:
        const Vec<NCols>& operator[] (int index) const
        {
            return m_Data[index];
        }

        Vec<NCols>& operator[] (int index)
        {
            return m_Data[index];
        }

        Vec<NRows>& GetCol(int index) const
        {
            Vec<NRows> ret{};
            for (int i = 0; i < NRows; ++i)
            {
                ret[i] = m_Data[i][index];
            }
            return ret;
        }

    private:
        Vec<NCols> m_Data[NRows] = { 0 };
    };
}