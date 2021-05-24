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
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int i = 1 ; i <= t ; i++){
		cin >> n;
		ari;
		ll cost = 0;
		for(int j = 0 ; j < n - 1 ; j++){
			ll mini = j;
			for(int k = j ; k < n ; k++)
				if(a[mini] > a[k]){
					mini = k;
				}
			cost += mini - j + 1;
			// cout << cost << " haha \n";
			for(int k = j ; k <= j + (mini - j) / 2 ; k++){
				ll temp = a[k];
				a[k] = a[mini + j - k];
				a[mini + j - k] = temp;
			}
		}
		cout << "Case " << i << "#: " << cost << endl;
	}
	return(0);
}