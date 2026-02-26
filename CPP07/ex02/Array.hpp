#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	private:
		T*				arr;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array();

		unsigned int	size() const;

		T&	operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;
};

template <typename T>
Array<T>::Array() : arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	_size = other.size();
	arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] arr;
		_size = other.size();
		arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (arr[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return (arr[index]);
}

#endif
