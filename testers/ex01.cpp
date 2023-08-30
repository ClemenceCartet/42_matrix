#include "../Vector.hpp"
#include "../Matrix.hpp"

int	main( void ) {

	Vector<> e1({1., 0., 0.});
    Vector<> e2({0., 1., 0.});
    Vector<> e3({0., 0., 1.});
	Vector<> v1({1., 2., 3.});
    Vector<> v2({0., 10., -100.});
	Vector<> v3({0., 10.});

	try {
        Vector<> blop = linear_combination({e1, e2, e3}, {10, -2, 0.5});
		std::cout << "blop: " << blop;
		Vector<> test = linear_combination({v1, v2}, {10, -2});
		std::cout << "test: " << test;
		//Vector<> hello = linear_combination({v1, v2}, {10, -2, 3});
		Vector<> hello = linear_combination({v1, v3}, {10, -2});
	}
    catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
	
	return 0;
}