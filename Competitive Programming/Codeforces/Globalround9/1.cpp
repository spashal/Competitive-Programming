#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100], b[100];
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

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		ll pos = 0, neg = 0;
		for(int i = 0 ; i < n - 1 ; i++){
			b[i] = a[i + 1] - a[i];
			if( b[i] > 0 )
				pos++;
			else if( b[i] < 0 )
				neg++;
		}
		// cout << pos << " " << neg << endl;
		int i = 1;
		while( pos > n / 2 and i < n ){
			for( ; i < n ; i++){
				// cout << i << " ";
				if( b[i] > 0 and b[i - 1] > 0 ){
					// cout << i << " ";
					if( a[i + 1] > a[i - 1] ){
						a[i] *= -1;
						pos -= 2;
						neg += 2;
						i += 2;
						// cout << a[i] << " ";
						break;
					}
				}
				// cout << endl;
			}
		}
		// cout << pos << " " << neg << endl;
		i = 1;
		while( neg > n / 2 and i < n ){
			for( ; i < n ; i++){
				if( b[i] < 0 and b[i - 1] < 0 ){
					if( a[i + 1] < a[i - 1] ){
						a[i] *= -1;
						neg -= 2;
						pos += 2;
						i += 2;
						break;
					}
				}
			}
		}
		// cout << pos << " " << neg << endl;
		for(int i = 0 ; i < n ; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return(0);
}