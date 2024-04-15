#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Span {
	private:
		
	protected:
		
	public:
		std::vector<int> vector;
		int total;
		int index;

		Span(unsigned int N);
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& copy);

		void addNumber(int nbr);
		int shortestSpan();
		int longestSpan();
		void	addMultiple(int total, int start, int end);
		class arrayFull : public std::exception {
			public:
				const char* what() const throw() {
					return ("Array is full!");
				};
		};
		class noSpan : public std::exception {
			public:
				const char* what() const throw() {
					return ("No span possible!");
				};
		};
};

#endif