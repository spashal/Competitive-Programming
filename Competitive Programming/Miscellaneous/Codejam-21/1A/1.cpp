#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, t, aa[100005];
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
	for(int g = 1 ; g <= t ; g++){
		cin >> n;
		ll ans = 0;
		vector< string > s(n);
		for(int i = 0 ; i < n ; i++){
			ll a;
			cin >> a;
			s[i] = to_string(a);
			if(i > 0 and s[i].size() <= s[i - 1].size()){
				int greater = 1;
				for(int j = 0 ; j < min(s[i].size(), s[i - 1].size()) ; j++){
					if(s[i][j] < s[i - 1][j]){
						greater = 2;
						break;
					}
					else if(s[i][j] > s[i - 1][j]){
						greater = 0;
						break;
					}
				}
				if(greater == 0)
					for(int j = s[i].size() ; j < s[i - 1].size() ; j++){
						s[i].pb('0');
						ans++;
					}
				else if(greater == 1){
					if(s[i].size() == s[i - 1].size()){
						s[i].pb('0');
						ans++;
					}
					else{
						int ctr = s[i].size();
						for(int j = s[i - 1].size() - 1 ; j >= s[i].size() ; j--){
							if(s[i - 1][j] == '9')
								ctr++;
							else
								break;
						}
						if(ctr == s[i - 1].size()){
							for(int j = s[i].size() ; j <= s[i - 1].size() ; j++){
								s[i].pb('0');
								ans++;
							}
						}
						else{
							ll index = s[i].size() - 1 + s[i - 1].size() - ctr;
							for(int j = s[i].size() ; j < index ; j++){
								s[i].pb(s[i - 1][j]);
								ans++;
							}
							s[i].pb((char)((int)s[i - 1][index] + 1));
							ans++;
							for(int j = index + 1 ; j < s[i - 1].size() ; j++){
								s[i].pb('0');
								ans++;
							}
						}
					}
				}
				else{
					for(int j = s[i].size() ; j <= s[i - 1].size() ; j++){
						s[i].pb('0');
						ans++;
					}
				}
			}
		}
			cout << "Case #" << g << ": " << ans << endl;
	}
	return(0);
}