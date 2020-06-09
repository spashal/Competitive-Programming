#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;
int f[100005], b[100005];

int fun( int a){
	if( f[a] != -1 )
		return f[a];
	int Max = 0;
	for( int i = a * 2 ; i <= n ; i += a )
		if( b[i] > b[a] )
			Max = max( Max, fun(i));
	f[a] = Max + 1;
	return f[a];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 1 ; i <= n ; i++ ){
			cin >> b[i];
			f[i] = -1;
		}
		for( int i = 1 ; i <= n ; i++ )
			fun(i);
		int ans = 0;
		for( int i = 1 ; i <= n ; i++ )
			ans = max( ans, f[i]);
		cout << ans << endl;
	}
	return(0);
}