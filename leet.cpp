#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int i)
    {
        data = i;
    }
};

bool isBST(Node *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;

    if (root->data < minVal || root->data > maxVal)
        return false;

    return (isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal));
}

int main()
{
    vector<int> arr = {2, 5, -3, -2, 7, 0, 1, -5, 3};
    int curr_sum = 0;
    int max_sum = 0;
    int minI = 0;
    int maxI = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (curr_sum < 0)
            curr_sum = 0;
        curr_sum += arr[i];
        if (curr_sum > max_sum)
        {
            maxI = i;
            max_sum = max(max_sum, curr_sum);
        }
    }

    int j = maxI;
    int sum = arr[maxI];
    while (sum != max_sum)
    {
        j--;
        sum += arr[j];
    }

    cout << max_sum << " " << j << " " << maxI << "\n";
}

// []