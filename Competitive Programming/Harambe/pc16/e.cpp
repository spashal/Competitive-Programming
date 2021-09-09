#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// ll n, m, t, a[300005];
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
    ll n, m, k, a, b, c;
    cin >> n >> m >> k >> a >> b >> c;
    vector< ll > ar(n, 0);
    for(int i = 0 ; i < k ; i++)
    	cin >> ar[i];
    ll mod = ((ll)1 << (ll)32);
    for(int i = k ; i < n ; i++){
    	ar[i] = ((a*ar[i-2]) + (b*ar[i-1]) + c)%(mod);
    	if(ar[i] >= ((ll)1 << (ll)31))
    		ar[i] -= ((ll)1 << (ll)32);
    }
    priority_queue< pair<ll, ll> > pq;
    for(int i = 0 ; i < m-1 ; i++)
    	pq.push(mp(-ar[i], i));
    int ctr = n-m;
    // for(int i = 0 ; i < n ; i++)
    // 	cout << ar[i] << " ";
    // cout << endl;
    ll sum = 0;
    for(int i = m-1 ; i < n ; i++){
    	pq.push(mp(-ar[i], i));
    	sum += -pq.top().ff;
    	// cout << sum << " ";
    	// while(!pq.empty() and pq.top().ss < i-m+2)
    	// 	pq.pop();
    	while(!pq.empty() and pq.top().ss < i-m+2)
    		pq.pop();
    }
	// sum += -pq.top().ff;
	cout << sum << endl;
	return(0);
}