#pragma once

#include "../Constants/Zero.hpp"
#include "../Constants/One.hpp"

template<typename T,unsigned int m_cols,unsigned int m_rows>
class StaticMatrix;

template<typename T,unsigned int m_rows,unsigned int m_cols>
class Zero<StaticMatrix<T,m_rows,m_cols> >
{
  public:
    static StaticMatrix<T,m_rows,m_cols> get()
	{
	    return StaticMatrix<T,m_rows,m_cols>(Zero<T>::get());
	}
};

template<typename T,unsigned int dim>
class One<StaticMatrix<T,dim,dim> >
{
  public:
    static StaticMatrix<T,dim,dim> get()
	{
	    StaticMatrix<T,dim,dim> result(Zero<T>::get());
	    T one = One<T>::get();
	    for (auto i = 0U; i < dim; i++)
	    {
		result[i][i] = one;
	    }
	    return result;
	}
};
