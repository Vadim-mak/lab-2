7)	В первом файле хранится k матриц размерности m x n, во втором - l матриц размерности m x n. Те матрицы из первого файла, у которых a00 = 0 , перенести в конец второго файла. Вывести на экран содержимое первого и второго файлов.
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

std::vector<std::vector<int>> readMatrixFromFile(const std::string& filename, int m, int n) {
    std::ifstream file(filename);
    std::vector<std::vector<int>> matrix;

    if (file.is_open()) {
        for (int i = 0; i < m; ++i) {
            std::vector<int> row;
            for (int j = 0; j < n; ++j) {
                int value;
                if (!(file >> value)) {
                    std::cerr << "Ошибка чтения файла " << filename << std::endl;
                    return matrix;
                }
                row.push_back(value);
            }
            matrix.push_back(row);
        }
        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
    }

    return matrix;
}

void writeMatrixToFile(const std::string& filename, const std::vector<std::vector<int>>& matrix) {
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {
        for (const auto& row : matrix) {
            for (int value : row) {
                file << std::setw(4) << value << " ";
            }
            file << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    const int m = 3; 
    const int n = 3;

    std::vector<std::vector<int>> firstFileMatrix = readMatrixFromFile("first_file.txt", m, n);
    std::vector<std::vector<int>> secondFileMatrix = readMatrixFromFile("second_file.txt", m, n);

    for (auto it = firstFileMatrix.begin(); it != firstFileMatrix.end();) {
        if ((*it)[0] == 0) {
            secondFileMatrix.push_back(*it);
            it = firstFileMatrix.erase(it);
        }
        else {
            ++it;
        }
    }

    std::cout << "Содержимое первого файла:" << std::endl;
    for (const auto& row : firstFileMatrix) {
        for (int value : row) {
            std::cout << std::setw(4) << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Содержимое второго файла после перемещения матриц:" << std::endl;
    for (const auto& row : secondFileMatrix) {
        for (int value : row) {
            std::cout << std::setw(4) << value << " ";
        }
        std::cout << std::endl;
    }

    writeMatrixToFile("first_file.txt", firstFileMatrix);
    writeMatrixToFile("second_file.txt", secondFileMatrix);

    return 0;
}
