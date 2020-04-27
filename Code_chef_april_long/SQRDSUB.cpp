#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

using namespace std;

long long int c;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin>> t;
	while(t--){
		vector<int> ar,at;
		int n; cin >> n;
		
		c = 0;
		int tz;
		rep(i,0,n){
			cin >> tz;
			ar.push_back(tz);
		} 

		rep(i, 0,n){
			long long  r = ar[i];
			int k = 0;
			if (r %2 == 0){
				k++;
				r = r >> 1;
				if (r%2 == 0)
					k++;
			}
			at.push_back(k);
		}
		c = 0;
		long long one = -1, two = -1, mul = 0 ;
		long  pre;
		vector<int> var;
		for(long long  i =0; i < n; i++){
			pre = c;
			if(at[i] == 0){
				if (two >= one)
					c += i + 1;
				else {
					mul = 0;
					for(long long  j = i-1; j >= two && j >=0  ; j--){
						if (i > 0 && at[i-1] == 0){
							// cout << *(var.end()-1) + 1 << " last value" << endl;
							c += *(var.end()-1);
							break;
						}
						mul += at[j];
						if (mul == 0)
							c += 1;
						if (mul >1){
							c += j+1;
							break;
						}
						
					}
					c+= 1;
				}
			}

			else if (at[i] == 1){
				if (one > two)
					c += one + 1;
				else 
					c += two + 1;
			}
			else 
				c += i + 1;

			var.push_back(c-pre);

			// cout << "c " <<  c << " i " << i << endl;
			if (at[i] == 1){
				one = i;
			}
			else if (at[i] == 2){
				two = i;
			}

		}
		cout << c << endl;
	}

}