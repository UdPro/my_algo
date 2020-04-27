#include<bits/stdc++.h>
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

using namespace std;



typedef long long ll;

using namespace std; 
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of a 
void modInverse(ll a) 
{ 
	ll m =  998244353;
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    ll res = (x%m + m) % m; 
    cout << "Modular multiplicative inverse is " << res; 
     
} 
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
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
  
// Driver Program 
int main() 
{ 
    ll a = 4;
    modInverse(a); 
    return 0; 
} 