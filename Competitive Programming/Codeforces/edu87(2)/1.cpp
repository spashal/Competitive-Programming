#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, in[5];
char n[200005];
ll a[200005];
queue< ll> q;

void fun( ll s){
	while( !q.empty() and in[1] and in[2] and in[3] ){
		a[q.front()] = s - q.front() + 1;
		in[n[q.front()]-48]--;
		q.pop();
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ll k = 0;
		ll na = strlen(n);
		for( int i = 0 ; i < na ; i++ )
			a[i] = 0;
		in[1] = 0;
		in[2] = 0;
		in[3] = 0;
		for( int i = 0 ; i < na ; i++ ){
			q.push(i);
			in[n[i]-48]++;
			fun(i);
		}
		ll ans = na + 5;
		for( int i = 0 ; i < na ; i++ ){
			if( !a[i] )
				k++;
			else{
				ans = min( ans, a[i]);
			}
		}
		if( k == na )
			cout << "0" << endl;
		else{
				cout << ans << endl;
		}
		while( !q.empty() )
			q.pop();
	}
	return(0);
}