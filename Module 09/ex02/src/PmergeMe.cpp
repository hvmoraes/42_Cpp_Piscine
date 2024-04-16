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
		this->list.push_back(std:: atoi(this->input[i]));
}

void PmergeMe::initDeque() {
	for (int i = 1; i < this->size; i++)
		this->deque.push_back(std:: atoi(this->input[i]));
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

void toPicoseconds(double duration) {
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

int PmergeMe::sort() {
    if (!this->parse())
        return 0;

    std::cout << "Before sort: ";
    this->showInput();

    clock_t listStart = clock();
    this->initList();
    this->sortList(this->list);
    clock_t listEnd = clock();
    double listDuration = (double)(listEnd - listStart) / CLOCKS_PER_SEC;

    clock_t dequeStart = clock();
    this->initDeque();
    this->sortDeque(this->deque);
    clock_t dequeEnd = clock();
    double dequeDuration = (double)(dequeEnd - dequeStart) / CLOCKS_PER_SEC;

    std::cout << std::endl << std::endl << "After sort: " << std::endl;
    this->showList();
    std::cout << std::endl;

    std::cout << "Duration (list): ";
    toPicoseconds(listDuration);
    std::cout << std::endl;

    this->showDeque();
    std::cout << std::endl;

    std::cout << "Duration (deque): ";
    toPicoseconds(dequeDuration);
    std::cout << std::endl;
    return 1;
}