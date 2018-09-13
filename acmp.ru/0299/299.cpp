#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


long long getAns(int firstTeam, int secondTeam, vector<vector<long long>> & memorized)
{
    if(firstTeam<0||secondTeam<0)
        return 0;
    if(firstTeam==0&&secondTeam==0)
        return 1;
    if(memorized[firstTeam][secondTeam]!=-1)
        return memorized[firstTeam][secondTeam];
    if((firstTeam>=25&&secondTeam<firstTeam-1)||(secondTeam>=25)&&firstTeam<secondTeam-1)
        return 0;
    return memorized[firstTeam][secondTeam] = getAns(firstTeam-1, secondTeam, memorized) + getAns(firstTeam,secondTeam-1, memorized);

}
int main()
{

    int firstTeam, secondTeam;
    scanf("%d:%d",&firstTeam, &secondTeam);

    vector<vector<long long> >  memorized(41, vector<long long>(41,-1));

    cout << getAns(firstTeam-1, secondTeam, memorized)+getAns(firstTeam, secondTeam-1, memorized);

    return 0;
}
