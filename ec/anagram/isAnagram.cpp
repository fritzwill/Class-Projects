// Will Fritz
// 11/13/2016
// Checks if wors are Anagrams
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() > 1 || t.size() > 1){
            sort(s);
            sort(t);
        }
        return (s.compare(t) == 0);                  
    }
    void sort(string &s){
        int mid;
        for (int i = 0; i < s.size(); i++){
            mid = i;
            for (int j = i; j < s.size(); j++){
                if (s[mid] > s[j]) mid = j;    
            }
            char temp = s[i];
            s[i] = s[mid];
            s[mid] = temp;
        }
    }
};
