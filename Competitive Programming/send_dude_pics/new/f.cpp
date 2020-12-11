#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//what the fuck
typedef long double ld;
ll n, m, t, a[100005];
vector< ll > children[100005];
ll level[100005];
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
set< pair< ll, ll> > info;

ll build(int node){
	level[node] = 0;
	for(int i = 0 ; i < children[node].size() ; i++)
		level[node] = max(level[node], build(children[node][i]));
	level[node] += 1;
	return level[node];
}
ll cunt;
ll ans = 0;
void brk(int node){
	int temp = 0;
	ans++;
	for(int i = 0 ; i < children[node].size() ; i++)
		if( level[temp] < level[children[node][i]] )
			temp = children[node][i];
	info.erase(mp(level[node], node));
	cunt--;
	if( temp == 0 )
		return;
	brk(temp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin >> n >> k;
	for(int i = 0 ; i < n - 1 ; i++){
		int ak;
		cin >> ak;
		children[ak].pb(i + 2);
	}	
	build(1);
	for(int i = 1 ; i <= n ; i++)
		info.insert(mp(level[i], i));
	cunt = n;
	while( cunt > 0 and k-- > 0 )
		brk((*info.crbegin()).second);
	cout << ans << endl;
	return(0);
}