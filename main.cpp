#include <iostream>
#include "Caesar.hh"

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
		case 2:	{
			std::string input;
			int key;
			std::cout << "Text to decrypt: ";
			std::cin >> input;
			while(std::cin.fail()) {
				std::cerr << "Invalid input!" << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Text to decrypt: ";
				std::cin >> input;
			}
			std::cout << "Decryption key: ";
			std::cin >> key;
			while(std::cin.fail()) {
				std::cerr << "Invalid decryption key!" << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Decryption key: ";
				std::cin >> key;
			}
			std::cout << "Decrypted text: " << decrypt(input, key);
			break;
		}
		case 3:
			break;
		default:
			break;
	}
}