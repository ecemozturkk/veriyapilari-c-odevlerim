#include <stdio.h>
 
int Asal_mi(int, int);
 
int main() {
    int sayi;
    printf("bir sayi giriniz: ");
    scanf("%d",&sayi);
    int sonuc = Asal_mi(sayi, sayi / 2);
    if (sonuc == 0)
        return 0;
        //printf("%d Asal sayi degildir. \n", sayi);
    else
        return 1;
        //printf("%d Asal sayidir. \n", sayi);
    return 0;
}
 
int Asal_mi(int x, int i) {
    if (x < 2)
        return 0;
    if (i == 1)
        return 1;
    if (x % i == 0)
        return 0;
    return Asal_mi(x, i - 1);
}
