#include <iostream>
#include <vector>
#include <algorithm>
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
	while( t-- ){
		cin >> n;
		vector< ll > h(n, 0), w(n, 0);
		vector< pair< pair< ll, ll>, ll> > vec;
		vector< ll > vec1, vec2, ans(n, 0);
		for(int i = 0 ; i < n ; i++){
			cin >> h[i] >> w[i];
			if( h[i] > w[i] ){
				vec.pb(mp(mp(h[i], w[i]), i));
			}
			else
				vec.pb(mp(mp(w[i], h[i]), i));
		}
		vector< ll > mi(n, 10000000000);
		sort(vec.begin(), vec.end());
		for(int i = 0 ; i < n ; i++){
			vec1.pb(vec[i].fff);
			vec2.pb(vec[i].fs);
			if( i > 0 ){
				if( vec[i].fs < vec[mi[i - 1]].fs )
					mi[i] = i;
				else
					mi[i] = mi[i - 1];
				// mi[i] = min(vec[mi[i - 1]].fs, vec[i].fs);
			}
			else
				mi[i] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			ll bada = max(w[i], h[i]);
			ll chota = min(w[i], h[i]);
			vector< ll> :: iterator it;
			it = lower_bound(vec1.begin(), vec1.end(), bada);
			// cout << *it << " hello\n";
			if( it != vec1.begin() ){
				while( it != vec1.begin() and *it == bada )
					it--;
				ll ii = distance(vec1.begin(), it);
				if( vec[ii].fff >= bada ){
					ans[i] = -1;
					continue;
				}
				if( vec[ii].ss == i )
					it--;
				// cout << *it << " bye\n";
				ii = distance(vec1.begin(), it);
				// if( vec[ii].fs * -1 < chota ){
				// 	cout << ii << " " << vec[ii].ss << " promise\n";
				// 	ans[i] = vec[ii].ss + 1;
				// }
				// it = lower_bound(vec2.begin(), vec2.begin() + ii, w[i]);
				// while( it != vec2.begin() and )
					// it--;
				if( vec[mi[ii]].fs < chota ){
					ans[i] = vec[mi[ii]].ss + 1;
				}
				else
					ans[i] = -1;
			}
			else{
				ans[i] = -1;
				continue;
			}	
			
		}
		for(int i = 0 ; i < n ; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return(0);
}