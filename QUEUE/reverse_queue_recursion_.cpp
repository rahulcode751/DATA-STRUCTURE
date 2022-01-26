#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<long long int>& q)
{
	if (q.empty()) return;
	long long int data = q.front();
	q.pop();
	reverseQueue(q);
	q.push(data);
}
void printQueue(queue<long long int> Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}


int main()
{
	queue<long long int> Queue;
	Queue.push(56);
	Queue.push(27);
	Queue.push(30);
	Queue.push(100);
	reverseQueue(Queue);
	printQueue(Queue);
}
