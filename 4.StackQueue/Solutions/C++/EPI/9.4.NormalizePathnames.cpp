#include "../Debug.h"
using namespace std;

string NormalizePathnames(const string& path) {
    string new_path;
    stringstream ss(path);
    string token;
    const char delimiter = '/';
    stack<string> path_stack;
    while (getline(ss, token, delimiter)) {
        if (token.empty() || token == ".") {
            continue;
        }

        if ((token == ".." && path_stack.empty()) || token != "..") {
            path_stack.emplace(token);
        } else if (token == ".." && path_stack.top() != ".."){
            path_stack.pop();
        }
    }

    while (!path_stack.empty()) {
        new_path = path_stack.top() + '/' + new_path;
        path_stack.pop();
    }

    return new_path; 
}

int main() {
    string path = "../.././Project/DuckCrack/../coding/EPI";
    std::cout << NormalizePathnames(path) << std::endl;

    return 0;
}
