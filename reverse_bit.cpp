//
//  reverse_bit.cpp
//  leet_code
//
//  Created by Ruikun Hong on 7/21/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <cstdint>

using namespace std;
    
class Solution {
public:
    
    
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t m = n;
        uint32_t res =0;
        
        uint32_t x;
        
        while (m > 0) {
            cout << x << endl;
            x = 1 & m;
            res = ((res << 1) | x) ;
            m = m >> 1;
        }
        
        
        return res;
        
    }
    
    
};