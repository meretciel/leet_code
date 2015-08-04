//
//  permutation.cpp
//  leet_code
//
//  Created by Ruikun Hong on 8/3/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> output;
    vector<vector<int>> permute(vector<int>& nums) {
        _permute(nums, 0, 0);
        return output;
    }
    
    void _permute(vector<int>& nums, int left, int bar) {
        if (bar >= nums.size()) { output.push_back(nums); return ; }
        
        //swap
        for (int i= left; i <= bar; ++i) {
            swap(nums[i], nums[bar]);
            _permute(nums, left, bar+1);
            swap(nums[i], nums[bar]);
        }
    }
};