#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>

template<typename T>
class Matrix {

	public:

		Vector( void );
		Vector( Vector const & src );
		~Vector( void );

		Vector &	operator=( Vector const & rhs );


	private:

		std::vector<std::vector<T>>	_matrix;
		int[2]						_size;

};

#endif