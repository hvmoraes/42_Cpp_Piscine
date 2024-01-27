#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) : size(argc), input(argv) {
	//std::cout << "Default constructor called" << std::endl;
}

PmergeMe::~PmergeMe() {
	//std::cout << "Default destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	std::cout << "Default assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

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

void PmergeMe::initList() {
	for (int i = 1; i < this->size; i++)
		this->list.push_back(std::stoi(this->input[i]));
}

void PmergeMe::initDeque() {
	for (int i = 1; i < this->size; i++)
		this->deque.push_back(std::stoi(this->input[i]));
}

void	PmergeMe::showList() {
	std::list<int>::iterator it;
	it = this->list.begin();
	out << "List: ";
	while (it != this->list.end()) {
		out << *it << " ";
		it++;
	}
}

void PmergeMe::showDeque() {
	std::deque<int>::iterator it;
	it = this->deque.begin();
	out << "Deque: ";
	while (it != this->deque.end()) {
		out << *it << " ";
		it++;
	}
}

void listMerge(std::list<int>& list, std::list<int>& left, std::list<int>& right) {
	std::list<int>::iterator leftIter = left.begin();
	std::list<int>::iterator rightIter = right.begin();
	std::list<int>::iterator listIter = list.begin();

	while (leftIter != left.end() && rightIter != right.end()) {
		if (*leftIter < *rightIter) {
			*listIter = *leftIter;
			++leftIter;
		} else {
			*listIter = *rightIter;
			++rightIter;
		}
		++listIter;
	}

	while (leftIter != left.end()) {
		*listIter = *leftIter;
		++leftIter;
		++listIter;
	}

	while (rightIter != right.end()) {
		*listIter = *rightIter;
		++rightIter;
		++listIter;
	}
}

void PmergeMe::sortList(std::list<int>& list) {
	if (list.size() <= 1)
    return;
    std::list<int> left, right;
    int mid = list.size() / 2;
    std::list<int>::iterator it = list.begin();
    for (int i = 0; i < mid; ++i) {
			left.push_back(*it);
			++it;
    }
    while (it != list.end()) {
			right.push_back(*it);
			++it;
    }
    this->sortList(left);
    this->sortList(right);
    listMerge(list, left, right);
}

void dequeMerge(std::deque<int>& deque, std::deque<int>& left, std::deque<int>& right) {
	std::deque<int>::iterator leftIter = left.begin();
	std::deque<int>::iterator rightIter = right.begin();
	std::deque<int>::iterator dequeIter = deque.begin();

	while (leftIter != left.end() && rightIter != right.end()) {
		if (*leftIter < *rightIter) {
			*dequeIter = *leftIter;
			++leftIter;
		} else {
			*dequeIter = *rightIter;
			++rightIter;
		}
		++dequeIter;
	}

	while (leftIter != left.end()) {
		*dequeIter = *leftIter;
		++leftIter;
		++dequeIter;
	}

	while (rightIter != right.end()) {
		*dequeIter = *rightIter;
		++rightIter;
		++dequeIter;
	}
}

void PmergeMe::sortDeque(std::deque<int>& deque) {
	if (deque.size() <= 1) {
        return;
    }

    std::deque<int> left, right;
    int mid = deque.size() / 2;
    std::deque<int>::iterator it = deque.begin();

    for (int i = 0; i < mid; ++i) {
        left.push_back(*it);
        ++it;
    }

    while (it != deque.end()) {
        right.push_back(*it);
        ++it;
    }

    this->sortDeque(left);
    this->sortDeque(right);
    dequeMerge(deque, left, right);
}

void PmergeMe::showInput() {
	for (int i = 1; i < this->size; i++)
		out << this->input[i] << " ";
}

void toPicoseconds(std::chrono::duration<double> duration) {
	float checkDuration = duration.count();
	if (checkDuration * 1000000000000 > 0.1 && checkDuration * 1000000000000 < 100)
		out << checkDuration * 1000000000000 << "ps";
	else if (checkDuration * 1000000000 > 0.1 && checkDuration * 1000000000 < 100)
		out << checkDuration * 1000000000 << "ns";
	else if (checkDuration * 1000000 > 0.1 && checkDuration * 1000000 < 100)
		out << checkDuration * 1000000 << "μs";
	else if (checkDuration * 1000 > 0.1 && checkDuration * 1000 < 100)
		out << checkDuration * 1000 << "ms";
	else if (checkDuration > 0.1 && checkDuration < 100)
		out << checkDuration << "s";
}


int PmergeMe::sort() {
	if (!this->parse())
		return (0);

	out << "Before sort: ";
	//this->showInput();

	std::chrono::high_resolution_clock::time_point listStart = std::chrono::high_resolution_clock::now();
	this->initList();
	this->sortList(this->list);
	std::chrono::high_resolution_clock::time_point listEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> listDuration = listEnd - listStart;

	std::chrono::high_resolution_clock::time_point dequeStart = std::chrono::high_resolution_clock::now();
	this->initDeque();
	this->sortDeque(this->deque);
	std::chrono::high_resolution_clock::time_point dequeEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> dequeDuration = dequeEnd - dequeStart;

	out << el << el << "After sort: " << el;
	//this->showList();
	out << el;

	out << "Duration (list): ";
	toPicoseconds(listDuration);
	out << el;

	//this->showDeque();
	out << el;

	out << "Duration (deque): ";
	toPicoseconds(dequeDuration);
	out << el;
	return (1);
}