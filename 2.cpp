2)	Дано 2 файла вещественных чисел а1.txt и а2.txt. Найти сумму положительных элементов в двух файлов.
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "ru");
   
    std::ifstream inputFile1("a1.txt");


    if (!inputFile1.is_open()) {
        std::cerr << "Не удалось открыть файл a1.txt" << std::endl;
        return 1;
    }

    std::ifstream inputFile2("a2.txt");

    if (!inputFile2.is_open()) {
        std::cerr << "Не удалось открыть файл a2.txt" << std::endl;
        return 1;
    }

    double number;
    double sum = 0;

    while (inputFile1 >> number) {
        if (number > 0) {
            sum += number;
        }
    }

    while (inputFile2 >> number) {
        if (number > 0) {
            sum += number;
        }
    }

    inputFile1.close();
    inputFile2.close();

    std::cout << "Сумма положительных элементов в двух файлах: " << sum << std::endl;

    return 0;
}
