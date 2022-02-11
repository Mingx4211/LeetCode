//题解答案代码
//朴素解法 用了二分查找来加快min_r的查找

#include <iostream>
#include <cstring>
#include <algorithm>
#include <assert.h>

using namespace std;

const int N = 100000;

int n;
int m;
int nums[N];


bool check(int lo, int hi)
{
    int pre = -1;
    for (int i = 0; i < n; i ++)
    {
        int x = nums[i];
        if (x < lo || hi < x)
        {
            if (pre > x)
                return false;
            pre = x;
        }
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> nums[i];
    
    int res = 0;
    for (int i = 1; i < m + 1; i ++)    //小美选的数字
    {
        //----小团选的数字。寻找符合提交的最左端
        int l = i;
        int r = m + 1;
        //二分查找来找符合条件的最小r
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(i, mid) == true)
                r = mid;
            else
                l = mid + 1;
        }
        if (l == m + 1)
            break;
        res += (m - l + 1);
    }
    
    cout << res << endl;
    return 0;
}

