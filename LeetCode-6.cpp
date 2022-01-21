#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1)
        return s;
    string res = "";
    for (int i = 0; i < numRows; i++) {
        int step2 = 2 * i, step1 = 2 * numRows - 2 - 2 * i;
        int index = i;
        if (index < s.size())
            res += s[index];
        while (index < s.size()) {
            if (step1 != 0 && index + step1 < s.size())
                res += s[index + step1];
            if (step2 != 0 && index + 2 * numRows - 2 < s.size())
                res += s[index + 2 * numRows - 2];
            index += 2 * numRows - 2;
        }
    }
    return res;
}

int main() {
    string test = "A";
    string res = convert(test, 1);
    cout << res << endl;
    return 0;
}