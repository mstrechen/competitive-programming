#include <iostream>
#include <vector>

using namespace std;

const int SQRT_SIZE = 200;
const int oo = 1000*1000*1000;

struct SqrtDecomposition
{
    vector<int> A;
    vector<int> mins, add, change;
    vector<long long> sum;
    vector<char> isChanged;
    
    SqrtDecomposition(vector<int> & source)
    {
        int smallSize = ((int)source.size() - 1)/SQRT_SIZE + 1;
        A.reserve(smallSize * SQRT_SIZE);
        A.assign(source.begin(), source.end());
        A.resize(smallSize*SQRT_SIZE, 0);
        
        sum.assign(smallSize, 0);
        mins.assign(smallSize, +oo);
        add.assign(smallSize, 0);
        change.assign(smallSize, 0);
        isChanged.assign(smallSize, 0);
        
        for(int i = 0; i<(int)A.size(); i++)
        {
            sum[i/SQRT_SIZE] += A[i];
            mins[i/SQRT_SIZE] = min(A[i], mins[i/SQRT_SIZE]);
        }
    }
    
    void push(int _i)
    {
        if(isChanged[_i])
        {
            for(int i = 0; i<SQRT_SIZE; i++)
                A[SQRT_SIZE*_i + i] = change[_i];
        }
        isChanged[_i] = 0;
        
        for(int i = 0; i<SQRT_SIZE; i++)
                A[SQRT_SIZE*_i + i] += add[_i];
        
        add[_i] = 0;
    }
    
    long long getSum(int l, int r)
    {
        long long ans = 0;
        
        push(l/SQRT_SIZE);
        push(r/SQRT_SIZE);
        
        for(int i = l; i<=r; )
            if(i%SQRT_SIZE == 0 && i+SQRT_SIZE<=r+1)
            {
                ans+=sum[i/SQRT_SIZE];
                i+=SQRT_SIZE;
            }
            else
            {
                ans+=A[i];
                i++;
            }
        
        return ans;
    }
    
    int getMin(int l, int r)
    {
        int ans = +oo;
        
        push(l/SQRT_SIZE);
        push(r/SQRT_SIZE);
        
        for(int i = l; i<=r; )
            if(i%SQRT_SIZE == 0 && i+SQRT_SIZE<=r+1)
            {
                ans = min(mins[i/SQRT_SIZE], ans);
                i+=SQRT_SIZE;
            }
            else
            {
                ans = min(A[i], ans);
                i++;
            }
        
        return ans;
    }
    
    int get(int i)
    {
        push(i/SQRT_SIZE);
        
        return A[i];
    }
    
    void updateInfo(int _i)
    {
        mins[_i] = 0;
        sum[_i] = 0;
        
        for(int i = 0; i<SQRT_SIZE; i++)
        {
            sum[_i] += A[_i*SQRT_SIZE + i];
            mins[_i] = min(mins[_i], A[_i*SQRT_SIZE + i]);
        }
    }
    
    void setSegment(int l, int r, int val)
    {
        push(l/SQRT_SIZE);
        push(r/SQRT_SIZE);
        
        for(int i = l; i<=r; )
            if(i%SQRT_SIZE == 0 && i+SQRT_SIZE<=r+1)
            {
               isChanged[i/SQRT_SIZE] = 1;
               change[i/SQRT_SIZE] = val;
               add[i/SQRT_SIZE] = 0;
               sum[i/SQRT_SIZE] = val*1LL*SQRT_SIZE;
               mins[i/SQRT_SIZE] = val;
            }
            else
            {
                A[i] = val;
                i++;
            }
        
        updateInfo(l/SQRT_SIZE);
        updateInfo(r/SQRT_SIZE);
    }    
    
    void addSegment(int l, int r, int val)
    {
        push(l/SQRT_SIZE);
        push(r/SQRT_SIZE);
        
        for(int i = l; i<=r; )
            if(i%SQRT_SIZE == 0 && i+SQRT_SIZE<=r+1)
            {
               add[i/SQRT_SIZE] += val;
               sum[i/SQRT_SIZE] += val*1LL*SQRT_SIZE;
               mins[i/SQRT_SIZE] += val;
            }
            else
            {
                A[i] += val;
                
                i++;
            }
        
        updateInfo(l/SQRT_SIZE);
        updateInfo(r/SQRT_SIZE);
    }
    
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    
    int n;
    cin >> n;
    
    vector<int> A(n);
    
    for(auto & i : A)
        cin >> i;
    
    SqrtDecomposition SD(A);
    
    int q;
    cin >> q;
    
    string tmp;
    while(q--)
    {
        cin >> tmp;
        
        if(tmp[0] == 'r')
        {
            int l, r;
            cin >> l >> r;
            if(tmp[1] == 'm')
                cout << SD.getMin(l-1,r-1);
            else
                cout << SD.getSum(l-1,r-1);
        }
        else if(tmp[0] == 'g')
        {
            int i;
            cin >> i;
            cout << SD.get(i-1);
        }
        else if(tmp[0] == 'a')
        {
            int l, r, val;
            cin >> l >> r >> val;
            SD.addSegment(l, r, val);
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            SD.setSegment(l, r, val);
        }
    }
    
	
	return 0;
}