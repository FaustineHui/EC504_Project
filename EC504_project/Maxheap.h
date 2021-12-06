#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Data structure to store a max-heap node
struct PriorityQueue
{
private:
    // vector to store heap elements
    vector<int> A;
    vector<int> original;

    // return parent of `A[i]`
    // don't call this function if `i` is already a root node
    int PARENT(int i) {
        return (i - 1) / 2;
    }

    // return left child of `A[i]`
    int LEFT(int i) {
        return (2 * i + 1);
    }

    // return right child of `A[i]`
    int RIGHT(int i) {
        return (2 * i + 2);
    }

    // Recursive heapify-down algorithm.
    // The node at index `i` and its two direct children
    // violates the heap property
    void heapify_down(int i)
    {
        // get left and right child of node at index `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        // compare `A[i]` with its left and right child
        // and find the largest value
        if (left < size() && original[A[left]] > original[A[i]]) {
            largest = left;
        }

        if (right < size() && original[A[right]] > original[A[largest]]) {
            largest = right;
        }

        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }

    // Recursive heapify-up algorithm
    void heapify_up(int i)
    {
        // check if the node at index `i` and its parent violate the heap property
        if (i && original[A[PARENT(i)]] < original[A[i]])
        {
            // swap the two if heap property is violated
            swap(A[i], A[PARENT(i)]);

            // call heapify-up on the parent
            heapify_up(PARENT(i));
        }
    }

public:
    // return size of the heap
    unsigned int size() {
        return A.size();
    }

    //to initialize the heap
    void initize(vector<int> input) {
        original = input;
        for (int i = 0; i < input.size(); i++) {
            push(i);
        }
    }

    // Function to check if the heap is empty or not
    bool isEmpty() {
        return size() == 0;
    }

    // insert key into the heap
    void push(int key)
    {
        // insert a new element at the end of the vector
        A.push_back(key);

        // get element index and call heapify-up procedure
        int index = size() - 1;
        heapify_up(index);
    }

    // Function to remove an element with the highest priority (present at the root)
    int pop()
    {
        int out = A[0];
        try {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                    "index is out of range(Heap underflow)");
            }


            // replace the root of the heap with the last element
            // of the vector
            A[0] = A.back();
            A.pop_back();

            // call heapify-down on the root node
            heapify_down(0);
        }
        // catch and print the exception
        catch (const out_of_range& oor) {
            cout << endl << oor.what();
        }

        return out;
    }

    // Function to return an element with the highest priority (present at the root)
    int top()
    {
        try {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                    "index is out of range(Heap underflow)");
            }

            // otherwise, return the top (first) element
            return A.at(0);        // or return A[0];
        }
        // catch and print the exception
        catch (const out_of_range& oor) {
            cout << endl << oor.what();
        }
    }
};
