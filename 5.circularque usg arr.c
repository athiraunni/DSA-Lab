//TITLE  : 5.circular queue using array
//DATE   : 12/02/2014
//AUTHOR : Athira Unni & Karpagam.B

# include<stdio.h>
# define MAX 5

void insert();
void del();
void display();
void search();

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

main()
{
	int choice;
	char ch;
	do
	{
		printf("\n\t1.Insert");
		printf("\n\t2.Delete");
		printf("\n\t3.Display");
		printf("\n\t4.Search");
		printf("\n\tEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			insert();
			break;
		case 2 :
			del();
			break;
		case 3:
			display();
			break;
		case 4:
		        search();
		        break;

		default:
			printf("Wrong choice\n");
		}                                                /*End of switch*/
		printf("\n\tDo u want to continue(y/n)??");
		scanf(" %c",&ch);
	}while(ch=='Y' || ch=='y');                                          /*End of while */;
	printf("\n\n");
}                                                               /*End of main()*/

void insert()
{
	int added_item;
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("\n\tQueue Overflow");
		return;
	}
	if (front == -1)                                   /*If queue is empty */
	{
		front = 0;
		rear = 0;
	}
	else
		if(rear == MAX-1)          /*rear is at last position of queue */
			rear = 0;
		else
			rear = rear+1;
	printf("\n\tInput the element for insertion in queue : ");
	scanf("%d", &added_item);
	cqueue_arr[rear] = added_item ;
}                                                              /*End of insert()*/

void del()
{
	if (front == -1)
	{
		printf("\n\tQueue Underflow");
		return ;
	}
	printf("\n\tElement deleted from queue is : %d",cqueue_arr[front]);
	if(front == rear)                        /* queue has only one element */
	{
		front = -1;
		rear=-1;
	}
	else
		if(front == MAX-1)
			front = 0;
		else
			front = front+1;
}                                                               /*End of del() */

void display()
{
	int front_pos = front,rear_pos = rear;
	if(front == -1)
	{
		printf("\n\tQueue is empty");
		return;
	}
	printf("\n\tQueue elements : ");
	if( front_pos <= rear_pos )
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	}                                                        /*End of else */
	printf("\n");
}    
void search()
{
     int front_pos = front,rear_pos = rear,item,flag=1;
	if(front == -1)
	{
		printf("\n\tQueue is empty");
		return;
	}
	printf("\n\tEnter the element to seach: ");
	scanf(" %d",&item);
//	printf("\n\tQueue elements : ");
	if( front_pos <= rear_pos )
		while(front_pos <= rear_pos)
		{
		        if(cqueue_arr[front_pos]==item)
		        {
		                printf("\n\n\tItem found!!!");
		                return;
		         }
		         else
		                flag=0;
		         
			//printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	else
	{
		while(front_pos <= MAX-1)
		{
		        if(cqueue_arr[front_pos]==item)
		        {
		                printf("\n\n\tItem found!!!");
		                return;
		         }
		         else
		                flag=0;
			//printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
		        if(cqueue_arr[front_pos]==item)
		        {
		                printf("\n\n\tItem found!!!");
		                return;
		         }
		         else
		                flag=0;
			//printf("%d ",cqueue_arr[front_pos]);
			front_pos++;
		}
	}        
	if(flag==0)
	        printf("\n\tItem not found!!!");                                                /*End of else */
	printf("\n");
}                                                          /*End of display() */

