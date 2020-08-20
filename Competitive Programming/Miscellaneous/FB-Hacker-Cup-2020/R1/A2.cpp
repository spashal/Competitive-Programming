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
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    ll mod = 1e9 + 7;
	for(int r = 1 ; r <= t ; r++){
		ll k, a, b, c, d;
		cin >> n >> k;

		vector< ll > l(n, 0), w(n, 0), h(n, 0);
		for(int i = 0 ; i < k ; i++)
			cin >> l[i];
		cin >> a >> b >> c >> d;
		for(int i = k ; i < n ; i++)
			l[i] = ((a * l[i - 2] + b * l[i - 1] + c) % d) + 1;

		for(int i = 0 ; i < k ; i++)
			cin >> w[i];
		cin >> a >> b >> c >> d;
		for(int i = k ; i < n ; i++)
			w[i] = ((a * w[i - 2] + b * w[i - 1] + c) % d) + 1;

		for(int i = 0 ; i < k ; i++)
			cin >> h[i];
		cin >> a >> b >> c >> d;
		for(int i = k ; i < n ; i++)
			h[i] = ((a * h[i - 2] + b * h[i - 1] + c) % d) + 1;

		set< ll > st;
		map< ll, bool> mp;

		st.insert(l[0]);
		st.insert(l[0] + w[0]);
		mp[l[0]] = true;
		ll toadd2 = -1, toadd1 = -1, per_yet = (2 * (h[0] + w[0])) % mod;
		ll ans = per_yet;
		set< ll > :: iterator it1, it2;

		for(int i = 1 ; i < n ; i++){
			vector< ll > ar;
			bool flag1 = false, flag2 = false;
			it1 = st.lower_bound(l[i]);
			it2 = st.lower_bound(l[i] + w[i]);
			if( it1 == st.end() or it2 == st.begin() ){
				if( st.begin() == it2 and l[i] + w[i] == *st.begin() ){
					per_yet += 2 * w[i];
					per_yet %= mod;
					ans = (ans * per_yet) % mod;
					mp[*it2] = false;
					st.erase(it2);
					st.insert(l[i]);
					mp[l[i]] = true;
				}
				else{
					per_yet += 2 * (w[i] + h[i]);
					per_yet %= mod;
					ans = (ans * per_yet) % mod;
					st.insert(l[i]);
					st.insert(l[i] + w[i]);
					mp[l[i]] = true;
				}
				continue;
			}
			else if( *it1 == l[i] and (++it1) == st.end() ){
				it1--;
				per_yet += 2 * w[i];
				per_yet %= mod;
				ans = (ans * per_yet) % mod;
				st.erase(it1);
				st.insert(l[i] + w[i]);
				continue;
			}
			if( *it1 == *it2 and mp[*it1] ){
				per_yet += 2 * w[i];
				mp[l[i]] = true;
				if( *it2 == (l[i] + w[i]) ){
					mp[*it2] = false;
					st.erase(it2);
				}
				else{
					st.insert(l[i] + w[i]);
					per_yet += 2 * h[i];
				}
				st.insert(l[i]);
				per_yet %= mod;
				ans = (ans * per_yet) % mod;
				continue;
			}
			if( l[i] != *it1 and mp[*it1] ){
				per_yet += 2 * (*it1 - l[i]);              //remember to remove the useless points inside the set
				per_yet %= mod;
				mp[*it1] = false;
				ar.pb(*it1);
				toadd1 = l[i];
				it1++;
				flag1 = true;
			}
			if( it2 == st.end() ){
				it2--;
				per_yet += 2 * (l[i] + w[i] - *it2);
				per_yet %= mod;
				ar.pb(*it2);
				toadd2 = l[i] + w[i];
				it2--;
				flag2 = true;
			}
			else if( *it2 > (l[i] + w[i]) and mp[*it2] ){
				it2--;
				ar.pb(*it2);
				toadd2 = l[i] + w[i];
				per_yet += 2 * (l[i] + w[i] - *it2);
				per_yet %= mod;
				it2--;
				flag2 = true;
			}
			if( !flag1 and (l[i] == *it1 and mp[*it1]) )
				it1++;
			if( !flag2 and ((l[i] + w[i] <= *it2 and !mp[*it2]) ))
				it2--;
			for( ; *it1 < *it2 ; it1++){
				ar.pb(*it1);
				ll temp = *it1;
				it1++;
				per_yet += (2 * (*it1 - tempa - h[i])) % mod;
				per_yet = (per_yet + mod) % mod;
				mp[*it1] = false;
				ar.pb(*it1);
			}
			ans = (ans * per_yet) % mod;
			for(int j = 0 ; j < ar.size() ; j++){
				mp[ar[j]] = false;
				st.erase(st.find(ar[j]));
			}
			if( toadd1 > -1 ){
				st.insert(toadd1);
				mp[toadd1] = true;
				toadd1 = -1;
			}
			if( toadd2 > -1 ){
				st.insert(toadd2);
				toadd2 = -1;
			}
		}
		cout << "Case #" << r << ": " << ans << endl;
	}
	return(0);
}