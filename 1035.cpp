#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cstdio>
#include <set>
#include <map>
#define MAX_V 500
#define oo 0x3f3f3f3f
using namespace std;
map <string,int> s;
int main() {
    string str;
    int i = 0, j;
    while (cin >> str) {
        if (str == "#") break;
        s.insert(make_pair(str, ++i));
    }
    while (cin >> str) {
        if (str == "#") break;
        if (s.find(str) != s.end()) {
            cout << str + " " << "is correct" << endl;
            continue;
        }
        string newstr = str;
        map <int, string>result;
        for (i = 0; i < str.size(); i++) {
            newstr = str;
            for (j = 0; j < 26; j++) {
                newstr[i] = 'a'+j;
                if (s.find(newstr) != s.end()) {
                    result[s[newstr]] = newstr;
                }
            }
        }
        for (i = 0; i < str.size(); i++) {
            newstr = str.substr(0, i) + str.substr(i+1, str.size()-i-1);
            if (s.find(newstr) != s.end()) {
                result[s[newstr]] = newstr;
            }
        }
        for (i = 0; i <= str.size(); i++) {
            for (j = 0; j < 26; j++) {
                string tmp = "a";
                tmp[0] = 'a'+j;
                newstr = str.substr(0, i) + tmp + str.substr(i, str.size()-i); 
                if (s.find(newstr) != s.end()) {
                    result[s[newstr]] = newstr;
                }
            }
        }
        cout << str << ":";
        for (map<int, string>::iterator it = result.begin(); it != result.end(); it++) {
            cout << " " << it->second;
        }
        cout << endl;
    }
    return 0;
}
