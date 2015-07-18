//
//  main.cpp
//  longest_common_prefix
//
//  Created by Ruikun Hong on 7/17/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>


using namespace std;



class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        int i = 0;
        
        string out_string;
        
        if (strs.size() == 0)
            return "";
        
        if (strs.size() == 1)
            return strs[0];
        
        out_string = longestCommonPrefix(strs[0], strs[1]);
        
        for (int i = 2; i != strs.size(); ++i){
            out_string = longestCommonPrefix(out_string, strs[i]);
            if (out_string.size() == 0)
                break;
        }
        
        
        return out_string;
   
    };
    
    
    
    string longestCommonPrefix(const string& str1, const string& str2) {
        vector<char> output;
        
        for (string::const_iterator iter1 = str1.begin(), iter2 = str2.begin();
             iter1 != str1.end() && iter2 != str2.end();
             ++iter1, ++iter2) {
            if (*iter1 == *iter2) {
                output.push_back(*iter1);
            } else {
                break;
            }
            
        }
        
        string str(output.begin(), output.end());
        return str;
    };
    
};





