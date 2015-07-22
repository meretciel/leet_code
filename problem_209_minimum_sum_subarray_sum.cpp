//
//  problem_209_minimum_sum_subarray_sum.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/19/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <vector>
#include <limits>
#include <iostream>




using namespace std;



class Solution {
public:
    
    int minSubArrayLen(int s, vector<int>& nums) {
        
        // flag is to indicate if we have found a solution. if not we should return 0
        int flag = false;
        
        
        // _sum is the sum of the range[left, i]
        int _sum = 0;
        
        // record indicates the length of subarray that satisfies the requirement.
        // this is the output variable.
        int record = 0;
        
        // left and i are the index of the range upon which the _sum is calculated
        int left =0 ;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            // update the _sum
            if (flag) {
                // if we have already found a solution, then we need to move
                // index left and index i and the same time.
                _sum += nums[i] - nums[left];
                ++left;
            } else {
                // if we have not found a solution yet, only increase the right side
                // of the range, which is i.
                
                _sum += nums[i];
                
                // if we have not found a solution yet, we need to increase the record.
                // once any solution is found, the record does not increase anymore.
                ++record;
            }
            

            
            // if _sum >= s, then we need to update the record

            if (_sum >= s) {
                flag = true;
                
                // check if the new element can help to create a new record
                int j = i - record + 1;
                int partial_sum  = _sum;

                while (j < nums.size() && partial_sum - nums[j] >= s) {
                    partial_sum -= nums[j];
                    ++j;
                }
                
                if (j > left) {
                    // update the new record
                    record -= j - left;
                    
                    // update the left side of the ragne
                    left = j;
                    
                    // update the _sum
                    _sum = partial_sum ;
                    
                }
                
            }

        }
        return flag ? record : 0;
        
    }
};


