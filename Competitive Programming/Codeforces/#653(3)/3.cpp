#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		string s, v;
		cin >> n;
		cin >> s;
		for(int i = 0 ; i < s.size() ; i++){
			if( !v.empty() and v.back() == '(' and s[i] == ')' )
				v.pop_back();
			else
				v.push_back(s[i]);
		}
		cout << (int)v.size() / 2 << endl;
	}
	return(0);
}