/*
* File: 
* Author: Nguyen Thai Tuan Anh
* Date: 23/01/2024
* Description: header file for managing stdent main file
*/

#ifndef _STUDENT_OPERATOR_HPP_
#define _STUDENT_OPERATOR_HPP_
#include "student.hpp"
#include<list>

void addMember(list<student> &info);
void displayMembers(const list<student>&info);

#endif _STUDENT_OPERATOR_HPP_