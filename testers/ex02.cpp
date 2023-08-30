#include "../Vector.hpp"
#include "../Matrix.hpp"

int	main( void ) {

	try {
		Vector<> neww = lerp(Vector<>({2, 1}), Vector<>({4, 2, 2}), 0.3f);
		std::cout << "neww: " << neww;
	}
    catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << lerp(0.f, 1.f, 0.) << std::endl;
	std::cout << lerp(0.f, 1.f, 1.f) << std::endl;
	std::cout << lerp(0.f, 1.f, 0.5f) << std::endl;
	std::cout << lerp(21.f, 42.f, 0.3f) << std::endl;

	Matrix<> m = lerp(Matrix<>({{2, 1}, {3, 4}}), Matrix<>({{20, 10}, {30, 40}}), 0.5f);
	std::cout << "m: " << m;

	return 0;
}