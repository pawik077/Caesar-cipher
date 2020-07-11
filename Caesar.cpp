#include "Caesar.hh"

std::string encrypt(const std::string& input, int key) {
	int k = key % 26;
	std::string output;
	for(unsigned int i = 0; i < input.size(); ++i) {
		if(input[i] >= 0x20 && input[i] <= 0x40 || input[i] >= 0x5b && input[i] <= 0x60) output.push_back(input[i]);
		else if(input[i] >= 0x41 && input[i] <= 0x5a) {
			if(input[i] + k > 0x5a) output.push_back(input[i] + k - 26);
			else output.push_back(input[i] + k);
		} else if(input[i] >= 0x61 && input[i] <= 0x7a) {
			if(input[i] + k > 0x7a) output.push_back(input[i] + k - 26);
			else output.push_back(input[i] + k);
		} else throw std::invalid_argument("non-printable ASCII characters in input");
	}
	return output;
}

std::string decrypt(const std::string& input, int key) {
	int k = key % 26;
	std::string output;
	for(int i = 0; i < input.size(); ++i) {
		if(input[i] >= 0x21 && input[i] <= 0x40 ||
			 input[i] >= 0x5b && input[i] <= 0x60 ||
			 input[i] >= 0x7b && input[i] <= 0x7e)
			output.push_back(input[i]);
		else if(input[i] >= 0x41 && input[i] <= 0x5a) {
			if(input[i] - k < 0x41) output.push_back(input[i] - k + 26);
			else output.push_back(input[i] - k);
		} else if(input[i] >= 0x61 && input[i] <= 0x7a) {
			if(input[i] - k < 0x61) output.push_back(input[i] - k + 26);
			else output.push_back(input[i] - k);
		} else
			throw std::invalid_argument("non-printable ASCII character in input");
	}
	return output;
}

int check(const std::string& plaintext, const std::string& ciphertext) {
	int k;
	if(plaintext.size() != ciphertext.size()) return 27;
	for(int i = 0; i < plaintext.size(); ++i) {
		if(plaintext[i] >= 0x21 && plaintext[i] <= 0x40 ||
			 plaintext[i] >= 0x5b && plaintext[i] <= 0x60 ||
			 plaintext[i] >= 0x7b && plaintext[i] <= 0x7e)
			continue;
		else {
			k = ciphertext[i] - plaintext[i];
			break;
		}
	}
	for(int i = 1; i < plaintext.size(); ++i) {
		if(plaintext[i] >= 0x21 && plaintext[i] <= 0x40 ||
			 plaintext[i] >= 0x5b && plaintext[i] <= 0x60 ||
			 plaintext[i] >= 0x7b && plaintext[i] <= 0x7e)
			continue;
		else if(ciphertext[i] - plaintext[i] != k) return 27;
	}
	return k;
}