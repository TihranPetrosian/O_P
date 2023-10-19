#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

void printGraphic()
{
  short n;     
  double x, y; 
  short h;     

  for (n = 0; n < 5; n++)
  {
    printf("|   x   |      у     |\n");
    printf("|-------|------------|\n");
    for (x = 0; x < 4; x += 0.25)
    {
      if (x < 2)
        y = sqrt(2 * 2 - (x - 2) * (x - 2));
      else if (x < 3)
        y = -sqrt(1 - (x - 3) * (x - 3));
      else
        y = 0;
      printf("| %5.2lf | %10.7lf |", x + n * 4, y);
      h = (y + 1) * 10;
      if (y - 1 - h * 10 > 0.5)
        h++;
      for (; h > 0; h--)
        printf(" ");
      printf("*\n");
    } 
  } 
};

int GetRandomNumber(int min, int max)
{
  srand(time(NULL));

  int num = min + rand() % (max - min + 1);

  return num;
};

void guessNumber(){
  int guessNum;
  short triesCounter = 0;

  int randNumber;
  randNumber = GetRandomNumber(-10, 10);
  cout << "number = " << randNumber << endl;

  while (true)
  {
        cout << "Give me some number" << endl;
    cin >> guessNum;
    triesCounter++;

    if (guessNum < randNumber)
    {
      cout << "No, your number is smaller" << endl;
    }
    else if (guessNum > randNumber)
    {
      cout << "No, your number is bigger" << endl;
    }

    if (guessNum == randNumber)
    {
      cout << "Correct, you find my number" << endl;
      cout << "Count of tries: " << triesCounter << endl;
      break;
    }
  }
}

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
};

void multiplicationTable(){
srand(static_cast<unsigned>(time(0))); 

    int score = 0;
    int userAnswer;

    std::cout << "Checking knowledge of the multiplication table" << std::endl;

    for (int i = 0; i < 10; i++) {
        int num1 = generateRandomNumber(2, 9);
        int num2 = generateRandomNumber(2, 9);
        int correctAnswer = num1 * num2;

        std::cout << num1 << " x " << num2 << " = ?" << std::endl;
        std::cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            std::cout << "Correct!" << std::endl;
            score++;
        } else {
            std::cout << "Incorrect. The right answer is: " << correctAnswer << std::endl;
        }
    }

    int finalScore;
    if (score == 10) {
        finalScore = 5;
    } else if (score == 9) {
        finalScore = 4;
    } else if (score == 8 || score == 7) {
        finalScore = 3;
    } else {
        finalScore = 2;
    }

    std::cout << "Your mark: " << finalScore << std::endl;
};

  void numberAnalysis(){
std::cout << "Give me a number: ";
    std::string input;
    std::cin >> input;

    bool validInput = true;

    for (char c : input) {
        if (!std::isdigit(c)) {
            validInput = false;
            break;
        }
    }

    if (!validInput) {
        std::cout << "Number is uncorrect." << std::endl;
    }

    int number = std::stoi(input);

    if (number < 0) {
        std::cout << "Number is negative." << std::endl;
    }

    if (input[0] == '0' || input.back() == '0') {
        std::cout << "Number starts or ends with 0." << std::endl;
    }

    int sum = 0;
    int count = 0;
    int reversedNumber = 0;

    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
        count++;
    }

    std::cout << "Reversed number: " << reversedNumber << std::endl;
    std::cout << "Count of numbers: " << count << std::endl;
    std::cout << "Sum: " << sum << std::endl;

  }

void startMenu(){
  int menuItem;

  do
  {
    cout << "1. Task1. Print graphic." << endl;
    cout << "2. Task2. Guess number." << endl;
    cout << "3. Task3. Multiplication table." << endl;
    cout << "4. Task4. Number Analysis and Transformation." << endl;
    cout << "0.Exit." << endl;
    cout << "Choice task by his number: ";

    cin >> menuItem;

    switch (menuItem)
    {
    case 1:
      printGraphic();
      break;

    case 2:
      guessNumber();
      break;

    case 3:
      multiplicationTable();
      break;
    
    case 4:
      numberAnalysis();
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
