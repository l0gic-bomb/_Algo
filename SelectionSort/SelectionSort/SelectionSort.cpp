// SelectionSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*
Сортировка выбором. Среднее время О(n^2)
Идея метода состоит в том, чтобы создавать отсортированную последовательность путем присоединения к ней одного элемента за другим в правильном порядке.
*/

#include <iostream>

template<typename Container>
void selectSort(Container* arr, size_t size)
{
    Container tmp;
    // i - номер текущего шага
    for (size_t i = 0; i < size; ++i) 
    {
        int pos = i;
        tmp = arr[i];
        // цикл выбора наименьшего элемента
        for (size_t j = i + 1; j < size; ++j) 
        {
            if (arr[j] < tmp)
            {
                pos = j;
                tmp = arr[j];
            }
        }
        arr[pos] = arr[i];
        // меняем местами наименьший с a[i]
        arr[i] = tmp;
    }
}

// функция вывода
template<typename Container>
void show(Container* arr, size_t size)
{
    for(size_t k = 0; k <= size; ++k)
        std::cout << arr[k] << "  ";
    std::cout << std::endl;
}

int main()
{
    const size_t size = 10;
    int arr[size]{ 5,2,8,4,31,6,45,8,9};
    show(arr, size);
    selectSort(arr, size);
    show(arr, size);
    return 0;
}