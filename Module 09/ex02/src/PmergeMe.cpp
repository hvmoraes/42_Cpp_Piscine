#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) : size(argc), input(argv) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) : size(copy.size), input(copy.input), vector(copy.vector), deque(copy.deque)  {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy)
	{
		this->size = copy.size;
		this->input = copy.input;
		this->vector = copy.vector;
		this->deque = copy.deque;
	}
	return *this;
}

void PmergeMe::initVector() {
	for (int i = 1; i < this->size; i++)
		this->vector.push_back(std::atoi(this->input[i]));
}

void PmergeMe::initDeque() {
	for (int i = 1; i < this->size; i++)
		this->deque.push_back(std::atoi(this->input[i]));
}

int PmergeMe::sort() {
	if (!this->parse())
		return 0;

	std::cout << std::endl << "Before sort: ";
	std::cout << std::endl;
	this->showInput();
	std::cout << std::endl << std::endl;

	std::cout << "After sort: " << std::endl;

	clock_t vectorStart = clock();
	this->initVector();
	this->sortVector();
	clock_t vectorEnd = clock();
	double vectorDuration = (double)(vectorEnd - vectorStart) / CLOCKS_PER_SEC;

	this->showVector();
	std::cout << std::endl;
	std::cout << "Duration (vector): ";
	convertTime(vectorDuration);
	std::cout << std::endl << std::endl;

	clock_t dequeStart = clock();
	this->initDeque();
	this->sortDeque();
	clock_t dequeEnd = clock();
	double dequeDuration = (double)(dequeEnd - dequeStart) / CLOCKS_PER_SEC;

	this->showDeque();
	std::cout << std::endl;
	std::cout << "Duration (deque): ";
	convertTime(dequeDuration);
	std::cout << std::endl;
	return 1;
}