5)	«Человек»: фамилия; имя; отчество; пол; национальность; рост; вес; дата рождения (год, месяц число); номер телефона; домашний адрес (почтовый индекс, страна, область, район, город, улица, дом, квартира). Вывести сведения о самом молодом человеке.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

struct Person {
    std::string surname;
    std::string name;
    std::string patronymic;
    char gender;
    std::string nationality;
    int height;
    int weight;
    int yearOfBirth;
    int monthOfBirth;
    int dayOfBirth;
    std::string phoneNumber;
    std::string postalCode;
    std::string country;
    std::string region;
    std::string district;
    std::string city;
    std::string street;
    std::string house;
    std::string apartment;
};


bool isYounger(const Person& person1, const Person& person2) {
    if (person1.yearOfBirth != person2.yearOfBirth) {
        return person1.yearOfBirth > person2.yearOfBirth;
    }
    if (person1.monthOfBirth != person2.monthOfBirth) {
        return person1.monthOfBirth > person2.monthOfBirth;
    }
    return person1.dayOfBirth > person2.dayOfBirth;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<Person> people;

 
    people.push_back({ "Иванов", "Иван", "Иванович", 'M', "русский", 180, 80, 1990, 5, 15, "+7 123-456-789", "123456", "Россия", "Московская", "Московский", "Москва", "Ленина", "1", "2" });
    people.push_back({ "Петрова", "Мария", "Сергеевна", 'Ж', "русская", 165, 55, 1995, 10, 20, "+7 987-654-321", "654321", "Россия", "Московская", "Московский", "Москва", "Пушкина", "5", "10" });

   
    auto youngestPerson = std::min_element(people.begin(), people.end(), isYounger);

    std::cout << "Сведения о самом молодом человеке:" << std::endl;
    std::cout << "Фамилия: " << youngestPerson->surname << std::endl;
    std::cout << "Имя: " << youngestPerson->name << std::endl;
    std::cout << "Отчество: " << youngestPerson->patronymic << std::endl;
    std::cout << "Пол: " << youngestPerson->gender << std::endl;
    std::cout << "Национальность: " << youngestPerson->nationality << std::endl;
    std::cout << "Дата рождения: " << youngestPerson->dayOfBirth << "." << youngestPerson->monthOfBirth << "." << youngestPerson->yearOfBirth << std::endl;
    std::cout << "Номер телефона: " << youngestPerson->phoneNumber << std::endl;
    std::cout << "Домашний адрес: " << youngestPerson->postalCode << ", " << youngestPerson->country << ", " << youngestPerson->region << ", " << youngestPerson->district << ", " << youngestPerson->city << ", " << youngestPerson->street << ", " << youngestPerson->house << ", " << youngestPerson->apartment << std::endl;

    return 0;
}
