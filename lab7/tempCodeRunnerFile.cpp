#include <iostream>
#include <iomanip>
using namespace std;

void convertToMatrix(int arr[], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i * N + j] << ' ';
        }
        cout << '\n';
    }
    cout<< "\nAgain initial array: \n";
    for (int i = 0; i < N*3; i++)
    {
        cout << arr[i] << " ";
    }
    
}

void multiplyMatrix(int result[], int matrix[], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i * N + j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i * N + j] += matrix[i * N + k] * matrix[k * N + j];
            }
        }
    }
}

void printMatrix(int arr[], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(10) << arr[i * N + j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    const int N = 3;
    int result[N][N];
    int initArr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Initial array:\n";
    for (int i = 0; i < (sizeof(initArr) / sizeof(initArr[0])); i++) {
        cout << initArr[i] << ' ';
    }

    cout << "\n\nChanged array:\n";
    int matrix[N][N];
    convertToMatrix(initArr, N);
    multiplyMatrix(initArr, initArr, N);

    cout << "\nResult Matrix (Initial Matrix multiplied by itself):\n";
    printMatrix(initArr, N);

}