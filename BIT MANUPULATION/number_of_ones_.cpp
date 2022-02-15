/// leetcode qustion 191 link -> https://leetcode.com/problems/number-of-1-bits/submissions/

class Solution {
public:
    int hammingWeight(uint32_t n) {
    uint32_t temp = n;
	int f = 1;
	int counter = 0;
	while(temp > 0){
		int ans = temp&f;
	    if(ans != 0) counter++;
	    temp = temp>>1;
	}
	return counter;
    }
};
