//TITLE  : 4.Input and Output Restricted Dequeue using Array
//DATE   : 12/02/2014
//AUTHOR : Athira Unni & Karpagam.B

# include<stdio.h>
# define MAX 5

void input_que();
void output_que();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display_queue();

int deque_arr[MAX];
int left = -1;
int right = -1;

main()
{
	int choice;

	printf("\n\t1.Input restricted dequeue");
	printf("\n\t2.Output restricted dequeue");
	printf("\n\tEnter your choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
	 case 1 :
		input_que();
		break;
	 case 2:
		output_que();
		break;
	 default:
		printf("\n\tWrong choice");
	}/*End of switch*/
	printf("\n\n");
}/*End of main()*/

void input_que()
{
	int choice;
	char ch;
	do
	{
		printf("\n\t1.Insert at right");
		printf("\n\t2.Delete from left");
		printf("\n\t3.Delete from right");
		printf("\n\t4.Display");
		printf("\n\tEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			delete_left();
			break;
		 case 3:
			delete_right();
			break;
		 case 4:
			display_queue();
			break;
		 default:
			printf("\n\tWrong choice\n");
		}/*End of switch*/
		printf("\n\tDo you want to continue (y/n)..??");
		scanf(" %c",&ch);
	}while(ch=='Y' || ch=='y');/*End of while*/
}/*End of input_que() */

void output_que()
{
	int choice;
	char ch;
	do
	{
		printf("\n\t1.Insert at right");
		printf("\n\t2.Insert at left");
		printf("\n\t3.Delete from left");
		printf("\n\t4.Display");
		printf("\n\tEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			insert_left();
			break;
		 case 3:
			delete_left();
			break;
		 case 4:
			display_queue();
			break;
		 default:
			printf("\n\tInvalid choice..!!!!");
		}/*End of switch*/
		printf("\n\tDo you want to continue (y/n)..??");
		scanf(" %c",&ch);
	}while(ch=='Y' || ch=='y');/*End of while*/
}/*End of output_que() */

void insert_right()
{
	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{
		printf("\n\tQueue Overflow");
		return;
	}
	if (left == -1)  /* if queue is initially empty */
	{
		left = 0;
		right = 0;
	}
	else if(right == MAX-1)  /*right is at last position of queue */
		right = 0;
	else
		right = right+1;
	printf("\n\tInput the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[right] = added_item ;
}/*End of insert_right()*/

void insert_left()
{
	int added_item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{
		printf("\n\tQueue Overflow ");
		return;
	}
	if (left == -1)/*If queue is initially empty*/
	{
		left = 0;
		right = 0;
	}
	else if(left== 0)
		left=MAX-1;
	else
		left=left-1;
	printf("\n\tInput the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[left] = added_item ;
}/*End of insert_left()*/

void delete_left()
{
	if (left == -1)
	{
		printf("\n\tQueue Underflow");
		return ;
	}
	printf("\n\tElement deleted from queue is : %d",deque_arr[left]);
	if(left == right) /*Queue has only one element */
	{
		left = -1;
		right=-1;
	}
	else if(left == MAX-1)
		left = 0;
	else
		left = left+1;
}/*End of delete_left()*/

void delete_right()
{
	if (left == -1)
	{
		printf("\n\tQueue Underflow");
		return ;
	}
	printf("\n\tElement deleted from queue is : %d",deque_arr[right]);
	if(left == right) /*queue has only one element*/
	{
		left = -1;
		right=-1;
	}
	else if(right == 0)
		right=MAX-1;
	else
		right=right-1;
}/*End of delete_right() */

void display_queue()
{
	int front_pos = left,rear_pos = right;
	if(left == -1)
	{
		printf("\n\tQueue is empty");
		return;
	}
	printf("\n\tQueue elements : ");
	if( front_pos <= rear_pos )
	{
		while(front_pos <= rear_pos)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}/*End of else */
	printf("\n\n");
}/*End of display_queue() */
