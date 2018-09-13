    #include<iostream>
    #include<vector>
    #include<algorithm>

    using namespace std;

    void rotate90(vector<string> & s){
        int n = s.size();
        vector<string> res(n, string(n, '-'));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                res[j][i] = s[n - i - 1][j];
        s = res;
    }
    void flipHorizontal(vector<string> & s){
        for(auto & i : s)
            reverse(i.begin(), i.end());
    }

    void flipVertical(vector<string> & s){
        reverse(s.begin(), s.end());
    }

    bool compare(vector<string> & s1, vector<string> & s2){
        for(int i = 0; i < (int)s1.size(); i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;
        vector<string> a1(n), a2(n);

        for(auto & i : a1)
            cin >> i;
        for(auto & i : a2)
            cin >> i;

        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);

        rotate90(a1);

        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);

        rotate90(a1);

        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);

        rotate90(a1);

        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipHorizontal(a1);
        if(compare(a1, a2)){ cout << "Yes"; return 0;}
        flipVertical(a1);

        cout << "No";




        return 0;
    }