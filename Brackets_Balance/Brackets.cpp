#include <iostream>

#include <stack>

#include<string>

using namespace std;
int isBalanced(string);
int main() {
    string line;
    cout << "Input: ";
    getline(cin, line);
    cout << isBalanced(line);
}
int isBalanced(string local_line) {
    stack < char > symbols;
    try {
        int i = 0;
        if (local_line.empty()) {
            throw length_error("Empty line\n");
        }

        for (auto c : local_line) {
            if (c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']') {
                throw c;
            }
            if (local_line.size() < 2) {
                cout << "NOT BALANCED (" << 1 << ")\n";
                return 1;
            }
            if (!symbols.empty()) {
                if ((symbols.top() == '(' && c == ')') || (symbols.top() == '{' && c == '}') || (symbols.top() == '[' && c == ']')) {
                    symbols.pop();
                    i++;
                    continue;
                }
                if (((symbols.top() == '(') && (c == ']' || c == '}')) || ((symbols.top() == '{') && (c == ')' || c == ']')) || ((symbols.top() == '[') && (c == ')' || c == '}'))) {
                    cout << "NOT BALANCED (" << i << ")\n";
                    return i;
                }
            }
            symbols.push(c);
            i++;
        }
        if (symbols.empty()) {
            cout << "BALANCED\n";
            return -1;
        }
        else {
            cout << "NOT BALANCED (" << i << ")\n";
            return i;
        }
    }
    catch (length_error& e) {
        cout << e.what();
        exit(0);
    }
    catch (char c) {
        cout << "A character '" << c << "' doesn’t belong to any known brackets type, a program returns an exception with a validation message inside.\n";
        exit(0);
    }
}