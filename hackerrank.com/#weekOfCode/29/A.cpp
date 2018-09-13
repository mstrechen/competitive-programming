#include<iostream>
#include<string>

using namespace std;

bool isLeap(int yr)
{
    if(yr%400 == 0)
        return 1;
    if(yr%4 == 0 && yr%100 != 0)
        return 1;
    return 0;
}

void getGrig(int yr)
{
    cout << "1" + string(1, '3' - isLeap(yr)) + ".09." << yr;
}
void get1918()
{
    cout << "26.09.1918";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int yr;
    cin >> yr;

    if(yr!=1918)
        getGrig(yr);
    else
        get1918();

    return 0;
}
