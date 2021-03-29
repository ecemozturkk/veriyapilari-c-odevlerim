#include<stdio.h>
#include<string.h>

int queue[1000],rear=-1,front=-1,i;
char str[1000];

void insert(int c) {
    if (rear == 999)
    	return;

    if (front == - 1)
        front = 0;

    rear = rear + 1;
    queue[rear] = c;   
}

int delete() {
    if (front == - 1 || front > rear)
        return -1;
    
	int tmp = queue[front];
    front = front + 1;
    return tmp;
} 

int main(){
	scanf("%s",str);
	int n = strlen(str);
	
	for (i=0; i<n; i++){
		if (str[i] == '+')
			insert(-1);
		else if(str[i] == '-')
			insert(-2);
		else if (str[i] == '*')
			insert(-3);
		else if(str[i] == '/')
			insert(-4);
		else
			insert(str[i]-'0');
	}

	int c1 = delete();
	int c2 = delete();
	int c3 = delete();

	while (n>=3) {
		if (c1 < 0 && c2 >= 0 && c3 >= 0) {
			n-=2;
			if (c1 == -1)
				insert(c2+c3);
			else if (c1 == -2)
				insert(c2-c3);
			else if (c1 == -3)
				insert(c2*c3);
			else
				insert(c2/c3);

			if (n >= 3){
				c1 = delete();
				c2 = delete();
				c3 = delete();
			}
		} else {
			insert(c1);
			c1 = c2;
			c2 = c3;
			c3 = delete();
		}
		
	}
	printf("%d\n",delete());
}