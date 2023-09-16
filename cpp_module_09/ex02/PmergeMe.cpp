#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& ref) {*this = ref;}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& ref) {
	if (this != &ref) {
		*this = ref;
	}
	return (*this);
}
