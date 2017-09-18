//Will Fritz
//11/14/2016
//given ann array of strings, group anagrams together


#include <string> 
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string> &str){
            vector<vector<string>> answer;
            unordered_map<string,multiset<string>> map;
            for (auto i : str){
                string orderedString = i;
                sort(orderedString.begin(), orderedString.end());
                map[orderedString].insert(i);
            }
            for (auto i : map){
                vector<string> anagrams(i.second.begin(), i.second.end());
                answer.push_back(anagrams);
            }
            return answer;
        }
};
                 
