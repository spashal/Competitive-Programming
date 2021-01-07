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
    cin >> t;
	while( t-- ){
		cin >> n;
		map<ll, ll> mapl, mapr, nextl, nextr;
		set< ll> setl, setr;
		vector< ll > inpl, inpr; 
		for(int i = 0 ; i < n ; i++){
			int l, r;
			cin >> l >> r;
			mapl[l]++;
			mapr[r]++;
			inpl.pb(l);
			inpr.pb(r);
			setl.insert(l);
			setr.insert(r);
		}
		int maX = 0, sum = 0;
		for(set< ll > iterator itr = setl.begin() ; itr != setl.end() ; itr++){
			sum += mapl[*itr];
			nextl[*itr] = sum;
		}
		for(set< ll > iterator itr = setr.begin() ; itr != setr.end() ; itr++){
			sum += mapr[*itr];
			nextr[*itr] = sum;
		}
		for(int i = 0 ; i < n ; i++){
			set< ll > iterator l, r;
			int temp = 0;
			l = setl.lower_bound(inpl[i]);
			r = setl.lower_bound(inpr[i]);
			int temp = nextl[*l] - nextl[*r] + mapl[*r];
			l = setr.lower_bound(inpl[i]);
			r = setr.lower_bound(inpr[i]);
			temp += nextr[*l] - nextr[*r] + mapl[*r];
			temp -= inter[i];
			maX = max(maX, temp);
		}
		cout << n - maX - 1 << endl;
	}
	return(0);
}