/// leetcode qustion 231 link -> https://leetcode.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int n) {
    if(n < 0) return 0;
	int counter = 0;
	while(n){
		counter++;
        n = n&(n-1);
	}
	if(counter == 1) return 1;
    else return 0;
    }
};
