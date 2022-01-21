#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        for(int i = releaseTimes.size() - 1; i > 0; i--){
            releaseTimes[i] = releaseTimes[i] - releaseTimes[i - 1];
        }
        int max_time = 0;
        char max_char = 'a';
        for(int i = 0; i < releaseTimes.size(); i++){
            if(releaseTimes[i] > max_time){
                max_time = releaseTimes[i];
                max_char = keysPressed[i];
            }else if(releaseTimes[i] == max_time){
                if(keysPressed[i] > max_char){
                    max_char = keysPressed[i];
                }
            }
        }
        return max_char;
    }
};