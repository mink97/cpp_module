#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>

struct pair
{
    int first;
    int second;
};
 
class PmergeMe {
	private:
		template<typename T>
		static void swap(T& a, T& b);

		template<typename T>
		static void insertionSort(T& arr, size_t start, size_t end);

		template<typename T>
		static void merge(T& arr, size_t start, size_t end);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& ref);

		template<typename T>
		static void mergeInsertionSort(T& arr, size_t start, size_t end);

};


template<typename T>
void PmergeMe::swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void PmergeMe::insertionSort(T& arr, size_t start, size_t end)
{
	for (size_t i = start; i < end; i++)
	{
		for (size_t j = i; j > start; j--)
		{
			if (arr[j] > arr[j - 1])
				break;
			swap(arr[j], arr[j - 1]);
		}
	}
}
template<typename T>
void PmergeMe::merge(T& arr, size_t start, size_t end)
{
	T tmp = arr;
	size_t mid = (start + end) / 2;
	size_t i = start, j = mid, k = start;
	while (i < mid && j < end)
	{
		if (tmp[i] < tmp[j])
		{
			arr[k] = tmp[i];
			i++;
		}
		else
		{
			arr[k] = tmp[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		arr[k] = tmp[i];
		i++;
		k++;
	}
	while (j < end)
	{
		arr[k] = tmp[j];
		j++;
		k++;
	}
}


/* ford-johnson algorithm
** 1. create a new array with the sorted pairs
** 2. sort the new array
** 3. pend
*/
template<typename T>
void PmergeMe::mergeInsertionSort(T& arr, size_t start, size_t end)
{
    size_t len = end - start;

    // sort each pair
    for (size_t i = start; i + 1 < end; i += 2)
    {
        if (arr[i] < arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

	if (end - start < 10)
		insertionSort(arr, start, end);
	else
	{
		size_t mid = (start + end) / 2;
		mergeInsertionSort(arr, start, mid);
		mergeInsertionSort(arr, mid, end);
		merge(arr, start, end);
	}
}

#endif
