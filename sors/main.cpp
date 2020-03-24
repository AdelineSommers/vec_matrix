#include <iostream>
#include <iomanip>

class vector
{
protected:
	int* data;

	int size;
public:
	vector()
	{
		data = nullptr;

		int size = 0;
	}
	vector(int n)
	{
		data = new int[n];
		for (int i = 0; i < n; i++)
			data[i] = i;
		size = n;

		std::cout << "New vector has been created \n";
	}
	vector(const vector& copy)
	{
		size = copy.size;
		data = new int[copy.size];
		for (int i = 0; i < copy.size; i++)
			data[i] = copy.data[i];
		std::cout << "Copy of vector has been created \n";
	}


	vector& operator = (const vector& vec)
	{
		size = vec.size;
		if (data != nullptr)
			delete[] data;
		data = new int[vec.size];

		for (int i = 0; i < vec.size; i++)
			data[i] = vec.data[i];
		std::cout << "Operator '=' has been used \n";
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& out, const vector& vec);

	~vector()
	{
		delete[] data;
	}


};
std::ostream& operator<< (std::ostream& out, const vector& vec)
{

	for (int j = 0; j < vec.size; j++)
		out << std::setw(4) << vec.data[j];
	out << "\n";
	return out;
}


class matrix
{
protected:
	int** data;
	int row;
	int col;

public:
	matrix()
	{
		data = nullptr;

		int col = 0;
		int row = 0;
	}
	matrix(int n, int m)
	{
		data = new int* [n];
		for (int i = 0; i < n; i++)
			data[i] = new int[m];
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
		data = new int* [copy.row];
		for (int i = 0; i < copy.row; i++)
			data[i] = new int[copy.col];
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
		data = new int* [mat.row];
		for (int i = 0; i < mat.row; i++)
			data[i] = new int[mat.col];
		for (int i = 0; i < mat.row; i++)
			for (int j = 0; j < mat.col; j++)
				data[i][j] = mat.data[i][j];
		std::cout << "Operator '=' has been used \n";
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& out, const matrix& mat);

	~matrix()
	{
		for (int i = 0; i < row; i++)
			delete[] data[i];
		delete[] data;
	}


};
std::ostream& operator<< (std::ostream& out, const matrix& mat)
{
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
			out << std::setw(4) << mat.data[i][j];
		out << "\n";
	}
	return out;
}


int main()
{
	vector a(5);
	vector b(8);
	a = b;
	std::cout << a;
	matrix c(4, 7);
	matrix d(7, 3);
	c = d;
	std::cout << c;
	return 0;
}

