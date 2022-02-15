/// leetcode 338 link --> https://leetcode.com/problems/counting-bits/submissions/
class Solution {
public:
    vector<int> countBits(int n) {
    /*    vector<int> ans;
        ans.push_back(0);
        int i=0;
        while(i<=n){
            int f = 1;
	        int counter = 0;
            int temp = i;
	        while(temp > 0){
		        int ans = temp&f;
	            if(ans != 0) counter++;
	            temp = temp>>1;
            }
            ans.push_back(counter);
        }
        return ans;  */

        vector<int> ans;
        int num = n;
        for(int i=0; i<=num; i++){
            n = i;
            int counter = 0;
            while(n){
                counter++;
                n = n&(n-1);
            }
            ans.push_back(counter);
        }
        return ans;
    }
};
