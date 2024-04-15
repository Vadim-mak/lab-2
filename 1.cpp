1)	Дан файл вещественных чисел a.txt Найти количество отрицательных и
количество положительных элементов.
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "ru");
   
    std::ifstream inputFile("a.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл a.txt" << std::endl;
        return 1;
    }

    double number;
    int positiveCount = 0;
    int negativeCount = 0;


    while (inputFile >> number) {
        if (number > 0) {
            positiveCount++;
        }
        else if (number < 0) {
            negativeCount++;
        }
    }

    inputFile.close();

    std::cout << "Количество положительных элементов: " << positiveCount << std::endl;
    std::cout << "Количество отрицательных элементов: " << negativeCount << std::endl;

    return 0;
}
