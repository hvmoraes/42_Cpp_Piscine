#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define print(x) std::cout << x << std::endl
#define out std::cout
#define el std::endl

class RPN {
	private:
		
	protected:
		
	public:
		std::string input;
		std::stack<std::string> stack;

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