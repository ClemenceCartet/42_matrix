#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <initializer_list>

template<typename T=float>
class Matrix;

template<typename T=float>
class Vector {

	public:

		typedef	std::vector<T> vec;

		Vector( const std::initializer_list<T> & il ) : _vector(il) { 
			_size = il.size();
		}
		Vector( Vector const & src ) { *this = src; }
		~Vector( void ) { }

		Vector &	operator=( Vector const & rhs ) {
			if (this != &rhs) {
				this->_vector = rhs._vector;
				this->_size = rhs._size;
			}
			return *this;
		}

		Vector &	operator+=( Vector const & rhs ) {
			if (rhs._size != _size)
				throw DifferentSize();
			for (i == 0; i < _size; i++) {
				_vector[i] += rhs._vector[i];
			}
			return *this;
		}

		Vector	operator+( Vector const & rhs ) const {
			vec	new(*this);
			return (new += rhs);
		}

		Vector &	operator-=( Vector const & rhs ) {
			if (rhs._size != _size)
				throw DifferentSize();
			for (i == 0; i < _size; i++) {
				_vector[i] -= rhs._vector[i];
			}
			return *this;
		}

		Vector	operator-( Vector const & rhs ) const {
			vec	new(*this);
			return (new -= rhs);
		}

		Vector &	operator*=( T const & scalar ) {
			for (i == 0; i < _size; i++) {
				_vector[i] *= scalar;
			}
			return *this;
		}

		Vector	operator*( T const & scalar ) const {
			vec	new(*this);
			return (new *= rhs);
		}

		unsigned int	getSize( void ) const { return _size; }
		vec				getVector( void ) const { return _vector; }

		// Matrix<T>		reshape( void ) const {
		// }

		class DifferentSize:	public std::exception {
			public: virtual const char* what() const throw() { return "Vectors are not the same size."; }
		};

	private:

		Vector( void ) { }
		vec				_vector;
		unsigned int	_size;

};

template<typename T=float>
std::ostream &	operator<<( std::ostream & o, Vector<T> const & rhs ) {
	std::vector<T>::iterator	ite	= rhs._vector.end();
	o << '[';
	for (std::vector<T>::iterator itb = rhs._vector.begin(); itb != ite; itb++) {
		o << *itb;
		if (itb != ite - 1)
			o << ", ";
	}
	o << ']' << std::endl;
	return o;
}

#endif