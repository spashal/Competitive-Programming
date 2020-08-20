#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[101][101];
ll parent[101];

ll root(ll a){
	while( parent[a] != a )
		a = parent[a];
	return a;
}

int main(){
	ll n, m, a, l, zer0 = 0;
	cin >> n >> m;
	vector< ll > lang[n];
	for(int i = 0 ; i < n ; i++){
		cin >> a;
		parent[i] = i;
		if( a == 0 )
			zer0++;
		for(int j = 0 ; j < a ; j++){
			cin >> l;
			lang[i].push_back(l);
			b[l][i] = true;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		ll prev = -1;
		for(int j = 0 ; j < n ; j++)
			if( b[i][j] ){
				if( prev < 0 )
					prev = j;
				else{
					ll p1 = root(prev), p2 = root(j);
					if( p1 != p2 )
						parent[p2] = p1;
				}
			}
	}
	ll ans = 0;
	for(int i = 0 ; i < n ; i++)
		if( parent[i] == i )
			ans++;
	if( zer0 == n )
		cout << n << endl;
	else
		cout << max(0ll, ans - 1) << endl;
	return(0);
}