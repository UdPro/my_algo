#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		if(n>1)
				cout << n/2 << endl;
		else 
			cout << 1 << endl;
		int i=1;
		if(n==1){
			cout << 1 << " " << n--<< endl;
		}
		if (n%2){
			cout << 3 <<" " << i << " "<< i+1 << " " << n <<endl;
			i+=2;
			n--;
		}
		for(;i <=n;i+=2)
			cout << 2  << " "<< i << " " << i+1 << endl;
		// if (n%2)

	}

}