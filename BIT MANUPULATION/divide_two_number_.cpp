/// qustion link -> https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) return dividend == INT_MIN ? INT_MAX : 0 - dividend;
        bool neg = (dividend < 0) ^ (divisor < 0);
        int count = 0;
        long long a = abs(dividend);
        long long b = abs(divisor);
        int ct = 1;

        while(b <= a){
            count += ct;
            a = a-b;
            b = b<<1;
            ct = ct<<1;
        }
        divisor = abs(divisor);
        while(divisor <= a){
            count++;
            a -= divisor;
        }
        return neg ? 0 - count : count;
    }
};
/// gfg qustion link -> https://practice.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1/#
class Solution
{
    public:
    long long divide(long long a, long long b)
    {
        if(a== 0) return 0;
        int sign = 1;
        if(a<0 && b>0) sign = -1;
        if(b<0 && a>0) sign = -1;

        a = abs(a);
        b = abs(b);
        int x = b;
        int count,result=0;
        while(a - b >= 0){
            count = 1;
            while((a - (b<<1)) >= 0){
                count = count<<1;
                b = b<<1;
            }
            a = a-b;
            b = x;
            result = result+count;
        }

        return sign*result;

    }
};
