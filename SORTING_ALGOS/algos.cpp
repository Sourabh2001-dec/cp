#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &arr)
{
    cout << "[ ";
    for (auto i : arr)
        cout << i << " ";
    cout << "]";
}

//! Selection Sort
// [Ω(n^2)	θ(n^2)	O(n^2)]
//? swap the current element with the smallest element in remaining array
void selection_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

//! Insertion Sort
// [Ω(n)	θ(n^2)	O(n^2)]
//? maintain sorted part on left and unsorted on right
//? pick from unsorted and place correctly in sorted
void insertion_sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int curr = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}

//! Bubble Sort
// [Ω(n)	θ(n^2)	O(n^2)]
void bubble_sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        bool isSwap = false;
        for (int j = 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]), isSwap = true;
        }

        if (!isSwap)
            return;
    }
}

//! Quick Sort
// [Ω(n log(n))	θ(n log(n))	O(n^2)]
int partition(vector<int> &arr, int lo, int hi)
{
    // here i maintains the index till where small values than pivot are present
    // when j iterates ahead and finds a value less than pivot it swaps with the i+1th element

    int pi = arr[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; j++)
    {
        if (arr[j] < pi)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[hi]);

    return i + 1;
}

void quick_sort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pi = partition(arr, start, end);
        quick_sort(arr, start, pi - 1);
        quick_sort(arr, pi + 1, end);
    }
}

//! Merge sort
// [Ω(n log(n))	θ(n log(n))	O(n log(n))]
void merge(vector<int> &arr, int s1, int e1, int s2, int e2)
{
    vector<int> a1, a2;

    for (int i = s1; i <= e1; i++)
    {
        a1.push_back(arr[i]);
    }

    for (int i = s2; i <= e2; i++)
    {
        a2.push_back(arr[i]);
    }

    int i = 0, j = 0;
    int k = s1;

    while (i < a1.size() && j < a2.size())
    {
        if (a1[i] < a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < a1.size())
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < a2.size())
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (end + start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);

        merge(arr, start, mid, mid + 1, end);
    }
}

int main()
{
    vector<int> arr = {7, 2, 5, 23, 5, 456, 423, 345, 56, 345342, 234, 234, 234, 234};

    // selection_sort(arr);
    // insertion_sort(arr);
    // bubble_sort(arr);
    // quick_sort(arr, 0, arr.size() - 1);
    merge_sort(arr, 0, arr.size() - 1);

    print(arr);
}