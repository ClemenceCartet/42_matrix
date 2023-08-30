#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <vector>
#include <initializer_list>
#include <exception>
#include <stdexcept>
#include <cmath>
#include "Matrix.hpp"

template<typename T>
class Matrix;

template<typename T=float>
class Vector {

	public:

		typedef	std::vector<T> vec;

		Vector( unsigned int size ) : _size(size) { 
			_vector = vec(size, T());
		}
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
			for (int i = 0; i < _size; i++) {
				_vector[i] += rhs._vector[i];
			}
			return *this;
		}

		Vector	operator+( Vector const & rhs ) const {
			Vector	neww(*this);
			return (neww += rhs);
		}

		Vector &	operator-=( Vector const & rhs ) {
			if (rhs._size != _size)
				throw DifferentSize();
			for (int i = 0; i < _size; i++) {
				_vector[i] -= rhs._vector[i];
			}
			return *this;
		}

		Vector	operator-( Vector const & rhs ) const {
			Vector	neww(*this);
			return (neww -= rhs);
		}

		Vector &	operator*=( T const & scalar ) {
			for (int i = 0; i < _size; i++) {
				_vector[i] *= scalar;
			}
			return *this;
		}

		Vector	operator*( T const & scalar ) const {
			Vector	neww(*this);
			return (neww *= scalar);
		}

		T	dot( Vector const & rhs ) const {
			if (rhs._size != _size)
				throw DifferentSize();
			T	product = T();
			for (int i = 0; i < _size; i++) {
				product += (_vector[i] * rhs._vector[i]);
			}	
			return product;
		}

		float	normL1( void ) const { //sum of magnitudes
			float res = 0.0;
			for (int i = 0; i < _size; i++) {
				res += abs(_vector[i]);
			}
			return res;	
		}

		float	normL2( void ) const { // euclidean norm
			float res = 0.0;
			for (int i = 0; i < _size; i++) {
				res += pow(_vector[i], 2.0);
			}
			return sqrt(res);
		}

		float	normInf( void ) const { // absolute value of the largest component of the vector
			float res = 0.0;
			for (int i = 0; i < _size; i++) {
				res = max(abs(_vector[i]), res);
			}
			return res;
		}	

		unsigned int	getSize( void ) const { return _size; }
		const vec &		getVector( void ) const { return _vector; }
		vec &			getVector( void ) { return _vector; }

		// Matrix<T>		reshape( void ) const {
		// }

		class DifferentSize:	public std::exception {
			public: virtual const char* what() const throw() { return "Impossible operation! Vectors are not the same size."; }
		};

	private:

		Vector( void ) { }
		vec				_vector;
		unsigned int	_size;

};

template<typename T>
std::ostream &	operator<<( std::ostream & o, Vector<T> const & rhs ) {
	typename std::vector<T>::const_iterator	ite	= rhs.getVector().end();
	o << '[';
	for (typename std::vector<T>::const_iterator itb = rhs.getVector().begin(); itb != ite; itb++) {
		o << *itb;
		if (itb != ite - 1)
			o << ", ";
	}
	o << ']' << std::endl;
	return o;
}

template <typename T, typename U=float>
Vector<T> operator*(const U& scalar, const Vector<T>& vector) {
    return (vector * scalar);
}

template<typename T=float>
Vector<T>	linear_combination( const std::initializer_list<Vector<T>> &u, const std::initializer_list<T> &coefs ) {
	if (u.size() != coefs.size() || u.empty())
		throw std::invalid_argument( "Invalid arguments: different inputs' size." );

	typename std::initializer_list<Vector<T>>::const_iterator	itb = u.begin();
	unsigned int	len = itb->getSize();
	Vector<T> neww(len);
	typename std::initializer_list<T>::const_iterator coee = coefs.end();
	for (typename std::initializer_list<T>::const_iterator coeb = coefs.begin(); coeb != coee; coeb++) {
		if (itb->getSize() != len)
		 	throw std::invalid_argument( "Invalid arguments: vectors are not the same size." );
		neww += *itb * *coeb;
		itb++;
	}
	return neww;
}

template<typename T>
T	lerp( const T &u, const T &v, const float &t) {
	if (t > 1 || t < 0)
		throw std::invalid_argument( "Invalid arguments: scalar is invalid." );
	return (u + ((v - u) * t));
}


#endif