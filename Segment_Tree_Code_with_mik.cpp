class Solution{
public:
    
    void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, int arr[]) {
        if(l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, segmentTree, arr);
        buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr);
        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

void updateSegTree(int index, int val, int i, int l, int r) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid) {
            updateSegTree(index, val, 2*i+1, l, mid);
        } else {
            updateSegTree(index, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    
    int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        if(l > end || r < start) {
            return 0;
        }
        
        if(l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l,    mid, segmentTree) +   querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree);
    }

void updateRange(int start, int end, int i, int l, int r, int val) {
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];
      
        if (l != r) { //Not a leaf node
            lazyTree[i * 2 + 1] += lazyTree[i]; //Left Child in Lazy Tree
            lazyTree[i * 2 + 2] += lazyTree[i]; //Right Child in Lazy tree
        }
        lazyTree[i] = 0;
    }

    //Invalid or out of range
    if (l > end || r < start || l > r)
        return;

    //[start...end[ is Exactly withing range of current nod [l..r]
    if (l >= start && r <= end) {
        segTree[i] += (r - l + 1) * val;
        if (l != r) {
            lazyTree[i * 2 + 1] += val;
            lazyTree[i * 2 + 2] += val;
        }
        return;
    }

    //Call for left and right subtree
    int mid = (l + r) / 2;
    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);
    segTree[i] = segTree[i * 2 + 1] + segTree[i * 2 + 2];
}
    
    vector<int> querySum(int n, int arr[], int q, int queries[]) { // QUESTION
        // vector<int> segmentTree(4*n);
        // vector<int> lazyTree(4*n);
        
        // buildSegmentTree(0, 0, n-1, segmentTree, arr);
        
        // vector<int> result;
        // for(int i = 0; i < 2*q; i+=2) {
        //     int start = queries[i]-1;   //Input is in 1 base indexing
        //     int end   = queries[i+1]-1; //Input is in 1 based indexing
            
        //     result.push_back(querySegmentTree(start, end, 0, 0, n-1, segmentTree));
        // }
        
        // return result;
        
    }
};

