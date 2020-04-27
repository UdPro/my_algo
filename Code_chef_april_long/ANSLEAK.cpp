#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		int c[n][k];
		for(int i = 0 ; i < n ;i++)
			for(int j = 0; j < k; j++)
				cin>> c[i][j];

		for(int i = 0 ; i < n ; i++){
			map< int, int> mp;
			for(int j = 0 ; j <k; j++)
				mp[c[i][j]]++;

			float ma = -1;
			int p;
			for(int j =1 ; j <= m; j++){
				if ( 1.0*mp[j]/m >= ma){
					ma = 1.0*mp[j]/m;
					p = j;
				}
			} 
			cout << p << " " ;
		}
		cout << "\n";

	
	}	
}