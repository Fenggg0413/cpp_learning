#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n == 0)
		return 1;
	else {
		int recurse = factorial(n-1);
		int result = n * recurse;
		return result;
	}
}

int main()
{
	int t = factorial(10);	
	cout << t << endl;
	return 0;
}
