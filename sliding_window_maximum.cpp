
class Solution {
public:
    
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // if k == 1, then return the original vector
        if (k == 1) { return nums;}
        
        deque<pair<int, int>> Q;
        vector<int> outputs;
        
        int val;
        
        
        for (int i=0; i< nums.size(); ++i) {
            
            val = nums[i];
            
            if (Q.size() == 0) { Q.push_back(make_pair(val, i)); }
            
            
            // remove the obsolete elements
            while (Q.size() != 0 && i - Q.front().second >= k) { Q.pop_front(); }
            
            
            
            if (val < Q.back().first) {
                // if val is smaller the last element, then add it to the queue
                Q.push_back(make_pair(val,i));
                
            } else if (val == Q.back().first) {
                // if val is equal the last element, change the last element
                Q.back() = make_pair(val, i);
                
            } else {
                // if val is larger then last element, then clean the queue
                while (Q.size() != 0 && val > Q.back().first) {
                    Q.pop_back();
                }
                Q.push_back(make_pair(val, i));
            }
            
            if (i >= k-1) { outputs.push_back(Q.front().first); }
            
        }
        
        return outputs;
        
    }
    
};