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
    cin >> n;
    ari;
    map< ll, bool > vis;
    vector< ll > ans(n, -1);
    ll index = 0, largest_yet = 0;
    vector< ll > chela(n + 1, -1);
    priority_queue< pair<ll, ll> > pq;
    for(int i = 0 ; i < n ; i++){
    	while( !pq.empty() and pq.top().ff > 2 * a[i] ){
    		ans[pq.top().ss] = i - pq.top().ss;
    		index = pq.top().ss;
    		largest_yet = pq.top().ff;
    		pq.pop();
    	}
	    while( !pq.empty() and pq.top().ff < a[i] ){
	    	chela[pq.top().ss] = i;
	    	pq.pop();
	    }
	    pq.push(mp(a[i], i));
    }

    for(int i = n - 1 ; i > -1 ; i--)
    	if( chela[i] >= 0 and ans[chela[i]] >= 0 )
    		ans[i] = ans[chela[i]] + chela[i] - i;
    ll max_yet = 0;

    if( !pq.empty() ){
    	for(int i = n - 1 ; i > pq.top().ss ; i--){
    		if( max_yet < a[i] ){
    			index = i;
    			max_yet = a[i];
    		}
    		else{
    			chela[i] = index;
    		}
    	}
    }
    for(int i = 0 ; i < n ; i++){
    	if( i == pq.top().ss or pq.empty() )
    		break;
    	while( !pq.empty() and pq.top().ff < a[i] ){
    		ans[pq.top().ss] = ans[i] + n + i - pq.top().ss;
    		pq.pop();
    	}
    	while( !pq.empty() and pq.top().ff > 2 * a[i] ){
    		ans[pq.top().ss] = n + i - pq.top().ss;
    		index = pq.top().ss;
    		largest_yet = pq.top().ff;
    		pq.pop();
    		while( !pq.empty() and pq.top().ss < index and largest_yet >= pq.top().ff )
    			pq.pop();
	    }
    }
    for(int i = n - 1 ; i > -1 ; i--)
    	if( chela[i] >= 0 and ans[chela[i]] >= 0 )
    		ans[i] = ans[chela[i]] + chela[i] - i;
    for(int i = 0 ; i < n ; i++)
    	cout << ans[i] << " ";
    cout << endl;
	return(0);
}