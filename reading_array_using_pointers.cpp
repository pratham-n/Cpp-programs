#include<iostream>
using namespace std;

int main()
{
	int n;
	printf("Enter number of elements: \n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nYou entered: ");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",*(arr+i));
	}
	return 0;
}
