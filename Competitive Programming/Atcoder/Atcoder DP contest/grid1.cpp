#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll h, w, dp[1005][1005], mod = 1000000007;
string s[1005];
queue< pair< ll, ll> > q;
bool vis[1005][1005];

int main(){
	cin >> h >> w;
	for( ll i = 0 ; i < h ; i++ )
		cin >> s[i];
	dp[h-1][w-1] = 1;
	if( s[h-1][w-2] == '.'){
    	vis[h-1][w-2] = true;
		q.push( make_pair( h-1, w-2));
        }
	if( s[h-2][w-1] == '.'){
    	vis[h-2][w-1] = true;
		q.push( make_pair( h-2, w-1));
        }
	while( !q.empty() ){
		pair< ll, ll> a = q.front();
		q.pop();
		if( a.first > 0 and s[a.first - 1][a.second] == '.' and !vis[a.first - 1][a.second] ){
			q.push( make_pair( a.first - 1, a.second));
            vis[a.first - 1][a.second] = true;
        }
		if( a.second > 0 and s[a.first][ a.second - 1] == '.' and !vis[a.first][a.second - 1] ){
			q.push( make_pair( a.first, a.second - 1));
            vis[a.first][a.second - 1] = true;
        }
		if( a.second < w-1 and a.first < h-1 ){
			if( s[a.first+1][a.second] == '.' and s[a.first][a.second+1] == '.' )
				dp[a.first][a.second] = ( dp[a.first+1][a.second] + dp[a.first][a.second+1]) % mod;
			else if( s[a.first+1][a.second] == '#' )
				dp[a.first][a.second] = dp[a.first][a.second + 1];
			else
				dp[a.first][a.second] = dp[a.first + 1][a.second];
		}
		else if( a.second < w-1 )
			dp[a.first][a.second] = dp[a.first][a.second+1];
		else
			dp[a.first][a.second] = dp[a.first+1][a.second];
	}
	cout << dp[0][0] << endl;
	return(0);
}
