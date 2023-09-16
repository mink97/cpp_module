#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

int myStoi(std::string str)
{
	long long num = 0;
	size_t len = str.size();
	if (len > 10)
		throw std::runtime_error("Error");
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			throw std::runtime_error("Error");
		num = num * 10 + str[i] - '0';
		if (num > 2147483647)
			throw std::runtime_error("Error");
	}
	if (num == 0)
		throw std::runtime_error("Error");
	return static_cast<int>(num);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::vector<int> vec;
	std::deque<int> deq;
	try
	{
		for (int i = 1; i < argc; i++)
		{
			int n = myStoi(argv[i]);
			vec.push_back(n);
			deq.push_back(n);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	std::cout << "Before:  ";
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	std::vector<int> sortedVec = vec;
	std::cout << "\nafter:   ";
	PmergeMe::mergeInsertionSort(sortedVec, 0, sortedVec.size());
	for (std::vector<int>::iterator itr = sortedVec.begin(); itr != sortedVec.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	clock_t start, finish;
	std::cout << "\nTime to process a range of " << argc - 1;
	std::cout << " elements with std::vector : ";
	start = std::clock();
	PmergeMe::mergeInsertionSort(vec, 0, vec.size());
	finish = std::clock();
	std::cout << std::fixed << std::setprecision(10) << static_cast<double>(finish - start) / CLOCKS_PER_SEC / 1000 << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with std::deque : ";
	start = std::clock();
	PmergeMe::mergeInsertionSort(deq, 0, deq.size());
	finish = std::clock();
	std::cout << static_cast<double>(finish - start) / CLOCKS_PER_SEC / 1000 << " us" << std::endl;
}
