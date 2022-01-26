/// SORT A STACK IN O(N)
void insert_correct_position(int x,stack<int> &s){
    if(s.size() == or s.top() < x) s.push(x);
    else{
        int a = s.top();
        s.pop();
        insert_correct_position(x,s);
        s.push(a);
    }
}

void reverse(stack<int> &st)
{
	if(st.size()>0)
	{
		int x = st.top();
		st.pop();
		reverse();
		insert_correct_position(x,st);
	}
}

void sort_stack(stack<int> &s){
    reverse(s);
}
