#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005], b[100005];
vector< ll > adj[100005];
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < n ; i++ ) cin >> b[i];
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
    cin >> n;
    ari;
    bri;
    vector< bool > vis(n + 1, false);
    vector< ll > pos(n + 1, -1);
    for(int i = 0 ; i < n ; i++)
    	pos[b[i]] = i;
    ll fine = 0, prev = 0;
    for(int i = 0 ; i < n ; i++){
    	if( !vis[pos[a[i]]] ){
	    	for(int j = prev ; j < pos[a[i]] ; j++){
    			vis[j] = true;
    			fine++;
    		}
    		vis[pos[a[i]]] = true;
    		prev = pos[a[i]] + 1;
    	}
    }
    cout << fine << endl;
	return(0);
}