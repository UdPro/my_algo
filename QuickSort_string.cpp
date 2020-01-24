#include<bits/stdc++.h>
using namespace std;

string s;

int parition(int lo, int hi){

	int pivot = s[lo];
	int i, j;
	i = lo+1;
	j = hi;

	while(i <= j) {
		//cout << "i " << i << " j " << j <<endl;	
		while((int)s[i] >= pivot and i <= hi )
			i++;
		while((int)s[j] < pivot and j >= lo)
			j--;
		if ( i < j){
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;		   
		}

	}
	if ( i > j ) {
	char temp = s[lo];
	s[lo] = s[j];
	s[j] = temp;
	}
	return j;

}

void quicksort(int lo, int hi){
	 if ( lo < hi ) {
	 int p = parition( lo, hi);
	 quicksort(lo, p-1);
	 quicksort(p+1, hi);
	 }


}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		quicksort(0, s.length()-1);
		cout << s << endl;
	}


		
	return 0;
}