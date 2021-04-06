#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

void build_trie (const vector <string>& patterns, vector<Node> &t)
{	
	for (int i = 0; i < patterns.size(); i++)
	{
		int a = 0;
		for (int j = 0; j < patterns[i].size(); j++)
		{
			int ind = letterToIndex(patterns[i][j]);
			if (a >= t.size())
			{
				t.resize(a + 1);
			}
			if (t[a].next[ind] != -1)
			{
				a = t[a].next[ind];
			}
			else
			{
				t[a].next[ind] = t.size();
				a = t[a].next[ind];
				t.resize(a + 1);
			}
		}
		t[a].patternEnd = true;
	}

}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;

	// write your code here
	vector<Node> t;
	build_trie(patterns, t);

	for (int i = 0; i < text.size(); i++)
	{
		int ind = letterToIndex(text[i]);
		int a = 0;
		if (t[a].next[ind] != -1)
		{
			bool look_for = true;
			for (int j = i; !t[a].patternEnd ; j++)
			{
				if (j >= text.size())
				{
					look_for = false;
					break;
				}
				ind = letterToIndex(text[j]);
				if (t[a].next[ind] != -1)
				{
					a = t[a].next[ind];
				}
				else
				{
					look_for = false;
					break;
				}
			}
			if (look_for)
			{
				result.push_back(i);
			}
		}
	}

	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
