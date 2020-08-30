#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld t, m, a[1005], b[1005];
vector< ll > adj[100005];
#define ari for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
#define bri for( int i = 1 ; i <= n ; i++ ) cin >> b[i];
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
    ll n, m;
    cin >> n >> m;
    ari;
    bri;
    if( b[1] > 1 ){
    	bool flag = false;
    	ld cur_wt = m;
    	cur_wt += m / (b[1] - 1);
    	for(int i = 0 ; i < 2 * n - 1 ; i++)
    		if( i % 2 == 0 ){
    			if( a[n - i / 2] > 1 )
    				cur_wt += cur_wt / (a[n - i / 2] - 1);
    			else{
    				flag = true;
    				break;
    			}
    		}
    		else{
    			if( b[n - i / 2] > 1 )
    				cur_wt += cur_wt / (b[n - i / 2] - 1);
    			else{
    				flag = true;
    				break;
    			}
    		}
    	if( flag )
    		cout << "-1" << endl;
    	else
    		cout << setprecision(7) << fixed << cur_wt - m << endl;
    }
    else
	    cout << "-1" << endl;
	return(0);
}