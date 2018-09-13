#include <iostream>
#include <set>
#include <string>
using namespace std;
char goodChars[12] = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y'};
char goodNumbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
set<char> setOfChars(goodChars, goodChars+12);
set<char> setOfNums(goodNumbers, goodNumbers+10);

int answers[50];
int main(){
	ios::sync_with_stdio(false);
	int n;
	bool allOk;
	string stringToParse;
	cin >> n;
	getline(cin,stringToParse);
	for(int i =0; i<n; i++)
	{
		getline(cin,stringToParse);
		allOk = stringToParse.length() == 6;
		if(allOk){
			allOk*=setOfChars.count(stringToParse[0]);
			allOk*=setOfChars.count(stringToParse[4]);
			allOk*=setOfChars.count(stringToParse[5]);
			allOk*=setOfNums.count(stringToParse[1]);
			allOk*=setOfNums.count(stringToParse[2]);
			allOk*=setOfNums.count(stringToParse[3]);
		}
		answers[i] = allOk;
	}
	for(int i = 0; i<n;i++)
		if(answers[i]) cout << "Yes\n";
		else cout << "No\n";
	return 0;
}