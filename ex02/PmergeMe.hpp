#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <cctype>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <string>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		//void	parseArgs(int argc, char **argv);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& source);
		PmergeMe& operator=(const PmergeMe& source);
		~PmergeMe();

		void	parseArgs(int argc, char **argv);
};

