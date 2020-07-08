/*
Cортировка методом пузырка (bubble sort). Среднее время O(n^2).
Пробегание по контейнеру и сравнивание соседних элементов, если элемент больше (или меньше в зависимотси от того как сортируем) меняем их местами
и так мы бегаем (циклом while) пока очередная пробежка пройдет без перестановок хотя бы одного элемента( это будет означать что элементы отсортированы)
*/

#include "Header.h"


// функция сортировки пузырком
template<typename Cont> 
void bubblesort(Cont* arr, const size_t m) {
	Cont tmp = 0;
	for (size_t i = 0; i < m - 1; ++i) // i - номер прохода
	{
		for (size_t j = 0; j < m - 1; ++j) // внутренний цикл прохода
		{
			if (arr[j + 1] < arr[j])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

template<typename Cont>
void show(Cont* arr, const size_t m)
{
	for (size_t i = 0; i < m; ++i)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

int main() {

	//srand(time(0));

	const int m = 10;
	int arr[m]{ 1,2,3,900,51,6,531,8,322 };

	//incil(arr, m);

	bubblesort(arr, m);
	show(arr, m);
	
	return 0;
}




/*
// функция для записи случайных чисел
void incil(int* arr, const size_t m) {
	//
	for(size_t i = 0; i < m; ++i)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
*/
