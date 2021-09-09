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
		stack< ll > stk;
		vector< string > ans;
		string prefix;
		for(int i = 0 ; i < n ; i++){
			ll num;
			cin >> num;
			if(!stk.empty() and stk.top() != num-1){
				if(num == 1){
					prefix += to_string(stk.top());
					prefix += '.';
					ans.pb((string)(prefix + to_string(num)));
					stk.push(num);
					continue;
				}
				while(!stk.empty() and stk.top() != num-1){	
					int ctr = stk.top();
					while(!stk.empty() and ctr){
						stk.pop();
						ctr--;
					}
					ctr = 0;
					for(int i = prefix.size() - 2 ; i >= 0 ; i--){
						if(prefix[i] == '.')
							break;
						ctr++;
					}
					prefix = prefix.substr(0, prefix.size() - 1 - ctr);
				}
				ans.pb((string)(prefix + to_string(num)));
				stk.push(num);
			}
			else if(!stk.empty()){
				ans.pb((string)(prefix + to_string(num)));
				stk.push(num);
			}
			else{
				string temp;
				temp += to_string(num);
				ans.pb(temp);
				stk.push(num);
				prefix = "";
			}
		}
		for(int i = 0 ; i < n ; i++)
			cout << ans[i] << endl;
	}
	return(0);
}