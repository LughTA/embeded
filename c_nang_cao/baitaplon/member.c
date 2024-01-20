/*
* File: member.c
* Author: Nguyen Thai Tuan Anh
* Date: 20/01/2024
* Description: Implementation file for the apartment management program's member-related functions.
*/

#include "D:\program\c\final1\member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Description: Creates and returns a new MemberNode with the given Member data.
* Input:
*   - member: Member data to be stored in the node
* Output:
*   - Returns a pointer to the newly created MemberNode.
*/
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
* Description: Adds a new member to the specified file by appending the member's information to the end of the file.
* Input:
*   - filename: The name of the file to which the member information will be added.
*   - member: The Member data to be added.
* Output: None
*/
void addMember(const char* filename, Member member) {
    FILE* file = fopen(filename, "a");

    if (file == NULL) {
        perror("Unable to open CSV file");
        return;
    }

    fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);
}

/*
* Description: Displays the list of members stored in the specified file.
* Input:
*   - filename: The name of the file from which member information will be displayed.
* Output: None
*/
void displayMembers(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open CSV file");
        return;
    }

    printf("List of Members:\n");
    printf("UID\t\tRoom\tName\t\tLicense Plate\n");

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);
}

/*
* Description: Searches for a member in the specified file by UID.
* Input:
*   - member: The Member data to be searched.
*   - uid: The UID (Unique Identifier) to search for.
* Output:
*   - Returns 1 if the member with the specified UID is found; otherwise, returns 0.
*/
int searchByUID(const Member* member, const char* uid) {
    return strcmp(member->uid, uid) == 0 ? 1 : 0;
}

/*
* Description: Searches for a member in the specified file by license plate.
* Input:
*   - member: The Member data to be searched.
*   - licensePlate: The license plate number to search for.
* Output:
*   - Returns 1 if the member with the specified license plate is found; otherwise, returns 0.
*/
int searchByLicensePlate(const Member* member, const char* licensePlate) {
    return strcmp(member->licensePlate, licensePlate) == 0 ? 1 : 0;
}

/*
* Description: Deletes a member with the specified UID from the specified file.
* Input:
*   - filename: The name of the file from which the member will be deleted.
*   - uid: The UID (Unique Identifier) of the member to be deleted.
* Output: None
*/
void deleteMember(const char* filename, const char* uid) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening CSV file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char tempUID[20];
        sscanf(line, "%[^,],", tempUID);

        if (strcmp(tempUID, uid) != 0) {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.csv", filename);
}

/*
* Description: Edits the information of a member with the specified UID in the specified file.
* Input:
*   - filename: The name of the file in which the member's information will be edited.
*   - updatedMember: The updated Member data.
* Output: None
*/
void editMember(const char* filename, Member updatedMember) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening CSV file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char tempUID[20];
        sscanf(line, "%[^,],", tempUID);

        if (strcmp(tempUID, updatedMember.uid) != 0) {
            fprintf(tempFile, "%s", line);
        }
        else {
            fprintf(tempFile, "%s,%s,%s,%s\n", updatedMember.uid, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.csv", filename);
}

/*
* Description: Searches for a member in the specified file based on a search value using a specified search function.
* Input:
*   - filename: The name of the file in which the search will be performed.
*   - searchValue: The value to search for.
*   - searchFunc: A function pointer to the search function (searchByUID or searchByLicensePlate).
* Output:
*   - Returns 1 if the member with the specified search value is found; otherwise, returns 0.
*/
int searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*)) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open CSV file");
        return -1;
    }

    Member member;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%[^,],%[^,],%s", member.uid, member.roomNumber, member.name, member.licensePlate);

        if (searchFunc(&member, searchValue) == 1) {
            printf("Member Information:\n");
            printf("UID: %s\n", member.uid);
            printf("Room: %s\n", member.roomNumber);
            printf("Name: %s\n", member.name);
            printf("License Plate: %s\n", member.licensePlate);
            fclose(file);
            return 1;
        }
    }

    printf("Member not found with value: %s\n", searchValue);
    fclose(file);
    return 0;
}
