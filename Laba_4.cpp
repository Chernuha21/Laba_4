#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string fullName;
    string groupNumber;
    int birthYear;
};

// Функція для порівняння студентів за номером групи
bool compareByGroup(const Student& a, const Student& b) {
    return a.groupNumber < b.groupNumber;
}

int main() {
    const int SIZE = 10;
    Student students[SIZE];

    // Введення даних
    for (int i = 0; i < SIZE; ++i) {
        cout << "Name " << (i + 1) << ": ";
        cin.ignore(); // Ігноруємо залишки буфера
        getline(cin, students[i].fullName);
        cout << "Group " << (i + 1) << ": ";
        cin >> students[i].groupNumber;
        cout << "Date " << (i + 1) << ": ";
        cin >> students[i].birthYear;
    }

    // Сортування за номером групи
    sort(students, students + SIZE, compareByGroup);

    // Введення року народження для пошуку
    int searchYear;
    cout << "Search by date: ";
    cin >> searchYear;

    // Виведення студентів з заданим роком народження
    bool found = false;
    cout << "Student result " << searchYear << ":" << endl;
    for (int i = 0; i < SIZE; ++i) {
        if (students[i].birthYear == searchYear) {
            cout << "Name: " << students[i].fullName << ", Group: " << students[i].groupNumber << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Студентів з роком народження " << searchYear << " не знайдено." << endl;
    }

    return 0;
}
