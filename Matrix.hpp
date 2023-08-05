#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>

template<typename T = float>
class Matrix {

	public:

		typedef	std::vector<std::vector<T>> vvec;

		Matrix( Matrix const & src );
		~Matrix( void );

		Matrix &	operator=( Matrix const & rhs );


	private:

		vvec	_matrix;
		int		_rows;
		int		_cols;
		Matrix( void );

};

#endif