#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

pair<int, string> chats[1000000];

int main(){
	ios::sync_with_stdio(false);
	
	int n, countOfChats = 0;
	string s;
	map<string, int> messages;
	pair<string, int> tmp;
	
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> s;
		messages[s] = i;
	}
	for(map<string, int>::iterator it = messages.begin(); it!=messages.end(); it++)
	{
		chats[countOfChats++] = {it->second, it->first};
	}
	sort(chats,chats+countOfChats);
	for(int i = countOfChats-1; i>=0; i--)
	{
		cout << chats[i].second << '\n';
	}
	return 0;
}