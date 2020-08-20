#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m, t, a1 = -INT_MAX, a2 = -INT_MAX, a3 = -INT_MAX;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define ginp for( int i = 0 ; i < m ; i++ ){ int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
#define pb push_back
#define ss second
#define ff first
#define fs first.second
#define fff first.first
#define sss second.second
#define sf second.first
unordered_map< int, bool > mp;
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll x = 0;
    for(int i = 0 ; i < n ; i++){
    	cin >> x;
    	mp[x] = true;
    	for(int j = 0 ; j < 30 ; j++)
    		if( mp[x - (1 << j)] and mp[x + (1 << j)] ){
    			a1 = x - (1 << j);
    			a2 = x + (1 << j);
    			a3 = x;
    		}
    	if( a3 == -INT_MAX ){
	    	for(int j = 0 ; j < 30 ; j++){
	    		if( mp[x - (1 << j)] ){
	    			a1 = x - (1 << j);
	    			a2 = i;
	    		}
	   			if( mp[x + (1 << j)] ){
	    			a1 = x + (1 << j);
	    			a2 = i;
	    		}
	   		}
	    }
    }
    if( a2 == -INT_MAX )
    	cout << "1\n" << x << endl;
    else if(a3 == -INT_MAX )
    	cout << "2\n" << a1 << " " << a2 << endl;
    else
    	cout << "3\n" << a1 << " " << a2 << " " << a3 << endl;
	return(0);
}