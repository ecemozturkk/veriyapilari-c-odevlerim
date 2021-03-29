#include <stdio.h>
#include <string.h>
 
void kontrolPalindrom(char [], int);
 
int main()
{
    char metin[25];
    printf("\n\n Özyineleme : Palindrom mu değil mi? :\n");
    printf("----------------------------------------------------------\n");
 
    printf(" Bir metin giriniz : ");
    scanf("%s", metin);
    kontrolPalindrom(metin, 0);
 
    return 0;
}
 
void kontrolPalindrom(char metin[], int index)
{
    int len = strlen(metin) - (index + 1);
    if (metin[index] == metin[len])
    {
        if (index + 1 == len || index == len)
        {
            printf("\nEvet, palindromdur. \n\n");
            return;
        }
        kontrolPalindrom(metin, index + 1);
    }
    else
    {
        printf("\nHayır, palindrom değildir.\n\n");
    }
}
