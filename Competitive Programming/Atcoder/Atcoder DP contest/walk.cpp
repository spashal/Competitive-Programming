#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< vector<ll > > multmat(vector< vector<ll> > a, vector< vector< ll > > b, ll n){
	ll mod = 1e9 + 7;
	vector< vector< ll > > temp(n, vector< ll > (n, 0));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			for(int k = 0 ; k < n ; k++){
				temp[i][k] += a[i][j] * b[j][k];
				temp[i][k] %= mod;
			}
	return temp;
}

int main(){
	ll n, k;
	cin >> n >> k;
	vector< vector< ll > > edges(n, vector< ll > (n, 0));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			cin >> edges[i][j];
	vector< vector< ll > > paths(n, vector< ll > (n, 0));
	for(int i = 0 ; i < n ; i++)
		paths[i][i] = 1;
	while( k ){
		if( k % 2 )
			paths = multmat(paths, edges, n);
		k /= 2;
		edges = multmat(edges, edges, n);
	}
	ll ans = 0, mod = 1e9 + 7;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			ans = (ans + paths[i][j]) % mod;
	cout << ans << endl;
	return(0);
}