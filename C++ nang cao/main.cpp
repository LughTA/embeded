/*
* File: main.c
* Author: Nguyen Thai Tuan Anh
* Date: 23/01/2024
* Description:  main file for student management program
*/
#include<iostream>
#include<string>
#include <cstdlib> 
#include"student.hpp"
#include "student_operator.hpp"
#include <list>
using namespace std;

void main(void) {

    list<student> danhsachsinhvien;

    int option;
    while (1)
    {
        system("cls");//WINDOWN
        // system("clear"); // Linux/Mac
        cout << "----------------Student__Management----------------" << endl;
        cout << "|               *QUAN LY SINH VIEN*               |" << endl;
        cout << "|>1. THEM SINH VIEN                               |" << endl;
        cout << "|>2. SUA THONG TIN SINH VIEN                      |" << endl;
        cout << "|>3. XOA SINH VIEN                                |" << endl;
        cout << "|>4. TIM KIEM SINH VIEN                           |" << endl;
        cout << "|>5. SAP XEP SINH VIEN                            |" << endl;
        cout << "|>6. HIEN THI DANH SACH SINH VIEN                 |" << endl;
        cout << "|>7. LUU DANH SACH VAO FILE 'DATABASE.CSV'        |" << endl;
        cout << "|>8. THOAT CHUONG TRINH                           |" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " => CHON CHUC NANG: ";
        cin >> option;
        cin.ignore();
        cout << "---------------------------------------------------" << endl;
        fflush(stdin);
        switch (option)
        {
        case 1:
            do
            {
                system("cls");//WINDOWN
                // system("clear"); // Linux/Mac
                option = 0;
                cout << "----------------Student__Management----------------" << endl;
                cout << "| *CHON CHUC NANG CHUONG TRINH:                   |" << endl;
                cout << "|>1. THEM MOT SINH VIEN                           |" << endl;
                cout << "|>2. THEM NHIEU SINH VIEN                         |" << endl;
                cout << "|>3. EXIT                                         |" << endl;
                cout << "|                                                 |" << endl;
                cout << "|                                                 |" << endl;
                cout << "|                                                 |" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << "   NHAP LUA CHON: ";
                cin >> option;
                cin.ignore();
                cout << "---------------------------------------------------" << endl;
                if (option == 1) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    cout << "----------------THEM_MOT_SINH_VIEN----------------" << endl;
                    addMember(danhsachsinhvien);
                    cout << "sinh vien da duoc them thanh cong!" << endl;
                    cout << "NHAP PHIM 0 DE THOAT :";
                    cin >> option;
                }
                else if (option == 2) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    int count = 0;
                    cout << "Nhap so luong sinh vien: ";
                    cin >> count;
                    cin.ignore();
                    for (int i = 0; i < count; i++)
                    {
                        system("cls");//WINDOWN
                        // system("clear"); // Linux/Mac
                        cout << "----------------THEM_NHIEU_SINH_VIEN----------------" << endl;
                        cout << "sinh vien thu " << i + 1 << endl;
                        addMember(danhsachsinhvien);
                        cout << "sinh vien da duoc them thanh cong!" << endl;
                        cout << "NHAP PHIM 0 DE THOAT :";
                        cin >> option;
                    }
                }
                else if (option == 3) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    break;
                }
               
            } while (option > 0 && option < 4);
            break;

        case 2:
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            cout << "----------------SUA_THONG_TIN_SINH_VIEN----------------" << endl;
            // HAM SUA THONG TIN
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            break;

        case 3:
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            cout << "----------------XOA_MOT_SINH_VIEN----------------" << endl;
            // HAM XOA SINH VIEN
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            break;
        case 4:
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            cout << "----------------TIM_KIEM_SINH_VIEN----------------" << endl;
            // HAM TIM KIEM
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            break;
        case 5:
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            cout << "----------------SAP_XEP_SINH_VIEN----------------" << endl;
            do
            {
                system("cls");//WINDOWN
                // system("clear"); // Linux/Mac
                option = 0;
                cout << "----------------SAP_XEP_SINH_VIEN------------------" << endl;
                cout << "| *CHON CHUC NANG CHUONG TRINH:                   |" << endl;
                cout << "|>1. SAP XEP THEO TEN                             |" << endl;
                cout << "|>2. SAP XEP THEO DIEM TRUNG BINH                 |" << endl;
                cout << "|>3. SAP XEP THEO DIEM TOAN                       |" << endl;
                cout << "|>4. SAP XEP THEO DIEM HOA                        |" << endl;
                cout << "|>5. SAP XEP THEO DIEM LY                         |" << endl;
                cout << "|>6. EXIT                                         |" << endl;
                cout << "|                                                 |" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << "   NHAP LUA CHON: ";
                cin >> option;
                cin.ignore();
                cout << "---------------------------------------------------" << endl;
                if (option == 1) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    cout << "----------------SAP XEP THEO TEN----------------" << endl;
                    // HAM SAP XEP THEO TEM
                    cout << "          --------------------------" << endl;
                    cout << "          | DA SAP XEP THANH CONG! |" << endl;
                    cout << "          --------------------------" << endl;
                    cout << "            NHAP PHIM *0* DE THOAT :";
                    cin >> option;
                    cin.ignore();
                }
                else if (option == 2) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    cout << "----------------SAP XEP THEO DIEM TRUNG BINH----------------" << endl;
                    // HAM SAP XEP THEO DIEM TRUNG BINH
                    cout << "          --------------------------" << endl;
                    cout << "          | DA SAP XEP THANH CONG! |" << endl;
                    cout << "          --------------------------" << endl;
                    cout << "            NHAP PHIM *0* DE THOAT :";
                    cin >> option;
                    cin.ignore();
                }
                else if (option == 3) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    cout << "----------------SAP XEP THEO DIEM TOAN----------------" << endl;
                    // HAM SAP XEP THEO TOAN 
                    cout << "          --------------------------" << endl;
                    cout << "          | DA SAP XEP THANH CONG! |" << endl;
                    cout << "          --------------------------" << endl;
                    cout << "            NHAP PHIM *0* DE THOAT :";
                    cin >> option;
                    cin.ignore();
                }
                else if (option == 4) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    cout << "----------------SAP XEP THEO DIEM HOA----------------" << endl;
                    // HAM SAP XEP THEO HOA 
                    cout << "          --------------------------" << endl;
                    cout << "          | DA SAP XEP THANH CONG! |" << endl;
                    cout << "          --------------------------" << endl;
                    cout << "            NHAP PHIM *0* DE THOAT :";
                    cin >> option;
                    cin.ignore();
                }
                else if (option == 5) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    cout << "----------------SAP XEP THEO DIEM LY----------------" << endl;
                    // HAM SAP XEP THEO DIEM LY
                    cout << "          --------------------------" << endl;
                    cout << "          | DA SAP XEP THANH CONG! |" << endl;
                    cout << "          --------------------------" << endl;
                    cout << "            NHAP PHIM *0* DE THOAT :";
                    cin >> option;
                    cin.ignore();
                }
                else if (option == 6) {
                    system("cls");//WINDOWN
                    // system("clear"); // Linux/Mac
                    break;
                }
                /* code */
            } while (option > 0 && option < 6);

            break;
        case 6:
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            cout << "----------------DANH_SACH_SINH_VIEN---------------------------------------------" << endl;
            displayMembers(danhsachsinhvien);
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "NHAP PHIM 0 DE THOAT :";
            cin >> option;
            break;
        case 7:
            system("cls");//WINDOWN
            // system("clear"); // Linux/Mac
            cout << "----------------LUU_FILE_DATABASE.CSV---------------------------------------------" << endl;
            // HAM LUU CSV
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "LUU XONG,NHAP PHIM 0 DE THOAT :";
            cin >> option;
            break;
        case 8:
            exit(1);
        default:
            break;
        }
        
    }
}


