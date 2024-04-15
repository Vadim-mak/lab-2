6)	Дан файл f, компоненты которого являются действительными числами. Найти произведение компонент файла.
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream inputFile("f.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл f.txt" << std::endl;
        return 1;
    }

    double number;
    double product = 1.0; 

    while (inputFile >> number) {
        product *= number;
    }

    inputFile.close();

    std::cout << "Произведение компонент файла: " << std::fixed << std::setprecision(2) << product << std::endl;

    return 0;
}
