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

void fun(ll num){
	ll temp = num;
	while(temp){
		if(temp % 10 == m){
			cout << "yes\n";
			return;
		}
		temp /= 10;
	}
	if(num >= 11 * m){
		cout << "yes\n";
		return;
	}
	else{
		ll temp = num;
		for(int i = 1 ; temp >= i * m ; i++){
			if((temp - i * m) % 10 == 0){
				cout << "yes\n";
				return;
			}
		}
	}
		cout << "no\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n >> m;
		ari;
		for(int i = 0 ; i < n ; i++)
			fun(a[i]);
	}
	return(0);
}