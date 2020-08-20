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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string s;
    cin >> s;
    vector< int > dp(n, -1);
    dp[n - 1] = 0;
    string s1(n, '$');
    s1[n - 1] = s[n - 1];
    string s2(n, '$');
    s2[n - 1] = s[n - 1];
    for(int i = n - 2 ; i >= 0 ; i--){
    	if( s1[i + 1] == s[i] and s2[i + 1] == s[i] ){
 			dp[i] = dp[i + 1] + 1;
 			if( s[i] == 'R' ){
 				s1[i] = 'B';
 				s2[i] = 'G';
 			}
 			else if( s[i] == 'G' ){
 				s1[i] = 'B';
 				s2[i] = 'R';
 			}
 			else{
 				s1[i] = 'G';
 				s2[i] = 'R';
 			}
 			continue;
    	}
    	if( s1[i + 1] != s[i] ){
    		dp[i] = dp[i + 1];
    		s1[i] = s[i];
    		if( i < n - 2 )
    			s2[i + 1] = s1[i + 1];
    		s2[i] = s[i];
    		continue;
    	}
    	if( s2[i + 1] != s[i] ){
    		dp[i] = dp[i + 1];
    		s2[i] = s[i];    		
    		if( i < n - 2 )
    			s1[i + 1] = s2[i + 1];
    		s1[i] = s2[i];
    	}
    }
    cout << dp[0] << endl << s1 << endl;
	return(0);
}