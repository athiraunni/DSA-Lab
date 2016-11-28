
#define SIZE 50            /* Size of Stack */
#include<stdio.h>
#include<string.h>
#include <ctype.h>
int s[SIZE];

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int top=-1;       /* Global declarations */

void push(int elem)
{                       /* Function for PUSH operation */
 s[++top]=elem;
 return;
}

int pop()
{                      /* Function for POP operation */
 return(s[top--]);
}

int main()
{                         /* Main Program */
 char prfx[50],pofx[50],ch;
 int i=0,op1,op2;
 printf("\n\nRead the Prefix Expression ? ");
 scanf("%s",prfx);
 strcpy(pofx,prfx);
 strrev(pofx);
 while( (ch=pofx[i++]) != '\0')
 {
  if(isdigit(ch)) push(ch-'0'); /* Push the operand */
  else
  {        /* Operator,pop two  operands */
   op1=pop();
   op2=pop();
   switch(ch)
   {
   case '+':push(op1+op2);break;
   case '-':push(op1-op2);break;
   case '*':push(op1*op2);break;
   case '/':push(op1/op2);break;
   }
  }
 }
 printf("\n Given Prefix Expn: %s\n",prfx);
 printf("\n Result after Evaluation: %d\n",s[top]);
 return 0;
}
 
