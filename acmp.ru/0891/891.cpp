#include<iostream>
#include<string>
#include<map>
#include<queue>

using namespace std;

struct side
{
    char c[2][2];


    void rotate(bool flag)
    {
        if(flag)
        {
            swap(c[0][0], c[1][0]);
            swap(c[0][0], c[0][1]);
            swap(c[0][1], c[1][1]);
        }
        else
        {
            swap(c[0][0],c[0][1]);
            swap(c[0][0],c[1][0]);
            swap(c[1][0],c[1][1]);
        }
    }
    bool check()
    {
        return (c[0][0]==c[1][0]&&
                c[0][0]==c[0][1]&&
                c[0][0]==c[1][1]);
    }
};


struct _cube
{
    side A,B,C,D,E,F;
    bool check()
    {
        return A.check()&&B.check()&&
               C.check()&&D.check()&&
               E.check()&&F.check();
    }

    void rotate(char _c, bool flag)
    {
        char tmp1, tmp2;
        if(_c=='F')
        {
            if(flag)
            {
                A.rotate(1);
                tmp1 = E.c[1][0];
                tmp2 = E.c[1][1];
                E.c[1][0] = D.c[0][0];
                E.c[1][1] = D.c[1][0];
                D.c[0][0] = F.c[0][1];
                D.c[1][0] = F.c[0][0];
                F.c[0][0] = B.c[0][1];
                F.c[0][1] = B.c[1][1];
                B.c[0][1] = tmp2;
                B.c[1][1] = tmp1;
            }
            else
            {
                A.rotate(0);
                tmp1 = E.c[1][0];
                tmp2 = E.c[1][1];
                E.c[1][0] = B.c[1][1];
                E.c[1][1] = B.c[0][1];
                B.c[0][1] = F.c[0][0];
                B.c[1][1] = F.c[0][1];
                F.c[0][0] = D.c[1][0];
                F.c[0][1] = D.c[0][0];
                D.c[0][0] = tmp1;
                D.c[1][0] = tmp2;
            }
        }
        if(_c=='R')
        {
            if(flag)
            {
                D.rotate(1);
                tmp1 = A[0][1];
                tmp2 = A[1][1];
                A[0][1] = E[0][1];
                A[1][1] = E[1][1];
                E[0][1] = C[1][0];
                E[1][1] = C[0][0];
                C[0][0] = ;
                C[1][0] = ;
            }
            else
            {
                D.rotate(0);
            }
        }
        if(_c=='U')
        {
            if(flag)
            {
                E.rotate(1);

            }
            else
            {
                E.rotate(0);

            }
        }

    }
} cube, tmpCube;

queue<pair<string, _cube> > q;
map<_cube, bool> used;

int main()
{
    ios::sync_with_stdio(false);
    string tmp;
    cin >> tmp;
    cube.A.c[0][0] = tmp[0];
    cube.A.c[0][1] = tmp[1];
    cin >> tmp;
    cube.B.c[0][0] = tmp[0];
    cube.B.c[0][1] = tmp[1];
    cin >> tmp;
    cube.C.c[0][0] = tmp[0];
    cube.C.c[0][1] = tmp[1];
    cin >> tmp;
    cube.D.c[0][0] = tmp[0];
    cube.D.c[0][1] = tmp[1];
    cin >> tmp;
    cube.E.c[0][0] = tmp[0];
    cube.E.c[0][1] = tmp[1];
    cin >> tmp;
    cube.F.c[0][0] = tmp[0];
    cube.F.c[0][1] = tmp[1];
    cin >> tmp;
    cube.A.c[1][0] = tmp[0];
    cube.A.c[1][1] = tmp[1];
    cin >> tmp;
    cube.B.c[1][0] = tmp[0];
    cube.B.c[1][1] = tmp[1];
    cin >> tmp;
    cube.C.c[1][0] = tmp[0];
    cube.C.c[1][1] = tmp[1];
    cin >> tmp;
    cube.D.c[1][0] = tmp[0];
    cube.D.c[1][1] = tmp[1];
    cin >> tmp;
    cube.E.c[1][0] = tmp[0];
    cube.E.c[1][1] = tmp[1];
    cin >> tmp;
    cube.F.c[1][0] = tmp[0];
    cube.F.c[1][1] = tmp[1];
    if(cube.check())
    {
        cout << "solved";
        return 0;
    }
    q.push({"",cube});
    while(1)
    {
        cube = q.front().second;
        tmp = q.front().first;
        if(cube.check())
        {
            cout << tmp;
            return 0;
        }
        q.pop();
        //TODO: check in map
        q.push(tmp+'F', cube.rotate('F',0));
        q.push(tmp+'R', cube.rotate('R',0));
        q.push(tmp+'U', cube.rotate('U',0));
        q.push(tmp+"F", cube.rotate('F',1));
        q.push(tmp+"R", cube.rotate('R',1));
        q.push(tmp+"U", cube.rotate('U',1));
    }

    return 0;
}
