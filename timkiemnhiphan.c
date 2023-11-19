#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//tạo 1 mảng 100 phan tu truoc
int random[100];
int trai;
int phai;
int giua;
void taomang() {
    // Thiết lập seed cho hàm rand() dựa trên thời gian hiện tại
    srand(time(NULL));

    // Tạo 100 số ngẫu nhiên có 5 chữ số và in chúng ra màn hình
    for (int i = 0; i < 100; i++) {
        random[i] = rand() % 90000 + 10000; // Sinh số ngẫu nhiên từ 10000 đến 99999
        printf("%d-", random[i]);
    }
}

void sapxepmang(int random[]) {
    int tam;
    for (int i = 0; i < 100 - 1; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (random[i] > random[j]) {
                // Hoan vi 2 so random[i] va random[j]
                tam = random[i];
                random[i] = random[j];
                random[j] = tam;
            }
        }
    }
}

int timkiem(int random[],int check) {
    
    giua = trai + ((phai - trai) / 2);
    if (((phai - trai) / 2) < 1) {
        return 0;
    }
    else {
            if (random[giua] == check) {
                return 1;
            }
            else {
                if (random[giua] < check) {
                    trai = giua;
                    timkiem(random, check);
                }
                else {
                    phai = giua;
                    timkiem(random, check);
                }
            }
    }
    
}
int main() {
    int check;
    //tao mang ngau nhien
    taomang();
    printf("\n------------------------------------------------------------\n");
    sapxepmang(random);
    //in gia tri trong mang sau khi da sap xep 
    for (int i = 0; i < 100; i++) {
        printf("%d- ", random[i]);
    }
    printf("\n------------------------------------------------------------\n");
    //tim gia tri 
    trai = 0;
    phai = 99;
    printf("\nnhap so can tim vo\n");
    scanf_s("%d", &check);
    int ketqua = timkiem(random, check);
    printf("\nketqua:%d\n",ketqua);
    if (ketqua == 1) {
        printf("Tim thay %d\n", check);
    }
    else {
        printf("Khong tim thay\n");
    }
    
    return 0;
}
