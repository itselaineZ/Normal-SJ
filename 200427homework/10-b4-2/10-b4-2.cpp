/*1952339 –≈08 ’≈‹∞‘¬*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

template<class T, int row, int col>
class matrix {
private:
	T* value;
public:
	matrix();
	matrix(const matrix<T, row, col>& x);
	~matrix();
	matrix<T, row, col> operator = (const matrix<T, row, col>& x);
	friend const matrix<T, row, col> operator + (const matrix<T, row, col>& x, const matrix<T, row, col>& y) {
		matrix<T, row, col> rt;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				rt.value[i * col + j] = y.value[i * col + j] + x.value[i * col + j];
		return rt;
	}
	friend istream& operator >> (istream& in, matrix<T, row, col>& x)
	{
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				in >> x.value[i * col + j];
		return in;
	}
	friend ostream& operator << (ostream& out, const matrix<T, row, col>& x)
	{
		for (int i = 0; i < row; ++i) {
			out << x.value[i * col];
			for (int j = 1; j < col; ++j)
				out << ' ' << x.value[i * col + j];
			out << endl;
		}
		return out;
	}
};

template<class T, int row, int col>
matrix<T, row, col> ::matrix()
{
	value = new(nothrow) T[row * col];
	memset(value, 0, sizeof(row * col * sizeof(T)));
}

template<class T, int row, int col>
matrix<T, row, col> ::matrix(const matrix<T, row, col>& x)
{
	value = new(nothrow) T[row * col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			value[i * col + j] = x.value[i * col + j];
}

template<class T, int row, int col>
matrix<T, row, col>::~matrix()
{
	delete[] value;
}

template<class T, int row, int col>
matrix<T, row, col> matrix<T, row, col>::operator = (const matrix<T, row, col>& x)
{
	value = new(nothrow) T[row * col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			value[i * col + j] = x.value[i * col + j];
	return *this;
}
