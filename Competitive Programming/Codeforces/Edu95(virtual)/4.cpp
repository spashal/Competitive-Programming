#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[100005];
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
    ll q;
    cin >> n >> q;
    set< int > s;
    for(int i = 0 ; i < n ; i++){
    	cin >> a[i];
    	s.insert(a[i]);
    }
    sort(a, a + n);
    map< pair<ll, ll>, bool> diff;
    map< ll, pair<ll, ll> > pr;
    priority_queue< pair<ll, pair<ll, ll> > > pq; 
    for(int i = 1 ; i < n ; i++){
    	pq.push(mp(a[i] - a[i - 1], mp(a[i - 1], a[i])));
    	diff[mp(a[i - 1], a[i])] = true;
    	pr[a[i]].ff = a[i - 1];
    	pr[a[i - 1]].ss = a[i];
    }
    if( n > 1 )
	    cout << a[n - 1] - a[0] - pq.top().ff << endl;
	else
		cout << "0" << endl;
    for(int i = 0 ; i < q ; i++){
    	ll k, e;
    	cin >> k >> e;
    	if( k == 0 ){
    		if( e != *s.begin() )
	    		diff[mp(pr[e].ff, e)] = false;
	    	if( e != *--s.end() )
	    		diff[mp(e, pr[e].ss)] = false;
    		if( *s.begin() != e and *--s.end() != e ){
    			pr[pr[e].ff].ss = pr[e].ss;
    			pr[pr[e].ss].ff = pr[e].ff;
    			pq.push(mp(pr[e].ss - pr[e].ff, pr[e]));
    			diff[pr[e]] = true;
    		}
    		s.erase(s.find(e));
    	}
    	else{
    		if( s.size() == 0 ){
    			s.insert(e);
    			cout << "0" << endl;
    			while( !pq.empty() and !diff[pq.top().ss] )
    				pq.pop();
    			continue;
    		}
    		set< int > :: iterator it = s.upper_bound(e);
    		if( it != s.end() ){
    			diff[mp(pr[*it].ff, *it)] = false;
    			pr[e].ss = *it;
    			if( it != s.begin() ){
	    			pr[pr[*it].ff].ss = e;
	    			pr[e].ff = pr[*it].ff;
	    			diff[mp(pr[e].ff, e)] = true;
    			}
    			pr[*it].ff = e;
    			diff[mp(e, pr[e].ss)] = true;
    			pq.push(mp(e - pr[e].ff, mp(pr[e].ff, e)));
    			pq.push(mp(pr[e].ss - e, mp(e, pr[e].ss)));
    		}
    		else{
    			pr[*--s.end()].ss = e;
    			pr[e].ff = *--s.end();
    			diff[mp(*--s.end(), e)] = true;
    			pq.push(mp(e - *--s.end(), mp(*--s.end(), e)));
    		}
   			s.insert(e);
    	}
		while( !pq.empty() and !diff[pq.top().ss] )
    		pq.pop();
    	if( pq.empty() )
    		cout << "0" << endl;
    	else
	    	cout << *--s.end() - *s.begin() - pq.top().ff << endl;    
    }
	return(0);
}