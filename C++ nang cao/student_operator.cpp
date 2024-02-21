/*
* File:
* Author: Nguyen Thai Tuan Anh
* Date: 23/01/2024
* Description: header file for managing stdent main file
*/
#include "student_operator.hpp"
using namespace std;

void addMember(list<student>& info){
    string name;
    int age;
    int genderInput;
    double mathScore;
    double physicScore;
    double chemicalScore;

    cout << "Nhap ten : ";
    cin >> name;

    cout << "nhap tuoi: ";
    cin >> age;

    cout << "nhap gioi tinh (nam 0, nu 1) : ";
    std::cin >> genderInput;
    gender gender = (genderInput == 0) ? male : female;
    cout << "Nhap diem toan: ";
    cin >> mathScore;

    cout << "Nhap diem ly: ";
    cin >> physicScore;

    cout << "Nhap diem hoa: ";
    cin >> chemicalScore;

    info.push_back(student(name, age, gender, mathScore, physicScore, chemicalScore));
    
}

void displayMembers(const list<student>& info)
{
    for (const auto& student : info) {
        student.display();
    }
}



