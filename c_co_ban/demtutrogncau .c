
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*dem ki tu xuat hien trong xau*/
int kiemtra(char chuoi[], char mangtu[])
{
    int tam,i,j, dem = 0;
    for (i = 0; i <= strlen(chuoi);)
    {
        if (chuoi[i] == mangtu[0])
        {
            tam = i;
            for (j = 0; j <= strlen(mangtu); j++) {
                if (mangtu[j] == chuoi[i]) {
                    i++;
                }
                else  {
                    if ((i - tam) == strlen(mangtu)) {
                        dem++;
                    }
                    break;
                }
            }

        }
        else i++;
    }
    if (dem > 0)
    {
        printf("\nki tu %s trong chuoi xuat hien %d lan ", mangtu, dem);
    }
    if (dem == 0)
    {
        printf("\nki tu '%s' trong chuoi khong xuat hien ",mangtu);
    }
}
void tachChuoi(char chuoi[], char*** mangtu, int* soTu) {
    int i = 0;
    *soTu = 0;

    while (chuoi[i] != '\0') {
        // Bỏ qua khoảng trắng ở đầu chuỗi
        while (chuoi[i] == ' ') {
            i++;
        }

        // Bắt đầu từ vị trí hiện tại
        int start = i;

        // Di chuyển đến khi gặp khoảng trắng hoặc kết thúc chuỗi
        while (chuoi[i] != ' ' && chuoi[i] != '\0') {
            i++;
        }

        // Cấp phát bộ nhớ động cho từ và copy từ vị trí start đến vị trí i - 1
        int length = i - start;
        (*mangtu)[*soTu] = (char*)malloc((length + 1) * sizeof(char));
        for (int j = 0; j < length; j++) {
            (*mangtu)[*soTu][j] = chuoi[start + j];
        }
        (*mangtu)[*soTu][length] = '\0';
        (*soTu)++;
    }
}

void giaiPhongBoNho(char*** mangTu, int soTu) {
    for (int i = 0; i < soTu; i++) {
        free((*mangTu)[i]);
    }
    free(*mangTu);
}

int main()
{
    char chuoi[] = "mot hai mot ba hai hai ba hai ";
    char*** mangtu;
    int soTu;
    int dem = 0;

    mangtu = (char***)malloc(50 * sizeof(char**)); // Giả sử không quá 50 từ
    for (int i = 0; i < 50; i++) {
        mangtu[i] = 0;
    }
    tachChuoi(chuoi, &mangtu, &soTu);
    printf("chuoi vua nhap la : %s", chuoi);
    
    //kiemtra(chuoi,mangtu[0]);
     for (int y = 0; y < soTu; y++) {
        kiemtra(chuoi, mangtu[y]);
     }
  
    giaiPhongBoNho(&mangtu, soTu);
}