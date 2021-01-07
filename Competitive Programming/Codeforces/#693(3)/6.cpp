#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, k, a[100005];
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

ll fun(ll index, ll sum1, ll sum2, bool dota){
	if( sum1 >= k and sum2 >= k )
		return index;
	if( index == n )
		return -1;
	ll ctr = 1000000;
	if( llabs(sum1 - sum2) < a[index] and max(sum1, sum2) < k and !dota )
		ctr = min(ctr, fun(index + 1, max(sum1, sum2) + a[index], min(sum1, sum2), true));
	if( sum1 < sum2 )
		ctr = min(ctr, fun(index + 1, sum1 + a[index], sum2, dota));
	else
		ctr = min(ctr, fun(index + 1, sum1, sum2 + a[index], dota));
	return ctr;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> k;
		ari;
		sort(a, a + n, greater< ll > ());
		cout << fun(1, a[0], 0, false) << endl;
	}
	return(0);
}