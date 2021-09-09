#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, a[200005];
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
    t = 1;
	while( t-- ){
		cin >> n;
		ari;
		int ctr = 0, ans = 0;
		priority_queue< pair<ll, ll> > pq;
		ll sumYet = 0;
		for(int i = 0 ; i < n ; i++){
			if(a[i] >= 0){
				ans++;
				sumYet += a[i];
			}
			else{
				if(sumYet + a[i] < 0){
					if(!pq.empty() and pq.top().ff > -a[i]){
						sumYet += pq.top().ff;
						pq.pop();
						pq.push(mp(-a[i], -i));
						sumYet += a[i];
					}
				}
				else{
					sumYet += a[i];
					pq.push(mp(-a[i], -i));
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return(0);
}