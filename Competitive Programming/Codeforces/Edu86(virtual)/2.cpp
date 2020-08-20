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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		string s;
		cin >> s;
		string ans;
		n = s.size();
		ll zero = 0;
		for(int i = 0 ; i < n ; i++)
			if( s[i] == '0' )
				zero++;
		if( zero == 0 or zero == n )
			cout << s << endl;
		else{
			for(int i = 0 ; i < n - 1 ; i++)
				if( s[i] == '1' and s[i + 1] == '1' ){
					s.insert(s.begin() + i + 1, '0');
					n++;
				}
				else if( s[i] == '0' and s[i + 1] == '0' ){
					s.insert(s.begin() + i + 1, '1');
					n++;					
				}
			cout << s << endl;
		}
	}
	return(0);
}