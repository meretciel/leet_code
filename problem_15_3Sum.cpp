//
//  problem_15_3Sum.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/18/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <math.h>



using namespace std;

class Solution{
    
public:
    typedef vector<int> intvector;
    unordered_map<int,int> records;
    
    void init(const vector<int>& nums, unordered_map<int,int>& record) {
        /* creat a hash map to record the number of appearience of values in the array. */
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) {
                ++record.at(nums[i]);
            } else {
                record[nums[i]] = 1;
            }
        }
    }

    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // initialize the records
        init(nums,records);
        
        
        // drop the duplicates in nums and sort the results
        
        intvector _nums;
        
        
        for (unordered_map<int,int>::const_iterator iter = records.begin();
             iter != records.end();
             ++iter) {
            _nums.push_back(iter->first);
        }
        sort(_nums.begin(), _nums.end());
        
        
        // from now on, we work on a strictly increasing vector
        
        return general_threeSum(_nums,0);
    }
    
    vector<vector<int>> general_threeSum(vector<int>& nums, int target) {
        /* 
         Generalized threeSum function. This function takes an additional parameter target.
         Args:
            nums: vector<int>
            target: int. The sum target
         
         Returns:
            vector<vector<int>>: vectors of (a,b,c) such that each (a,b,c) satisfies a + b + c = target.
        */
         
         
        
        vector<intvector> outputs;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            int _target = target - nums[i];
            // generate the results
            vector<intvector> results = _threeSum(nums, _target, nums[i], i);
            // add results to the outputs.
            outputs.insert(outputs.end(), results.begin(), results.end());
        }
    
        return outputs;
        
    };
    
    

    

    
    vector<intvector> _threeSum(const vector<int>& nums, int target, int third, int lim_idx) {
        /*
         _threeSum function will generate a vector of triplets. 
         To construct such a triplet (x0, x1, x2), the function will find pairs (x0, x1) in the nums such that
         x0 + x1 = target. x2 is given as third.
         
         Args:
            nums:    vector<int> of values.
            target:  int. Sum target of a pair.
            third:   int. The third element in the triplets.
            lim_idx: int. This sets a limit for the range that we can search for pairs.
         
         Returns:
            vector<vector<int>>. A vector of triplets.
         
        */
        
        vector<intvector> outputs;
        
        int i = lim_idx;
        intvector _vec;
        
        while (i >=0 && 2 * nums[i] >= target) {
            _vec.clear();
            int n = nums[i];
            //cout << "i: " << i << " nums[i]: " << n << " target: " << target << endl;
            
            // try to find target - n in the available range of nums.
            // if we can find one, then we may construct the triplet (target, target - n, third)
            if (binary_search(nums.begin(), nums.begin() + i + 1, target - n)) {
                
                // sort the element.
                // because nums is sorted, therefore, third is garanteed to be the largest number among three.
                int x0 = min(n,target - n);
                int x1 = max(n,target - n);
                int x2 = third;
                
                //cout <<"i: " << i <<  " x0: " << x0 << " x1: " << x1 << " x2: " << x2 << " target: " << target << endl;
                
                // check is the triplet is valide.
                // when performing the search, we allowed that the triplet can have duplicate elements.
                // Here, we check if this is allowed by the records.
                // Records holds the number of appeareance of different values in the original array.
                int flag = true;
                
                if (x0 == x1 && x0 == x2 && records[x0] < 3) {
                    flag = false;
                } else if (x0 == x1 && records[x0] < 2) {
                    flag = false;
                } else if (x0 == x2 && records[x0] < 2) {
                    flag = false;
                } else if (x1 == x2 && records[x1] < 2) {
                    flag = false;
                }
                
                // if pass the check
                if (flag) {
                    _vec.push_back(x0);
                    _vec.push_back(x1);
                    _vec.push_back(x2);
                    outputs.push_back(_vec);
                }
            }

            --i;
        }
        
        return outputs;
        
    }
    
};