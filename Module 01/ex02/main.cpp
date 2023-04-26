#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory adress of str: " << &str << std::endl << "Memory access of strPTR: " << stringPTR << std::endl << "Memory access of strREF: " << &stringREF << std::endl << "Value of str: " << str << std::endl << "Value of strPTR: " << *stringPTR <<std:: endl << "Vaslue of strRef: " << stringREF << std::endl;
}