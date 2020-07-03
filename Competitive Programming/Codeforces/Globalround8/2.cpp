#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll k, m, t, a[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

ll powers(ll a){
	ll po = 1;
	for(int i = 0 ; i < 10 ; i++)
		po *= a;
	return po;
}
int main(){
	cin >> k;
	string ch("codeforces");
	ll prev = 1;
	for(int i = 1 ; prev < k ; i++){
		if( k <= powers(i) )
			break;
		prev = i;
	}
	ll c = 0;
	ll final = powers(prev);
	for(int i = 0 ; ;){
		if( k <= final )
			break;
		i++;
		final /= prev;
		final *= prev + 1;
		c = i;
	}
	for(int i = 0 ; i < 10 ; i++){
		if( c ){
			for(int j = 0 ; j < prev + 1 ; j++)
				cout << ch[i];
			c--;
		}
		else
			for(int j = 0 ; j < prev ; j++)
				cout << ch[i];

	}
	cout << endl;
	return(0);
}