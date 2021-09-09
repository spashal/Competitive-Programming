#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
#define mp make_pair
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    // for(int i = 1 ; i  <= 1000 ; i++)
    	// for(int j = 1 ; j <= 1000 ; j++)
    // {
    	// n = i;
    	// m = j;
    	if(m < n){
        	n += m;
        	m -= n;
        	n += m;
        	m *= -1;
        }
        ll g = gcd(n, m);
        ll ans = n;
        ll temp = (m/g) % (n/g);
        if(temp == 0 or (n/g)%temp == 0)
        	ans *= ((m-1)/n + 1);
        else{
        	ans *= (m/n + 1); 
        	if(n % 2 == 0 or m % 2 == 0)
        		ans += (temp*g) - 1;
        	else
	        	ans += (((n+1)*temp*g)/n)/2;
        }
        cout << ans << endl;
	return(0);
}