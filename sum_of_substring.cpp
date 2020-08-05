#include <bits/stdc++.h> 
using namespace std; 
 
int sumOfSubstrings(string num) 
{ 
	long long int sum = 0; 
	long long int mf = 1; 
	for (int i=num.size()-1; i>=0; i--) 
	{ 
		sum += (num[i]-'0')*(i+1)*mf; 
		mf = mf*10 + 1; 
	} 

	return sum; 
} 

// Driver code to test above methods 
int main() 
{ 
	string s;
  cin >> s;
  long long ans = sumOfSubstrings(s);
	return 0; 
} 
