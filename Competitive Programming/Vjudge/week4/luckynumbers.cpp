#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[100005];
ll po[12];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}

ll decConverter(vector< ll > &a){
	ll len = a.size();
	ll dec = 0;
	for( ll i = 0 ; i < len ; i++ )
		dec += a[i] * po[i];
	return dec;
}

int main(){
	ll time[6];
	vector< ll > v[6], fin;
	po[0] = 1;
	time[1] = 2;
	time[2] = 6;
	time[3] = 20;
	time[4] = 70;
	time[5] = 252;
	for( int i = 1 ; i < 11 ; i++ )
		po[i] = po[i-1] * 10;
	for( int i = 1 ; i <= 5 ; i++ ){
		for( int j = 1 ; j <= i ; j++ )
			v[i].push_back(4);
		for( int j = 1 ; j <= i ; j++ )
			v[i].push_back(7);
	}
	for( int i = 1 ; i <= 5 ; i++ )
		for( int j = 1 ; j <= time[i] ; j++ ){
			fin.push_back(decConverter(v[i]));
			next_permutation(v[i].begin(), v[i].end());
		}
	sort(fin.begin(), fin.end());
	cin >> n;
	ll ans = 0;
	for( int i = 0 ; i < fin.size() ; i++ )
		if( n <= fin[i] ){
			ans = fin[i];
			break;
		}
	cout << ans << endl;
	return(0);
}