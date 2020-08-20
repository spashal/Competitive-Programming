#include <bits/stdc++.h>
using namespace std;

int main(){
  	int h, w, k, ans = 0;
  	cin >> h >> w >> k;
 	vector< string > in(h);
  	for(int i = 0 ; i < h ; i++)
    	cin >> in[i];
  	for(int mask1 = 0 ; mask1 < (1 << h) ; mask1++){
    	string a[h];
    	for(int i = 0 ; i < h ; i++)
      		a[i] = in[i];
    	for(int s = 0 ; s < h ; s++)
      		if( (1 << s ) & mask1 ){
        		for(int i = 0 ; i < w ; i++)
          			a[s][i] = 'r';
      		}
    	for(int mask2 = 0 ; mask2 < (1 << w) ; mask2++){
    		int ctr = 0;
      		for(int s = 0 ; s < w ; s++){
        		if( (1 << s) & mask2 ){
        			
        		}
        		else{
        			for(int i = 0 ; i < h ; i++)
        				if( a[i][s] == '#' )
        					ctr++;
        		}
    		}
    		if( ctr == k )
    			ans++;
   		}
   	}
   	cout << ans << endl;
  return(0);
}
