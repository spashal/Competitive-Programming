#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// class Solution {
// public:
//     vector< ll > inp;
//     ll sums = 0;
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         // inp.resize(nums.size(), 0);
//         // inp = nums;
//         for(int i = 0 ; i < nums.size() ; i++)
//             inp.push_back(nums[i]);

//         for(int i = 0 ; i < nums.size() ; i++)
//             sums += nums[i];
//         if( sums % k )
//             return false;
//         sums /= k;
//         vector< bool > used(nums.size(), false);
//         return call(used, 0, nums.size());
//     }
//     bool call(vector< bool >& used, ll cursum, ll count){
//         if( count == 0 and cursum == 0 )
//             return true;
//     	vector< bool > temp;
//         // temp = used;
//         for(int i = 0 ; i < inp.size() ; i++)
//             temp.push_back(used[i]);
//         for(int i = 0 ; i < inp.size() ; i++)
//             if( !used[i] ){
//                 used[i] = true;
//                 count--;
//                 if( cursum < sums and call(used, cursum + inp[i], count))
//                     return true;
//                 else if( cursum == sums and call(used, 0, count))
//                     return true;
//                 for(int j = 0 ; j < inp.size() ; j++)
//                     used[j] = temp[j];
//             }
//         return false;
//     }
// };

//the above is a slow solution
//below is the fater version

class Solution {
public:
    vector< ll > inp, dp;
    ll sums = 0;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        dp.resize((1 << nums.size()), -1);
        // inp = nums;
        for(int i = 0 ; i < nums.size() ; i++)
            inp.push_back(nums[i]);

        for(int i = 0 ; i < nums.size() ; i++)
            sums += nums[i];
        if( sums % k )
            return false;
        sums /= k;
        vector< bool > used(nums.size(), false);
        return call(0, 0);
    }
    bool call(int mask, int cursum){
        // cout << mask << " " << cursum << endl;
        if( dp[mask] != -1 ){
            // cout << "*1*";
            return dp[mask];
        }
        if( mask == ((1 << inp.size()) - 1)){
            // cout << "*2*";
            dp[mask] = 1;
            return dp[mask];
        }
        for(int i = 0 ; i < inp.size() ; i++)
            if( ((1 << i) & mask) == 0 ){
                // count--;
                cursum += inp[i];
                if( cursum < sums and call(mask | (1 << i), cursum)){
                    dp[mask] = 1;
                    return 1;
                }
                else if( cursum == sums and call(mask | (1 << i), 0)){
                    dp[mask] = 1;
                    return true;
                }
                cursum -= inp[i];
            }
        // cout << "*3*";
        dp[mask] = 0;
        return false;
    }
};

// class Solution{
// public:
//     bool canPartitionKSubsets(vector< int > & nums, int k){
//         vector< bool > dp((1 << nums.size()), 0);
//         ll sums = 0;
//         for(int i = 0 ; i < nums.size() ; i++)
//             sums += nums[i];
//         if( sums % k or sums == 0 )
//             return false;
//         sums /= k;
//         return call((1 << nums.size()) - 1); 
//     }

// };

int main(){
	int k, n;
	cin >> n;
	Solution solve;
	vector< int > inp(n, 0);
	for(int i = 0 ; i < n ; i++)
		cin >> inp[i];
	cin >> k;
	cout << solve.canPartitionKSubsets(inp, k) << endl;
	return 0;
}