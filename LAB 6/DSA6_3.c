//Postfix evaluation
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define capacity 5

int top=-1,arr[capacity];

int isFull()
{
	if(top==capacity-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int data)
{
	if(isFull())
    {
    	printf("Stack is full");
	}
	else
	{
		top++;
		arr[top]=data;
	}
}

int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int pop()
{
	if(isempty())
	{
		printf("Stack is empty");
		return -1;
	}
	else
	{
		top--;
		return arr[top+1];
	}
}

int main()
{
	char str[50];
    printf("Enter a postfix expression (e.g., 231*+9-): ");
    scanf("%s", str);
	int i,num1,num2;
	int n=strlen(str);
	for(i=0;i<n;i++)
	{
		if(isdigit(str[i]))
		{
			push(str[i]-'0');
		}
		else
		{
			num2=pop();
			num1=pop();
			switch(str[i])
			{
				case '+':
				   push(num1+num2);
				   break;

				 case '-':
				   push(num1-num2);
				   break;

				  case '*':
				    push(num1*num2);
					break;

				  case '/':
				     push(num1/num2);
					 break;
			}
		}
	}
	printf("Evaluated answer: %d",pop());
}
