#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

using namespace std;
using namespace __gnu_pbds;


typedef tree<
int,
null_type,
greater<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int x,y;

    ordered_set A;
    for(int i = 0; i<n; i++)
    {
        cin >> x >> y;
        if(x==1)
        {
            A.insert(y);
            cout << A.order_of_key(y) << '\n';
        }
        else
        {
            A.erase(A.find_by_order(y));
        }
    }

    return 0;
}
