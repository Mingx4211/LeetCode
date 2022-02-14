#include<bits/stdc++.h>

using namespace std;

class Bitset {
private:
    int size;
    vector<int> bits;
    int flipped = 0;
    int count1 = 0;

public:
    Bitset(int size) {
        bits.resize(size);
        this->size = size;
    }
    
    void fix(int idx) {
        if(flipped && bits[idx] == 1){
            bits[idx] = 0;
            count1++;
        }else if(!flipped && bits[idx] == 0){
            bits[idx] = 1;
            count1++;
        }
    }
    
    void unfix(int idx) {
        if(flipped && bits[idx] == 0){
            bits[idx] = 1;
            count1--;
        }else if(!flipped && bits[idx] == 1){
            bits[idx] = 0;
            count1--;
        }
    }
    
    void flip() {
        this->flipped += 1;
        this->flipped %= 2;
        count1 = size - count1;
    }
    
    bool all() {
        if(count1 == size)
            return true;
        else    return false;
    }
    
    bool one() {
        if(count1 > 0)
            return true;
        else
            return false;
    }
    
    int count() {
        return count1;
    }
    
    string toString() {
        string res;
        for(int i = 0; i < size; i++){
            if((bits[i] ^ flipped) == 0){
                res += '0';
            }else{
                res += '1';
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */