#include <stdio.h>
#include <stdlib.h>

struct dugum {
 int veri;
 struct dugum *sonraki;
}*head;

void ListeOlustur(int n)
{
 struct dugum *dugumYeni, *temp;
 int veri, i;

 head = (struct dugum *)malloc(sizeof(struct dugum));

 if(head == NULL)
 {
 printf("Bellek ayrılamadı");
 }
 else
 {
 printf("\nDugum 1 in verilerini girin : ");
 scanf("%d", &veri);
 head->veri = veri;
 head->sonraki = NULL;
 temp = head;
 for(i=2; i<=n; i++)
 {
 dugumYeni = (struct dugum *)malloc(sizeof(struct dugum));
 if(dugumYeni == NULL)
 {
 printf("Bellek ayrılamadı");
 break;
 }
 else
 {
 printf("\nDugum verilerini girin %d: ", i);
 scanf("%d", &veri);
 dugumYeni->veri = veri;
 dugumYeni->sonraki = NULL;
 temp->sonraki = dugumYeni;
 temp = temp->sonraki;
 }
 }
 }
}

int ListeUzunlugu(struct dugum * head)
{
 int count = 0;
 if(head == NULL)
 {
 return 0;
 }
 return 1 + ListeUzunlugu(head -> sonraki);
}

void ListeGoruntule()
{
 struct dugum *temp;
 if(head == NULL)
 {
 printf("List is empty.\n");
 }
 else
 {
 temp = head;
 while(temp != NULL)
 {
 printf("%d\t", temp->veri);
 temp = temp->sonraki;
 }
 printf("\n");
 }
}

int main()
{
 int n, veri;
 printf("\nToplam dugum sayisini girin: ");
 scanf("%d", &n);
 ListeOlustur(n);
 printf("\nListe \n");
 ListeGoruntule();
 printf("\nBagli liste'nin uzunlugu : %d ",ListeUzunlugu(head));
 return 0;
}
