#include<stdio.h>
#include<string.h>
#include<math.h>

#define oper(x) (x=='+' || x=='-' || x=='*' || x=='/')

char in[30], post[30], stack[30];
int top=-1;

void push(char x)
{
	stack[++top]=x;
	return ;
}

char pop()
{
	return stack[top--];
}

int precedence(char c)
{
	if (c=='+' || c=='-')
		return 1;
	if (c=='*' || c=='/')
		return 2;
	if (c=='(')
		return 3;
}

int main()
{
	int l,i,j=0;
	printf("Enter the infix expression : ");
	scanf("%s",&in);
	l=strlen(in);
	for(i=0;i<=l;i++)
	{	
		if(oper(in[i]))
		{	
			post[j++]=' ';
			while(precedence(in[i])<precedence(stack[top]))
			{
				post[j++]=stack[top];
				pop();
				post[j++]=' ';

			}
			push(in[i]);
		}
		else if(in[i]=='\0')
		{
			while(top!=-1)
			{
				post[j++]=' ';
				post[j++]=stack[top];
				pop();
			}
		}
		else
			post[j++]=in[i];
	}
	post[j]='\0';
	printf("Postfix Expression : %s\n",post);
	return 0;
}


