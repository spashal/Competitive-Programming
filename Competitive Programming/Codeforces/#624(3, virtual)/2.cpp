#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, t, m, a[105], eye[105];

int main(){
	cin >> t;
	while( t-- ){
		priority_queue< pair< ll, ll> > pq;
		cin >> n >> m;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
			pq.push(make_pair(a[i], i));
		}
		for(int i = 0 ; i < m ; i++)
			cin >> eye[i];
		sort(eye, eye + m);
		int r = -1;
		int z = 0;
		for(int j = 0 ; j < n ; j++){
			int maxi = 0;
			int last = 0;
			for(int k = 0 ; k < n - j ; k++){
				if( maxi < a[k] ){
					last = k;
					maxi = a[k];
				}
			}
			int al = last;
			r++;
			int cool = 0;
			for(int i = 0 ; i < m ; i++){
				if( eye[i] - 1 == al ){
					if( m - i == n - al ){
						cool = 1;
						a[al] = a[n-j-1];
					}
					break;
				}
			}
			if( cool == 0 ){
				z = 1;
				break;
			}
		}
		if( !z )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return(0);
}