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
#include "solution.cpp"




using namespace std;






int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> strs = {"aca","cba"};
    //string output_string = Solution::longestCommonPrefix(strs);
    
    Solution solution;
    
    cout << solution.longestCommonPrefix(strs) << endl;
    cout << solution.longestCommonPrefix(strs[0], strs[1]) << endl;
    
    cout << "done." << endl;
    
    return 0;
}
