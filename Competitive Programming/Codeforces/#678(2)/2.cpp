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
bool vis[100005];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    vector< ll > prime, comp;
    for(int i = 2 ; i < 100001 ; i++)
    	if( !vis[i] ){
    		prime.pb(i);
    		for(int j = i * 2 ; j < 100001 ; j += i){
    			vis[j] = true;
    			comp.pb(j);
    		}
    	}
    comp.pb(1);
    sort(comp.begin(), comp.end());
	while( t-- ){
		cin >> n;
		int sum = 0;
		bool flag = false;
		for(int j = 0 ; j < comp.size() ; j++){
			if( !vis[comp[j] + n - 1] ){
				sum = comp[j];
				break;
			}
		}
		for(int i = 0 ; i < n - 1 ; i++){
			for(int j = 0 ; j < n - 1 ; j++)
				cout << "1 ";
			cout << sum << "\n";
		}
		for(int i = 0 ; i < n - 1 ; i++)
			cout << sum << " ";
		for(int j = 0 ; j < comp.size() ; j++){
			bool flag = false;
			if( !vis[sum*(n - 1) + comp[j]] ){
				flag = true;
			}
			if( flag ){
				cout << comp[j] << "\n";
				break;
			}
		}
	}
	return(0);
}