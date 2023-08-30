#ifndef MATRIX_HPP
# define MATRIX_HPP

#include <iostream>
#include <vector>
#include <initializer_list>
#include <exception>
#include "Vector.hpp"

template<typename T>
class Vector;

template<typename T=float>
class Matrix {

	public:

		typedef std::vector<T>	row;
		typedef	std::vector<row>	vvec;
		typedef std::initializer_list<std::initializer_list<T>>	initlist;

		Matrix( const initlist & il ) { 
			typename initlist::iterator ite = il.end();
			unsigned int	len = 0;

			for (typename initlist::iterator itb = il.begin(); itb != ite; ++itb)
			{
				if (itb == il.begin())
					len = itb->size();
				else if (itb->size() != len)
					throw InvalidMatrix();
				_matrix.emplace_back(*itb);
			}
			_rows = il.size();
			_cols = len;
			if (isSquare() == false)
				throw InvalidMatrix();
		}
		Matrix( Matrix const & src ) { *this = src; }
		~Matrix( void ) { }

		Matrix &	operator=( Matrix const & rhs ) {
			if (this != &rhs) {
				this->_matrix = rhs._matrix;
				this->_rows = rhs._rows;
				this->_cols = rhs._cols;
			}
			return *this;
		}

		Matrix &	operator+=( Matrix const & rhs ) {
			if (_cols != rhs._rows)
				throw OperationImpossible();
			for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _cols; j++)
					_matrix[i][j] += rhs._matrix[i][j];
			}
			return *this;
		}

		Matrix	operator+( Matrix const & rhs ) const {
			if (_cols != rhs._rows)
				throw OperationImpossible();
			Matrix	neww(*this);
			return (neww += rhs);
		}

		Matrix &	operator-=( Matrix const & rhs ) {
			if (_cols != rhs._rows)
				throw OperationImpossible();
			for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _cols; j++)
					_matrix[i][j] -= rhs._matrix[i][j];
			}
			return *this;
		}

		Matrix	operator-( Matrix const & rhs ) const {
			if (_cols != rhs._rows)
				throw OperationImpossible();
			Matrix	neww(*this);
			return (neww -= rhs);
		}

		Matrix &	operator*=( T const & scalar ) {
			for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _cols; j++)
					_matrix[i][j] *= scalar;
			}
			return *this;
		}

		Matrix	operator*( T const & scalar ) const {
			Matrix	neww(*this);
			return (neww *= scalar);
		}

		bool			isSquare( void ) { return (_rows == _cols); }
		unsigned int	getRaws( void ) const { return _rows; }
		unsigned int	getCols( void ) const { return _cols; }
		const vvec &	getMatrix( void ) const { return _matrix; }
		vvec &			getMatrix( void ) { return _matrix; }

		// Vector<T>		reshape( void ) const {
		// }

		class InvalidMatrix:	public std::exception {
			public: virtual const char* what() const throw() { return "Matrix is invalid."; }
		};

		class OperationImpossible:	public std::exception {
			public: virtual const char* what() const throw() { return "Impossible operation between this two matrices."; }
		};

	private:

		Matrix( void ) { }
		vvec			_matrix;
		unsigned int	_rows;
		unsigned int	_cols;

};

template<typename T>
std::ostream &	operator<<( std::ostream & o, Matrix<T> const & rhs ) {
	typename Matrix<T>::vvec::const_iterator	ite	= rhs.getMatrix().end();
	for (typename Matrix<T>::vvec::const_iterator itb = rhs.getMatrix().begin(); itb != ite; itb++) {
		o << '[';
		for (typename Matrix<T>::row::const_iterator vecb = itb->begin(); vecb != itb->end(); vecb++) {
			o << *vecb;
			if (vecb != itb->end() - 1)
				o << ", ";
		}
		o << ']' << std::endl;
	}
	return o;
}

template <typename T, typename U=float>
Matrix<T> operator*(const U& scalar, const Matrix<T>& matrix) {
    return (matrix * scalar);
}

#endif