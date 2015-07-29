//
//  traping_rain_water.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/28/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        
        if (height.size() <= 2) { return 0; }
        
        
        vector<int> reserve(height.size(), 0);
        vector<int> prev_top_height(height.size(), 0);
        vector<int> level(height.size(), 0);
        
        int i = 0;
        
        while (i < height.size() && height[i] == 0) {++i;}
        
        if (i == height.size()) { return 0; }
        
        
        int start = i;
        int top_height = height[i];
        level[i] = top_height;
        prev_top_height[i] = top_height;
        ++i;
        
        int sum = 0;
        
        while (i < height.size()) {
            cout << "i: " << i << " height[i]: " << height[i] << endl;
            // if current height is above the previous level
            if (height[i] >= top_height) {
                
                // calculate the traped water at current level
                
                int j = i;
                
                while (j >= start && height[j-1] <= height[i]) {
                    int _level = min(height[i], prev_top_height[j-1]);
                    cout << "** j:" << j << " _level: " << _level << " level[j-1]: " << level[j-1] <<endl;
                    sum += _level - level[j-1];
                    cout << "sum: " << sum << endl;
                    level[j-1] = _level;
                    --j;
                }
                
                /*
                if (j >= start) {
                    int _height = height[j];
                    for (int k=j; k <= i; ++k) { prev_top_height[k] = _height; }
                }
                 */
                
                top_height = height[i];
                level[i] = top_height;
                prev_top_height[i] = max(height[i], prev_top_height[i-1]);
                
                
                
            } else { // if current height is below the level, then continue
                
                level[i] = height[i];
                prev_top_height[i] = prev_top_height[i-1];
                top_height = height[i];
                
            }
            
            ++i;
        }
        
        
        return sum;
        
    }
};