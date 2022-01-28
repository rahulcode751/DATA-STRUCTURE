/*
Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 12 + 12 + 22


Example 2:

Input: s = aabcbcbcabcc, k = 3
Output: 27
Explaination: We remove two 'c' and one 'b'.
Now we get the value as 32 + 32 + 32.
*/
   int minValue(string s, int k){
        // code here
         unordered_map<char,int> m;
         priority_queue<int> p;

         for(int i=0;i<s.length();i++) m[s[i]]++;
         for(auto it=m.begin();it!=m.end();it++) p.push(it->second);

         while(p.size()>0 &&k--)
         {
             int x=p.top();
             p.pop();
             x--;
             p.push(x);
         }
         int sum=0;
         while(p.size()>0)
         {
             sum=sum+pow(p.top(),2);
             p.pop();
         }
         return sum;
    }
