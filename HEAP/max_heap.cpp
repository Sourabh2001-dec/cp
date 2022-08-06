#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<int> heap;
    int MAX_SIZE = 1000;
    int currSize = 0;

public:
    MaxHeap() : heap(vector<int>(MAX_SIZE)){};
    void push(int element);
    int pop();

private:
    void heapify(int root);
    int parent(int i) { return ((i / 2) - 1); };
    int left(int i) { return 2 * i + 1; };
    int right(int i) { return 2 * i + 2; };
};

void MaxHeap::push(int ele)
{
    if (currSize == MAX_SIZE)
    {
        cout << "Heap Overflow\n";
        return;
    }

    // push element at end
    heap[currSize] = ele;

    // percolate up algorithm
    // compare child with parent if max heap property is followed and swap up as required
    int child = currSize;
    while (child > 0 and heap[parent(child)] < heap[child])
    {
        // swap child with parent
        swap(heap[child], heap[parent(child)]);
        child = parent(child);
    }

    currSize++;
}

void MaxHeap::heapify(int root)
{
    // O(logN)
    // assumes the left and the right are already in the form of heap
    int curr = root;
    int lChild = left(curr);
    int rChild = right(curr);

    while (lChild < currSize) // while we have not reached the lead node
    {
        int largest = lChild;

        if (rChild < currSize) // if right child exist compare right and left and chose largest
        {
            largest = heap[lChild] > heap[rChild] ? lChild : rChild;
        }

        if (heap[curr] < heap[largest]) // if parent is smaller than child then swap and heapify the child
        {
            swap(heap[curr], heap[largest]);

            curr = largest;
            lChild = left(curr);
            rChild = right(curr);
        }
        else
            break;
    }
}

int MaxHeap::pop()
{
    if (currSize == 0)
    {
        cout << "Heap Underflow";
        return -1;
    }

    int maxEle = heap[0];

    // bring last node to main root of tree
    swap(heap[currSize - 1], heap[0]);
    currSize--;
    // apply heapify from root
    heapify(0);

    return maxEle;
}

int main(int argc, char const *argv[])
{
    MaxHeap heap;
    heap.push(20);
    heap.push(10);
    heap.push(70);

    cout << heap.pop() << "\n";
    cout << heap.pop() << "\n";
    cout << heap.pop() << "\n";

    return 0;
}
