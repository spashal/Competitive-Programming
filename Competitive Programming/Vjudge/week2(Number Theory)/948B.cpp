#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t;
bool comp[1000006];
vector< ll > prime, adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first

void seive(){
	for(int i = 2 ; i < 1000001 ; i++)
		if( !comp[i] ){
			prime.pb(i);
			for(int j = i + i ; j < 1000001 ; j += i)
				comp[j] = true;
		}
}

ll maxPf(ll a){                //finding max prime factor of a
	for(int i = 0 ; i < prime.size() and a >= prime[i] * prime[i] ; i++){
		if( a % prime[i] == 0 ){
			while( a % prime[i] == 0 )
				a /= prime[i];
			if( a == 1 )
				return prime[i];
		}
	}
	return a;
}

int main(){
	seive();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x1, x2, x0= 1000006;
    cin >> x2;
    ll min_x1 = x2 - maxPf(x2) + 1;

    for(int x1 = min_x1 ; x1 <= x2 ; x1++){
    	ll mpf = maxPf(x1);
    	if( mpf == x1 )
    		continue;
    	x0 = min(x0, x1 - mpf + 1);
    	if( x1 / mpf == 2 )
    		break;
    }
    cout << x0 << endl;
	return(0);
}