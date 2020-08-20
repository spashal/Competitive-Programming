#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, t, a[300005], sel[300005];
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
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;
		ll ctr = 1;
		sel[0] = 0;
		ll prev = 0;
		bool no = false;
		for(int i = 0 ; i < n ;){
			while( i < n - 1 and a[i] < a[i + 1] ){
				i++;
			}
			if( prev + 1 < i and i < n - 1 )
				i++;
			bool flag = false;
			for(int j = prev ; j <= i ; j++)
				if( sel[ctr - 1] < a[j] ){
					sel[ctr] = a[j];
					flag = true;
					break;
				}
			if( !flag ){
				// cout << prev << " " << i << endl;
				no = true;
			}
			ctr++;
			i++;
			prev = i;
		}
		// if( prev != n - 1 and sel[ctr - 1] >= a[n - 1] )
		// 	no = true;
		if( !no )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return(0);
}