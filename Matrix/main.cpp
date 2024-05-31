#include<iostream>
#include<math.h>
using namespace std;

class Matrix
{
private:
	int** matrix;
	int m, n; // m - строка n - столбец
public:

	// constructor

	Matrix() : matrix(0), m(0), n(0)
	{
		cout << "default constructor:\t\t" << this << endl;
	}
	
	// матрица вида n на x, E определяет будет матрица нулевая или еденичная матрица
	// https://ru.wikipedia.org/wiki/%D0%93%D0%BB%D0%B0%D0%B2%D0%BD%D0%B0%D1%8F_%D0%B4%D0%B8%D0%B0%D0%B3%D0%BE%D0%BD%D0%B0%D0%BB%D1%8C главная диагональ(еденичная матрица)
	// https://ru.wikipedia.org/wiki/%D0%9D%D1%83%D0%BB%D0%B5%D0%B2%D0%B0%D1%8F_%D0%BC%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0 нулевая матрица

	Matrix(int M, int N, bool E = 0) : m(N), n(M)
	{	
		matrix = new int* [m];
		for (int i = 0; i < m; ++i)
		{
			matrix[i] = new int[n] {};
			for (int j = 0; j < n; j++) matrix[i][j] = (i == j) * E;
		}
		cout << "two arguments constructor:\t\t" << this << endl;
	}

	// 
	Matrix(int array[], int M, int N) : m(M), n(N)
	{
		matrix = new int* [m];
		for (int i = 0; i < m; ++i)
		{
			matrix[i] = new int[n];
			for (int j = 0; j < n; ++j) matrix[i][j] = array[i];
		}
		cout << "array arguments constructor:\t\t" << this << endl;
	}

	Matrix(const Matrix& other) : m(other.m), n(other.n)
	{
		matrix = new int* [m];
		cout << "copy constructor:\t\t" << this << endl;
	}

	~Matrix() // destructor
	{
		for (int i = 0; i < m; ++i) delete[] matrix[i];
		delete[] matrix;
	}

	void print()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) cout << matrix[i][j] <<"\t";
			cout << endl;
		}
		cout << "destructor:\t\t" << this << endl;
	}
};

void main()
{
	int arr[] = {4, 5, 6, 7, 8};
	Matrix A(arr, 4, 4);
	A.print();

	Matrix B = A;
	B.print();
}