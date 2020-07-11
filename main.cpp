#include <iostream>
#include "Caesar.hh"

int main() {
	int op = -1;
	do {
		std::cout << "Caesar cipher solver\n";
		std::cout << "Available options:\n";
		std::cout << "1 - Encrypt input using given key\n";
		std::cout << "2 - Decrypt input using given key\n";
		std::cout << "3 - Check if input encrypted correctly\n";
		std::cout << "0 - Exit\n";
		std::cout << "Your choice: ";
		std::cin >> op;
		while(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			op = -1;
		}
		switch(op) {
			case 1:
			{
				std::string input;
				int key;
				std::cout << "Text to encrypt: ";
				std::cin >> input;
				while(std::cin.fail()) {
					std::cerr << "Incorrect input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Text to encrypt: ";
					std::cin >> input;
				}
				std::cout << "Encryption key: ";
				std::cin >> key;
				while(std::cin.fail()) {
					std::cerr << "Incorrect encryption key!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Encryption key: ";
					std::cin >> key;
				}
				std::cout << "Encrypted text: " << encrypt(input, key);
				break;
			}
			case 2:
			{
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
			case 3: {
				std::string plaintext;
				std::string ciphertext;
				std::cout << "Plaintext: ";
				std::cin >> plaintext;
				while(std::cin.fail()) {
					std::cerr << "Invalid input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Plaintext: ";
					std::cin >> plaintext;
				}
				std::cout << "Ciphertext: ";
				std::cin >> ciphertext;
				while(std::cin.fail()) {
					std::cerr << "Invalid input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Ciphertext: ";
					std::cin >> ciphertext;
				}
				int k = check(plaintext, ciphertext);
				if(k == 27) std::cout << "Text is *NOT* correctly encrypted";
				else if(k < 0) std::cout << "Text is reversely encrypted with key " << k;
				else if(k == 0) std::cout << "Text is not encrypted, ciphertext is the same as plaintext";
				else if(k > 0 && k < 26) std::cout << "Text is correctly encrypted with key " << k;
				break;
			}
			default:
				std::cerr << "Invalid option!";
				op = -1;
				break;
		}
	} while(op != 0);
	return 0;
}