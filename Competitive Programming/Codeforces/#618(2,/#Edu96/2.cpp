#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ll cost = 0, a = 0, b = 0, c = 0;
		for(int i = 0 ; i * 3 <= n ; i++){
			cost = 0;
			for(int j = 0 ; i * 3 + j * 5 <= n ; j++){
				cost = 0;
				for(int k = 0 ; i * 3 + j * 5 + k * 7 <= n ; k++){
					cost = i * 3 + j * 5 + k * 7;
					if( cost == n ){
						a = i;
						b = j;
						c = k;
					}
				}
			}
		}
		if( a * 3 + b * 5 + c * 7 == n )
			cout << a << " " << b << " " << c << "\n";
		else
			cout << "-1\n";
	}
	return(0);
}