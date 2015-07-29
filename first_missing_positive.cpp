//
//  first_missing_positive.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/26/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> pos_nums;
        int posMin = numeric_limits<int>::max();
        int posMax = numeric_limits<int>::min();
        
        int val;
        for (int i=0; i < nums.size(); ++i) {
            val = nums[i];
            if (val > 0) {
                pos_nums.push_back(val);
                if (val > posMax) { posMax = val;}
                if (val < posMin) { posMin = val;}
            }
        }
        
        
        
        if (posMin > 1 || pos_nums.size() == 0) { return 1; }
        
        if (posMin == posMax) { return 2; }
        
        
        
        
        vector<int> buket_min(pos_nums.size(), numeric_limits<int>::max());
        vector<int> buket_max(pos_nums.size(), numeric_limits<int>::min());
        
        int index;
        int size = pos_nums.size();
        
        for (int i=0; i < pos_nums.size(); ++i) {
            int val = pos_nums[i];
            index = ((double)(val - posMin) / (posMax - posMin)) * (size-1);
            if (val > buket_max[index]) {buket_max[index] = val;}
            if (val < buket_min[index]) {buket_min[index] = val;}
        }
        
        cout << "buket_max: " << endl;
        copy(buket_max.begin(), buket_max.end(), ostream_iterator<int>(cout, " "));
        
        cout << endl;
        
        cout << "buket_min: " << endl;
        copy(buket_min.begin(), buket_min.end(), ostream_iterator<int>(cout, " "));
        
        cout << endl;
        
        int lim = buket_max[0];
        
        for (int i=1; i < size ; ++i) {
            /*
            if (buket_max[i] == numeric_limits<int>::min()) {
                int result;
                result = (posMax - posMin) / (size - 1) * i;
                return result;
            }
            
            if (buket_min[i] - buket_max[i-1] > 1) { return buket_max[i-1] + 1; }
             */
            if (buket_max[i] == numeric_limits<int>::min()) {continue;}
            if (buket_min[i] - lim > 1) { return lim + 1; }
            lim = buket_max[i];
        }
        
        
        return buket_max.back() + 1;
        
    }
};