#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <exception>
#include <memory>
#include <iterator>
#include <type_traits>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>

template <typename T>
class Vector
{
public:

	////constructors
	//default
	Vector()
		: length(0),
		data(nullptr)
	{ }
	//length
	Vector(int length)
		: length(length),
		data(new T[length])
	{ }
	//copy
	Vector(const Vector<T>& other)
		: Vector(other.length)
	{
		for (auto i = 0; i < other.length; ++i)
			data[i] = other.data[i];
	}
	//initializer list
	Vector(std::initializer_list<T> list)
		: Vector((int)list.size())
	{
		std::uninitialized_copy(list.begin(), list.end(), data);
	}

	////destructor
	~Vector()
	{
		delete[] data;
		length = 0;
	}

	////operators
	//copy
	Vector<T>& operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			delete[] data;
			length = other.length;
			data = new T[other.length];
			for (auto i = 0; i < other.length; ++i)
				data[i] = other.data[i];
		}
		return *this;
	}
	//move
	Vector<T>& operator=(Vector<T>&& other)
	{
		if (this != &other)
		{
			delete[] data;
			length = other.length;
			data = other.data;
			other.length = 0;
			other.data = nullptr;
		}
		return *this;
	}
	//point-wise addition
	template<typename U>
	Vector<typename std::common_type<T, U>::type> operator+(const Vector<U>& other) const
	{
		if (length != other.length) throw "Vectors have different size!";
		Vector<typename std::common_type<T, U>::type> result(length);
		for (auto i = 0; i < this->length; ++i)
			result.data[i] = data[i] + other.data[i];
		return result;
	}
	//point-wise subtraction
	template<typename U>
	Vector<typename std::common_type<T, U>::type> operator-(const Vector<U>& other) const
	{
		if (length != other.length) throw "Vectors have different size!";
		Vector<typename std::common_type<T, U>::type> result(length);
		for (auto i = 0; i < this->length; ++i)
			result.data[i] = data[i] - other.data[i];
		return result;
	}
	//right multiplication with a scalar
	template<typename U>
	Vector<typename std::common_type<T, U>::type> operator*(U scalar) const
	{
		Vector<typename std::common_type<T, U>::type> result(length);
		for (auto i = 0; i < length; ++i)
			result.data[i] = scalar * data[i];
		return result;
	}

	std::string getVector() const {
		std::ostringstream output;
		for (auto i = 0; i < length; ++i)
		{
			output << i << " " << this->data[i] << "\n";
		}
		std::string s = output.str();
		return s;
	}

	T maxValue() const {
		T maxValue = 0.0;
		for (int i = 0; i < length; ++i) {
			if (this->data[i] > maxValue)
				maxValue = this->data[i];
		}
		return maxValue;
	}

	T norm() const {
		T norm = 0.0;
		for (int i = 0; i < length; ++i)
			norm += this->data[i] * this->data[i];
		norm = sqrt(norm) / ((T) length);
		return norm;
	}

//private:

	//attributes:
	int length;
	T* data;
};

//left multiplication with a scalar (as a non-member operator)
template<typename T, typename U>
Vector<typename std::common_type<T, U>::type> operator*(U scalar, const Vector<T>& vec)
{
	return vec * scalar;
}

template<typename T>
T dot(const Vector<T>& lhs, const Vector<T>& rhs)
{
	if (lhs.length != rhs.length) throw "Vectors have different size!";
	T result = 0;
	for (auto i = 0; i < lhs.length; ++i)
		result += lhs.data[i] * rhs.data[i];
	return result;
}

#endif // VECTOR_HPP