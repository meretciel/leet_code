//
//  maximum_product_subarray.cpp
//  leet_code
//
//  Created by Ruikun Hong on 8/1/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <limits>
#include <vector>
#include <iostream>


using namespace std;


/*
 Notice that if a subarray contains zeros, then the product of this subarray is zero. 
 Therefore, we first identify the position of each zero and work on subarray that does not 
 contains zero.
 
 We also notice that the key point is we can only consider products calculated from
 [i..j] and [i..j-1] where nums[j] < 0. This observation gives the following draft solution
 of the problem.
 
 TODO:
 
 In _maxProduct, we use two loops which is not necessary. An other possible improvement is when 
 add new calculation to the vector results, we can first compare and add the max of the two.
 */





class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if (nums.size() == 1) { return nums[0]; }
        
        vector<int> zero_pos;
        zero_pos.push_back(-1);
        
        for (int i=0; i < nums.size(); ++i) {
            if (nums[i] == 0) { zero_pos.push_back(i); }
        }
        
        zero_pos.push_back(nums.size());
        
        
        
        int record = numeric_limits<int>::min();
        for (int i = 0; i < zero_pos.size() - 1; ++i) {
            //cout << "zero_pos loop -> i -> " << i << endl;
            record = max(record, _maxProduct(nums, zero_pos[i]+1, zero_pos[i+1]));
        }
        
        
        
        return zero_pos.size() <= 2 ? record : max(record, 0);
        
    };
    
    int _maxProduct(vector<int>& nums, int left, int right) {
        
        //cout << "_maxProduct -> left -> " << left << " -> right -> " << right << endl;
        
        if (left >= right) { return numeric_limits<int>::min(); }
        
        vector<int> results;
        
        int prod = 1;
        
        for (int i = left; i < right; ++i) {
            if (i != left && nums[i] < 0) {
                results.push_back(prod);
                prod *= nums[i];
                results.push_back(prod);
            } else if (i == left && nums[i] < 0) {
                prod *= nums[i];
                results.push_back(prod);
            } else if (i == right - 1){
                prod *= nums[i];
                results.push_back(prod);
            } else {
                prod *= nums[i] ;
            }
        }
        
        prod = 1;
        
        
        for (int i = right - 1; i >= left; --i) {
            if (i != right - 1 && nums[i] < 0) {
                results.push_back(prod);
                prod *= nums[i];
                results.push_back(prod);
            } else if (i == right - 1 && nums[i] < 0) {
                prod *= nums[i];
                results.push_back(prod);
            } else if (i == left) {
                prod *= nums[i];
                results.push_back(prod);
            } else {
                prod *= nums[i];
            }
        }
        
        int output = numeric_limits<int>::min();
        
        for (int i = 0; i < results.size(); ++i) {
            if (results[i] > output) { output = results[i]; }
        }
        
        return output;
    }
};