#include <iostream>
using namespace std; 

int catalan(int n) 
{
	int ans = 0;
	// Base case
	if (n <= 1)
	{
	 	return 1;
	}
	// Recursively solves for the catalan number of value n
	for (int i = 0; i < n; i++) 
	{
		ans += catalan(i) * catalan(n - i - 1);
	}
	return ans;
}


int main(int argc, char* argv[])  
{
	int n;
	cout << "Enter in a number: ";
	cin >> n;
	// Makes sure inputted values are not negative
	if (n < 0) 
	{
		cout << "Catalan numbers do not work with a negative term." << endl;
		cout << "The inputted value will now be turned positive for convenience." << endl; 
		n = -1 * n; 
	}
	cout << "Catalan: " << catalan(n) << endl;
}


