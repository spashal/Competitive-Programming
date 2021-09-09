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
		string s;
		cin >> s;
		if(s[0] != '?'){
			for(int i = 0 ; i < n ; i++){
				if(s[i] == '?'){
					s[i] = (s[i-1] == 'R') ? 'B': 'R';
				}
			}
			cout << s << endl;
		}
		else{
			int ans1 = 0, ans2 = 0;
			string temp = s;
			s[0] = 'R';
			for(int i = 0 ; i < n ; i++){
				if(s[i] == '?'){
					s[i] = (s[i-1] == 'R') ? 'B': 'R';
				}
			}
			for(int i = 0 ; i < n-1 ; i++)
				if(s[i] == s[i+1])
					ans1++;
			temp[0] = 'B';
			for(int i = 0 ; i < n ; i++){
				if(temp[i] == '?'){
					temp[i] = (temp[i-1] == 'R') ? 'B': 'R';
				}
			}
			for(int i = 0 ; i < n-1 ; i++)
				if(temp[i] == temp[i+1])
					ans2++;
			if(ans1 < ans2)
				cout << s << endl;
			else
				cout << temp << endl;
		}
		
	}
	return(0);
}