//
//  shortest_palindrome.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/26/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        
        if (s.size() <= 1) { return s; }
        
        string res = matcher(s);
        
        return res + s;
    }
    
    
    bool equal(int q, int i, int m, const string& s, const string& rev_s) {
        if (i > m) { return true; }
        
        return s[q-1] == rev_s[i-1];
    }
    
    
    // macher function
    string matcher(const string & s) {
        
        // given the context, the pattern is s itself and the text is reversed s.
        
        // we first reversed the strings, then compute the prefix_function of s.
        // finally we go through text (reversed_s) to see if we can match any.
        
        
        // reverse s and get reversed_s
        string reversed_s(s);
        reverse(reversed_s.begin(), reversed_s.end());
        
        
        // get prefix_function of s
        vector<int> preFun = compute_prefix_function(s);
        
        
        int q = 0;
        int record = -1;
        
        
        int n = 2 * s.size() - 1;
        int m = s.size();
        
        // go through reversed_s and try to match the pattern
        // Note that we need to change the compare funtion, which is equal in our case
        
        // for example, we have s = bbc, what we want to do is to match bbc with cbb***.
        // here * represents any character. That is the reason why we need to re-define the
        // compare funciton in the traditional KMP algorithm
        
        for (int i = 1; i <= n; ++i) {
            while (q > 0 && !equal(q+1, i, m, s, reversed_s)) { q = preFun[q]; }
            
            if (equal(q+1, i, m, s, reversed_s)) { ++q; }
            
            
            
            if (q == m) {
                record = i;
                q = preFun[q];
                break;
            }
        }
        
        return reversed_s.substr(0,record - m);
        
        
        
    }
    
    
    // compute the standard prefix-function for the string s
    vector<int> compute_prefix_function(const string& s) {
        vector<int> outputs(s.size() + 1, 0);
        
        int q = 0;
        int k = 0;
        
        for (int q = 2; q < s.size()+1; ++q) {
            while (k > 0 && s[k] != s[q-1]) {
                k = outputs[k];
            }
            
            if (s[k] == s[q-1]) { ++k; }
            
            outputs[q] = k;
        }
        
        return outputs;
    }
    
    
};