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