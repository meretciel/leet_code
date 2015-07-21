//
//  problem_134_Gas_Station.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/20/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <algorithm>


using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 1) {
            return gas[0] >= cost[0] ? 0 : -1;
        }
        int s = 0;
        int min = numeric_limits<int>::max();
        int start_position = -1;
        for (int i=0; i < gas.size(); ++i) {
            s += gas[i] - cost[i];
            if (s <=  min) {
                start_position = i;
                min = s;
            }
        }
        
        if (s > 0) {
            return start_position % gas.size();
        } else if (s == 0) {
            return (start_position + 1) % gas.size();
        } else {
            return -1;
        }
        
        
    }
};