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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string s;
    cin >> s;
    vector< bool > a(256, false);
    ll ctr = 0, localctr = 0, mini = n;
    for(int i = 0 ; i < n ; i++)
    	if( !a[s[i]] ){
    		ctr++;
    		a[s[i]] = true;
    	}
    vector< ll > cnt(256, 0);
    ll End = 0;
    cnt[s[End]]++;
    localctr++;
   	for(int start = 0 ; start < n ; start++){
   		if( End < start)
   			End = start;
   		while( End < n - 1 and localctr < ctr ){
   			End++;
   			cnt[s[End]]++;
   			if( cnt[s[End]] == 1 )
   				localctr++;
   		}
    	if( localctr == ctr )
    		mini = min(mini, End - start + 1);
    	cnt[s[start]]--;
    	if( !cnt[s[start]] )
    		localctr--;
    }
    cout << mini << endl;
	return(0);
}