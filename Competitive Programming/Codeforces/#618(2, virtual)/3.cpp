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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ari;
    ll zero = 0;
    vector< set< ll > > bits(31, set< ll >());
    for(int i = 0 ; i < n ; i++){
    	if( a[i] == 0 ){
    		zero++;
    		continue;
    	}
    	for(int j = 30 ; j >= 0 ; j--)
    		if( a[i] & (1 << j) )
    			bits[j].insert(i);
    }
    for(int i = 0 ; i < n - zero ; i++){
    	ll cur = - 1;;
    	for(int j = 30 ; j >= 0 ; j--){
    		if( bits[j].size() == 1 ){
    			cur = *bits[j].begin();
    			break;
    		}
    	}
    	if( cur < 0 )
    		for(int j = 30 ; j >= 0 ; j--)
    			if( bits[j].size() > 0 ){
	    			cur = *(bits[j].begin());
	    			break;
    			}
    	for(int j = 30 ; j >= 0 ; j--)
    		if( bits[j].size() > 0 and bits[j].find(cur) != bits[j].end() )
    			bits[j].erase(bits[j].find(cur));
    	cout << a[cur] << " ";
    }
    while( zero-- )
    	cout << "0 "; 
    cout << endl;
	return(0);
}