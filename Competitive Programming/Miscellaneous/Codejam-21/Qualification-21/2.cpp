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
	
void fun(ll index, string &s){
	if(s[index] == '?'){
		bool one = false;
		bool two = false;
		if(index + 1 < s.size() and s[index + 1] != '?')
			one = true;
		if(index > 0 and s[index - 1] != '?')
			two = true;
		if(!one and !two){
			if(index + 1 < s.size())
				fun(index + 1, s);
		}
		if((index > 0 and s[index - 1] == 'C') or (index + 1 < s.size() and s[index + 1] == 'C'))
			s[index] = 'C';
		else
			s[index] = 'J';
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	for(int i = 1 ; i <= t ; i++){
		cin >> n >> m;
		string s;
		cin >> s;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '?')
				fun(i, s);
		}
		ll cost = 0;
		for(int j = 0 ; j + 1 < s.size() ; j++){
			if(s[j] == 'C' and s[j + 1] == 'J')
				cost += n;
			if(s[j] == 'J' and s[j + 1] == 'C')
				cost += m;
		}
		cout << "Case #" << i << ": " << cost << endl;
	}
	return(0);
}