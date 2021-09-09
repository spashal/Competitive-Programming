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

int fun(string s, string t, int i, int j, map<pair<int, int>,int> &ans, vector<set<int> > &pos){
	// cout << i << " " << j << endl;
	if(j == t.size() and (s.size()-i)%2 == 0)
		return 1;
	else if(i < 0 or j < 0 or i >= s.size())
		return -1;
	else if(ans[mp(i,j)] != 0)
		return ans[mp(i,j)];
	// cout << "here" << endl;
	if(s.size()-i < t.size()-j){
		ans[mp(i,j)] = -1;
		return -1;
	}
	if(s[i] != t[j] and j > 0){
		ans[mp(i,j)] = -1;
		return -1;
	}
	if(s[i] != t[j]){
		// cout << "??" << endl;
		if(j == 0 and fun(s, t, i+1, j, ans, pos) > 0){
			ans[mp(i,j)] = 1;
			return 1;
		}
		ans[mp(i,j)] = fun(s, t, i+2, j, ans, pos);
		return ans[mp(i,j)];
	}
	else if(s[i] == t[j]){
		if(j == t.size()-1 and (s.size()-i-1)%2 == 0){
			ans[mp(i,j)] = 1;
			return 1;
		}
		else if(j == t.size()-1){
			ans[mp(i,j)] = -1;
			return -1;
		}
		// cout << "**v " << t[j+1]-'a' << endl;
		// for(set<int> :: iterator it = pos[t[j+1]-'a'].begin() ; it!=pos[t[j+1]-'a'].end();it++)
		// 	cout << *it << " ";
		// cout << "haha" << endl;
		set<int> :: iterator it = pos[t[j+1]-'a'].lower_bound(i);
		// cout << "kya hua " << *it << endl;
		for(; it != pos[t[j+1]-'a'].end() ; it++)
			if(((*it-i-1)%2 == 0 or j == 0)and fun(s, t, *it, j+1, ans, pos) > 0){
				// cout << "&&" << *it << endl;
				ans[mp(i,j)] = 1;
				return 1;
			}
	}
	ans[mp(i,j)] = -1;
	return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		string s, t;
		cin >> s >> t;
		vector<set<int> > pos(26);
		map<pair<int, int>,int> ans;
		for(int i = 0 ; i < s.size() ; i++)
			pos[s[i]-'a'].insert(i);
		if(fun(s, t, 0, 0, ans, pos) > 0)
			cout << "Yes\n";
		else
			cout << "No\n";
		// remember to clear pos
	}
	return(0);
}