#include <iostream>

int main() {
	int op;
	std::cout << "Caesar cipher solver\n";
	std::cout << "Available options:\n";
	std::cout << "1 - Encrypt input using given key\n";
	std::cout << "2 - Decrypt input using given key\n";
	std::cout << "3 - Check if input encrypted correctly\n";
	std::cout << "Your choice: ";
	std::cin >> op;
	while(std::cin.fail() || op > 3 || op < 1) {
		std::cerr << "Incorrect option!" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Your choice: ";
		std::cin >> op;
	}
	switch(op) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
	}
}