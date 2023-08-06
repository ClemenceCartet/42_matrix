#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include "Vector.hpp"

template<typename T=float>
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
			if (isSquare == false)
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

		bool			isSquare( void ) { return (_rows == _cols); }
		unsigned int	getRaws( void ) const { return _rows; }
		unsigned int	getCols( void ) const { return _cols; }
		vvec			getMatrix( void ) const { return _matrix; }

		// Vector<T>		reshape( void ) const {
		// }

		class InvalidMatrix:	public std::exception {
			public: virtual const char* what() const throw() { return "Matrix is invalid."; }
		};

	private:

		Matrix( void ) { }
		vvec			_matrix;
		unsigned int	_rows;
		unsigned int	_cols;

};

template<typename T=float>
std::ostream &	operator<<( std::ostream & o, Matrix<T> const & rhs ) {
	typename initlist::iterator	ite	= rhs._matrix.end();
	for (typename initlist::iterator itb = rhs._matrix.begin(); itb != ite; itb++) {
		o << '[';
		o << *itb;
		if (itb != ite - 1)
			o << ", ";
		o << ']' << std::endl;
	}
	return o;
}

#endif