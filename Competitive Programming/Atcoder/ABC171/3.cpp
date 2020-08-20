#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll n, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> n;
	string s;
	while( n ){
		if( n % 26 )
			s.push_back( (char)( 96 + n % 26 ));   
		else{
			s.push_back('z');
			n--;
		}
		n = n / 26;
	}
	for(int i = (int)s.size() - 1 ; i > -1 ; i--)
		cout << s[i];
	cout << endl;
	return(0);
}