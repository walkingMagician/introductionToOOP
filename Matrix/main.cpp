﻿#include<iostream>
#include<math.h>
using namespace std;

class Matrix
{
private:
	double** matrix;
	int m, n; // m - строка n - столбец
public:

	//get/set
	int get_m()const { return m; }
	int get_n()const { return n; }
	double* get_column(int index) 
	{
		if (index >= 0 && index < n) return matrix[index]; 
		return 0; 
	}
	
	void set_m(int m) { this->m = m; }
	void set_n(int n) { this->n = n; }

	// constructor
	Matrix() : matrix(0), m(0), n(0)
	{
		cout << "default constructor:\t\t" << this << endl;
	}

	// матрица вида n на x, E определяет будет матрица нулевая или еденичная матрица
	// https://ru.wikipedia.org/wiki/%D0%93%D0%BB%D0%B0%D0%B2%D0%BD%D0%B0%D1%8F_%D0%B4%D0%B8%D0%B0%D0%B3%D0%BE%D0%BD%D0%B0%D0%BB%D1%8C главная диагональ(еденичная матрица)
	// https://ru.wikipedia.org/wiki/%D0%9D%D1%83%D0%BB%D0%B5%D0%B2%D0%B0%D1%8F_%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0 нулевая матрица
	/*Matrix(int M, int N, bool E = 0) : m(N), n(M)
	{	
		matrix = new int* [m];
		for (int i = 0; i < m; ++i)
		{
			matrix[i] = new int[n] {};
			for (int j = 0; j < n; j++) matrix[i][j] = (i == j) * E;
		}
		cout << "two arguments constructor:\t\t" << this << endl;
	}*/

	Matrix(int M, int N) : m(M), n(N)
	{
		matrix = new double* [m];
		for (int i = 0; i < m; ++i)
		{
			matrix[i] = new double[n];
			for (int j = 0; j < n; ++j) matrix[i][j] = rand() % 10;
		}
		cout << "array arguments constructor:\t\t" << this << endl;
	}

	Matrix(const Matrix& other) : m(other.m), n(other.n)
	{
		matrix = new double* [m];
		for (int i = 0; i < m; ++i)
		{
			matrix[i] = new double[n];
			for (int j = 0; j < n; ++j) matrix[i][j] = other.matrix[i][j];
		}
		cout << "copy constructor:\t\t" << this << endl;
	}

	~Matrix() // destructor
	{
		for (int i = 0; i < m; ++i) delete[] matrix[i];
		delete[] matrix;
	}

	// operators
	double* operator[] (int index) { return get_column(index); }

	Matrix& operator=(const Matrix& other)
	{
		matrix = new double* [m];
		for (int i = 0; i < m; ++i)
		{
			matrix[i] = new double[n];
			for (int j = 0; j < n; ++j) matrix[i][j] = other.matrix[i][j];
		}
		cout << "copy assegment:\t\t" << this << endl;
		return *this;
	}

	// methods
	std::ostream& print(std::ostream& os = std::cout) const
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) os << matrix[i][j] <<"\t";
			os << endl;
		}
		os << "destructor:\t\t" << this << endl;
		return os;
	}

	

};

// operators
std::ostream& operator<<(std::ostream& os, Matrix& obj)
{
	return obj.print(os);
}

Matrix operator+ (Matrix& left, Matrix& right)
{
	if (left.get_m() != right.get_m() && left.get_n() != left.get_n())
		return Matrix();
	Matrix result = Matrix(left.get_m(), right.get_n());
	for (int i = 0; i < left.get_m(); ++i)
		for (int j = 0; j < left.get_n(); ++j)
			result[i][j] = left[i][j] + right[i][j];
	return result;
}

Matrix operator- (Matrix& left, Matrix& right)
{
	if (left.get_m() != right.get_m() && left.get_n() != left.get_n())
		return Matrix();
	Matrix result = Matrix(left.get_m(), right.get_n());
	for (int i = 0; i < left.get_m(); ++i)
		for (int j = 0; j < left.get_n(); ++j)
			result[i][j] = left[i][j] - right[i][j];
	return result;
}

Matrix operator* (Matrix& left, Matrix& right)
{
	if (left.get_m() != right.get_n())
		return Matrix();

	Matrix result = Matrix(left.get_m(), right.get_n());
	for (int i = 0; i < left.get_m(); i++)
		for (int j = 0; j < right.get_n(); j++)
			for (int k = 0; k < left.get_n(); k++)
				result[i][j] += left[i][k] * right[k][j];
	return result;
}


int main()
{
	Matrix A(2, 2);
	A.print();
	Matrix B = A;
	cout << B;
	Matrix C = A * B;
	C.print();



}