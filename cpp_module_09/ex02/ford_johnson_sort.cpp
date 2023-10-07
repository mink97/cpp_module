#include <iostream>
#include <string>
#include <vector>
#include <deque>

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void printArr(const T& arr)
{
	for (typename T::const_iterator itr = arr.begin(); itr != arr.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

// template<typename T>
// void insertionSort(T& arr, size_t start, size_t end)
// {
// 	for (int i = start; i < end; i++)
// 	{
// 		for (int j = i; j > start; j--)
// 		{
// 			if (arr[j] > arr[j - 1])
// 				break;
// 			swap(arr[j], arr[j - 1]);
// 		}
// 	}
// }

// template<typename T>
// void merge(T& arr, size_t start, size_t end)
// {
// 	T tmp = arr;
// 	size_t mid = (start + end) / 2;
// 	int i = start, j = mid, k = start;
// 	while (i < mid && j < end)
// 	{
// 		if (tmp[i] < tmp[j])
// 		{
// 			arr[k] = tmp[i];
// 			i++;
// 		}
// 		else
// 		{
// 			arr[k] = tmp[j];
// 			j++;
// 		}
// 		k++;
// 	}
// 	while (i < mid)
// 	{
// 		arr[k] = tmp[i];
// 		i++;
// 		k++;
// 	}
// 	while (j < end)
// 	{
// 		arr[k] = tmp[j];
// 		j++;
// 		k++;
// 	}
// }

// template<typename T>
// void mergeSort(T& arr, size_t start, size_t end)
// {
// 	if (end - start > 1)
// 	{
// 		size_t mid = (start + end) / 2;
// 		mergeSort(arr, start, mid);
// 		mergeSort(arr, mid, end);
// 		merge(arr, start, end);
// 	}
// }

// void merge(int (*arr)[2], size_t start, size_t end)
// {
// 	int (*tmp)[2] = new int[end - start][2];
// 	size_t mid = (start + end) / 2;
// 	size_t i = start, j = mid, k = 0;

// 	while (i < mid && j < end)
// 	{
// 		if (arr[i][0] < arr[j][0])
// 		{
// 			tmp[k][0] = arr[i][0];
// 			tmp[k][1] = arr[i][1];
// 			i++;
// 		}
// 		else
// 		{
// 			tmp[k][0] = arr[j][0];
// 			tmp[k][1] = arr[j][1];
// 			j++;
// 		}
// 		k++;
// 	}

// 	while (i < mid)
// 	{
// 		tmp[k][0] = arr[i][0];
// 		tmp[k][1] = arr[i][1];
// 		i++;
// 		k++;
// 	}

// 	while (j < end)
// 	{
// 		tmp[k][0] = arr[j][0];
// 		tmp[k][1] = arr[j][1];
// 		j++;
// 		k++;
// 	}

// 	for (size_t i = start; i < end; i++)
// 	{
// 		arr[i][0] = tmp[i - start][0];
// 		arr[i][1] = tmp[i - start][1];
// 	}
// 	delete[] tmp;

// }

// template<typename T>
void mergeSort(std::vector<std::pair<int, int>>& arr, size_t start, size_t end)
{
    if (end - start > 1)
    {
        size_t mid = start + (end - start) / 2;

        // 왼쪽과 오른쪽 반을 정렬합니다.
        mergeSort(arr, start, mid);
        mergeSort(arr, mid, end);

        std::vector<std::pair<int, int>> merged(end - start);

        size_t i = start, j = mid, k = 0;
        while (i < mid && j < end)
        {
            if (arr[i].first < arr[j].first)
            {
                merged[k] = arr[i];
                i++;
            }
            else
            {
                merged[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i < mid)
        {
            merged[k] = arr[i];
            i++;
            k++;
        }

        while (j < end)
        {
            merged[k] = arr[j];
            j++;
            k++;
        }

        // 정렬된 merged를 원래 배열 arr에 복사합니다.
        for (k = 0, i = start; i < end; i++, k++)
        {
            arr[i] = merged[k];
        }
    }
}


// void mergeSort(int (*arr)[2], size_t start, size_t end)
// {
// 	if (end - start > 1)
// 	{
// 		size_t mid = (start + end) / 2;
// 		mergeSort(arr, start, mid);
// 		mergeSort(arr, mid, end);
// 		merge(arr, start, end);
// 	}
// }

template<typename T>
size_t binarySearch(const T& arr, size_t start, size_t end, int target)
{
    if (end <= start)
        return end;

    size_t mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, end, target);
    else
        return binarySearch(arr, start, mid, target);
}

template<typename T>
T mergeInsertionSort(T& arr, size_t start, size_t end)
{
	size_t len = end - start;
	if (len < 2)
		return arr;
	int straggler = 0;
	if (len % 2)
		straggler = arr[end - 1];
	// int (*splitArr)[2] = new int[len / 2][2];
	std::vector<std::pair<int, int>> splitArr(len / 2);
	size_t i = start, j = 0;
	for (; i + 1 < end; i += 2)
	{
		std::pair<int, int> tmpPair;
		if (arr[i] < arr[i + 1])
		{
			tmpPair.first = arr[i + 1];
            tmpPair.second = arr[i];
		}
		else
		{
			tmpPair.first = arr[i];
            tmpPair.second = arr[i + 1];
		}
		splitArr[j] = tmpPair;
		j++;
	}
	// splitArr 정렬시키기
	mergeSort(splitArr, 0, len / 2);
	// splitArr 출력
	// for (i = 0; i < len / 2; i++)
	// {
	// 	std::cout << "splitArr[" << i << "]: ";
	// 	std::cout << splitArr[i][0] << " " << splitArr[i][1] << std::endl;
	// }
	// splitArr 합치기
	T result;
	T pend;
	for (i = 0; i < len / 2; i++)
	{
		result.push_back(splitArr[i].first);
        pend.push_back(splitArr[i].second);
	}
	result.insert(result.begin(), pend[0]);
	// result에 pend 합치기(jacobsthal number)
	size_t jacob1 = 1;
	size_t jacob2 = 1;
	size_t insertPoint;
	size_t pendSize = pend.size();
	// std::cout << "pendSize: " << pendSize << std::endl;
	i = 0;
	while (i < pendSize)
	{
		if (i == jacob1 - 1)
		{
			if (jacob2 > pendSize)
				break;
			size_t tmp = jacob2;
			jacob2 = jacob2 + (jacob1 * 2);
			jacob1 = tmp;
			if (jacob2 > pendSize)
				i = pendSize - 1;
			else
				i = jacob2 - 1;
		}
		insertPoint = binarySearch(result, 0, result.size(), pend[i]);
		// std::cout << "pend[" << i << "]: " << pend[i] << std::endl;
		// std::cout << "insertPoint: " << insertPoint << std::endl;
		result.insert(result.begin() + insertPoint, pend[i]);
		i--;
	}
	if (straggler)
	{
		insertPoint = binarySearch(result, 0, result.size(), straggler);
		result.insert(result.begin() + insertPoint, straggler);
	}
	return result;
}


int main()
{
	std::vector<int> vec = {12, 11, 11, 11, 3, 5, 13, 9, 7, 4, 11, 23, 2345, 215, 3456, 456, 253, 124, 234, 342};
	// std::vector<int> vec2 = {1};
	// std::deque<int> deq = {3, 5, 9, 7, 4, 11, 23, 2345, 215, 3456, 456, 253, 124, 234, 342};

	// printArr(vec2);
	// mergeSort(vec2, 0, vec2.size());
	// printArr(vec2);
	// printArr(vec);
	// printArr(deq);
	std::vector<int> sortedVec = mergeInsertionSort(vec, 0, vec.size());
	printArr(sortedVec);
	// mergeInsertionSort(deq, 0, deq.size());
	
	// printArr(vec);
	// printArr(deq);
}