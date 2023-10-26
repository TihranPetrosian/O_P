#include <iostream>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

void arrayCheck()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(-10, 10);   

    int arr[20];
    int sumPos = 0,
        countPos = 0,
        sumNeg = 0,
        countNeg = 0;

    cout << "\033[32mYour array: ";

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        arr[i] = distribution(gen);
        cout << "\033[34m" << setw(3) << arr[i] << "\033[32m";
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] > 0)
        {
            sumPos += arr[i];
            countPos++;
        }
        else
        {
            sumNeg += arr[i];
            countNeg++;
        }
    }

    double avgPos = sumPos / countPos;
    double avgNeg = sumNeg / countNeg;

    cout << "\nAverage positive number: " << setw(3) << "\033[34m" << avgPos << "\033[32m" << endl;
    cout << "Average negative number: " << setw(3) << "\033[34m" << avgNeg << "\033[32m" << endl;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] > 0 && abs(arr[i]) > avgPos)
        {
            arr[i] = avgPos;
        }
        else if (arr[i] < 0 && abs(arr[i]) > avgNeg)
        {
            arr[i] = avgNeg;
        }
    }

    cout << "New array: "
         << "\033[33m";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
}

void plane()
{
    const int totalSeats = 10;
    bool seats[totalSeats] = {false};
    int smokingSeats = 5;
    int nonSmokingSeats = 5;
    std::string choice;

    while (true)
    {

        for (int i = 0; i < totalSeats; i++)
        {
            std::cout << "\033[32m" << (seats[i] ? "1" : "0") << " ";
        }
        std::cout << std::endl;

        if (smokingSeats == 0 && nonSmokingSeats == 0)
        {
            std::cout << "\033[31mThe plane is full. We offer a new flight." << std::endl;
            char newFlight;
            std::cout << "\033[32mUpload a new flight? (y/n): ";
            std::cin >> newFlight;
            if (newFlight == 'y' || newFlight == 'Y')
            {
                for (int i = 0; i < totalSeats; i++)
                {
                    seats[i] = false;
                }
                smokingSeats = 5;
                nonSmokingSeats = 5;
            }
            else
            {
                break;
            }
        }

        std::cout << "\033[32mSmoking? (Y/N): ";
        std::cin >> choice;

        if ((choice == "Y" || choice == "y") && smokingSeats > 0)
        {
            for (int i = 0; i < totalSeats; i++)
            {
                if (!seats[i])
                {
                    seats[i] = true;
                    smokingSeats--;
                    break;
                }
            }
        }
        else if ((choice == "N" || choice == "n") && nonSmokingSeats > 0)
        {
            for (int i = 5; i < totalSeats; i++)
            {
                if (!seats[i])
                {
                    seats[i] = true;
                    nonSmokingSeats--;
                    break;
                }
            }
        }
        else
        {
            std::cout << "\033[31mThere are no more seats in the desired sector. Select another sector." << std::endl;
        }
    }
}

void arrayTransform(){
    const int maxSize = 10;
    int arr[maxSize];
    int k, pos;
    std::string action;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(-10, 10);

    for (int i = 0; i < maxSize; i++) {
        arr[i] = distribution(gen);
    }

    std::cout << "\033[32mThe initial state of the array: ";
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\033[32mSelect an operation (insert or delete): ";
    std::cin >> action;

    if (action == "insert") {
        std::cout << "\033[32mEnter the position (0-" << maxSize - 1 << "): ";
        std::cin >> pos;
        std::cout << "\033[32mEnter the number of items to insert: ";
        std::cin >> k;

        if (pos >= 0 && pos <= maxSize - 1 && k > 0 && k <= maxSize - pos) {

            for (int i = maxSize - 1; i >= pos; i--) {
                arr[i + k] = arr[i];
            }

            for (int i = pos; i < pos + k; i++) {
                std::cout << "\033[32mEnter a value for the element " << i << ": ";
                std::cin >> arr[i];
            }

            std::cout << "\033[32mArray after insertion: ";
            for (int i = 0; i < maxSize; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "\033[31mIncorrect position or number of items to insert." << std::endl;
        }
    } else if (action == "delete" ) {
        std::cout << "\033[32mEnter the position (0-" << maxSize - 1 << "): ";
        std::cin >> pos;
        std::cout << "\033[32mEnter the number of items to delete: ";
        std::cin >> k;

        if (pos >= 0 && pos <= maxSize - 1 && k > 0 && pos + k <= maxSize) {

            for (int i = pos; i < maxSize - k; i++) {
                arr[i] = arr[i + k];
            }

            std::cout << "\033[32mArray after deletion: ";
            for (int i = 0; i < maxSize; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "\033[31mIncorrect position or number of items to delete." << std::endl;
        }
    } else {
        std::cout << "\033[31mncorrect operation. Select 'insert' or 'delete'." << std::endl;
    }
}


void startMenu(){
  int menuItem;

  do
  {
    cout << "\x1B[32m1. Task1. Ararray Check." << endl;
    cout << "2. Task2. Plane." << endl;
    cout << "3. Task3. Array Transform." << endl;
    cout << "0.Exit." << endl;
    cout << "Choice task by his number: ";

    cin >> menuItem;

    switch (menuItem)
    {
    case 1:
      arrayCheck();
      break;

    case 2:
      plane();
      break;

    case 3:
      arrayTransform();
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

int main()
{
    startMenu();
    
}
