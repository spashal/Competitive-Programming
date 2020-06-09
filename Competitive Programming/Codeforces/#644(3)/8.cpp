#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, p[65], m, v[105];
queue< ll > q;

ll bToD( char s[] ){
	ll ans = 0;
	for( int i = 0 ; i < m ; i++ )
		ans += p[m-1-i]*(s[i]-48);
	return ans;
}

string dToB( ll a ){
	string s;
	for( int i = m - 1 ; i >= 0 ; i-- ){
		if( (a/p[i]) == 1 )
			s.push_back('1');
		else
			s.push_back('0');
		a %= p[i];
	}
	return s;
}

int main(){
	p[0] = 1;
	for( int i = 1 ; i < 61 ; i++ )
		p[i] = p[i-1]*2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		int r = 0, median;
		char s[200];
		cin >> n >> m;
		for( int i = 0 ; i < n ; i++ ){
			cin >> s;
			v[i] = bToD(s);
		}
		sort( v, v + n, greater< ll > ());
		median = p[m-1] - 1;
		for( int i = 0 ; i < n ; i++ )
			if( median >= v[i] ){
				r = i;
				// cout << r << "**" << endl;
				break;
			}
		if( r == 0 ){
			if( v[0] <= median ){
				while( r < n - r ){
					median++;
					r++;
				}
				// cout << "wow" << endl;
			}
			else{
				// cout << "WHOA" << endl;
				median -= ceil(n/2);
			}
		}
		else if( r < (n-r) ){
			for( int i = r - 1 ; i > -1 ; i-- )
				q.push(v[i]);
			// median += ((n-r)-r)/2;
			while( !q.empty() and median < q.front() and r < (n-r)){
				median++;
				r++;
				while( !q.empty() and median == q.front() and r < (n-r) ){
					q.pop();
					median++;
					r++;
				}
			}
			// cout << "hi" << endl;
		}
		else if( r > n-r ){
			for( int i = r ; i < n ; i++ )
				q.push(v[i]);
			while( !q.empty() and median > q.front() and r > (n-r) ){
				q.pop();
				median--;
				r--;
				while( !q.empty() and median == q.front() and r > (n-r) ){
					q.pop();
					median--;
					r--;
				}
			}
			// cout << "bye" << endl;
		}
		cout << dToB(median) << endl;
		while( !q.empty() )
			q.pop();
	}
	return(0);
}