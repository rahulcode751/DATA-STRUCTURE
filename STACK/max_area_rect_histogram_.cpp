class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> s;
        long long ma = 0;
        long long i = 0;
        while(i<n){
            if(s.empty() or arr[s.top()] <= arr[i]){
                s.push(i++);
            }
            else{
                long long tp = s.top();
                s.pop();
                long long ans = arr[tp]*(s.empty() ? i : i-s.top()-1);
                ma = max(ma,ans);
            }
        }
        while(!s.empty()){
            long long tp = s.top();
            s.pop();
            long long ans = arr[tp]*(s.empty() ? i : i-s.top()-1);
            ma = max(ma,ans);
        }
        return ma;
    }
};
