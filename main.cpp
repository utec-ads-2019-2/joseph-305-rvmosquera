#include <iostream>
#include <vector>

const int MAX_K = 15;

using namespace std;

int find(int k, int m) {
    int good_bad_guys = 2 * k;
    int i = 0;

    auto dead_man = (m - 1) % good_bad_guys;
    for (i = 0; i < good_bad_guys; ++i) {
        if (dead_man < k)
            break;
        --good_bad_guys;
        dead_man = (dead_man + m - 1) % good_bad_guys;
    }

    return i;
}

int main() {
    int k;
    vector<int> result2;

    result2.push_back(0);
    for (int i = 1; i <= MAX_K - 1; ++i) {
        int j = 1;
        while (true) {
            if (find(i, j) == i) {
                result2.push_back(j);
                break;
            }

            j++;
        }
    }

    while (cin >> k && k != 0) {
        cout << result2.at(k) << endl;
    }

    result2.clear();

    return 0;
}