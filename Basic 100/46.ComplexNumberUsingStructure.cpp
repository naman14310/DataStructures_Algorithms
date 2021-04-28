#include<iostream>
using namespace std;

struct complex
{
	int real;
	int imaginary;
};

void add(struct complex num1, struct complex num2)
{
	int a = num1.real+num2.real;
	int b = num1.imaginary+num2.imaginary;
	cout<<endl<<"Addition : "<<"("<<a<<")"<<" + ("<<b<<"i)";
}

void sub(struct complex num1, struct complex num2)
{
	int a = num1.real-num2.real;
	int b = num1.imaginary-num2.imaginary;
	cout<<endl<<"Subtraction : "<<"("<<a<<")"<<" + ("<<b<<"i)";
}

void mul(struct complex num1, struct complex num2)
{
	int a = num1.real*num2.real-num1.imaginary*num2.imaginary;
	int b = num1.real*num2.imaginary+num2.real*num1.imaginary;
	cout<<endl<<"Multiplication : "<<"("<<a<<")"<<" + ("<<b<<"i)";
}

int main()
{
	struct complex num1, num2;
	cout<<endl<<"Enter complex no.1 : ";
	cin>>num1.real>>num1.imaginary;
	cout<<endl<<"Enter complex no.2 : ";
	cin>>num2.real>>num2.imaginary;
	
	add(num1,num2);
	sub(num1,num2);
	mul(num1,num2);
}

