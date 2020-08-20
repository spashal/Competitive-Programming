#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll b, c, l, r, m;
		cin >> l >> r >> m;
		ll low = max(1ll, m - r + l), high = m + r - l;
		for(int i = l ; i <= r ; i++){
			if( ceil((long double)low / i) * i <= high){
				if( m <= ceil((long double)low / i) * i ){
					c = r;
					b = m - ceil((long double)low / i) * i + r;
					// cout << "hi" << endl;
				}
				else{
					c = l;
					b = m - ceil((long double)low / i) * i + l;
					// cout << "hello" << " " << ceil((long double)low / i) * i << endl;
				}
				cout << i << " " << b << " " << c << endl;
				break;
			}
		}
	}
	return(0);
}