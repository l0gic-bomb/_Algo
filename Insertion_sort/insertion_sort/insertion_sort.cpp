/*
Сортировка вставками. Среднее время O(n^2)
*/

#include <iostream>

template< typename Container >
void Insertion_Sort(Container* arr, size_t size)
{
    Container tmp;
    for (int i = 1, j; i < size; ++i)
    {
        tmp = arr[i];
        // поиск места элемента в готовой последовательности 
        for (j = i - 1; j >= 0 && arr[j] > tmp; --j)
            // сдвигаем элемент направо, пока не дошли
            arr[j + 1] = arr[j];

        // место найдено, вставить элемент  
        arr[j + 1] = tmp;
    }
}

template<typename Container>
void show(Container* arr, const size_t m)
{
    for (size_t i = 0; i < m; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    const int m = 10;
    int arr[m]{ 1111,2222,3,900,51,6,531,8,322 };

    Insertion_Sort(arr, m);
    show(arr, m);
    return 0;
}

