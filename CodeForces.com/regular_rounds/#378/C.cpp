#include<iostream>
#include<vector>


using namespace std;

bool getAns(vector<pair<int,char> > & res, vector<int> & before, int l, int r, int delta)
{
    vector<pair<int,char> > currAns;

    vector<int> lft, rght;
    for(int _i = l; _i<=r; _i++)
    {
        int candidate = before[_i];
        currAns.clear();
        lft.clear();
        rght.clear();
        for(int i = l; i<_i; i++)
            lft.push_back(before[i]);
        for(int i = r; i>_i; i--)
            rght.push_back(before[i]);

        bool flag = 1;

        while(flag)
        {
            flag = 0;
            if(lft.size()&&lft[lft.size()-1]<candidate)
            {
                flag = 1;
                candidate+=lft[lft.size()-1];
                currAns.push_back({lft.size()+delta,'L'});
                lft.pop_back();
            }
            else
            if(rght.size()&&rght[rght.size()-1]<candidate)
            {
                flag = 1;
                candidate+=rght[rght.size()-1];
                currAns.push_back({lft.size()+delta,'R'});
                rght.pop_back();
            }
        }
        if(rght.size()==0 && lft.size()==0)
        {
            for(int i = 0; i<currAns.size(); i++)
                res.push_back(currAns[i]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int m;

    cin >> n;
    vector<int> before(n+1,0);
    for(int i = 0; i<n; i++)
        cin >> before[i];

    cin >> m;
    vector<int> after(m+1,0);
    for(int i = 0; i<m; i++)
        cin >> after[i];

    vector<pair<int,char> > res;
    {
        int l =  0,r = 0;
        int ii  = 0;
        int currMass = after[0];
        for(r = 0; r<n; r++)
        {
            currMass-=before[r];
            if(currMass<0)
            {
                cout <<"NO";
                return 0;
            }
            if(currMass == 0)
            {
                if(!getAns(res, before, l, r, ii))
                {
                    cout << "NO";
                    return 0;
                }
                l = r+1;
                currMass = after[++ii];
            }
        }
		
		if(currMass)
		{
			cout << "NO";
			return 0;
		}

    }

    cout << "YES" << '\n';
    for(auto i : res)
    {
        cout << i.first+1 << ' ' << i.second << '\n';
    }




    return 0;
}
