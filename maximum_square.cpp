//
//  maximum_square.cpp
//  leet_code
//
//  Created by Ruikun Hong on 8/6/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;


template<typename T>
void print_vector2D(vector<vector<T>>& vec){
    int nrow = vec.size();
    int ncol = vec[0].size();
    
    cout << "***nrow, ncol: " << nrow << " " << ncol << endl;
    
    for (int i=0; i < nrow; ++i) {
        cout << endl;
        for (int j=0; j < ncol; ++j) {
            cout << vec[i][j] << " ";
        }
    }
}




class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) { return 0;}
        
        print_vector2D(matrix);
        
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        
        // make record of the horizental number
        vector<vector<int>> hrecord(nrow, vector<int>(ncol));
        
        for (int i=0; i < nrow; ++i) {
            int _record=0;
            for (int j=ncol-1; j>=0; --j) {
                if (matrix[i][j] == '1') {
                    ++_record;
                    hrecord[i][j] = _record;
                } else {
                    _record = 0;
                    hrecord[i][j] = _record;
                }
            }
        }
        
        
        // make record of the vertial number
        vector<vector<int>> vrecord(nrow, vector<int>(ncol));
        
        for (int j=0; j < ncol; ++j) {
            int _record = 0;
            for (int i=nrow-1; i >= 0 ; --i){
                if (matrix[i][j] == '1') {
                    ++_record;
                } else {
                    _record = 0;
                }
                
                vrecord[i][j] = _record;
            }
        }
        
 
        
        int output = 0;
        
        // search: the worst case is N * M * max(N,M)
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                // the maximum posible size of the square
                int size = min(hrecord[i][j], vrecord[i][j]);
                
                // if the potential size is greater than the current output
                // then we do the test
                if (size > output) {
                    // tt is used to keep track of the minimum number of horizontal ones
                    int  tt = max(nrow, ncol) + 1;
                    for (int k=1; k < min(tt,size); ++k) {
                        tt = min(tt, hrecord[i+k][j]);
                    }
                    if (tt >= size) {
                        output = size;
                    } else {
                        output = max(output, tt);
                    }
                }
            
            }
        }
  
        
        return output * output;
    }
};