#include<stdio.h>
void carpanlar( int sayi);
 
int main( )
{
        int sayi;
        printf("Bir sayi giriniz : ");
        scanf("%d", &sayi);
        carpanlar(sayi);
 
        return 0;
 
}

void carpanlar( int sayi)
{
        int i = 2;
        if( sayi == 1 )
                return;
        while( sayi%i != 0 )
                i++;
        printf("%d ", i);
        carpanlar(sayi/i);
}
