#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

#define print(x) std::cout << x << std::endl
#define out std::cout
#define el std::endl

class RPN {
	private:
		
	protected:
		
	public:
		std::string input;
		std::stack<float> stack;

		RPN(char *input);
		~RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);

		int initStack();
		int mult(int *flag);
		int div(int *flag);
		int sub(int *flag);
		int add(int *flag);
};

#endif