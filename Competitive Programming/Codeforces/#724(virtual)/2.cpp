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

bool check(string &word, int index, string &ans){
	if(word.size() < ans.size() + index)
		return false;
	for(int i = index ; i < ans.size() + index ; i++)
		if(word[i] != ans[i-index])
			return false;
	return true;
}
	
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		string s;
		cin >> s;
		bool found = false;
		for(int i = 0 ; i < 26 ; i++){
			bool present = false;
			for(int j = 0 ; j < n ; j++)
				if(s[j] - 'a' == i)
					present = true;
			if(!present){
				cout << (char)('a' + i) << endl;
				found = true;
				break;
			}
		}
		if(found)
			continue;
		for(int i = 0 ; i < 26 ; i++){
			for(int j = 0 ; j < 26 ; j++){
				bool present = false;
				string ans;
				ans.pb('a'+i);
				ans.pb('a'+j);
				for(int k = 0 ; k < n ; k++)
					if(check(s, k, ans))
						present = true;
				if(!present){
					cout << ans << endl;
					found = true;
					break;
				}
			}
			if(found)
				break;
		}
		if(found)
			continue;

		for(int i = 0 ; i < 26 ; i++){
			for(int j = 0 ; j < 26 ; j++){
				for(int ij = 0 ; ij < 26 ; ij++){
					bool present = false;
					string ans;
					ans.pb('a'+i);
					ans.pb('a'+j);
					ans.pb('a'+ij);
					for(int k = 0 ; k < n ; k++)
						if(check(s, k, ans))
							present = true;
					if(!present){
						cout << ans << endl;
						found = true;
						break;
					}
				}
				if(found)
				break;
			}
			if(found)
				break;
		}
		if(found)
			continue;
	}
	return(0);
}