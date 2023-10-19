int main()
{
    std::cout << "Введіть число: ";
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
        std::cout << "Введено некоректне число." << std::endl;
        return 1;
    }

    int number = std::stoi(input);

    if (number < 0) {
        std::cout << "Число не може бути від'ємним." << std::endl;
        return 1;
    }

    if (input[0] == '0' || input.back() == '0') {
        std::cout << "Число не може починатися або закінчуватися нулем." << std::endl;
        return 1;
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

    std::cout << "Число навпаки: " << reversedNumber << std::endl;
    std::cout << "Кількість цифр: " << count << std::endl;
    std::cout << "Сума цифр: " << sum << std::endl;

    return 0;
}
