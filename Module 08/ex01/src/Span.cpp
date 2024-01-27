#include "../inc/Span.hpp"

Span::Span(unsigned int N) : total(N) {
	//std::cout << "Span constructor called" << std::endl;
}

Span::~Span() {
	//std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span& copy) {
	std::cout << "Span copy constructor called" << std::endl;
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	std::cout << "Span assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

void Span::addNumber(int nbr) {
	if (index < this->total) {
		//std::cout << "Number " << nbr << " added!" << std::endl;
		this->vector.push_back(nbr);
		this->index++;
	}
	else
		throw(arrayFull());
}

int Span::shortestSpan() {
	int shortest = INT_MAX;
	int temp;
	//std::sort(this->vector.begin(), this->vector.end());
	if (this->vector.size() < 2)
		throw(noSpan());
	for (unsigned int i = 0; i < this->vector.size(); i++) {
		for (unsigned int j = i + 1; j < this->vector.size(); j++) {
			temp = this->vector.at(j) - this->vector.at(i);
			if (temp < 0)
				temp *= -1;
			if (temp < shortest) {
				shortest = temp;
			}
		}
	}
	return (shortest);
}

int Span::longestSpan() {
	std::sort(this->vector.begin(), this->vector.end());
	if (this->vector.size() < 2)
		throw(noSpan());
	return (this->vector.back() - this->vector.front());
}

void Span::addMultiple(int total, int start, int end) {
	srand(time(NULL));
	for (int i = 0; i < total; i++) {
		try {
			this->addNumber(rand()%(end - start + 1) + start);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
			break;
		}
	}
}