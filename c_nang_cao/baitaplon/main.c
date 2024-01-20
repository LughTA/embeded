/*
* File: main.c
* Author: Nguyen Thai Tuan Anh
* Date: 20/01/2024
* Description: Main program file for managing apartment members
*/

#include "D:\program\c_vscode\member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

#define add_member 0
#define delete_member 1
#define find_UID_member 2
#define find_licensePlates_member 3
#define update_member 4
#define out 5

int main() {
    int choice;
    char searchValue[20];

    do {
        printf("\nMenu:\n");
        printf("0 - Add member\n");
        printf("1 - Delete member\n");
        printf("2 - Search by UID\n");
        printf("3 - Search by license plate\n");
        printf("4 - Update member\n");
        printf("5 - Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
        case add_member: {
            Member newMember;
            printf("Enter information for the new member:\n");
            printf("UID: ");
            scanf("%s", newMember.uid);


            printf("Room Number: ");
            fflush(stdin);
            fgets(newMember.roomNumber, sizeof(newMember.roomNumber), stdin);
            newMember.roomNumber[strcspn(newMember.roomNumber, "\n")] = '\0';

            printf("Name: ");
            fflush(stdin);
            fgets(newMember.name, sizeof(newMember.name), stdin);
            newMember.name[strcspn(newMember.name, "\n")] = '\0';

            printf("License Plate: ");
            fflush(stdin);
            fgets(newMember.licensePlate, sizeof(newMember.licensePlate), stdin);
            newMember.licensePlate[strcspn(newMember.licensePlate, "\n")] = '\0';

            addMember("10000_Members.CSV", newMember);
            printf("Member has been added.\n");
            break;
        }
        case delete_member: {
            char deleteUID[20];
            printf("Enter the UID of the member to delete: ");
            fflush(stdin);
            fgets(deleteUID, sizeof(deleteUID), stdin);
            deleteUID[strcspn(deleteUID, "\n")] = '\0';
            deleteMember("10000_Members.CSV", deleteUID);
            printf("Member has been deleted.\n");
            break;
        }
        case find_UID_member: {
            printf("Enter the UID to search: ");
            fflush(stdin);
            fgets(searchValue, sizeof(searchValue), stdin);
            searchValue[strcspn(searchValue, "\n")] = '\0';
            searchMember("10000_Members.CSV", searchValue, searchByUID);
            break;
        }
        case find_licensePlates_member: {
            printf("Enter the license plate to search: ");

            fflush(stdin);
            fgets(searchValue, sizeof(searchValue), stdin);
            searchValue[strcspn(searchValue, "\n")] = '\0';
            searchMember("10000_Members.CSV", searchValue, searchByLicensePlate);
            break;
        }
        case update_member: {
            Member updatedMember;
            printf("Enter the UID of the member to update: ");
            scanf("%s", updatedMember.uid);

            printf("Enter the new information:\n");
            printf("Room Number: ");
            fflush(stdin);
            fgets(updatedMember.roomNumber, sizeof(updatedMember.roomNumber), stdin);
            updatedMember.roomNumber[strcspn(updatedMember.roomNumber, "\n")] = '\0';

            printf("Name: ");
            fflush(stdin);
            fgets(updatedMember.name, sizeof(updatedMember.name), stdin);
            updatedMember.name[strcspn(updatedMember.name, "\n")] = '\0';

            printf("License Plate: ");
            fflush(stdin);
            fgets(updatedMember.licensePlate, sizeof(updatedMember.licensePlate), stdin);
            updatedMember.licensePlate[strcspn(updatedMember.licensePlate, "\n")] = '\0';

            editMember("10000_Members.CSV", updatedMember);
            printf("Member information has been updated.\n");
            break;
        }
        case out:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 5);

    return 0;
}
