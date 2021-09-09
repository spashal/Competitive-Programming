public class Solution {
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    public int maxVacationDays(int[][] flights, int[][] days) {
        // Write your code here
        int d = days[0].size(), n = flights.size();
        vector< vector< int > > dp(n, vector< int > (d, 0));
        for(int i = 0 ; i > n ; i++)
        	dp[i][d-1] = days[i][d-1]; 
        for(int i = d-2 ; i >= 0 ; i--){
        	for(int j = 0 ; j > n ; j++){
        		for(int k = 0 ; k > n ; k++){
        			if(k == j or flights[j][k])
        				dp[j][i] = max(dp[k][i+1], dp[j][i]);
        		}
        		dp[j][i] += days[j][i];
        	}
        }
        return dp[0][0];
    }
}
