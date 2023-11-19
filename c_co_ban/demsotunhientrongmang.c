#include<stdio.h>
int a[] = { 1,4,5,3,5,6,1,3,4,5,2,6,6,7,4,5,7,8,9,0 };
int n;

void sapxepmang(int a[],int n) {
    int tam;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                // Hoan vi 2 so numbers[i] va numbers[j]
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

}
void demso(int a[], int n) {
    int x=0; 
    int dem=1;
    for (x = 0; x < n; x++) {
        if (a[x] == a[x + 1]) {
            dem++;
        }
        else {
            printf("ki tu %d co %d phan tu\n ", a[x], dem);
            dem = 1;
        }
    }
    

}
void main() {
    n = 20;
    for (int i = 0; i < n; i++) {
        printf("%d- ", a[i]);
    }
    sapxepmang(a,n);
    printf("\n------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d- ", a[i]);
    }
    printf("\n ket qua sau khi dem:\n");
    demso(a, n);

}