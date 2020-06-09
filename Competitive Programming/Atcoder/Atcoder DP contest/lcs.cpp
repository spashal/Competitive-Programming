#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005], parent[1005][1005];
string a, b, res;

int main(){
	cin >> a;
	cin >> b;
	int A = (int)a.size();
	int B = (int)b.size();
	for( int i = 0 ; i <= A ; i++ ){
		for( int j = 0 ; j <= B ; j++ ){
			if( i == 0 or j == 0 )
				dp[i][j] = 0;
			else if( a[i-1] == b[j-1] ){
				dp[i][j] = dp[i-1][j-1] + 1;
				parent[i][j] = -1 * i;
			}
			else{
				if( dp[i-1][j] > dp[i][j-1] ){
					dp[i][j] = dp[i-1][j];
					parent[i][j] = i-1;
				}
				else{
					dp[i][j] = dp[i][j-1];
					parent[i][j] = i;
				}
			}
		}
	}
	int i = A, j = B;
	while( i > 0 and j > 0 and dp[i][j] > 0 ){
		if( parent[i][j] < 0 ){
			res.push_back(a[i-1]);
			i--;
			j--;
		}
		else{
			if( parent[i][j] == i )
				j--;
			else
				i--;
		}
	}
	if( res.size() > 0 )
		for( i = (int)res.size() - 1 ; i > -1 ; i-- )
			cout << res[i];
	cout << endl;
	return(0);
}