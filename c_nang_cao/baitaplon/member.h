/*
* File: member.h
* Author:Nguyen Thai Tuan Anh
* Date: 20/1/2024
* Description: libary for file main.c 
*/


#ifndef MEMBER_H
#define MEMBER_H
/*
* Description: Defines a data structure (struct) named Member, containing information about the member, including uid, roomNumber, name, and licensePlate.
*/
typedef struct {
    char uid[20];
    char roomNumber[10];
    char name[50];
    char licensePlate[20];
} Member;
/*
* Description: Defines a linked list node structure (struct) named MemberNode, representing a node in the linked list of members.
*/
typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

MemberNode* createMemberNode(Member member);

void addMember(const char* filename, Member member);

void displayMembers(const char* filename);

int searchByUID(const Member* member, const char* uid);

int searchByLicensePlate(const Member* member, const char* licensePlate);

void deleteMember(const char* filename, const char* uid);

void editMember(const char* filename, Member updatedMember);

int searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));

#endif
#pragma once
