#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
vector< ll > ar;
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		ar.push_back(a[0]);
		ar.push_back(a[1]);
		for( int i = 2 ; i < n ; i++ ){
			if( ( ar.back() < a[i] and ar[ar.size() - 2] < ar.back() ) or (ar.back() > a[i] and ar[ar.size() - 2] > ar.back()))
				ar[ar.size() - 1] = a[i];
			else
				ar.push_back(a[i]);
		}
		cout << (int)ar.size() << endl;
		for( int i = 0 ; i < ar.size() ; i++ )
			cout << ar[i] << " ";
		cout << endl;
		ar.clear();
	}
	return(0);
}