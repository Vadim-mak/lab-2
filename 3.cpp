3)	Организовать текстовый файл. Заменить в файле все маленькие латинские буквы на большие. (Создавая новый дополнительный файл)
#include <iostream>
#include <fstream>
#include <cctype> 

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream inputFile("input.txt");

    
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

   
    std::ofstream outputFile("output.txt");

   
    if (!outputFile.is_open()) {
        std::cerr << "Не удалось создать или открыть файл output.txt" << std::endl;
        return 1;
    }

    char ch;

   
    while (inputFile.get(ch)) {
        if (std::islower(ch)) {
            ch = std::toupper(ch);
        }

        outputFile << ch;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Замена успешно завершена. Результат записан в файл output.txt" << std::endl;

    return 0;
}
