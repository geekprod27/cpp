#ifndef ARRAY_HPP
# define ARRAY_HPP

template< typename T>
class Array
{

	public:

		Array() : _size(0), _array(new T[0]) {};
		Array(unsigned int n) : _size(n), _array(new T[n]) {};
		Array(Array& src)
		{
			this->_size = src._size;
			this->_array = new T[src._size];
			for (unsigned int i = 0; i < src._size; i++)
				this->_array[i] = src._array[i];
		}

		~Array()
		{
			delete [] this->_array;
		}

		Array& operator=(const Array& rhs)
		{
			if (this != rhs)
			{
				delete [] this->_array;
				this->_size = rhs._size;
				this->_array = new T[rhs._size];
				for (unsigned int i = 0; i < rhs._size; i++)
					this->_array[i] = rhs._array[i];
			}
		}

		T&	operator[](unsigned int n)
		{
			if (n >= this->_size)
				throw OutofRangeExeption();
			return (this->_array[n]);
		}
		class OutofRangeExeption : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return("Out of range");
				}
		};

	private:

		unsigned int _size;
		T*			_array;


};

#endif