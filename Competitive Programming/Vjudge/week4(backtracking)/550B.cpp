#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[105], l, x, r;
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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

ll rec(int i, ll total_yet, ll first){
	if( i == n - 1 and first >= 0 ){
		if( total_yet + a[i] >= l and total_yet + a[i] <= r and a[first] + x <= a[i] )
			return 1;
		else
			return 0;
	}
	else if( i == n - 1 )
		return 0;
	if( total_yet + a[i] >= l and total_yet + a[i] <= r ){
		if( first >= 0 ){
			if( a[first] + x <= a[i] )
				return rec(i + 1, total_yet + a[i], first) + 1 + rec(i + 1, total_yet, first);
			else
				return rec(i + 1, total_yet + a[i], first) + rec(i + 1, total_yet, first);
		}
		else
			return rec(i + 1, total_yet + a[i], i) + rec(i + 1, total_yet, first);
	}
	if( total_yet + a[i] < l ){
		if( first >= 0 )
			return rec(i + 1, total_yet + a[i], first) + rec(i + 1, total_yet, first);
		else
			return rec(i + 1, total_yet + a[i], i) + rec(i + 1, total_yet, first);
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l >> r >> x;
    ari;
    sort(a, a + n);
    cout << rec(0, 0, -1) << endl;
	return(0);
}