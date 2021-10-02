#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	getline(cin, a);
	int n = a.length();
	unordered_map<char, int> m;
	m['-'] = m['+'] = 1;
	m['*'] = m['/'] = 2;
	m['('] = INT_MIN;
	stack<char> op;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' ')
			continue;
		if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*')
		{
			while (!op.empty() && m[op.top()] >= m[a[i]])
			{

				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				if (op.top() == '+')
					s.push(a + b);
				else if (op.top() == '-')
					s.push(a - b);
				else if (op.top() == '*')
					s.push(a * b);
				else
					s.push(a / b);
				op.pop();
			}
			op.push(a[i]);
		}
		else if (a[i] == ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				if (op.top() == '+')
					s.push(a + b);
				else if (op.top() == '-')
					s.push(a - b);
				else if (op.top() == '*')
					s.push(a * b);
				else
					s.push(a / b);
				op.pop();
			}
			op.pop();
		}
		else
		{
			s.push(a[i] - '0');
		}
	}
	// cout << "opo";
	while (!op.empty() && !s.empty())
	{
		int b = s.top();
		s.pop();
		int a = s.top();
		s.pop();
		if (op.top() == '+')
			s.push(a + b);
		else if (op.top() == '-')
			s.push(a - b);
		else if (op.top() == '*')
			s.push(a * b);
		else
			s.push(a / b);
		op.pop();
	}
	cout << s.top();
}