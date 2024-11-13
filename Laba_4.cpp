#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string fullName;
    string groupNumber;
    int birthYear;
};

// ������� ��� ��������� �������� �� ������� �����
bool compareByGroup(const Student& a, const Student& b) {
    return a.groupNumber < b.groupNumber;
}

int main() {
    const int SIZE = 10;
    Student students[SIZE];

    // �������� �����
    for (int i = 0; i < SIZE; ++i) {
        cout << "Name " << (i + 1) << ": ";
        cin.ignore(); // �������� ������� ������
        getline(cin, students[i].fullName);
        cout << "Group " << (i + 1) << ": ";
        cin >> students[i].groupNumber;
        cout << "Date " << (i + 1) << ": ";
        cin >> students[i].birthYear;
    }

    // ���������� �� ������� �����
    sort(students, students + SIZE, compareByGroup);

    // �������� ���� ���������� ��� ������
    int searchYear;
    cout << "Search by date: ";
    cin >> searchYear;

    // ��������� �������� � ������� ����� ����������
    bool found = false;
    cout << "Student result " << searchYear << ":" << endl;
    for (int i = 0; i < SIZE; ++i) {
        if (students[i].birthYear == searchYear) {
            cout << "Name: " << students[i].fullName << ", Group: " << students[i].groupNumber << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "�������� � ����� ���������� " << searchYear << " �� ��������." << endl;
    }

    return 0;
}
