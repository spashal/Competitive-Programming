#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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
ll mod = 998244353;
	
ll fun(ll num){
	ll exp = mod-2, ans = 1;
	while(exp){
		if(exp%2)
			ans = (ans*num)%mod;
		exp /= 2;
		num = (num*num)%mod;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> fac(200005), inv(200005);
    fac[0] = 1;
    for(int i = 1 ; i < 200005 ; i++)
    	fac[i] = (fac[i-1]*i)%mod;
    for(int i = 0 ; i < 200005 ; i++)
    	inv[i] = fun(fac[i]);
    // for(int i = 0 ; i <= 10 ; i++)
    // 	cout << fac[i] << " ";
    cout << endl;
    cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		sort(a, a+n);
		if(n == 1)
			cout << "1\n";
		else if(a[n-1] == a[n-2])
			cout << fac[n] << endl;
		else if(a[n-1]-1 == a[n-2]){
			ll count = 0, index = n-2;
			while(a[n-2] == a[index] and index > -1){
				count++;
				index--;
			}
			ll ans = 1;
			ll temp = 1;
			ll k = count;
			for(ll i = k+1 ; i <= n-1 ; i++){
				temp = (temp*i)%mod;
				ans = (ans + (temp*inv[i-k])%mod)%mod;
			}
			cout << ((fac[n]-(((ans*fac[k])%mod)*fac[n-k-1])%mod)%mod+mod)%mod << endl;
		}
		else
			cout << "0\n";
	}
	return(0);
}