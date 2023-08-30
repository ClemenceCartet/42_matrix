#include "../Vector.hpp"
#include "../Matrix.hpp"

int	main( void ) {
	/*
	Vector<int>	a{1, 2, 3};
	std::cout << "a: " << a;
	Vector<int>	b{1, 1, 1};
	std::cout << "b: " << b;
	Vector<int> c{0, 1};
	std::cout << "c: " << c;

	std::cout << "// Tests additions" << std::endl;
	try {
		a += b;
		std::cout << "a: " << a;
		a += c;
		std::cout << "a: " << a;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	c = a + b;
	std::cout << "c: " << c;

	std::cout << "// Tests construction par copie et opérateur =" << std::endl;
	Vector<int> d(c);
	c += b;
	std::cout << "d: " << d;
	std::cout << "c: " << c;
	
	//////

	Vector<>	e{1., 4.59, 7.8};
	std::cout << "e: " << e;
	Vector<>	f{0.8, 1., 2.1};
	std::cout << "f: " << f;
	//Vector<int>	b{1, 1, 1};

	std::cout << "// Test soustraction" << std::endl;
	e -= f;
	std::cout << "e: " << e;
	//e -= b;
	std::cout << "// Test scalar" << std::endl;
	e *= 2;
	std::cout << "e: " << e;
	e *= 0.8;
	std::cout << "e: " << e;
	e = 2.2 * e;
	std::cout << "e: " << e;
	*/
	//////

	Matrix<> u = {{1, 2}, {1, 2}};
	std::cout << "u: " << u;
	Matrix<> v = {{3, 2}, {3, 2}};
	std::cout << "v: " << v;

	u += v;
	std::cout << "u: " << u;
	u -= v;
	std::cout << "u: " << u;
	u *= 2.2;
	std::cout << "u: " << u;

	Matrix<> w = {{3, 2, 1}, {3, 2, 1}, {1, 1, 1}};
	std::cout << "w: " << w;

	try {
		u += w;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}