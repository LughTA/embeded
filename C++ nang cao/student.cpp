/*
* File: main.c
* Author: Nguyen Thai Tuan Anh
* Date: 23/01/2024
* Description: define funtion, menthor for studen.hpp file
*/
// student.cpp
#include "student.hpp"

int student::getid() {
    return id;
}

void student::setname(string data) {
    name = data;
}

string student::getname() {
    return name;
}

void student::setage(int data) {
    age = data;
}

int student::getage() {
    return age;
}

void student::setgender(gender data) {
    st_gender = data;
}

gender student::getgender() {
    return st_gender;
}

void student::setmathsc(double data) {
    math_sc = data;
}

double student::getmathsc() {
    return math_sc;
}

void student::setphysicsc(double data) {
    physic_sc = data;
}

double student::getphysicsc() {
    return physic_sc;
}

void student::setchemicalsc(double data) {
    chemical_sc = data;
}

double student::getchemicalsc() {
    return chemical_sc;
}

double student::getaverage() {
    return (math_sc + physic_sc + chemical_sc) / 3.0;
}

studentRank student::getrank() {
    double MediumScore = (math_sc + physic_sc + chemical_sc) / 3.0;
    if (MediumScore >= 8.5) return excellent;
    else if (MediumScore < 8.5 && MediumScore >= 6.5) return good;
    else if (MediumScore < 6.5 && MediumScore >= 5) return average;
    else return bad;
}

void student::display() const {
    cout << "Name: " << name << ", Age: " << age << ", Gender: " << st_gender << ", Math Score: " << math_sc << ", Physics Score: " << physic_sc << ", Chemical Score: " << chemical_sc <<endl;
}