//Question https://leetcode.com/problems/maximum-sum-circular-subarray
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int n = a.size();
        if(n == 1)
            return a[0];
        int min_ans = 30000+10;
        int total_sum = 0;
        int sum = 0;
        // min sum of array
        for(int i = 0; i < n; i++){
            sum = a[i] + min(0,sum);
            min_ans = min(min_ans, sum);
            total_sum += a[i];
        }
        int max_ans = -30000-10;
        sum = 0;
        //max sum of array
        for(int i = 0; i < n; i++){
            sum = a[i] + max(0,sum);
            max_ans = max( max_ans,sum);
        }
        cout << min_ans << endl;
        //
        if(total_sum != min_ans)
            min_ans = total_sum - min_ans;
        return max(max_ans, min_ans);
    }
};
