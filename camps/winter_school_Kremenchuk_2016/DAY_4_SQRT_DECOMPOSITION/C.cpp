#include<iostream>
#include<vector>

using namespace std;

const int sizeOfBlock = 1000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int> > blocks((n-1)/sizeOfBlock + 1, vector<int>((n-1)/sizeOfBlock + 1));
    vector<int> bombsH(n),bombsV(n);

    for(int i = 0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        bombsH[x]=y;
        bombsV[y]=x;
        blocks[x/sizeOfBlock][y/sizeOfBlock]++;
    }
    for(int i = 0; i<(int)blocks.size(); i++)
        for(int j = 0; j<(int)blocks[0].size(); j++)
        {
            if(j>0)
                blocks[i][j]+=blocks[i][j-1];
            if(i>0)
                blocks[i][j]+=blocks[i-1][j];
            if(i>0&&j>0)
                blocks[i][j]-=blocks[i-1][j-1];
        }
    int q;
    cin >> q;

    while(q--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = y2-y1+1;

        int x_1,x_2,y_1,y_2;

        for(x_1 = x1-1; (x_1+1)%sizeOfBlock; x_1--)
        {
            ans-=y1<=bombsH[x_1] && bombsH[x_1]<=y2;
        }


        for(x_2 = x2+1; x_2%sizeOfBlock && x_2<n; x_2++)
        {
            ans-=y1<=bombsH[x_2] && bombsH[x_2]<=y2;
        }

        for(y_1 = y1; y_1%sizeOfBlock && y_1<=y2; y_1++)
        {
            ans-= bombsV[y_1] < x_1 || x_2 < bombsV[y_1];
        }

        for(y_2 = y2-1; (y_2+1)%sizeOfBlock && y_2 >= y_1; y_2--)
        {
            ans-= bombsV[y_2] < x_1 || x_2 < bombsV[y_2];
        }
        y_1/=sizeOfBlock;
        y_2 = (y_2 + 1)/sizeOfBlock - 1;

        if(y_1<=y_2)
        {
            if(x_1>=0)
            {
                ans-=blocks[x_1/sizeOfBlock][y_2];
                if(y_1>0)
                    ans+=blocks[x_1/sizeOfBlock][y_1-1];
            }
            if(x_2<n)
            {
                ans-=blocks[blocks.size()-1][y_2];
                ans+=blocks[x_2/sizeOfBlock - 1][y_2];
                if(y_1>0)
                {
                  ans+=blocks[blocks.size()-1][y_1-1];
                  ans-=blocks[x_2/sizeOfBlock - 1][y_1-1];
                }
            }
        }


        cout << ans << endl;

    }




    return 0;
}

