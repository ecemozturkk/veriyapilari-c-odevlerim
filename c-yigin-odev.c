#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>

struct Yigin {
    int bas;
    int kapasite;
    char* dizi;
};
 
struct Yigin* yarat(int kapasite)
{
    struct Yigin* yigin = (struct Yigin*)malloc(sizeof(struct Yigin));
    yigin->kapasite = kapasite;
    yigin->bas = -1;
    yigin->dizi = (char*)malloc(yigin->kapasite * sizeof(char));
    return yigin;
}

int bosMu(struct Yigin* yigin)
{
    return yigin->bas == -1;
}

void ekle(struct Yigin* yigin, char item)
{
    yigin->dizi[++yigin->bas] = item;
}
 
char cikart(struct Yigin* yigin)
{
    return yigin->dizi[yigin->bas--];
}

bool balanced(const char p[], size_t n) {
	int i;
	struct Yigin *yigin = yarat(n);

	for (i=0; i<n; i++) {

		if (p[i] == '(' || p[i] == '{')
			ekle(yigin, p[i]);
		else if (p[i] == ')') {
			if (bosMu(yigin))
				return false;

			if (cikart(yigin) != '(')
				return false;
		} else {
			if (bosMu(yigin))
				return false;

			if (cikart(yigin) != '{')
				return false;	
		}

	}
	if (bosMu(yigin))
		return true;

	return false;
}

int main(){
	char s[1000];
	scanf("%s",s);

	if (balanced(s,strlen(s)))
		puts("YES");
	else
		puts("NO");

}