8)	Создать бинарный файл со списком о студентах: − фамилия и инициалы студентов; − номер группы; − успеваемость (массив из трех дисциплин по 100-бальной систе-ме); − размер стипендии. Вывести список студентов, имеющих по всем предметам положительныеоценки и распечатать все сведения о них.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int NUM_SUBJECTS = 3;
const int NUM_STUDENTS = 3;

struct Student {
    std::string name;
    std::string groupNumber; 
    int marks[NUM_SUBJECTS]; 
    float scholarship; 
};

void writeStudentsToFile(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename, std::ios::binary);

    if (file.is_open()) {
        for (const auto& student : students) {
            file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        }
        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
    }
}

std::vector<Student> readStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename, std::ios::binary);

    if (file.is_open()) {
        while (!file.eof()) {
            Student student;
            file.read(reinterpret_cast<char*>(&student), sizeof(Student));
            students.push_back(student);
        }
        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
    }

    return students;
}

void printStudentsWithPositiveMarks(const std::vector<Student>& students) {
    std::cout << "Студенты с положительными оценками по всем предметам:" << std::endl;
    for (const auto& student : students) {
        bool allPositive = true;
        for (int i = 0; i < NUM_SUBJECTS; ++i) {
            if (student.marks[i] <= 0) {
                allPositive = false;
                break;
            }
        }
        if (allPositive) {
            std::cout << "ФИО: " << student.name << ", Группа: " << student.groupNumber
                << ", Стипендия: " << student.scholarship << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<Student> students = {
        {"Иванов И.И.", "Группа 1", {90, 85, 95}, 1500.0},
        {"Петров П.П.", "Группа 2", {80, 75, 85}, 1600.0},
        {"Сидоров С.С.", "Группа 1", {70, 65, 75}, 1700.0}
    };

    writeStudentsToFile("students.bin", students);

    std::vector<Student> studentsFromFile = readStudentsFromFile("students.bin");

    printStudentsWithPositiveMarks(studentsFromFile);

    return 0;
}
