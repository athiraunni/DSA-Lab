#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 40
int stack[SIZE];
int top=-1;
void push(int n)
{
	if(top==SIZE-1)
	{
	        printf("\n\tStack is full");
	        return;
	}
        else
    	{
        	top=top+1;
        	stack[top]=n;
        	printf("\n\tPushed element is %d",n);
    	}
}
int pop()
{
	int n;
	if(top==-1)
        {
        	printf("\n\tStack is empty");
        	return;
        }
        else
        {
       		n=stack[top];
        	top=top-1;
        	printf("\n\tThe poped element is %d",n);
        	return(n);
        }
}
int evaluate(int op1, int op2,char ch)
{
	printf("\n\top1 = %d  op2 = %d  h = %c",op1,op2,ch);
	int n;
	if (op1<op2)
	{
		n=op1;
	        op1=op2;
	        op2=n;
	}
	if(ch=='+')
	        n=op1+op2;
        else if(ch=='-')
      		n=op1-op2;
	else if(ch=='*')
        	n=op1*op2;
	else if(ch=='/')
	        n=op1/op2;
	else if(ch=='%')
	        n=op1%op2;
	else
	{
	        printf("\n\tThe operator is not identified");
	        exit(0);
	}
	printf("n=%d\n",n);
	return(n);
}
int main()
{
      char str[50],ch,ch1;
      int i=0,n,op1,op2;
      printf("\n\tEnter the Postfix string : ");
      scanf("%s",str);
      ch=str[i];
      while(ch!='\0')
      {
	      printf("\n\tThe char is  %c",ch);
	//if(ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5')//
		if(isdigit(ch))
		{
	                n=ch-'0';
	                push(n);
                }
		else
		{
	                op1=pop();
	                op2=pop();
	                n=evaluate(op1,op2,ch);
	                push(n);
	        }
        	ch=str[++i];
      }
      printf("\n\tThe value of the arithmetic expression is = %d\n\n",pop());
      return;
}
