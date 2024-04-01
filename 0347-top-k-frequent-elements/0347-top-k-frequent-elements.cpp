class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create an unordered map to store the frequency of each element in nums.
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
            // cout << freq[num] << endl;
        }
        
        // create a priority queue to store the k most frequent elements.
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        // priority queue stores pairs of (number, frequency) and is ordered by frequency in ascending order

        // iterate over the entries in freq, add each entry to the priority quere and ensure its size does not exceed k
        for (auto & entry : freq){
            pq.push(entry);
            if (pq.size() > k){
                pq.pop(); // remove smallest element if priority quere size exceeds k
            }
        }
        
        // construct the output vector by popping the largest k elements from the priority queue and adding them to the back of the vector.
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().first); // add the number to the back of the output vector
            pq.pop(); // remove the pair from the priority queue
        }
        reverse(res.begin(), res.end()); // reverse the output vector to ensure the elements are in descending order of frequency.
        return res;
    }
};