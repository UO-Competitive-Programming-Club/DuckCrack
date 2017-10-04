#include "../Debug.h"
#include <cctype>
using namespace std;

bool IsPalindorm(const string& s) {
    int left = 0, right = s.size();

    while (left < right) {
        while (!isalpha(s[left]) && left < right) { ++left; }
        while (!isalpha(s[right]) && left < right) { --right; }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        ++left, --right;
    }

    return true;
}
