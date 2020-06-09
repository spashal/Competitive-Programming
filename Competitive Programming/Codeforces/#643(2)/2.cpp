#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, a;
vector< ll > v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 0 ; i < n ; i++ ){
			cin >> a;
			v.push_back(a);
		}
		sort( v.begin(), v.end());
		ll spare = 0, ans = 0;
		for( int i = 0 ; i < n ; i++ ){
			if( v[i] == 1 ){
				ans++;
			}
			else{
				if( v[ v[i] + i - 1 ] == v[i] ){
					ans++;
					i = v[i] + i - 1;
				}
				else if( spare + 1 >= v[i] ){
					ans++;
					spare -= v[i] - 1;
				}
				else
					spare++;
			}
		}
		v.clear();
		cout << ans << endl;
	}
	return(0);
}