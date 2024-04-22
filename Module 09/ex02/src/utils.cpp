#include "../inc/PmergeMe.hpp"

int PmergeMe::parse() {
	for (int i = 1; i < this->size; i++) {
		for (size_t j = 0; j < std::strlen(this->input[i]); j++) {
			if (!std::isdigit(this->input[i][j])) {
				out << "\033[31mError: invalid number inserted => " << this->input[i] << "\033[0m" << el;
				return (0);
			}
		}
	}
	return (1);
}

void PmergeMe::showInput() {
	int	i = 1;
	if (this->size > 10) {
		while (i < 6) {
			out << this->input[i] << " ";
			i++;
		}
		out << "[...] ";
		while (i < this->size - 5) {
			i++;
			continue;
		}
		while (i < this->size) {
			out << this->input[i] << " ";
			i++;
		}
	}
	else {
		while (i < this->size) {
			out << this->input[i] << " ";
			i++;
		}
	}
}

void	PmergeMe::showVector() {
	out << "Vector: ";
	int	i = 0;
	if (this->size > 10) {
		while (i < 5) {
			out << vector[i] << " ";
			i++;
		}
		out << "[...] ";
		while (i < this->size - 6) {
			i++;
			continue;
		}
		while (i < this->size - 1) {
			out << vector[i] << " ";
			i++;
		}
	}
	else {
		while (i < this->size - 1) {
			out << vector[i] << " ";
			i++;
		}
	}
}

void PmergeMe::showDeque() {
	std::deque<int>::iterator it;
	it = this->deque.begin();
	out << "Deque: ";
	int	i = 1;
	if (this->size > 10) {
		while (i < 6) {
			out << *it << " ";
			it++;
			i++;
		}
		out << "[...] ";
		while (i < this->size - 5) {
			i++;
			it++;
			continue;
		}
		while (i < this->size) {
			out << *it << " ";
			i++;
			it++;
		}
	}
	else {
		while (i < this->size) {
			out << *it << " ";
			i++;
			it++;
		}
	}
}

void PmergeMe::convertTime(double duration) {
	if (duration * 1000000000000 > 0.1 && duration * 1000000000000 < 100)
		std::cout << duration * 1000000000000 << "ps";
	else if (duration * 1000000000 > 0.1 && duration * 1000000000 < 100)
		std::cout << duration * 1000000000 << "ns";
	else if (duration * 1000000 > 0.1 && duration * 1000000 < 100)
		std::cout << duration * 1000000 << "μs";
	else if (duration * 1000 > 0.1 && duration * 1000 < 100)
		std::cout << duration * 1000 << "ms";
	else if (duration > 0.1 && duration < 100)
		std::cout << duration << "s";
}

size_t  jacobsthalEquation(int order)
{
	if (order == 1)
		return 1;
	else
		return ((std::pow(2, order) - std::pow(-1, order)) / 3);
}

size_t  PmergeMe::getJacobsthal(size_t i, size_t *jacob_order, size_t *smaller_index)
{
	if (i - 1 != 0 && i - 1 != jacobsthalEquation(*jacob_order - 1)) // Decrementing elements after the jc number
		i--;
	else // Next jc number and first element cases
	{
		(*jacob_order)++;
		*smaller_index = i;
		i = jacobsthalEquation(*jacob_order);
	}
	return i;
}