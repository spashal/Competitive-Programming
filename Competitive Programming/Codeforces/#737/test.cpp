#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
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
void printar(vector< int > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

void dfs(ll num, ll k, ll And, ll Xor){
	if(num == 0 and And >= Xor){
		// printar(yet, 0, yet.size());
		m++;
		return;
	}
	else if(num == 0)
		return;
	for(int mask = 0 ; mask < (1 << k) ; mask++){
		dfs(num-1, k, (And&mask), (Xor^mask));
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll k;
		m = 0;
		cin >> n >> k;
		vector<int> temp;
		dfs(n, k, (1 << k)-1, 0, temp);
		cout << m << endl;
	}
	return(0);
}