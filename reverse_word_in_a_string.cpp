//
//  reverse_word_in_a_string.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/29/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        
        
        
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(std::isspace))));
        
        int start = 0;
        bool is_space = false;
        for (int i = 0; i < s.size(); ++i) {
            if (!is_space && (s[i] == ' ' )) {
                reverse(s.begin()+start, s.begin() + i);
                start = i + 1;
                is_space = true;
            } else if (is_space && s[i] == ' ') {
                continue;
            } else if (is_space) {
                int _size = s.size();
                s.erase(s.begin() + start, s.begin() + i);
                start = i + 1 - (_size - s.size() + 1);
                i = i - (_size - s.size() + 1);
                is_space = false;
            }
        }
        
        // reverse the last piece
        reverse(s.begin() + start, s.end());
        
        // reverse the whole string to get the required order
        reverse(s.begin(), s.end());
        
        // remove the leading space of the string
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(std::isspace))));
    }
    
    
};