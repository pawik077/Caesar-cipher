#include <iostream>
#include <fstream>
#include "Caesar.hh"

int main() {
	int op = -1;
	do {
		std::cout << "Caesar cipher solver\n";
		std::cout << "Available options:\n";
		std::cout << "1 - Encrypt input using given key\n";
		std::cout << "2 - Decrypt input using given key\n";
		std::cout << "3 - Check if input encrypted correctly\n";
		std::cout << "4 - Brute-force crack an encrypted text\n";
		std::cout << "0 - Exit\n";
		std::cout << "Your choice: ";
		std::cin >> op;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		while(std::cin.fail()) {
			op = -1;
		}
		switch(op) {
			case 1:
			{
				std::string input;
				int key;
				std::cout << "Text to encrypt: ";
				getline(std::cin, input);
				while(std::cin.fail()) {
					std::cerr << "Incorrect input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					input = "";
					std::cout << "Text to encrypt: ";
					getline(std::cin, input);
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
				std::cout << "Encrypted text: " << encrypt(input, key) << std::endl;
				break;
			}
			case 2:
			{
				std::string input;
				int key;
				std::cout << "Text to decrypt: ";
				getline(std::cin, input);
				while(std::cin.fail()) {
					std::cerr << "Invalid input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Text to decrypt: ";
					getline(std::cin, input);
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
				std::cout << "Decrypted text: " << decrypt(input, key) << std::endl;
				break;
			}
			case 3: {
				std::string plaintext;
				std::string ciphertext;
				std::cout << "Plaintext: ";
				getline(std::cin, plaintext);
				while(std::cin.fail()) {
					std::cerr << "Invalid input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Plaintext: ";
					getline(std::cin, plaintext);
				}
				std::cout << "Ciphertext: ";
				getline(std::cin, ciphertext);
				while(std::cin.fail()) {
					std::cerr << "Invalid input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::cout << "Ciphertext: ";
					getline(std::cin, ciphertext);
				}
				int k = check(plaintext, ciphertext);
				if(k == 27) std::cout << "Text is *NOT* correctly encrypted" << std::endl;
				else if(k == 0) std::cout << "Text is not encrypted, ciphertext is the same as plaintext" << std::endl;
				else if(k > 0 && k < 26) std::cout << "Text is correctly encrypted with key " << k << std::endl;
				break;
			}
			case 4: {
				std::string input;
				std::string fileName;
				std::cout << "Encrypted text to brute-force crack: ";
				getline(std::cin, input);
				while(std::cin.fail()) {
					std::cerr << "Incorrect input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					input = "";
					std::cout << "Encrypted text to brute-force crack: ";
					getline(std::cin, input);
				}
				std::cin.clear();
				std::cout << "Output file name (leave empty for stdout): ";
				getline(std::cin, fileName);
				std::ostream& out = fileName == "" ? std::cout : *(new std::ofstream(fileName));
				out << "Encrypted input: " << input;
				out << "\n\n";
				out << "Possible decrypted solutions: \n";
				for(int i = 1; i < 26; ++i) {
					if(i < 10) out << i << "  - ";
					else out << i << " - ";
					out << decrypt(input, i) << "\n";
				}
				break;
			}
			case 0:
				break;
			default:
				std::cerr << "Invalid option!";
				op = -1;
				break;
		}
	} while(op != 0);
	return 0;
}