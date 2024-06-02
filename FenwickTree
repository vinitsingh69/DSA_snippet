A Fenwick Tree, also known as a Binary Indexed Tree (BIT), is a data structure that allows for efficient querying and updating of prefix sums or cumulative frequencies of an array of values. It was developed by Peter M. Fenwick in 1994 and is particularly useful in scenarios where you need to perform these operations frequently and efficiently, such as in range queries in arrays.

The key idea behind the Fenwick Tree is to represent the array in a binary tree structure, where each node stores the cumulative sum of a specific range of elements in the array. The structure of the tree allows for efficient updates and queries in O(log n) time complexity, where 'n' is the size of the array.

Here are the fundamental operations supported by a Fenwick Tree:

Initialization: The Fenwick Tree is initialized by constructing the tree based on the input array. Typically, the input array is 1-indexed, and the Fenwick Tree is 1-indexed as well for simplicity.

Update: To update the value of an element at a specific index 'i', you would perform the following steps:

Add the value 'delta' to the element at index 'i' in the input array.
Update the corresponding nodes in the Fenwick Tree to reflect the change. You need to update all nodes responsible for the range that includes index 'i'.
Query (Prefix Sum): To find the prefix sum of elements up to index 'i' in the input array, you would perform the following steps:

Initialize a variable to store the cumulative sum.
Traverse the Fenwick Tree from index 'i' to 1 (in a specific manner) while adding the values stored at each node to the cumulative sum.
Return the cumulative sum.
The efficient part of the Fenwick Tree is in how it identifies the nodes to update or query. To do this, it utilizes the binary representation of indices. To find the parent node of a given node, you flip the rightmost set bit of the index, which can be done using bitwise operations.


Fenwick Trees are particularly useful in scenarios like range queries in arrays, such as finding the sum of elements in a range or finding the number of elements smaller than a given value in a range. They are more memory-efficient compared to segment trees and are often used in competitive programming and various algorithms where frequent prefix sum or cumulative frequency computations are needed.

How Bits Work in Fenwick Trees
In a Fenwick Tree (Binary Indexed Tree or BIT), bitwise operations are used to efficiently update and query prefix sums. The key concept involves using the binary representation of indices to determine which nodes in the tree need to be updated or queried. Let's explore how bits work in the context of a Fenwick Tree using binary representation.

Initialization:

When initializing a Fenwick Tree, you create an array to represent the tree structure. Each index in the tree corresponds to a specific range of elements in the original array. The key is that each index's binary representation helps you identify which elements it covers.

For example, in a 1-indexed Fenwick Tree with a size of 8, the binary representations of indices are as follows:

Index 1:  001 (covers element 1)
Index 2:  010 (covers element 2)
Index 3:  011 (covers elements 1 and 2)
Index 4:  100 (covers element 4)
Index 5:  101 (covers elements 1 and 4)
Index 6:  110 (covers elements 2 and 4)
Index 7:  111 (covers elements 1, 2, and 4)
Index 8:  1000 (covers element 8)
Each bit position in the binary representation corresponds to a level in the Fenwick Tree. If a bit is set (1), it means that the node at that position in the tree covers some elements from the original array.

Update Operation:

To update an element at a specific index 'i' in the original array, you update the Fenwick Tree nodes that cover this index.

To find the next index to update, you flip the rightmost set bit in the binary representation of 'i'. This can be done efficiently using bitwise operations. The operation i & -i extracts the rightmost set bit of 'i'.

For example, if you want to update index 6 (binary: 110), you find the rightmost set bit, which is at position 2. So, you update index 6 and also index 7 (since it covers elements 1, 2, and 4). Then, you continue updating upwards until you reach the root of the tree.

Query Operation:

To query the prefix sum up to a specific index 'i' in the original array, you traverse the Fenwick Tree nodes associated with that index.

To find the next index to query, you also use bitwise operations. You start with 'i' and subtract the rightmost set bit using i -= i & -i. This operation effectively "removes" the rightmost set bit, and you move to the next node in the Fenwick Tree.

For example, to find the prefix sum up to index 6, you first query index 6 (element 6) and then query index 4 (element 4). The result is the cumulative sum of elements 1, 2, 4, and 6.

Using bitwise operations in this way allows the Fenwick Tree to efficiently update and query prefix sums in O(log n) time complexity, making it a powerful data structure for these operations.

Fenwick Tree Implementation

#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int size) {
        fenwick_tree.resize(size + 1, 0);
    }

    // Update the value at index 'i' by adding 'delta' to it.
    void update(int i, int delta) {
        while (i < fenwick_tree.size()) {
            fenwick_tree[i] += delta;
            i += i & -i; // Flip the rightmost set bit
        }
    }

    // Query the prefix sum up to index 'i' in the original array.
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += fenwick_tree[i];
            i -= i & -i; // Flip the rightmost set bit
        }
        return sum;
    }

private:
    vector<int> fenwick_tree;
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();

    // Initialize Fenwick Tree with the same size as the array.
    FenwickTree fenwick_tree(n);

    // Build the Fenwick Tree by updating it with the elements of the array.
    for (int i = 1; i <= n; ++i) {
        fenwick_tree.update(i, arr[i - 1]);
    }

    // Query the prefix sum up to various indices.
    cout << "Prefix Sums:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Prefix sum up to index " << i << ": " << fenwick_tree.query(i) << endl;
    }

    return 0;
}
Fenwick Tree Applications
Fenwick Trees (Binary Indexed Trees) are a powerful data structure that allows for efficient querying and updating of prefix sums or cumulative frequencies of an array of values. They are particularly useful in scenarios where you need to perform these operations frequently and efficiently, such as in range queries in arrays.

Here are some common applications of Fenwick Trees:

Range Queries: Fenwick Trees are often used to perform range queries in arrays, such as finding the sum of elements in a range or finding the number of elements smaller than a given value in a range. They are more memory-efficient compared to segment trees and are often used in competitive programming and various algorithms where frequent prefix sum or cumulative frequency computations are needed.

Inversion Count: Fenwick Trees can be used to count the number of inversions in an array. An inversion is a pair of indices (i, j) such that i < j and arr[i] > arr[j]. The number of inversions in an array is a measure of how unsorted the array is. For example, a sorted array has 0 inversions, while an array sorted in reverse order has the maximum number of inversions.

Offline Queries: Fenwick Trees can be used to process offline queries, which are queries that are known in advance and can be processed before the input is given. For example, if you have a list of queries that ask for the sum of elements in a range, you can process them in advance using a Fenwick Tree and then output the results when the input is given.

Dynamic Programming: Fenwick Trees can be used to solve dynamic programming problems that involve prefix sums. For example, you can use a Fenwick Tree to find the number of subarrays with a given sum in an array.

Binary Search: Fenwick Trees can be used to perform binary search on an array. For example, you can use a Fenwick Tree to find the kth smallest element in an array.

All Implemented Problems of the above mentioned applications are listed below:

[Range Queries]
cpp implementation of range queries using fenwick tree

#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int size) {
        fenwick_tree.resize(size + 1, 0);
    }

    void update(int i, int delta) {
        while (i < fenwick_tree.size()) {
            fenwick_tree[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += fenwick_tree[i];
            i -= i & -i;
        }
        return sum;
    }

private:
    vector<int> fenwick_tree;
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();

    FenwickTree fenwick_tree(n);

    for (int i = 1; i <= n; ++i) {
        fenwick_tree.update(i, arr[i - 1]);
    }

    // Query the sum of elements in a range [l, r].
    int l = 2, r = 6;
    int sum_in_range = fenwick_tree.query(r) - fenwick_tree.query(l - 1);
    cout << "Sum of elements in range [" << l << ", " << r << "]: " << sum_in_range << endl;

    return 0;
}
[Inversion Count]
cpp implementation of inversion count using fenwick tree

int countInversions(vector<int>& arr) {
    int n = arr.size();
    FenwickTree fenwick_tree(n);
    int inversions = 0;

    for (int i = n - 1; i >= 0; --i) {
        inversions += fenwick_tree.query(arr[i] - 1);
        fenwick_tree.update(arr[i], 1);
    }

    return inversions;
}

int main() {
    vector<int> arr = {8, 4, 2, 1, 3, 6, 7, 5};
    int inversions = countInversions(arr);
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
[Offline Queries]
cpp implementation of offline queries using fenwick tree


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = arr.size();

    FenwickTree fenwick_tree(n);

    vector<pair<int, int>> queries = {{2, 6}, {3, 7}, {1, 5}};
    vector<int> results;

    for (const auto& query : queries) {
        int l = query.first, r = query.second;
        int sum_in_range = fenwick_tree.query(r) - fenwick_tree.query(l - 1);
        results.push_back(sum_in_range);
    }

    for (int i = 0; i < queries.size(); ++i) {
        cout << "Sum of elements in range [" << queries[i].first << ", " << queries[i].second << "]: " << results[i] << endl;
    }

    return 0;
}

Btw what is diff between offline and online queries?

Offline and online queries refer to different approaches for processing queries in algorithms and data structures. The key difference between them lies in when the queries are known and how they are processed.

Offline Queries:

In offline queries, all queries are known in advance before processing begins. You have the complete set of queries, and you can preprocess them before processing the input data.

Offline query processing typically involves sorting, data structure setup, or other preprocessing steps based on the queries themselves.

Once the queries are preprocessed, you can efficiently apply them to the input data.

Offline queries are suitable when you have a fixed set of queries and can optimize their processing in advance.

Example: Count the number of elements in an array less than a given value for multiple elements. You have all the queries beforehand and can sort the queries based on the values you want to count. Then, you can iterate through the array once and incrementally answer each query as you process the array.

Online Queries:

In online queries, queries arrive one by one, and you process them immediately without prior knowledge of future queries.

Online query processing involves updating data structures or performing computations as queries arrive.

Online queries are suitable for scenarios where you don't know all the queries in advance, and you must process them as they come.

Example: Monitoring system logs for errors in real-time. Log entries arrive sequentially, and you analyze and process each log entry as it arrives. You don't have all the logs beforehand; you process them in real-time.

Not getting it? Let's take an example.

Suppose you have an array of integers and a list of queries that ask for the sum of elements in a range. You can process these queries in two ways:

Offline Queries:

Sort the queries based on the range.

Iterate through the array once and incrementally answer each query as you process the array.

Online Queries:

Iterate through the array once and update a Fenwick Tree as you process the array.

For each query, query the Fenwick Tree for the sum of elements in the range.

Important Points Regarding Fenwick Tree:

Fenwick Tree is 1-indexed: The Fenwick Tree is 1-indexed, which means that the input array is 1-indexed as well. This is done for simplicity and to avoid dealing with 0s in the tree.

Fenwick Tree is 1D: The Fenwick Tree is a 1D data structure, which means that it can only be used to compute prefix sums of 1D arrays. To compute prefix sums of 2D arrays, you need to use a 2D Fenwick Tree.

Fenwick Tree is not a Segment Tree: Fenwick Trees are often confused with Segment Trees, but they are not the same. Segment Trees are more general and can be used to compute any associative function on a range of elements in an array, while Fenwick Trees can only be used to compute prefix sums.

Fenwick Tree is more memory-efficient than Segment Tree: Fenwick Trees are more memory-efficient than Segment Trees because they don't store the original array. Instead, they store the prefix sums of the array, which is all that is needed to compute prefix sums.

Fenwick Tree is less flexible than Segment Tree: Fenwick Trees are less flexible than Segment Trees because they can only be used to compute prefix sums. Segment Trees can be used to compute any associative function on a range of elements in an array.

2D Fenwick Tree

Implementation of 2D Fenwick Tree


class FenwickTree2D {
public:
    FenwickTree2D(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        fenwick_tree.resize(rows + 1, vector<int>(cols + 1, 0));
    }

    // update the value at coordinates (x, y) by adding 'delta' to it.
    void update(int x, int y, int delta) {
        for (int i = x; i <= rows; i += i & -i) {
            for (int j = y; j <= cols; j += j & -j) {
                fenwick_tree[i][j] += delta;
            }
        }
    }

    // query the cumulative sum in the rectangle [(1, 1), (x, y)].
    int query(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                sum += fenwick_tree[i][j];
            }
        }
        return sum;
    }

    // query the cumulative sum in the rectangle [(x1, y1), (x2, y2)].
    int queryRange(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }

private:
    int rows, cols;
    vector<vector<int>> fenwick_tree;
};






