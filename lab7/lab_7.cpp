#include <iostream>
#include <iomanip>
using namespace std;

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

void convertToMatrix(int arr[], int matrix[][3], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = arr[i * N + j];
            std::cout << std::setw(5) << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
    std::cout << "Again initial array;\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << arr[i * N + j] << ' ';
        }
    }
    std::cout << '\n';
}

void printMatrix(int arr[][3], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(10) << arr[i][j] << ' ';
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

    int matrix[N][N];
    std::cout << "\nConverted to matrix:\n";
    convertToMatrix(initArr, matrix, N);
    multiplyMatrix(result[0], matrix[0], N);

    cout << "\nResult Matrix (Initial Matrix multiplied by itself):\n";
    printMatrix(result, N);

    return 0;
}
