#include<iostream>
#include<vector>
#include<map>

using namespace std;


bool notThis(vector<char> & A, int n)
{
    for(int i = 0; i<(int)A.size(); i++)
        if(i!=n && A[i])
            return 1;

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;

    cin >> q;

    while(q--)
    {
        int nUsers, nMessages;
        cin >> nUsers;

        vector<string> users(nUsers);

        map<string, int> usersToId;

        for(int i = 0; i<nUsers; i++)
        {
            cin >> users[i];
            usersToId.insert({users[i], i});
        }
        cin >> nMessages;

        vector<pair<string, string> > mess(nMessages), messCopy(nMessages);

        int _j = 0;
        for(auto & i : mess)
        {
            char c;
            do
            {
                cin >> c;
                i.first.push_back(c);
            }
            while(c!=':');
            getline(cin, i.second);
            messCopy[_j++] = i;
            i.second = ' ' + i.second;
            i.second.push_back(' ');

            i.first.pop_back();


            for(auto & j : i.second)
                if(j=='.' || j==',' || j=='!' || j=='?')
                    j = ' ';
        }

        vector<vector<char> > dp(nMessages+1, vector<char>(nUsers, 0));

        dp[0].assign(nUsers+1, 1);
        for(int i = 1; i<=nMessages; i++)
        {
            if(mess[i-1].first == "?")
            {
                for(int id = 0; id<nUsers; id++)
                {
                    if(notThis(dp[i-1], id) && mess[i-1].second.find(' ' + users[id]+' ')==string::npos)
                    {
                        dp[i][id] = 1;
                    }
                }
            }
            else
            if(usersToId.count(mess[i-1].first))
            {
                int id = usersToId[mess[i-1].first];
                if(notThis(dp[i-1], id))
                {
                    dp[i][id] = 1;
                }
            }


        }
        bool res = 0;

        for(auto i : dp[nMessages])
            res|=i;

        if(res)
        {
            int lastUser = -1;

            for(int i = nMessages; i>0; i--)
            {
                for(int j = 0; j<nUsers; j++)
                if(dp[i][j] && j!=lastUser)
                {
                    messCopy[i-1].first = users[j] + ':';
                    lastUser = j;
                    break;
                }
            }

            for(int i = 0; i<nMessages; i++)
                cout << messCopy[i].first << messCopy[i].second << '\n';
        }
        else
        {
            cout << "Impossible\n";
        }

    }


    return 0;
}
