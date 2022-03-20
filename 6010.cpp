#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = *min_element(time.begin(), time.end()), r = *min_element(time.begin(), time.end()) * totalTrips;
        while(l < r){
            long long mid = (l + r) / 2;
            long long trips = trip_time(time, mid);
            if(trips >= totalTrips && trip_time(time, mid - 1) >= totalTrips){
                r = mid - 1;
            }else if(trips < totalTrips){
                l = mid + 1;
            }else{
                l = r = mid;
            }
        }
        return l;
    }

    long long trip_time(vector<int>& time, long long t){
        long long res = 0;
        for(int i = 0; i < time.size(); i++){
            res += t / time[i];
        }
        return res;
    }
};