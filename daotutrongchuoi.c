#include <stdio.h>
#include <string.h>

// Hàm đảo ngược thứ tự các từ trong dãy
void daoNguocCacTu(char *day) {
    int doDai = strlen(day);
    int end = doDai - 1;

    // Tìm vị trí khoảng trắng cuối cùng
    while (end >= 0 && day[end] == ' ') {
        end--;
    }
    
    while (end >= 0) {
        // Tìm vị trí của khoảng trắng trước từ
        int start = end;
        while (start >= 0 && day[start] != ' ') {
            start--;
        }

        // In từ đó
        for (int i = start + 1; i <= end; i++) {
            printf("%c", day[i]);
        }

        // Nếu không phải là từ đầu tiên, in một dấu cách
        if (start >= 0) {
            printf(" ");
        }

        // Tiếp tục với từ trước đó
        end = start - 1;
    }

    printf("\n");
}

int main() {
    char day[] = "oi con ga ma di an dem";
    printf("Day ban dau: %s\n", day);

    printf("Day sau khi dao nguoc cac tu: ");
    daoNguocCacTu(day);

    return 0;
}
