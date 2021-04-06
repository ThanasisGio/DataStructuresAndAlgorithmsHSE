#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";

  // write your code here
  vector<string> a(text.size());
  for (int i = 0; i < a.size(); i++) {
  	a[i] = text.substr(i) + text.substr(0, i);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < a.size(); i++) {
  	result += a[i][a.size() - 1];
  }

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
