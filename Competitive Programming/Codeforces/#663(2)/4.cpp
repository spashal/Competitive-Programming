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
string s[1000006];
void printar(vector< ll > ar, ll l, ll r){
	for(int i = l ; i < r ; i++)
		cout << ar[i] << " ";
	cout << endl;
}
 
bool checker(int a, int b){
    if( ((a & 1) ^ ((a & 2) >> 1 ) ^ (b & 1) ^ ((b & 2) >> 1)) and
        ((a & 2) ^ ((a & 4) >> 1 ) ^ (b & 2) ^ ((b & 4) >> 1)))
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    ll ans = 0;

    vector< int > cnt(8, 0);
    for(int i = 0 ; i < 8 ; i++){
        if( i & 1 )
            cnt[i]++;
        if( i & 2 )
            cnt[i]++;
        if( i & 4 )
            cnt[i]++;
    }
    vector< vector< bool > > comp3(8, vector< bool > (8, false)), comp2(4, vector< bool > (4, false));
    for(int prevmsk = 0 ; prevmsk < 8 ; prevmsk++)
        for(int curmsk = 0 ; curmsk < 8 ; curmsk++)
            comp3[prevmsk][curmsk] = checker(prevmsk, curmsk);
    for(int prevmsk = 0 ; prevmsk < 4 ; prevmsk++)
        for(int curmsk = 0 ; curmsk < 4 ; curmsk++)
            if( ((prevmsk & 1) ^ ((prevmsk & 2) >> 1 ) ^ (curmsk & 1) ^ ((curmsk & 2) >> 1)) )
                comp2[prevmsk][curmsk] = true;

    for(int i = 0 ; i < n ; i++)
    	cin >> s[i];
    if( n >= 4 and m >= 4 ){
    	cout << "-1" << endl;
    	return (0);
    }
    if( n < 2 or m < 2 ){
    	cout << "0" << endl;
    	return (0);
    }
    vector< vector< ll > > dp(max(n, m), vector< ll > ((1 << min(n, m)), INT_MAX));
    vector< ll > a(max(n, m), 0), b(max(n, m), 0);
    for(int j = 0 ; j < m ; j++)
        for(int i = 0 ; i < n ; i++)
            if( s[i][j] == '1' )
                a[j] += (1 << i);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if( s[i][j] == '1' )
                b[i] += (1 << j);
    if( n == min(n, m) and n == 3 ){
        for(int curmsk = 0 ; curmsk < 8 ; curmsk++)
            dp[0][curmsk] = cnt[a[0] ^ curmsk];
        for(int i = 1 ; i < m ; i++)
            for(int prevmsk = 0 ; prevmsk < 8 ; prevmsk++)
                for(int curmsk = 0 ; curmsk < 8 ; curmsk++)
                    if( comp3[prevmsk][curmsk] )
                        dp[i][curmsk] = min(dp[i][curmsk], dp[i - 1][prevmsk] + cnt[curmsk ^ a[i]]);
    }
    else if( n == min(n, m) and n == 2 ){
        for(int curmsk = 0 ; curmsk < 4 ; curmsk++)
            dp[0][curmsk] = cnt[a[0] ^ curmsk];
        for(int i = 1 ; i < m ; i++)
            for(int prevmsk = 0 ; prevmsk < 4 ; prevmsk++)
                for(int curmsk = 0 ; curmsk < 4 ; curmsk++)
                    if( comp2[prevmsk][curmsk] )
                        dp[i][curmsk] = min(dp[i][curmsk], dp[i - 1][prevmsk] + cnt[curmsk ^ a[i]]);
    }
    else if( m == min(n, m) and m == 3 ){
        for(int curmsk = 0 ; curmsk < 8 ; curmsk++)
            dp[0][curmsk] = cnt[b[0] ^ curmsk];
        for(int i = 1 ; i < n ; i++)
            for(int prevmsk = 0 ; prevmsk < 8 ; prevmsk++)
                for(int curmsk = 0 ; curmsk < 8 ; curmsk++)
                    if( comp3[prevmsk][curmsk] )
                        dp[i][curmsk] = min(dp[i][curmsk], dp[i - 1][prevmsk] + cnt[curmsk ^ b[i]]);
    }
    else{
       for(int curmsk = 0 ; curmsk < 4 ; curmsk++)
            dp[0][curmsk] = b[0] ^ curmsk;
        for(int i = 1 ; i < m ; i++)
            for(int prevmsk = 0 ; prevmsk < 4 ; prevmsk++)
                for(int curmsk = 0 ; curmsk < 4 ; curmsk++)
                    if( comp2[prevmsk][curmsk] )
                        dp[i][curmsk] = min(dp[i][curmsk], dp[i - 1][prevmsk] + curmsk ^ b[i]); 
    }
    ans = INT_MAX;
    if( n == min(n, m) )
        for(int curmsk = 0 ; curmsk < (1 << n) ; curmsk++)
            ans = min(dp[m - 1][curmsk], ans);
    else
        for(int curmsk = 0 ; curmsk < (1 << m) ; curmsk++)
            ans = min(dp[n - 1][curmsk], ans);
    cout << ans << endl;
	return(0);
}