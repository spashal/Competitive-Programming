#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, a[200005];
vector< int > v;
queue< pair< int , pair< int, int> > > q;

void fun2(){
	ll k = 0;
	for( int i = 0 ; i < v.size() ; i++ )
		a[v[i]] = ++k;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 1 ; i <= n ; i++ )
			a[i] = 0;
		if( n % 2 ){
			q.push( make_pair( n / 2 + 1, make_pair( 1, n)));
			v.push_back( n / 2 + 1);
		}
		else{
			q.push( make_pair( n / 2, make_pair( 1, n)));
			v.push_back( n / 2);
		}
		while( !q.empty() ){
			ll w = q.front().first;
			ll A = q.front().second.first;
			ll b = q.front().second.second;
			q.pop();
			if( ( w - A ) % 2 == 0 and A + ( w - A )/2 - 1 >= A and w != A ){
				q.push( make_pair( A + ( w - A )/2 - 1, make_pair(A, w - 1)));
				v.push_back(A+(w-A)/2 - 1);
			}
			else if( ( w - A ) % 2 == 1 and A + ( w - A )/2 >= A and A + ( w - A )/2 < w ){
				q.push( make_pair( A + ( w - A )/2, make_pair( A, w - 1)));
				v.push_back( A + ( w - A )/2);
			}
			else if( ( w - A ) == 1 ){
				q.push( make_pair( A, make_pair( A, w - 1)));
				v.push_back(A);
			}
			if( ( b - w ) % 2 == 0 and w + ( b - w )/2 <= b and w != b ){
				q.push( make_pair( w + ( b - w )/2, make_pair( w + 1, b)));
				v.push_back( w + ( b - w )/2);
			}
			else if( ( b - w ) % 2 == 1 and w + ( b - w )/2 <= b and w + ( b - w ) / 2 > w ){
				q.push( make_pair( w + ( b - w ) / 2, make_pair( w + 1, b)));
				v.push_back( w + ( b - w )/2);

			}
			else if( b - w == 1 ){
				q.push( make_pair( b, make_pair( b, b)));
				v.push_back(b);
			}
		}
		fun2();
		for( int i = 1 ; i <= n ; i++ )
			cout << a[i] << " ";
		cout << endl;
		v.clear();

	}
	return(0);
}