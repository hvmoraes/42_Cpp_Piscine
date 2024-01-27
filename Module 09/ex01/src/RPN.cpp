#include "../inc/RPN.hpp"

RPN::RPN(char *input) : input(input) {
	//std::cout << "RPN constructor called" << std::endl;
}

RPN::~RPN() {
	//std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN(const RPN& copy) {
	std::cout << "RPN copy constructor called" << std::endl;
	*this = copy;
}

RPN& RPN::operator=(const RPN& copy) {
	std::cout << "RPN assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

int	RPN::mult(int *flag) {
	if (this->stack.size() < 2) {
		*flag = 1;
		return (0);
	}
	int i,j;
	i = stoi(this->stack.top());
	this->stack.pop();
	j = stoi(this->stack.top());
	this->stack.pop();
	this->stack.push(std::to_string(j * i));
	return (1);
}

int	RPN::div(int *flag) {
	if (this->stack.size() < 2) {
		*flag = 1;
		return (0);
	}
	int i,j;
	i = stoi(this->stack.top());
	this->stack.pop();
	j = stoi(this->stack.top());
	this->stack.pop();
	this->stack.push(std::to_string(j / i));
	return (1);
}

int	RPN::sub(int *flag) {
	if (this->stack.size() < 2) {
		*flag = 1;
		return (0);
	}
	int i,j;
	i = stoi(this->stack.top());
	this->stack.pop();
	j = stoi(this->stack.top());
	this->stack.pop();
	this->stack.push(std::to_string(j - i));
	return (1);
}

int	RPN::add(int *flag) {
	if (this->stack.size() < 2) {
		*flag = 1;
		return (0);
	}
	int i,j;
	i = stoi(this->stack.top());
	this->stack.pop();
	j = stoi(this->stack.top());
	this->stack.pop();
	this->stack.push(std::to_string(j + i));
	return (1);
}

int RPN::initStack() {
	int flag = 0;
	for (size_t i = 0; i < this->input.size(); i++) {
		std::string str (1, this->input[i]);
		if (this->input[i] != ' ') {
			if (this->input[i] == '*' && this->mult(&flag))
				continue;
			else if (this->input[i] == '/' && this->div(&flag))
				continue;
			else if (this->input[i] == '-' && this->sub(&flag))
				continue;
			else if (this->input[i] == '+' &&this->add(&flag))
				continue;
			else if (std::isdigit(this->input[i]))
				this->stack.push(str);
			else if (!flag) {
				out << "\033[31mError: invalid character inserted => " << this->input[i] << "\033[0m" << el;
				return (0);
			}
		}
	}
	if (this->stack.size() != 1 || flag) {
		print("\033[31mError: bad input\033[0m");
		return (0);
	}
	print(this->stack.top());
	return (1);
}