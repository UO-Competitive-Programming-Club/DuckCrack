#include "../Debug.h"
using namespace std;

/* naive solution using a stack */
string NormalizePathnamesSlow(const string& path) {
    string new_path;
    stringstream ss(path);
    string token;
    const char delimiter = '/';
    stack<string> path_stack;

    /* absolute path */
    if (path.front() == '/') {
        path_stack.emplace("/");
    }

    while (getline(ss, token, delimiter)) {
        /* the case where token is a directory name */
        if (!token.empty() && token != "." && token != "..") {
            path_stack.emplace(token);

        /* the case where token is previous directory */
        } else if (token == "..") {
            if (path_stack.empty()) {
                path_stack.emplace(token);
            } else {
                string prev_dir = path_stack.top();
                if (prev_dir == "/") {
                    throw invalid_argument("input error");
                } else if (prev_dir == "..") {
                    path_stack.emplace(token);
                } else {
                    path_stack.pop();
                }
            }
        }
    }

    while (!path_stack.empty()) {
        /* note that this string concatination is very slow because string are added at the begining 
         * not appended at the end */

        if (path_stack.top() != "/") {
            new_path = path_stack.top() + '/' + new_path;
        } else {
            new_path = path_stack.top() + new_path;
        }

        path_stack.pop();
    }

    return new_path; 
}


string NormalizePathnamesFast(const string& path) {
    string new_path;
    stringstream ss(path);
    string token;
    const char delimiter = '/';
    vector<string> path_stack;

    /* absolute path */
    if (path.front() == '/') {
        path_stack.emplace_back("/");
    }

    while (getline(ss, token, delimiter)) {
        /* the case where token is a directory name */
        if (!token.empty() && token != "." && token != "..") {
            path_stack.emplace_back(token);

        /* the case where token is previous directory */
        } else if (token == "..") {
            if (path_stack.empty()) {
                path_stack.emplace_back(token);
            } else {
                string prev_dir = path_stack.back();
                if (prev_dir == "/") {
                    throw invalid_argument("input error");
                } else if (prev_dir == "..") {
                    path_stack.emplace_back(token);
                } else {
                    path_stack.pop_back();
                }
            }
        }
    }

    if (path_stack.front() != "/") {
        new_path += path_stack.front();
    }

    for (size_t i = 1; i < path_stack.size(); i++) {
        /* here we are appending string at the back */
        new_path += '/' + path_stack[i];
    }


    return new_path; 
}





int main() {
    string path = "../.././Project/DuckCrack/../../../../coding/EPI";
    std::cout << NormalizePathnamesFast(path) << std::endl;

    return 0;
}
