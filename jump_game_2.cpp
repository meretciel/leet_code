//
//  jump_game_2.cpp
//  leet_code
//
//  Created by Ruikun Hong on 8/3/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <deque>
#include <vector>

#include <iostream>


using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        
        if (nums.size() == 1) { return 0; }
        
        // create a Queue
        // we will use BFS method to calculate the minimum jump necessary
        deque<pair<int, int>> Q;
        Q.push_back(make_pair(0,0));
        
        
        
        int level = 0;
        int time = 0;
        
        
        while (level < nums.size()) {
            
            int front = Q.front().first;
            time = Q.front().second + 1;
            Q.pop_front();
            
            
            // add elements to the queue
            for (int i = level; i < nums.size() && i <= front + nums[front] ; ++i) {
                Q.push_back(make_pair(i, time));
            }
            
            // update the current level
            // when level = nums.size(), it means that we reach the end of the array
            level = max(level, front + nums[front] + 1);
            
        }
        
        return time;
        
    }
};