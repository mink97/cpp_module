#include "Span.hpp"

Span::Span() : _capacity(0)
{
	std::cout << "\x1b[33m""[Span]: default constructor has called!""\x1b[0m" << std::endl;
	_vec.reserve(0);
}

Span::Span(const Span& ref) : _capacity(ref._capacity)
{
	std::cout << "\x1b[35m""[Span]: deep-copy constructor has called!""\x1b[0m" << std::endl;
	_vec.reserve(ref._capacity);
	for (size_t i = 0; i < ref._vec.size(); i++)
	{
		_vec.push_back(ref._vec[i]);
	}
}

Span::Span(unsigned int N) : _capacity(N)
{
	std::cout << "\x1b[33m""[Span]: constructor has called!""\x1b[0m" << std::endl;
	_vec.reserve(N);
}

Span::~Span()
{
	std::cout << "\x1b[31m""[Span]: destructor has called!""\x1b[0m" << std::endl;
}

Span&	Span::operator=(const Span& ref)
{
	if (this != &ref)
	{
		std::cout << "\x1b[34m""[Span]: overloaded operator has called!""\x1b[0m" << std::endl;
		_vec.clear();
		_capacity = ref._capacity;
		_vec.reserve(_capacity);
		for (size_t i = 0; i < ref._vec.size(); i++)
			_vec.push_back(ref._vec[i]);
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if (_vec.size() >= _capacity)
		throw MaxStoreException();
	_vec.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw NoSpanException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	unsigned int ans = *(tmp.begin() + 1) - *tmp.begin();
	for (std::vector<int>::iterator itr = (tmp.begin() + 1); itr != tmp.end(); itr++)
	{
		if (static_cast<unsigned int>(*(itr + 1) - *(itr)) < ans)
			ans = *(itr + 1) - *(itr);
	}
	return (ans);
}

unsigned int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw NoSpanException();
	unsigned int ans;
	ans = *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
	return (ans);
}

const char* Span::MaxStoreException::what() const throw()
{
	return ("There are already Max elements");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("The number of elements is less than 2");
}
