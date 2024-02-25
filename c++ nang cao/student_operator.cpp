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

void editstudent(list<student>& info) {
    int Id;
    string name;
    int age;
    float math;
    float physics;
    float chemistry;

    cout << "Nhap ID sinh vien can thay doi: ";
    cin >> Id;
    cin.ignore();  // Clear newline character from the input buffer

    bool found = false;
    for (auto& student : info) {
        if (student.getid() == Id) {
            found = true;
            cout << "Da tim thay sinh vien co ID : " << Id << endl;
            student.display();
            cout << "Nhap thong tin sinh vien thay doi:" << endl;
            cout << "Ho & ten  : "; getline(cin, name);
            cout << "Tuoi : "; cin >> age;
            do {
                cout << "Toan : ";
                cin >> math;
            } while (math > 10 || math < 0);
            do {
                cout << "Ly   : ";
                cin >> physics;
            } while (physics > 10 || physics < 0);
            do {
                cout << "Hoa  : ";
                cin >> chemistry;
            } while (chemistry > 10 || chemistry < 0);

            student.edit(name, age, math, physics, chemistry);
            student.getaverage();
            student.getrank();
            cout << "Da thay doi thong tin sinh vien" << endl;
            break;  // Exit the loop since student is found
        }
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co ID: " << Id << endl;
    }
}

void remove(list<student>& info) {
    int Id;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> Id;

    auto i = info.begin();
    while (i != info.end()) {
        if (i->getid() == Id) {
            i = info.erase(i);  
            cout << "Da xoa sinh vien co ID: " << Id << endl;
            return;
        }
        else {
            ++i;
        }
    }

    cout << "Khong tim thay sinh vien co ID: " << Id << endl;
}

void findst(list<student>& info)
{
     int Id;
    cout << "Nhap ID sinh vien can tim: ";
    cin >> Id;

    auto i = info.begin();
    while (i != info.end()) {
        if (i->getid() == Id) {
            cout << "thong tin sinh vien co ID: " << Id << endl;
            i->display();
            return;
        }
        else {
            ++i;
        }
    }

    cout << "Khong tim thay sinh vien co ID: " << Id << endl;
}

bool sortName(string arr1, string arr2)
{
    string::iterator it1 = arr1.begin();
    string::iterator it2 = arr2.begin();
    while (it1 != arr1.end()) {
        if (*it1 == *it2) {
            it1++;
            it2++;
            continue;
        }
        else if (*it1 > *it2) return true;
        else return false;
    }
    return false;
}

void arrangeName(list<student>& info) {
    for (auto it1 = info.begin(); it1 != std::prev(info.end()); ++it1) {
        for (auto it2 = std::next(it1); it2 != info.end(); ++it2) {
            if (sortName(it1->getname(), it2->getname())) {
                swap(*it1, *it2);
            }
        }
    }
}

void arrangeScore(list<student>& info) {
    for (auto it1 = info.begin(); it1 != std::prev(info.end()); ++it1) {
        for (auto it2 = std::next(it1); it2 != info.end(); ++it2) {
            if (it1->getaverage() > it2->getaverage()) {
                std::swap(*it1, *it2);
            }
        }
    }
 
}

void arrangemath(list<student>& info) {
    for (auto it1 = info.begin(); it1 != std::prev(info.end()); ++it1) {
        for (auto it2 = std::next(it1); it2 != info.end(); ++it2) {
            if (it1->getmathsc() > it2->getmathsc()) {
                std::swap(*it1, *it2);
            }
        }
    }

}

void arrangephysic(list<student>& info) {
    for (auto it1 = info.begin(); it1 != std::prev(info.end()); ++it1) {
        for (auto it2 = std::next(it1); it2 != info.end(); ++it2) {
            if (it1->getphysicsc() > it2->getphysicsc()) {
                std::swap(*it1, *it2);
            }
        }
    }

}

void arrangechem(list<student>& info) {
    for (auto it1 = info.begin(); it1 != std::prev(info.end()); ++it1) {
        for (auto it2 = std::next(it1); it2 != info.end(); ++it2) {
            if (it1->getchemicalsc() > it2->getchemicalsc()) {
                std::swap(*it1, *it2);
            }
        }
    }

}
void saveToCSV( list<student>& info, const string& filename)
{
    std::ofstream file(filename);

    file << "ID,Name\n";

    for (auto& student : info) {
        file << student.getid() << "," << student.getname() << "\n";
    }

    std::cout << "Da luu vao file " << filename << std::endl;
}


