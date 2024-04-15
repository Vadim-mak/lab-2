4)	Организовать файл целых чисел. В новый файл записать элементы файла занимающие нечётные позиции, в другой новый файл элементы файла занимающие чётные позиции.
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream inputFile("input.txt");


    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int number;

    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    std::ofstream oddFile("odd_numbers.txt");

    std::ofstream evenFile("even_numbers.txt");

    if (!oddFile.is_open() || !evenFile.is_open()) {
        std::cerr << "Не удалось создать или открыть файлы для записи" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i % 2 == 0) {
            evenFile << numbers[i] << std::endl;
        }
        else {
            oddFile << numbers[i] << std::endl;
        }
    }

    oddFile.close();
    evenFile.close();

    std::cout << "Элементы файла, занимающие нечётные позиции, записаны в файл odd_numbers.txt" << std::endl;
    std::cout << "Элементы файла, занимающие чётные позиции, записаны в файл even_numbers.txt" << std::endl;

    return 0;
}
