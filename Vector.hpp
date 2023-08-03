#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>

template<typename T>
class Vector {

	public:

		Vector( void );
		Vector( Vector const & src );
		~Vector( void );

		Vector &	operator=( Vector const & rhs );


	private:

		std::vector<T>	_vector;
		int				_size;

};

#endif