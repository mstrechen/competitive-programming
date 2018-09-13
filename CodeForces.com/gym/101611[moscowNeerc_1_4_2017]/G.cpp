#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

template<typename T = int>
using row_t = vector<T>;

template<typename T = int>
using matrix_t = vector<row_t<T> >;


int rank_of_matrix(matrix_t<> mat){
    int R = mat.size(),
        C = mat[0].size();

	int Rank = C;

	for (int row = 0; row <Rank; row++)
	{
		if (mat[row][row])
            for (int col = 0; col < R; col++)
            {
                if (col != row)
                {
                    double mult = (double)mat[col][row] /
                                        mat[row][row];
                    for (int i = 0; i <Rank; i++)
                    mat[col][i] -= mult * (mat[row][i]);
                }
            }
		else
		{
			bool reduce = true;

			for (int i = row + 1; i < R; i++)
			{
				if (mat[i][row])
				{
				    swap(mat[row], mat[i]);
					reduce = false;
					break ;
				}
			}
            if (reduce)
			{
				Rank--;

				for (int i = 0; i < R; i ++)
					mat[i][row] = mat[i][Rank];
			}

			row--;
		}

	}
	return Rank;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    matrix_t<pair<int, int> > input(n, row_t<pair<int, int> >(m) );
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> input[i][j].first >> input[i][j].second;
    int eq_cnt = n*m*2;
    matrix_t<> eq(eq_cnt, row_t<>(n*m));

    for(int i = 0, r = 0; i < n; i++)
        for(int j = 0; j < m; j++, r++){
            eq[r][i*m + j] = -1,
            eq[r][i*m + (j+1)%m] = 1;
        }

    for(int i = 0, r = n*m; i < n; i++)
        for(int j = 0; j < m; j++, r++){
            eq[r][i*m + j] = 1,
            eq[r][((i+1)%n)*m + j] = -1;
        }


    int R1 = n * m - 1;

    int sum = 0;
    for(int i = 0, r = 0; i < n; i++)
        for(int j = 0; j < m; j++, r++){
            eq[r].push_back(input[i][(j+1)%m].second);
            sum += input[i][(j+1)%m].second;
        }

    for(int i = 0, r = n*m; i < n; i++)
        for(int j = 0; j < m; j++, r++){
            eq[r].push_back(input[(i+1)%n][j].first);
            sum += input[(i+1)%n][j].first;
        }
    sort(eq.begin(), eq.end());
    for(auto & i : eq){
        for(auto & j : i)
            cout << j << ' ';
        cout << '\n';
    }




    int R2 = rank_of_matrix(eq);
    cout << ((R1 == R2) ? "Yes" : "No");

    return 0;
}
