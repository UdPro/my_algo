#include <bits/stdc++.h> 
using namespace std;


typedef long long ll;

ll gcdExtended(ll a, ll  b, ll *x, ll  *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
}


ll mmi(ll p, ll q){
    ll x, y;
    ll m =  998244353; 
    ll g = gcdExtended(q, m, &x, &y); 
    ll res = ((x%m)+m)%m;
    ll r =  ((p%m) * (res%m) ) %m;
    return r;
}


int main() 
{ 
    int t;
    cin >> t;
    ll m =  998244353; 
    while(t--){
        string s;
        cin>> s;
        ll zero_N, one_N, a_N, A_N ;
        zero_N = a_N = A_N = one_N = 1;
        ll ss = 1;
        stack<char> st;
        char op;
        int hash = 0;
        if (s[0] == '(')
            for(int i =0 ; i < s.length() ; i++){
                if (s[i] == '(')
                    st.push(s[i]);
                else if (s[i] == ')'){
                    hash = 0;
                    while(st.top() != '('){
                        if (st.top() == '#')
                            hash++;
                        if (st.top() == '&' || st.top() == '|' || st.top() == '^')
                            op = st.top();
                        st.pop();
                    }
                    st.pop();

                    if ( op == '&'){
                        if (hash == 1){
                            ss = ss * 4 %m;
                            zero_N = zero_N*4%m + one_N*1%m + a_N*2%m + A_N*2%m;
                            one_N = one_N*1;
                            a_N = one_N*1%m + a_N*2%m;
                            A_N = one_N*1%m + A_N*2%m;
                        }
                        else {
                            ss = ss *16 %m;
                            zero_N = zero_N * 9%m;
                            a_N =a_N *3%m;
                            A_N =A_N *3%m;
                            one_N = one_N *1%m;
                        }

                    }
                    else if ( op == '|'){
                        if (hash == 1){
                            ss = ss * 4 %m;
                            one_N = one_N*4%m + zero_N*1%m + a_N*2%m + A_N*2%m;
                            zero_N = zero_N*1%m;
                            a_N = zero_N*1%m + a_N*2%m;
                            A_N = zero_N*1%m + A_N*2%m;
                        }      
                        else {
                            ss *= 16;
                            zero_N =zero_N*1%m;
                            a_N =a_N*3%m;
                            A_N =A_N*3%m;
                            one_N = one_N*9%m;
                        }
                    }
                    else if ( op == '^'){
                        if (hash == 1){
                            ss = ss * 4 %m;
                            ll vv = one_N*1 + zero_N*1 + a_N*1 + A_N*1;
                            one_N = zero_N = a_N = A_N = vv;
                        }      
                        else{
                            ss = ss * 16 % m;
                            zero_N = zero_N * 4 %m;
                            a_N = a_N*4 % m;
                            A_N = A_N*4%m;
                            one_N = one_N * 4 % m;
                        }
                    }

                }
                else
                    st.push(s[i]);
            }
        else{
            zero_N = a_N = A_N = one_N = 1;
            ss = 4;
        }

    // cout << zero_N <<  " " << one_N <<  " " << a_N << " " << A_N << " " <<ss << endl; 
    cout << mmi(zero_N,ss) << " " << mmi(one_N,ss) << " " << mmi(a_N,ss) << " " << mmi(A_N,ss) << "\n";
    }
    return 0; 
} 