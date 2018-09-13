#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Solution
{
    vector<int> boxes;
    int minCount;
    mutable vector<vector<long long> > memory;

    Solution(istream & in)
    {
        int n;
        in >> n >> minCount;
        boxes.assign(n, 0);
        for(auto & i : boxes)
            in >> i;

        memory.assign(n, vector<long long>(minCount, -1));
    }

    long long smallAnswer(int last, int count) const
    {
        if(last<0)
            return count == 0;
        if(count<0)
            return 0;
        if(memory[last][count]!=-1)
            return memory[last][count];

        return memory[last][count] = smallAnswer(last-1, count) + smallAnswer(last-1, count - boxes[last]);

    }

    long long getAnswer() const
    {
        long long ans = 1LL << (long long)boxes.size();

        long long sum = accumulate(boxes.begin(), boxes.end(), 0LL);
        if(sum/2 > minCount - 1)
        {
            for(int i = minCount - 1; i>=0; i--)
                ans -= smallAnswer((int)boxes.size()-1, i)*2;
        }
        else
        {
            for(int i = sum/2; i>=0; i--)
                    ans -= smallAnswer((int)boxes.size()-1, i)*2;
            if(sum%2 == 0)
            {
                ans+=smallAnswer((int)boxes.size()-1, sum/2);
            }
        }

        return ans;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solution(cin);

    cout << solution.getAnswer();

    return 0;
}
