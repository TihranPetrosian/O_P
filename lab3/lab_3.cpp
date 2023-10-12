#include <iostream>
#include <math.h>

int main() {

    //Task 1
    // double x, y; // координати точки

    // while (1) {
    //     printf("\n \033[1;32mВведіть координату x >");
    //     scanf("%lf", &x);
    //     printf("\033[1;32m Введіть координату y >");
    //     scanf("%lf", &y);

    //     printf("x=%6.3lf; y=%6.3lf\n", x, y);

    //     // Перевірка умов
    //     if ((x * x + y * y <= 1) || (x <= -1 && y >= -1 && y <= 1))
    //         printf("\033[1;34mТочка потрапляє в область\n");
    //     else
    //         printf("\033[1;31mТочка не потрапляє в область\n");
    // }

    //Task 2
    double a, b, c;
    printf("\033[1;32mВведіть коефіцієнт a: ");
    scanf("%lf", &a);
    printf("Введіть коефіцієнт b: ");
    scanf("%lf", &b);
    printf("Введіть коефіцієнт c: ");
    scanf("%lf", &c);

    double discriminant = b * b - 4 * a * c;

    if (a == 0) {
        printf("\033[1;31mЦе не є квадратним рівнянням. Рівняння лінійне.\n");
    } else if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("\033[1;34mРівняння має два корені: x1 = %lf та x2 = %lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("\033[1;34mРівняння має один корінь: x = %lf\n", root);
    } else {
        printf("\033[1;31mРівняння не має дійсних коренів.\n");
    }

}
