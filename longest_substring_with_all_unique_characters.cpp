//Given a string S, finding the length of the longest substring with all unique characters.
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;// total no. of case
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int ch[26];
    for(int i = 0 ; i < 26; i++)
      ch[i] = -1;
    int rep = -1;
    int curlen =0;
    for(int i = 0 ; s[i]; i++){
      if(ch[s[i]-97] == - 1){
        ch[s[i]-97] = i;
      }
      else{
        curlen = max(curlen, i - rep -1);
        //cout << "curlen " <<i - rep -1 << endl;
        if (rep < ch[s[i]-97])
        	rep = ch[s[i]-97];
        ch[s[i]-97] = i;
      }
    }
    curlen = max(curlen, (int) s.length() - rep -1);
    cout << curlen << endl;
  }
  
  return 0;
}
