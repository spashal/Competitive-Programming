#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, first = 0, last = 0, ct = 0;
bool a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}



int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		string s;
		cin >> s;
		for(int i = 0 ; i < n ; i++)
			a[i] = (int)s[i] - '0';
		// cout << endl;
		int i = 0;
		ct = 0;
		first = 0;
		last = 0;
		for(int i = 0 ; i < n ; i++){
			if( !ct and a[i] )
				ct++;
			else if( ct and !a[i] ){
				ct--;
				first++;
				break;
			}
		}
		while( i < n and !a[i] )
			i++;
		first += i;
		i = n - 1;
		while( i >= 0 and a[i] )
			i--;
		last = n - i - 1;
		// cout << first << " " << last << endl;
		while( first-- )
			cout << "0";
		while( last-- )
			cout << "1";
		cout << endl;
	}
	return(0);
}