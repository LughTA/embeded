/*
* File: 
* Author: Nguyen Thai Tuan Anh
* Date: 23/01/2024
* Description: header file for managing stdent main file containing all fution for every option
*/

#ifndef _STUDENT_OPERATOR_HPP_
#define _STUDENT_OPERATOR_HPP_
#include "student.hpp"
#include<list>
#include <fstream>
/*
* Description: Defines funtion for all option in main program 
*/
void addMember(list<student> &info);

void displayMembers(const list<student>&info);

void editstudent(list<student>& info);

void remove(list<student>& info);

void findst( list<student>& info);

void saveToCSV( list<student>& info, const string& filename);

bool sortName(string arr1, string arr2);

void arrangeName(list<student>& info);

void arrangeScore(list<student>& info);

void arrangechem(list<student>& info);

void arrangephysic(list<student>& info);

void arrangemath(list<student>& info);

#endif _STUDENT_OPERATOR_HPP_