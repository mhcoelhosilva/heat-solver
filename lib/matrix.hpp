#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <array>
#include <map>
#include "vector.hpp"

template <typename T>
class Matrix
{
public:
	////constructors
	Matrix(int i, int j)
	{
		shape = { i, j };
	}

	////operators
	//assignment
	T& operator[](std::array<int, 2> pos) 
	{
		return values[pos];
	}

	//member functions
	std::string getMatrix() const {
		std::ostringstream output;
		for (const auto &it : this->values)
		{
			auto i = it.first[0];
			auto j = it.first[1];
			auto value = it.second;

			output << i << " " << j << " " << value << "\n";
		}
		std::string s = output.str();
		return s;
	}

	void matrixClear() {
		values.clear();
	}

//private:
	////attributes
	std::map<std::array<int, 2>, T> values;
	std::array<int, 2> shape;

};

template<typename T>
Vector<T> operator*(const Matrix<T>& lhs, const Vector<T>& rhs)
{
	if (std::get<1>(lhs.shape) != rhs.length) throw "Matrix must have as many columns as the vector has rows";
	Vector<T> result(std::get<0>(lhs.shape));
	for (int i = 0; i < result.length; ++i)
		result.data[i] = 0;
	int i, j;
	T value;
	for (auto it = lhs.values.cbegin(); it != lhs.values.cend(); ++it) 
	{
		i = it->first[0];
		j = it->first[1];
		value = it->second;
		
		result.data[j] += value * rhs.data[i];
	}
	return result;
}

#endif // MATRIX_HPP