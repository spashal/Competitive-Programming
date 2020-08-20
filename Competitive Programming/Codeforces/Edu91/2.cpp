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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		string str;
		cin >> str;
		n = str.size();
		ll r = 0, s = 0, p = 0;
		for(int i = 0 ; i < n ; i++)
			if( str[i] == 'R' )
				r++;
			else if( str[i] == 'S' )
				s++;
			else
				p++;
		if( max(r, max(s, p)) == r )
			for(int i = 0 ; i < n ; i++)
				cout << "P";
		else if( max(r, max(s, p)) == s )
			for(int i = 0 ; i < n ; i++)
				cout << "R";
		else if( max(r, max(s, p)) == p )
			for(int i = 0 ; i < n ; i++)
				cout << "S";
		cout << endl;
	}
	return(0);
}