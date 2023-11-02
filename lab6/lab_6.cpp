#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


const int N = 6; 

void matrixSwitch(){
int matrix[N][N];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = std::rand() % 100; 
        }
    }

    std::cout << "\x1B[34mInitial matrix:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int mirroredMatrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mirroredMatrix[i][j] = matrix[N - j - 1][N - i - 1];
        }
    }

    std::cout << "\x1B[33mReflected matrix:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << mirroredMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void matrixBlend(){
    const int rows = 6;
    const int cols = 6;

    int matrix[rows][cols];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = std::rand() % 10; 
        }
    }

    std::cout << "Initial array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        int maxElement = matrix[i][0];
        int indexOfMax = 0;

        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                indexOfMax = j;
            }
        }

        int temp = matrix[i][0];
        matrix[i][0] = maxElement;
        matrix[i][indexOfMax] = temp;
    }

    std::cout << "\x1B[35mArray after task a:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int j = 0; j < cols; j++) {
        int minElement = matrix[0][j];
        int indexOfMin = 0;

        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                indexOfMin = i;
            }
        }

        int temp = matrix[rows - 1][j];
        matrix[rows - 1][j] = minElement;
        matrix[indexOfMin][j] = temp;
    }

    std::cout << "\x1B[34mArray after tasks a and b:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void startMenu(){
  int menuItem;

  do
  {
    cout << "\x1B[32m\n1. Task1. Switching matrix." << endl;
    cout << "2. Task2. Blending matrix." << endl;
    cout << "0.Exit." << endl;
    cout << "Choice task by his number: ";

    cin >> menuItem;

    switch (menuItem)
    {
    case 1:
      matrixSwitch();
      break;

    case 2:
      matrixBlend();
      break;
    
    case 0:
    cout << "Bye-Bye" << endl;
    break;

    default:
      cout << "Incorrect choice";
      break;
    }
  } while (menuItem != 0);
  
}

int main() {
    
    startMenu();
    
}
