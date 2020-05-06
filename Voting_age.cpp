#include<iostream>
using namespace std;

int main()
{
	int age;
	
	cout<<"Enter your age: \n";
	cin>>age;
	
	if(age>=18)
		cout<<"You are eligible for voting\n";
	else{
		cout<<"You are not eligible for voting\n";
		cout<<"You must wait for "<<18-age<<" years\n";}
	return 0;
}
