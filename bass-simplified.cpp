class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, i = prices.size()-1, j = prices.size()-2;
        while(j>=0){
            if(prices[i] - prices[j] > max) max = prices[i] - prices[j];
            else if(prices[i] < prices[j]) i = j;
            j--;
        }
        return max;
    }
};

// this solution is the best
