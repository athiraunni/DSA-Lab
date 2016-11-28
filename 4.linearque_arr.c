//TITLE  : 3.Stack Operations
//DATE   : 12/02/2014
//AUTHOR : Athira Unni & Karpagam.B

#include<stdio.h>
void insert();
void delete();
void display();
void search();

#define MAX 10
int front=-1;
int rear=-1;
int queue[MAX];

main()
{
	int choice;
	char ch;
	do
	{
		printf("\n\t1.INSERT\n\t2.DELETE\n\t3.DISPLAY\n\t4.SEARCH");
		printf("\n\tEnter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
			        search();
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

void insert()
{
	int item;
	if(front==MAX-1)
	{
		printf("\n\tQueue Full");
		return;	
	}
	if(front==-1)
		front=0;
	printf("\n\tEnter the element to insert : ");
	scanf("%d",&item);
	rear+=1;
	queue[rear]=item;
}
void delete()
{
	if(front==-1||front>rear)
	{
		printf("\n\tQueue Empty");
		return;
	}
	printf("\n\tDeleted element is : %d",queue[front]);
	front+=1;
}
void display()
{
	int i;
	//printf("\n\tTop = %d",top);
	if(front==-1||front>rear)
	{
		printf("\n\tQueue is empty");
		return;
	}
	printf("\n\tThe Queue elements are : ");
	for(i=front;i<=rear;i++)
		printf("%d\t",queue[i]);
}
void search()
{
        int i,item,flag=1;
        printf("\n\tEnter the element to be searched: ");
        scanf(" %d",&item);
        for(i=front;i<=rear;i++)
        {
                if(queue[i]==item)
                {
                        printf("\n\tItem found at %d position!!",i+1);
                        flag=0;
                }
        }
        if(flag)
                printf("\n\tItem not found!!");
} 
                
	
