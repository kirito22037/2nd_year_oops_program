#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ll
{
	char data;
	struct ll *next;
};
struct nll
{
	int data;
	struct nll *next;
};
typedef struct ll *node;
class stk
{
	node top;
	public:
	stk()
	{
		top = NULL;
	}
	void push(char data)
	{
		node temp = new struct ll;
		temp->data = data;
		temp->next = NULL;
		if(top!=NULL)
			temp->next = top;
		
		top = temp;
	}
	void pop()
	{
		if(top==NULL){
			cout<<"The Stack is Empty\n";
			return;
		}
		node ptr = top;
		top = top->next;
		delete ptr;
	}
	void pop(char *a)
	{
		if(top==NULL){
			return;
		}
		node ptr = top;
		*a = top->data;
		top = top->next;
		delete ptr;
	}
	void stack_top(){
		if(top==NULL){
			cout<<"The Stack is Empty\n";
			return;
		}
		cout<<top->data;
	}
	bool chp(char a,char b)
	{
		char op[4] = {'*','/','+','-'};
		int i;
		int j;
		for(i=0;i<4;i++){
			if(op[i]==a)
				break;
		}
		for(j=0;j<4;j++){
			if(op[j]==b)
				break;
		}
		if(i<j)
			return true;
		else
			return false;
		
	}
	void post(char *a,char *b){
		int i = 0;
		int k = 0;
		while(a[i])
		{
			if( isalnum(a[i]) )
				b[k++] = a[i++];
			else if( a[i] == '(' ){
				push(a[i++]);
			}
			else if( a[i]== ')' ){
				do
				{
					pop(&b[k++]);
				}while(top->data != '(');
				pop();
				i++;
			}
			else{
				if(top == NULL){
					push(a[i++]);
				}
				else if(chp(a[i],top->data))
					push(a[i++]);
				else{
					while(chp(top->data,a[i]))
					{
						pop(&b[k++]);
						if(top == NULL)
							break;
					}
					push(a[i++]);
				}
			}	
		}
		while(top!=NULL){
			pop(&b[k++]);
		}
		b[k]='\0';
	}
	int evaluate(char *a,char *b)
	{
		int freq[26]={0};
		for(int i=0;i<strlen(a);i++){
			if( isalnum(a[i]) && freq[a[i]-97]==0)
			{
				cout<<"Enter The Value of "<<a[i]<<endl;
				cin>>freq[a[i]-97];
			}
		}
	
	int arr[5];
	int op1,op2;
	int i,j;
	for(i=0,j=0;i<strlen(b);i++){
		if( isalnum(b[i]) )
			arr[j++] = freq[b[i]-97];
		else{
			op2 = arr[--j];
			op1 = arr[--j];
			if(b[i]=='+'){
				arr[j++] = op1 + op2;
			}
			else if(b[i]=='-'){
				arr[j++] = op1 - op2;
			}
			else if(b[i]=='*'){
				arr[j++] = op1 * op2;
			}
			if(b[i]=='/'){
				arr[j++] = op1 / op2;
			}
			
			
		}
		
	}
	return arr[0];
	}
};
class stac:public stk
{
	struct nll *top;
	public:
	stac()
	{	
		top = NULL;
	}
	void push(int data)
	{
		struct nll *temp = new struct nll;
		temp->data = data;
		temp->next = NULL;
		if(top!=NULL)
			temp->next = top;
		
		top = temp;
	}
	void pop(int a)
	{
		if(top==NULL){
			return;
		}
		struct nll * ptr = top;
		a = top->data;
		top = top->next;
		delete ptr;
	}
	int evaluate(char *a,char *b)
	{
		int freq[26]={0};
		for(int i=0;i<strlen(a);i++){
			if( isalnum(a[i]) && freq[a[i]-97]==0)
			{
				cout<<"Enter The Value of "<<a[i]<<endl;
				cin>>freq[a[i]-97];
			}
		}
	int op1,op2;
	int i;
	for(i=0;i<strlen(b);i++){
		if( isalnum(b[i]) )
			push(freq[b[i]-97]);
		else{
			pop(op2);
			pop(op1);
			if(b[i]=='+'){
				push(op1 + op2);
			}
			else if(b[i]=='-'){
				push(op1 - op2);
			}
			else if(b[i]=='*'){
				push(op1 * op2);
			}
			if(b[i]=='/'){
				push(op1 / op2);
			}
			
			
		}
		
	}
	int ans;
	pop(ans);
	return ans;
	}
};
int main()
{
	stk s1;
	char inf[30];
	cout<<"Give The Infix Expression\n";
	cin>>inf;
	char opo[30];
	
	s1.post(inf,opo);
	cout<<"Postfix Expression for the Given Expression is :: ";
	cout<<opo<<"\n";
	int asw1 = s1.evaluate(inf,opo);
	cout<<asw1;
	
}

