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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

ll givePower(ll a){
	ll temp = -1;
	while(a){
		temp++;
		a /= 2;
	}
	return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		vector< ll > cnt(21, 0);
		for(int i = 0 ; i < n ; i++){
			ll temp;
			cin >> temp;
			cnt[givePower(temp)]++;
		}
		vector< ll > rows(n, 0);
		for(int i = 20 ; i >= 0 ; i--){
			ll index = 0;
			while(cnt[i]){
				ll temp = rows[index];
				while(m - temp >= (1 << i) and cnt[i]){
					cnt[i]--;
					temp += (1 << i);
				}
				rows[index] = temp;
				index++;
			}

		}
		// cout << "haha" << endl;
		ll ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(rows[i])
				ans++;
		}
		cout << ans << endl;
	}
	return(0);
}