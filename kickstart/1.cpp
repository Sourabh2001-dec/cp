#include <bits/stdc++.h>
using namespace std;

void dispProgressions(vector<vector<int>> arr, int caseNo)
{
    vector<int> elem;

    elem.push_back((arr[0][0] + arr[2][2]) / 2);
    elem.push_back((arr[0][2] + arr[2][1]) / 2);
    elem.push_back((arr[1][0] + arr[1][2]) / 2);
    elem.push_back((arr[0][1] + arr[2][1]) / 2);

    // for (auto x : elem)
    //     cout << x << " ";

    int max = 0;

    for (int i = 0; i < elem.size(); i++)
    {
        int e = elem[i];
        int freq = std::count(elem.begin(), elem.end(), e);
        if (freq > max)
        {
            max = freq;
        }
    }

    // top

    // bottom

    //left

    //right

    cout << "Case #" << caseNo << ": " << max << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        vector<vector<int>> arr(3, vector<int>(3, 0));
        scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);

        scanf("%d %d", &arr[1][0], &arr[1][2]);

        scanf("%d %d %d", &arr[2][0], &arr[2][1], &arr[2][2]);

        dispProgressions(arr, i + 1);
    }
    return 0;
}