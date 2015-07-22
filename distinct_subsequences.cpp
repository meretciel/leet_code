#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> A;
        // initialization
        for (int i=0; i < t.size() + 1; ++i) {
            vector<int> _vec(s.size() + 1);
            A.push_back(_vec);
        }
        
        
        for(int j=0; j < s.size(); ++j) {
            if (s.at(j) == t.at(0)) {
                A[1][j+1] = A[1][j] + 1;
            } else {
                A[1][j+1] = A[1][j];
            }
        }
        
        
        for (int i=2; i < t.size() + 1; ++i) {
            for (int j=1; j < s.size() + 1; ++j) {
                if (s.at(j-1) == t.at(i-1)) {
                    A[i][j] = A[i-1][j-1] + A[i][j-1];
                } else {
                    A[i][j] = A[i][j-1];
                }
            }
        }
        
        return A[t.size()][s.size()];
        
    }
};