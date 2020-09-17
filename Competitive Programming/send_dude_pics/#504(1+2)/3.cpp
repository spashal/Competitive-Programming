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
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    stack< ll > stk;
    vector< ll > ar;
    for(int i = 0 ; i < n ; i++){
    	if( !stk.empty() and s[i] == ')' ){
    		ar.pb(i);
    		ar.pb(stk.top());
    		stk.pop();
    	}
    	else if( s[i] == '(' )
    		stk.push(i);
    	if( ar.size() == k )
    		break;
    }
    sort(ar.begin(), ar.end());
    for(int i = 0 ; i < ar.size() ; i++)
    	cout << s[ar[i]];
    cout << endl;
	return(0);
}