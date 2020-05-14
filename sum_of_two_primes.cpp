#include<iostream>
using namespace std;

int is_prime(int n)
{
	int flag=1;
	for(int i=2;i<=n/2;i++)
	{
		if(n%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}

int main()
{
	int n, flag1=0;
	cout<<"Enter a positive integer: \n";
	cin>>n;
	for(int i=2; i<=n/2; i++)
	{
		if(is_prime(i))
		{
			if(is_prime(n-i))
			{
				cout<<n<<"="<<i<<"+"<<n-i<<"\n";
				flag1=1;
			}
		}
	}
	if(flag1==0)
	{
		cout<<n<<" cannot be expressed as sum of two prime numbers\n";
	}
	return 0;
}
