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





int main()
{
	return 0;
}