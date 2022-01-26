/*
Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
*/
void reverse(stack<int> &st)
{
	if(st.size()>0)
	{
		int x = st.top();
		st.pop();
		reverse();
		st.push(x);
	}
}
void interLeaveQueue(queue<int>& q)
{
    int size = q.size();
    stack<int> s;
    for(int i=0;i<size/2;i++){
        s.push(q.front());
        q.pop();
    }
    reverse(s);
    int a = size/2;
    while(a--){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
