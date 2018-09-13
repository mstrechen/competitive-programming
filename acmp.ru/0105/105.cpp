#include <iostream>
#include <string>
using namespace std;

int stack[20];
void solveThis{
	
}
int calculate(int be,int en){
	
}
int main(){
	ios::sync_with_stdio(false);
	int numbers[20];
	int openingBrackets[20] = {}, closingBrackets[20] = {};
	int countOfNumbers=0, tmpNumber=0; 
	
	string justTmpString;
	
	getline(cin,justTmpString);
	for(int i = 0; i<justTmpString.length(); i++)
	{
		if(justTmpString[i]==' '||justTmpString[i]=='('||justTmpString[i]==')'||justTmpString[i]=='=')
		{
			if(tmpNumber!=0)
			{
				numbers[countOfNumbers] = tmpNumber;
				tmpNumber = 0;
				countOfNumbers++;
			}
			openingBrackets[countOfNumbers-1] += (justTmpString[i]=='(');
			closingBrackets[countOfNumbers-1] += (justTmpString[i]==')');
		}
		else
		{
			tmpNumber*=10;
			tmpNumber+=justTmpString[i]-'0';
		}
	}
	if(tmpNumber!=0)
	{
		numbers[countOfNumbers] = tmpNumber;
		countOfNumbers++;
	}
	for(int i = 0; i<countOfNumbers;i++)
	{
		cout << numbers[i];
		for(int j = 0; j<closingBrackets[i]; j++)
		{
			cout << ')';
		}
		cout << ' ';
		for(int j = 0; j<openingBrackets[i]; j++)
		{
			cout << '(';
		}
	}
	solveThis(&numbers, &openingBrackets, &closingBrackets, countOfNumbers,)
	
	return 0;
}
/*
Запилить подсчёт и рекурсивный перебор
!!!!



*/