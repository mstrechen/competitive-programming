#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> getIndex(const string& s) {
	vector <int> coll(26,0);
	for (int i=0; i<s.size(); i++) {
		coll[s[i]-'a']++; 
	}
	return coll;
}

int getEven(vector <int> coll) {
	int even = 0;
	for (int i=0; i<26; i++) {
		even += (coll[i] / 2);
	}
	return even;
}

int getOdd(vector <int> coll) {
	int odd = 0;
	for (int i=0; i<26; i++) {
		if (coll[i] % 2 == 1) {
			odd++;
		}
	}
	return odd;
}

void test() {
	string s;
	cin >> s;
	vector <int> coll = getIndex(s);
	int even = getEven(coll);
	int odd = getOdd(coll);
	int dp[even+1][27];
	for (int n=0; n<=even; n++) {
		for (int p=0; p<=26; p++) {
			dp[n][p] = 0;
		}
	}
	if (even == 0) {
		cout << "D";
		return;
	}

	for (int p=0; p<=26; p++) { 
		dp[1][p] = 1;
	}
	for (int n=0; n<=even; n++) {
		for (int p=0; p<=26; p++) {
			if (p > 0 && dp[n][p - 1] == 0 &&
     			p < 26 && n > 0 && dp[n - 1][p + 1] == 0)
				dp[n][p] = 1;
		}
	}
	cout << (dp[even][odd] % 2 ? "G" : "D");
}
						                
void solution() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		test();
	}
}

int main() {
	solution();
	return 0;
}
