#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

//========================================================================================
/*                                                                                      *
 *                                   Inorder Traversal                                  *
 *                                                                                      */
//========================================================================================
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> in;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        in.push_back(curr->data);
        st.pop();

        curr = curr->right;
    }

    return in;
}

//========================================================================================
/*                                                                                      *
 *                                  PREORDER TRAVERSAL                                  *
 *                                                                                      */
//========================================================================================
vector<int> getPreOrderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> pre;
    if (root != NULL)
        st.push(root);

    while (!st.empty())
    {
        auto *node = st.top();
        pre.push_back(node->data);
        st.pop();

        if (node->right)
            st.push(node->right);

        if (node->left)
            st.push(node->left);
    }

    return pre;
}

//========================================================================================
/*                                                                                      *
 *                               POST ORDER USING 2 STACK                               *
 *                                                                                      */
//========================================================================================
vector<int> getPostOrderTraversal(TreeNode *root)
{
    stack<TreeNode *> st1, st2;
    vector<int> post;
    if (root != NULL)
        st1.push(root);
    while (!st1.empty())
    {
        auto *node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->left)
            st1.push(node->left);
        if (node->right)
            st1.push(node->right);
    }

    while (!st2.empty())
    {
        post.push_back(st2.top()->data);
        st2.pop();
    }

    return post;
}

//========================================================================================
/*                                                                                      *
 *                          POST ORDER TRAVERSAL USING 1 STACK                          *
 *                                                                                      */
//========================================================================================
vector<int> getPostOrderTraversal(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> post;
    TreeNode *curr = root;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;

            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                post.push_back(temp->data);
                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }

    return post;
}

//========================================================================================
/*                                                                                      *
 *                                    PRINT LEFT VIEW                                   *
 *                                                                                      */
//========================================================================================
void leftView(TreeNode *root, int level, vector<int> &left)
{
    if (root == NULL)
        return;

    if (level == left.size())
        left.push_back(root->data);

    leftView(root->left, level + 1, left);
    leftView(root->right, level + 1, left);
}

vector<int> getLeftView(TreeNode *root)
{
    vector<int> left;
    leftView(root, 0, left);
    return left;
}

//========================================================================================
/*                                                                                      *
 *                                   PRINT BOTTOM VIEW                                  *
 *                                                                                      */
//========================================================================================

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        mp[top.second] = top.first->data;

        if (top.first->left)
            q.push({top.first->left, top.second - 1});
        if (top.first->right)
            q.push({top.first->right, top.second + 1});
    }
    vector<int> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}

//========================================================================================
/*                                                                                      *
 *                                   TOP VIEW OF TREE                                   *
 *                                                                                      */
//========================================================================================
vector<int> getTopView(TreeNode<int> *root)
{
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    if (root)
        q.push({root, 0});
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        if (mp.count(top.second) == 0)
            mp[top.second] = top.first->val;

        if (top.first->left)
            q.push({top.first->left, top.second - 1});
        if (top.first->right)
            q.push({top.first->right, top.second + 1});
    }
    vector<int> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}

//========================================================================================
/*                                                                                      *
 *                                3 TRAVERSALS AT A TIME                                *
 *                                                                                      */
//========================================================================================
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans(3, vector<int>());
    stack<pair<BinaryTreeNode<int> *, int>> st;
    vector<int> *in = &ans[0], *pre = &ans[1], *pos = &ans[2];

    if (root)
        st.push({root, 0});

    while (!st.empty())
    {
        auto top = st.top();
        st.pop();

        if (top.second == 0)
        {
            pre->push_back(top.first->data);
            top.second += 1;
            st.push(top);
            if (top.first->left)
                st.push({top.first->left, 0});
        }

        else if (top.second == 1)
        {
            in->push_back(top.first->data);
            top.second += 1;
            st.push(top);
            if (top.first->right)
                st.push({top.first->right, 0});
        }

        else if (top.second == 2)
        {
            pos->push_back(top.first->data);
        }
    }

    return ans;
}

//========================================================================================
/*                                                                                      *
 *                                 WIDTH OF BINARY TREE                                 *
 *                                                                                      */
//========================================================================================

int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    queue<pair<TreeNode<int> *, int>> q;
    if (root)
        q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int minId = q.front().second;
        int first = INT_MAX, last = NULL;

        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();

            node.second -= minId;

            if (i == 0)
                first = node.second;

            if (i == size - 1)
                last = node.second;

            if (node.first->left)
                q.push({node.first->left, 2 * node.second + 1});

            if (node.first->right)
                q.push({node.first->right, 2 * node.second + 2});

            ans = max(ans, last - first + 1);
        }
    }

    return ans;
}

//========================================================================================
/*                                                                                      *
 *                                   DIAMETER OF TREE                                   *
 *                                                                                      */
//========================================================================================
struct Pair
{
    int height = 0;
    int diameter = 0;
};

Pair f(TreeNode<int> *root)
{
    Pair p;
    if (root == NULL)
        return p;

    Pair left = f(root->left);
    Pair right = f(root->right);

    p.height = 1 + max(left.height, right.height);
    p.diameter = max(left.diameter, max(right.diameter, left.height + right.height));
    return p;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    return f(root).diameter;
}

//========================================================================================
/*                                                                                      *
 *                               IS HEIGHT BALANCED TREE?                               *
 *                                                                                      */
//========================================================================================

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    if (left == -1)
        return -1;

    int right = height(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    return 1 + max(left, right);
}

bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return height(root) != -1;
}

//========================================================================================
/*                                                                                      *
 *                                 Check Identical Trees                                *
 *                                                                                      */
//========================================================================================

bool identicalTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;

    return (root1->data == root2->data) && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}

//========================================================================================
/*                                                                                      *
 *                                   ZIG ZAG TRAVERSAL                                  *
 *                                                                                      */
//========================================================================================

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    bool isRight = true;
    queue<BinaryTreeNode<int> *> q;
    if (root)
        q.push(root);

    vector<int> ans;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> trav;
        while (size--)
        {
            auto *node = q.front();
            q.pop();
            trav.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        if (isRight)
        {
            for (auto &i : trav)
                ans.push_back(i);
        }
        else
        {
            for (int i = trav.size() - 1; i >= 0; i--)
                ans.push_back(trav[i]);
        }

        isRight = !isRight;
    }

    return ans;
}

//========================================================================================
/*                                                                                      *
 *                                  ANTICLOCKWISE NODES                                 *
 *                                                                                      */
//========================================================================================
bool isLeaf(TreeNode<int> *root)
{
    return (root->left == NULL and root->right == NULL);
}

void leftTraversal(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *temp = root;
    while (temp and !isLeaf(temp))
    {
        ans.push_back(temp->data);

        if (temp->left)
        {
            temp = temp->left;
        }
        else if (temp->right)
        {
            temp = temp->right;
        }
    }
}

void rightTraversal(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *temp = root;
    stack<int> st;
    while (temp and !isLeaf(temp))
    {
        st.push(temp->data);

        if (temp->right)
        {
            temp = temp->right;
        }
        else if (temp->left)
        {
            temp = temp->left;
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

void leafTraversal(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (isLeaf(root))
        ans.push_back(root->data);

    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    leftTraversal(root->left, ans);
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
    rightTraversal(root->right, ans);
    return ans;
}

//========================================================================================
/*                                                                                      *
 *                            MAX PATH SUM BETWEEN TWO LEAVES                           *
 *                                                                                      */
//========================================================================================
long long maxPath(TreeNode<int> *root, long long &maxi)
{
    if (!root)
        return 0;
    long long l = maxPath(root->left, maxi);
    long long r = maxPath(root->right, maxi);
    maxi = max(maxi, root->val + l + r);
    return root->val + max(l, r);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if (!root)
        return -1LL;
    if (root->left == NULL or root->right == NULL)
        return -1LL;
    long long maxi = INT_MIN;
    maxPath(root, maxi);
    return maxi;
}

//========================================================================================
/*                                                                                      *
 *                                 SYMMETRIC TREE CHECK                                 *
 *                                                                                      */
//========================================================================================

bool same(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if (!p || !q)
        return p == q;

    return (p->data == q->data) && same(p->left, q->right) && same(p->right, q->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    return same(root->left, root->right);
}

//========================================================================================
/*                                                                                      *
 *                                  FLATTEN BINARY TREE                                 *
 *                                                                                      */
//========================================================================================

void flatten(TreeNode<int> *root, TreeNode<int> *&prev)
{
    if (root == NULL)
        return;

    flatten(root->right, prev);
    flatten(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    flatten(root, prev);
    return root;
}

//========================================================================================
/*                                                                                      *
 *                                  CHILD SUM PROPERTY                                  *
 *                                                                                      */
//========================================================================================

void changeTree(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    int childSum = 0;

    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;

    if (childSum >= root->data)
    {
        root->data = childSum;
    }
    else
    {
        if (root->left)
            root->left->data = root->data;
        else if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int totalSum = 0;

    if (root->left)
        totalSum += root->left->data;
    if (root->right)
        totalSum += root->right->data;

    // It may be a leaf node so check if any sum exists
    if (totalSum)
        root->data = totalSum;
}

//========================================================================================
/*                                                                                      *
 *                            BALANCED BST FROM SORTED ARRAY                            *
 *                                                                                      */
//========================================================================================

TreeNode<int> *create(int start, int end, vector<int> &arr)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);

    root->left = create(start, mid - 1, arr);
    root->right = create(mid + 1, end, arr);
    return root;
}

TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return create(0, n - 1, arr);
}

//========================================================================================
/*                                                                                      *
 *                              IS VALID BST OR PARTIAL BST                             *
 *                                                                                      */
//========================================================================================
bool valid(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
        return true;

    if (root->data < min or root->data > max)
        return false;

    return valid(root->left, min, root->data) and valid(root->right, root->data, max);
}

bool validateBST(BinaryTreeNode<int> *root)
{
    return valid(root, -1e9, 1e9);
}

//========================================================================================
/*                                                                                      *
 *                                      LARGEST BST                                     *
 *                                                                                      */
//========================================================================================

struct NodeValue
{
    int minNode;
    int maxNode;
    int maxSize;

    NodeValue(int minN, int maxN, int maxS)
    {
        this->minNode = minN;
        this->maxNode = maxN;
        this->maxSize = maxS;
    }
};

struct NodeValue largestBSTSubtreeHelper(TreeNode<int> *root)
{
    // An empty tree is a BST of size 0.
    if (!root)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // Get values from left and right subtree of current tree.
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // Current node is greater than max in left AND smaller than min in right, it is a BST.
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        // It is a BST.
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode),
                         left.maxSize + right.maxSize + 1);
    }

    // Otherwise, return [-inf, inf] so that parent can't be valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(TreeNode<int> *root)
{
    return largestBSTSubtreeHelper(root).maxSize;
}

//========================================================================================
/*                                                                                      *
 *                            SERIALIZE AND DESERIALIZE TREE                            *
 *                                                                                      */
//========================================================================================
string serializeTree(TreeNode<int> *root)
{
    //    Write your code here for serializing the tree
    string ser = "";
    queue<TreeNode<int> *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        auto *top = q.front();
        q.pop();

        if (top == NULL)
        {
            ser.append("#,");
            continue;
        }
        else
        {
            ser.append(to_string(top->data));
            ser += ',';
        }

        q.push(top->left);

        q.push(top->right);
    }

    return ser;
}

TreeNode<int> *deserializeTree(string &data)
{
    if (data.size() == 0)
        return NULL;
    //    Write your code here for deserializing the tree
    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode<int> *root = new TreeNode<int>(stoi(str));

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        auto *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str != "#")
        {
            node->left = new TreeNode<int>(stoi(str));
            q.push(node->left);
        }

        getline(s, str, ',');
        if (str != "#")
        {
            node->right = new TreeNode<int>(stoi(str));
            q.push(node->right);
        }
    }

    return root;
}

//========================================================================================
/*                                                                                      *
 *                                     SEARCH IN BST                                    *
 *                                                                                      */
//========================================================================================
bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    auto *temp = root;

    while (temp)
    {
        if (temp->data == x)
            return true;
        if (temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return false;
}

//========================================================================================
/*                                                                                      *
 *                                   BST FROM PREORDER                                  *
 *                                                                                      */
//========================================================================================

TreeNode<int> *create(vector<int> &pre, int l, int r)
{
    if (l >= pre.size())
        return NULL;
    if (l > r)
        return NULL;

    TreeNode<int> *node = new TreeNode<int>(pre[l]);

    int right = l;
    while (pre[right] <= pre[l])
        right++;

    if (pre[l + 1] < pre[l])
        node->left = create(pre, l + 1, right - 1);
    if (pre[right] > pre[l])
        node->right = create(pre, right, r);

    return node;
}

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    return create(preOrder, 0, preOrder.size() - 1);
}

//========================================================================================
/*                                                                                      *
 *                                      LCA IN BST                                      *
 *                                                                                      */
//========================================================================================

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (root == NULL)
        return root;

    while (root)
    {
        if (root->data > p->data and root->data > q->data)
        {
            root = root->left;
        }
        else if (root->data < p->data and root->data < q->data)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
}

//========================================================================================
/*                                                                                      *
 *                                   MORRIS TRAVERSAL                                   *
 *                                                                                      */
//========================================================================================
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    TreeNode *curr = root;
    vector<int> inorder;
    while (curr != NULL)
    {
        // *** 1 ***
        // left is not present i.e left is processed so curr node and go right
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;

            while (prev->right and prev->right != curr)
            {
                prev = prev->right;
            }

            // left is not processed other wise thread would be present
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                // *** 2 ***
                // left is processed bcoz thread is present so process right
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

//========================================================================================
/*                                                                                      *
 *                          FLATTEN TREE USING MORRIS TRAVERSAL                         *
 *                                                                                      */
//========================================================================================
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *curr = root;

    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode<int> *prev = curr->left;

            while (prev->right)
                prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }

    return root;
}

//========================================================================================
/*                                                                                      *
 *                        RECOVER BST WHERE TWO NODES ARE SWAPPED                       *
 *                                                                                      */
//========================================================================================

void fix(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&prev, BinaryTreeNode<int> *&mid, BinaryTreeNode<int> *&last, BinaryTreeNode<int> *&first)
{
    if (root == NULL)
        return;
    fix(root->left, prev, mid, last, first);

    if (prev != NULL && prev->data > root->data)
    {
        if (first == NULL)
        {
            first = prev;
            mid = root;
        }
        else
        {
            last = root;
        }
    }

    prev = root;

    fix(root->right, prev, mid, last, first);
}

BinaryTreeNode<int> *FixBST(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *prev = NULL, *first = NULL, *mid = NULL, *last = NULL;
    fix(root, prev, mid, last, first);

    if (first and last)
    {
        swap(first->data, last->data);
    }
    else if (first and mid)
    {
        swap(first->data, mid->data);
    }

    return root;
}
