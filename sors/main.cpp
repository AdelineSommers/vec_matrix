
#include <iostream>
#include <iomanip>
#include <stdexcept>
template <typename T>
class vector
{
protected:
	T* data;

	int size;
public:
	vector()
	{
		data = nullptr;

		size = 0;
	}
	vector(int n)
	{
		data = (T*) new T[n];
		for (int i = 0; i < n; i++)
			data[i] = i;
		size = n;

		std::cout << "New vector has been created \n";
	}
	vector(const vector& copy)
	{
		size = copy.size;
		data = (T*) new T[copy.size];
		for (int i = 0; i < copy.size; i++)
			data[i] = copy.data[i];
		std::cout << "Copy of vector has been created \n";
	}


	vector& operator = (const vector& vec)
	{
		size = vec.size;
		if (data != nullptr)
			delete[] data;
		data = (T*) new T[vec.size];

		for (int i = 0; i < vec.size; i++)
			data[i] = vec.data[i];
		std::cout << "Operator '=' has been used \n";
		return *this;
	}

	vector operator + (const vector& vec)
	{
		vector tmp;
		if (this->size != vec.size)
			throw "Incompatible dimensions";
		tmp.size = this->size;
		tmp.data = (T*) new T[this->size];
		for (int i = 0; i < tmp.size; i++)
			tmp.data[i] = this->data[i] + vec.data[i];
		std::cout << "Operator '+' has been used \n";
		return tmp;
	}

	vector operator * (const vector& vec)
	{
		vector tmp;
		if (this->size != vec.size)
			throw "Incompatible dimensions";
		tmp.size = this->size;
		tmp.data = (T*) new T[this->size];
		for (int i = 0; i < tmp.size; i++)
			tmp.data[i] = this->data[i] * vec.data[i];
		std::cout << "Operator '*' has been used \n";
		return tmp;
	}

	vector operator * (int num)
	{
		vector tmp;
		tmp.size = this->size;
		tmp.data = (T*) new T[this->size];
		for (int i = 0; i < tmp.size; i++)
			tmp.data[i] = this->data[i] * num;
		std::cout << "Operator '*' has been used \n";
		return tmp;
	}

	friend std::ostream& operator<< (std::ostream& out, const vector& vec);

	~vector()
	{
		delete[] data;
	}


};
std::ostream& operator<< (std::ostream& out, const vector <int>& vec)
{

	for (int j = 0; j < vec.size; j++)
		out << std::setw(4) << vec.data[j];
	out << "\n";
	return out;
}

template <typename T>
class matrix
{
protected:
	T** data;
	int  row;
	int  col;

public:
	matrix()
	{
		data = nullptr;

		col = 0;
		row = 0;
	}
	matrix(int n, int m)
	{
		data = (T**) new T * [n];
		for (int i = 0; i < n; i++)
			data[i] = (T*) new T[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				data[i][j] = i + j;
		row = n;
		col = m;
		std::cout << "New matrix has been created \n";
	}
	matrix(const matrix& copy)
	{
		row = copy.row;
		col = copy.col;
		data = (T**) new T * [copy.row];
		for (int i = 0; i < copy.row; i++)
			data[i] = (T*) new T[copy.col];
		for (int i = 0; i < copy.row; i++)
			for (int j = 0; j < copy.col; j++)
				data[i][j] = copy.data[i][j];
		std::cout << "Copy of matrix has been created \n";
	}


	matrix& operator = (const matrix& mat)
	{
		row = mat.row;
		col = mat.col;
		if (data != nullptr)
			delete[] data;
		data = (T**) new T * [mat.row];
		for (int i = 0; i < mat.row; i++)
			data[i] = (T*) new T[mat.col];
		for (int i = 0; i < mat.row; i++)
			for (int j = 0; j < mat.col; j++)
				data[i][j] = mat.data[i][j];
		std::cout << "Operator '=' has been used \n";
		return *this;
	}


	matrix operator + (const matrix& mat)
	{
		matrix <T> tmp;
		if (this->col != mat.col && this->row != mat.row)
			throw "Incompatible dimensions";
		tmp.row = this->row;
		tmp.col = this->col;
		tmp.data = (T**) new T * [this->row];
		for (int i = 0; i < tmp.row; i++)
			tmp.data[i] = (T*) new T[tmp.col];//�������� �������

		for (int i = 0; i < tmp.row; i++)
			for (int j = 0; j < tmp.col; j++)
			{
				tmp.data[i][j] = this->data[i][j] + mat.data[i][j];
			}
		std::cout << "Operator '+' has been used \n";
		return tmp;
	}

	matrix operator * (const matrix& mat)
	{
		matrix tmp;
		if (this->col != mat.row)
			throw "Incompatible dimensions";
		tmp.row = this->row;
		tmp.col = mat.col;
		tmp.data = (T**) new T * [this->row];
		for (int i = 0; i < tmp.row; i++)
			tmp.data[i] = (T*) new T[tmp.col];//�������� �������

		for (int i = 0; i < tmp.row; i++)
			for (int j = 0; j < tmp.col; j++)
			{
				tmp.data[i][j] = 0;
				for (int k = 0; k < tmp.col; k++)
				{
					tmp.data[i][j] += this->data[i][k] * mat.data[k][j];
				}

			}
		std::cout << "Operator '*' has been used \n";
		return tmp;
	}

	matrix operator * (int num)
	{
		matrix <T> tmp;
		tmp.row = this->row;
		tmp.col = this->col;
		tmp.data = (T**) new T * [this->row];
		for (int i = 0; i < tmp.row; i++)
			tmp.data[i] = (T*) new T[this->col];
		for (int i = 0; i < tmp.row; i++)
			for (int j = 0; j < tmp.col; j++)
				tmp.data[i][j] = this->data[i][j] * num;
		std::cout << "Operator '*' has been used \n";
		return tmp;
	}
	friend std::ostream& operator<< (std::ostream& out, const matrix& mat);

	~matrix()
	{
		for (int i = 0; i < row; i++)
			delete[] data[i];
		delete[] data;
	}


};
std::ostream& operator<< (std::ostream& out, const matrix <int>& mat)
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
			out << std::setw(4) << mat.data[i][j];
		out << "\n";
	}
	return out;
}


typedef matrix <int> IntMat;
typedef vector <int> IntVec;


int main()
{
	vector <int> a(5);
	std::cout << a;
	a = a * 4;

	std::cout << a;
	vector <int> b(8);
	std::cout << b;
	try
	{
		b = a * b;
	}
	catch (...)
	{
		std::cout << "Fail! Incompatible dimensions \n";
	}
	a = b;
	try
	{
		a = a + b;
	}
	catch (...)
	{
		std::cout << "Fail! Incompatible dimensions \n";
	}
	std::cout << a;


	matrix <int> c(4, 7);
	c = c * 2;
	std::cout << c;
	matrix <int> d(7, 3);

	try
	{
		c = c * d;
	}
	catch (...)
	{
		std::cout << "Fail! Incompatible dimensions \n";
	}
	std::cout << c;
	c = d;
	try
	{
		c = c + d;
	}
	catch (...)
	{
		std::cout << "Fail! Incompatible dimensions \n";
	}
	std::cout << c;
	return 0;
}
