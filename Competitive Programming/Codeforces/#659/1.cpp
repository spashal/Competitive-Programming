#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[105];
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
		cin >> n;
		ari;
		a[n] = 0;
		string s[n + 1];
		s[0].pb('a');
		for(int i = 1 ; i < a[0] ; i++)
			s[0].pb('a');
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < a[i - 1] ; j++)
				s[i].pb(s[i - 1][j]);
			if( a[i] > a[i - 1] and s[i - 1].size() > a[i - 1] ){
				if( s[i - 1][a[i - 1]] == 'a' ){
					s[i].pb('b');
					for(int j = a[i - 1] + 1 ; j < a[i] ; j++)
						s[i].pb('a');
				}
				else{
					s[i].pb('a');
					for(int j = a[i - 1] + 1 ; j < a[i] ; j++)
						s[i].pb('a');
				}
			}
			else if( a[i] > a[i - 1] )
				for(int j = a[i - 1] ; j < a[i] ; j++)
					s[i].pb('a');
			else if( a[i] == 0 and a[i - 1] == 0 ){
				if( s[i - 1][0] == 'a' )
					s[i].pb('b');
				else
					s[i].pb('a');

			}
		}
		for(int i = 0 ; i <= n ; i++)
			cout << s[i] << endl;
	}
	return(0);
}