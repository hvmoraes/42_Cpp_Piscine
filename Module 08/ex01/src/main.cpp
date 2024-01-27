#include "../inc/Span.hpp"

int main() {
	Span span = Span(5);
	Span span1 = Span(0);
	try {
		span1.addNumber(2);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	span.addNumber(-1);
	span.addNumber(5);
	span.addNumber(2);
	span.addNumber(10);
	span.addNumber(6);
	try {
		span.addNumber(10);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	try
	{
		std::cout << span1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Subject

	std::cout << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	// Adding a lot of numbers

	Span multiple = Span(10000);
	multiple.addMultiple(10000, -10000, 10000);
	std::cout << multiple.shortestSpan() << std::endl;
	std::cout << multiple.longestSpan() << std::endl;
}