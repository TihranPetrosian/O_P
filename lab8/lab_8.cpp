#include <iostream>
#include <cstdlib>
using namespace std;

void fillArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        *(arr + i) = rand() % 21 - 10;
    }
    std::cout << std::endl;
}

void fillArrayResult(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << *(arr + i) << " ";
    }
}

void swapWithFirstEven(int* arr, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > *(arr + maxIndex)) {
            maxIndex = i;
        }
    }

    int firstEvenIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) % 2 == 0) {
            firstEvenIndex = i;
            break;
        }
    }

    if (firstEvenIndex != -1) {
        std::swap(*(arr + maxIndex), *(arr + firstEvenIndex));
    }
}

int* createNegativeArray(const int* arr, int size, int& newSize) {
    int negativeCount = 0;
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) < 0) {
            negativeCount++;
        }
    }

    newSize = negativeCount;

    int* negativeArray = new int[newSize];
    int currentIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (*(arr + i) < 0) {
            *(negativeArray + currentIndex) = *(arr + i);
            currentIndex++;
        }
    }

    return negativeArray;
}

int main()
{

    int N;
    std::cout << "\033[32mGive me the length of the array: ";
    std::cin >> N;

    int *dynamicArray = new int[N];

    fillArray(dynamicArray, N);

    std::cout << "\033[33mFilled array: ";
    fillArrayResult(dynamicArray, N);

    int newSize;
    int* negativeArray = createNegativeArray(dynamicArray, N, newSize);

    swapWithFirstEven(dynamicArray, N);

    std::cout << "\n\033[32mArray after swapping: \033[33m";
    fillArrayResult(dynamicArray, N);

    std::cout << "\n\033[32mNegative array: \033[31m";
    fillArrayResult(negativeArray, newSize);

    delete[] dynamicArray;
    delete[] negativeArray;

}