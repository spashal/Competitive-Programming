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
	for(int z = 1 ; z <= t ; z++){
		cin >> n >> m;
		map<ll, ll> Map;
		set<ll> starts, ends;
		for(int i = 0 ; i < n ; i++){
			ll x, y;
			cin >> x >> y;
			starts.insert(x);
			Map[x] = y;
		}
		vector<ll> ans;
		for(int i = 0 ; i < m ; i++){
			ll k;
			cin >> k;
			set<ll> :: iterator it1 = starts.upper_bound(k);
			set<ll> :: iterator it2 = it1;
			if(it1 != starts.begin())
				it1--;
			else{
				ans.pb(*it2);
				Map[*it2+1] = Map[*it2];
				Map[*it2] = 0;
				ll temp = *it2+1;
				starts.erase(it2);
				if(temp-1 != Map[temp])
					starts.insert(temp);
				continue;
			}
			if(Map[*it1] >= k){
				if(Map[*it1] == *it1){
					ans.pb(*it1);
					starts.erase(*it1);
				}
				else if(Map[*it1] == k){
					ans.pb(Map[*it1]);
					Map[*it1] -= 1;
				}
				else if(*it1 == k){
					ans.pb(*it1);
					starts.insert(*it1+1);
					Map[*it1+1] = Map[*it1];
					Map[*it1] = 0;
					starts.erase(*it1); 
				}
				else{
					ans.pb(k);
					ll temp = Map[*it1];
					Map[*it1] = k-1;
					Map[k+1] = temp;
					starts.insert(k+1);
				}
			}
			else{
				if(it2 != starts.end() and k-Map[*it1]> *it2-k){
					ans.pb(*it2);
					if(Map[*it2] == *it2){
						starts.erase(it2);
						continue;
					}
					Map[*it2+1] = Map[*it2];
					Map[*it2] = 0;
					ll temp = *it2+1;
					starts.erase(it2);
					starts.insert(temp);
				}
				else{
					ans.pb(Map[*it1]);
					if(*it1 == Map[*it1]){
						starts.erase(it1);
						continue;
					}
					Map[*it1] -= 1;
				}
			}
		}
		cout << "Case #" << z << ": ";
		for(int i = 0 ; i < m ; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return(0);
}