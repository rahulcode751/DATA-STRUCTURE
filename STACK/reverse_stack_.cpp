#include<bits/stdc++.h>
using namespace std;

stack<char> st;

char reverse()
{
	if(st.size()>0)
	{
		char x = st.top();
		st.pop();
		reverse();
		st.push(x);
	}
}
int main()
{
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');

	cout<<"Original Stack"<<endl;
	cout<<"1"<<" "<<"2"<<" "
		<<"3"<<" "<<"4"
		<<endl;

	reverse();
	cout<<"Reversed Stack"
		<<endl;

	while(!st.empty())
	{
		char p=st.top();
		cout<<p<<" ";
		st.pop();
	}
	return 0;
}
