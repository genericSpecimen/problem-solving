#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    string simplifyPath(string path) {
        if (path.empty()) return path;
        
        bool is_absolute = (path.front() == '/');
        cout << "processing" << (is_absolute ? " abs " : " rel ") << "path" << endl;
        
        stack<string> st;
        
        stringstream ss(path);
        string tok;
        
        
        while (getline(ss, tok, '/')) {
            //cout << "processing token : " << tok << endl;
            if (tok.compare(".") == 0) continue;
            if (tok.compare("..") == 0) {
                if (!st.empty() && st.top().compare("..") != 0) st.pop();
                else if (!is_absolute) st.push(tok);
            } else if (!tok.empty()) {
                st.push(tok);
            }
        }
        
        string curr_path;
        string tos;
        while (!st.empty()) {
            //cout << st.top() << endl;
            tos = "/";
            tos += st.top(); st.pop();
            tos += curr_path;
            curr_path = tos;
        }
        
        if (is_absolute) {
            if (curr_path.empty()) curr_path = "/";
        } else if (curr_path.front() == '/') curr_path = curr_path.substr(1);
        
        return curr_path;
    }
    */
    
    
    string simplifyPath(string path) {
        if (path.empty()) return path;
        
        bool is_absolute = (path.front() == '/');
        cout << "processing" << (is_absolute ? " abs " : " rel ") << "path" << endl;
        
        vector<string> st;
        
        stringstream ss(path);
        string tok;
        
        
        while (getline(ss, tok, '/')) {
            //cout << "processing token : " << tok << endl;
            if (tok.compare(".") == 0) continue;
            if (tok.compare("..") == 0) {
                if (!st.empty() && st.back().compare("..") != 0) st.pop_back();
                else if (!is_absolute) st.push_back(tok);
            } else if (!tok.empty()) {
                st.push_back(tok);
            }
        }
        
        string curr_path = is_absolute ? "/" : "";
        for (string s : st) {
            curr_path += s;
            curr_path += "/";
        }
        if (curr_path.size() > 1) curr_path.pop_back(); // remove trailing /
        
        return curr_path;
    }    
};

int main() {
    Solution sln;
    
    vector<string> paths = {
        "/home/",
        ".",
        "./",
        "/.",
        "/./",
        "/../",
        "..",
        "../"
        "/home//foo/",
        "/a/./b/../../c/",
        "sc//././tc/awk/././",
        "./../",
        "../../.",
        "/../../..",
        "/home/hooman/../..",
        "./../.."
    };
    
    for (string path : paths)
        cout << path << "   " << sln.simplifyPath(path) << endl << endl;
}
