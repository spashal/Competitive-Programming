#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t;
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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		ll k;
		cin >> n >> m >> k;
		ll ans = 0;
		vector< ll > a1(k, 0), a2(k, 0), num1(n + 1, 0), num2(m + 1, 0);
		for(int i = 0 ; i < k ; i++){
			cin >> a1[i];
			num1[a1[i]]++;
		}
		for(int i = 0 ; i < k ; i++){
			cin >> a2[i];
			num2[a2[i]]++;
		}
		for(int i = 0 ; i < k ; i++){
			ans += num1[a1[i]] + num2[a2[i]] - k - 1;
		}
		cout << (-1) * ans / 2 << endl;
	}
	return(0);
}