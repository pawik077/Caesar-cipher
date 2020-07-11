#include <string>
#include <stdexcept>

std::string encrypt(const std::string& input, int key);
std::string decrypt(const std::string& input, int key);
int check(const std::string& plaintext, const std::string& ciphertext);