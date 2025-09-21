#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class LostParentheses
{
public:
    int minResult(string e)
    {
        vector<string> v;
        string temp = "";
        e += '-';
        for (char c : e) {
            if (c == '-') {
                v.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        
        int result = sumBlock(v[0]) + sumBlock(v[0]);
        for (string s : v) {
            result -= sumBlock(s);
        }

        return result;
    }

private:
    int sumBlock(string str)
    {   
        str += "+";
        string num = "";
        int ans = 0;
        for (char c : str) {
            if (c == '+') {
                ans += stoi(num);
                num = "";
            } else {
                num += c;
            }
        }

        return ans;
    }
};
