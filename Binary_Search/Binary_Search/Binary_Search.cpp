
#include "header.h"

template <typename RandomIterator, typename Value>
bool binarySearch(RandomIterator begin, RandomIterator end, const Value target)
{
	bool result = false;
	std::size_t numberOfElements = end - begin;

	if (numberOfElements < 1)
		return result;
	else if (numberOfElements == 1)
		if (target == *begin)
			result = true;
	else
	{
		auto middle = begin + numberOfElements / 2;

		if (target == *middle)
		{
			result = true;
		}
		else if (target < *middle)
		{
			result = binarySearch(begin, middle, target);
		}
		else
		{
			result = binarySearch(middle, end, target);
		}
	}

	return result;
}

template <typename Type>
Type randomNumber(const Type begin, const Type end)
{
	// генератор случайных чисел
	static std::mt19937 generator((std::size_t)time(0));
	std::uniform_int_distribution<Type> distribution(begin, end);
	return distribution(generator);
}

template <typename Container, typename ValueType>
void fillSequenceRand(Container& seq, const ValueType Num, const ValueType toNum)
{
	for (auto& elem : seq)
		elem = randomNumber(Num, toNum);
}


template <typename Container>
void show(const Container& seq)
{
	for (const auto elem : seq)
		std::cout << elem << ' ';
	std::cout << std::endl;
}

void binary_Search_launch()
{
	constexpr std::size_t num_of_tests = 100000;

	constexpr int target = 11;
	constexpr int lower = 1;
	constexpr int upper = 20;

	std::vector<int> arr;
	bool testSuccess = true;

	for (std::size_t i = 0; i < num_of_tests; ++i)
	{
		arr.clear();
		arr.resize(randomNumber(lower, upper));
		fillSequenceRand(arr, lower, upper);
		std::sort(arr.begin(), arr.end()); 

		if (binarySearch(arr.begin(), arr.end(), target))
		{
			if (std::find(arr.begin(), arr.end(), target) == arr.end())
			{
				std::cout
					<< "Expected that this sequence contains "
					<< target << ", but it doesn't:\n";
				show(arr);
				testSuccess = false;
				break;
			}
		}
		else
		{
			if (std::find(arr.begin(), arr.end(), target) != arr.end())
			{
				std::cout
					<< "Expected that this sequence not contains "
					<< target << ", but it does:\n";
				show(arr);
				testSuccess = false;
				break;
			}
		}
	}

	if (testSuccess)
	{
		std::cout << "Test passed successfully.\n";
	}
}

int main()
{
	binary_Search_launch();
}