#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function to parse the program string into a vector of integers
vector<int> parseProgram(const string &program) {
    vector<int> parsed;
    size_t pos = 0, start = 0;

    while ((pos = program.find(',', start)) != string::npos) {
        parsed.push_back(stoi(program.substr(start, pos - start)));
        start = pos + 1;
    }
    if (start < program.size()) {
        parsed.push_back(stoi(program.substr(start)));
    }

    return parsed;
}

// Function to solve the problem with brute force
bool checkCondition(long long A, const vector<int> &program) {
    for (size_t i = 0; i < program.size(); ++i) {
        int B = ((A >> (3 * i)) % 8) ^ 5;
        if (((B ^ 6 ^ (A >> (3 * i + B))) % 8) != program[i]) {
            return false;
        }
    }
    return true;
}

long long iterate(long long ub, const vector<int> &program) {
    for (long long A = 0; A < ub; ++A) {
        if (checkCondition(A, program)) {
            return A;
        }
    }
    return -1; // No solution found
}

int main() {
    // Input
    string regA, regB, regC, dummy, programLine;
    getline(cin, regA);
    getline(cin, regB);
    getline(cin, regC);
    getline(cin, dummy); // Skip unused line
    getline(cin, programLine);

    // Parse the program from the input
    auto program = parseProgram(programLine.substr(9));

    long long sol = 1e18;

    while (true) {
        long long nxt = iterate(sol, program);
        if (nxt == -1) break;

        cout << nxt << endl;
        sol = nxt;
    }

    cout << "sol=" << sol << endl;

    return 0;
}
