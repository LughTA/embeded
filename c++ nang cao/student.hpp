/*
* File: main.c
* Author: Nguyen Thai Tuan Anh
* Date: 23/01/2024
* Description: header file for managing stdent main file
*/

#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

#include <iostream>
#include <string>

using namespace std;
/*
* Description: Defines a new type variable gender and studenrank
*/
typedef enum gender {
    male,
    female
}gender;

typedef enum studentRank {
    excellent,
    good,
    average,
    bad
}studentRank;
/*
* Description: Defines a new calss student containing information about: id, name, age, gender, score and menthod to get private property , edit value, and display 
*/
class student {
private:
    int id;
    string name;
    int age;
    gender st_gender;
    double math_sc;
    double physic_sc;
    double chemical_sc;

public:
    student(string _name, int _age, gender _st_gender, double _math_sc, double _physic_sc, double _chemical_sc) :
        name(_name), age(_age), st_gender(_st_gender), math_sc(_math_sc), physic_sc(_physic_sc), chemical_sc(_chemical_sc) {
        static int ID = 0000;
        id = ID;
        ID++;
    }

    int getid();
    void setname(string data);
    string getname();

    void setage(int data);
    int getage();

    void setgender(gender data);
    gender getgender();

    void setmathsc(double data);
    double getmathsc();

    void setphysicsc(double data);
    double getphysicsc();

    void setchemicalsc(double data);
    double getchemicalsc();

    double getaverage();
   
    studentRank getrank();
    
    void edit(string sName, int iAge, float fMath, float fPhysics, float fChemistry);
    
    void display() const;

  
};


#endif // _STUDENT_HPP_
