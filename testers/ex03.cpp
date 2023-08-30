#include "../Vector.hpp"
#include "../Matrix.hpp"

int	main( void ) {

	Vector<> u = {0, 0};
    Vector<> v = {1, 1};
    Vector<> u2 = {1, 1};
    Vector<> v2 = {1, 1.3};
    Vector<> u3 = {-1, 6};
    Vector<> v3 = {3, 2};

	std::cout << u.dot(v) << std::endl;
	std::cout << u2.dot(v2) << std::endl;
	std::cout << u3.dot(v3) << std::endl;

	return 0;
}