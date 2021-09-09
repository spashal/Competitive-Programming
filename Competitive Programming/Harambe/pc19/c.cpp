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
    ll n, q;
    cin >> t >> n;
    map<int, int> mainmap;
    vector< int > inp(n, 0);
    for(int i = 0 ; i < n ; i++)
    	cin >> inp[i];
    sort(inp.begin(), inp.end());
    map<int, int> count;
    for(int i = 0 ; i < n ; i++)
    	count[inp[i]]++;
    vector<int>::iterator ip;
    ip = unique(inp.begin(), inp.end());
    inp.resize(distance(inp.begin(), ip));
    int ctr = 0;
    set<int> st;
    for(int i = 0 ; i < inp.size() ; i++){
    	ctr += count[inp[i]];
    	mainmap[ctr] = inp[i];
    	st.insert(ctr);
    }
    cin >> q;
    for(int i = 0 ; i < q ; i++){
    	ll query;
    	cin >> query;
    	set<int> :: iterator it = st.upper_bound(query);
    	if(it == st.end()){
    		cout << t << endl;
    		continue;
    	}
    	cout << mainmap[*it]-1 << endl;
    }
	return(0);
}