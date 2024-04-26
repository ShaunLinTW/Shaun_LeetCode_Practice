class KthLargest {
private:
    int k_largest;
    priority_queue<int, vector<int>,greater<int>> pq_minHeap;
public:
    // initialize KthLargest helper function
    KthLargest(int k, vector<int>& nums) {
        k_largest = k;
        // iterate through stream and put element into the pq_minHeap
        for (int it:nums){
            pq_minHeap.push(it);
            // pop the kth largest element from pq
            if (pq_minHeap.size() > k_largest) pq_minHeap.pop();
        }
    }
    
    // add helper function
    int add(int val) {
        pq_minHeap.push(val);
        // only keep kth largest element and pop other element
        if (pq_minHeap.size() > k_largest) pq_minHeap.pop();

        return pq_minHeap.top(); // return the top element in the minHeap priority_queue, which is the answer
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// example:
// initialize, and sort the stream >>>
// 2, 4, 5, 8 -> null
// add 3, and sort the stream >>>
// 2, 3, 4, 5, 8 -> return 3rd largest element, which is 4
// add 5, and sort the stream >>>
// 2, 3, 4, 5, 5, 8 -> return 3rd largest element, which is 5
// add 10, and sort the stream >>>
// 2, 3, 4, 5, 5, 8, 10 -> return 3rd largest element, which is 5
// add 9, and sort the stream >>>
// 2, 3, 4, 5, 5, 8, 9, 10 -> return 3rd largest element, which is 8
// add 4, and sort the stream >>>
// 2, 3, 4, 4, 5, 5, 8, 9, 10 -> return 3rd largest element, which is 8