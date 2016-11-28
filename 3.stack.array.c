//TITLE  : 3.Stack Operations
//DATE   : 12/02/2014
//AUTHOR : Athira Unni & Karpagam.B

#include<stdio.h>
void push();
void pop();
void display();

#define MAX 3
int top=-1;
int stack[MAX];

main()
{
	int choice;
	char ch;
	do
	{
		printf("\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY");
		printf("\n\tEnter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				printf("\n\n\tInvalid Choice !!!");
				break;
		}
		printf("\n\n\tDo u want to continue (y/n)? ");
		scanf(" %c",&ch);
	}while(ch=='y' || ch=='Y');
	printf("\n\n");
}	

void push()
{
	int item;
	if(top==MAX-1)
	{
		printf("\n\tStack Overflow");
		return;
	}
	printf("\n\tEnter the element to push : ");
	scanf("%d",&item);
	top+=1;
	stack[top]=item;	
}
void pop()
{
	
	if(top==-1)
	{
		printf("\n\tStack Empty");
		return;
	}
	printf("\n\tThe poped item is : %d",stack[top]);
	top=top-1;
	
}
void display()
{
	int i;
	//printf("\n\tTop = %d",top);
	if(top==-1)
	{
		printf("\n\tStack is empty");
		return;
	}
	printf("\n\tThe Stack elements are : ");
	for(i=top;i>=0;i--)
		printf("%d\t",stack[i]);
}
	
	
	
	
	
	
	
	
	
	
	
	
