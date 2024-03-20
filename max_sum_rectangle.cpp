#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Code {
public:
    static vector<int> kadane(vector<int>& a) {
        vector<int> result{INT_MIN, 0, -1};
        int currentSum = 0;
        int localStart = 0;

        for (int i = 0; i < a.size(); i++) {
            currentSum += a[i];
            if (currentSum < 0) {
                currentSum = 0;
                localStart = i + 1;
            } else if (currentSum > result[0]) {
                result[0] = currentSum;
                result[1] = localStart;
                result[2] = i;
            }
        }
        if (result[2] == -1) {
            result[0] = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] > result[0]) {
                    result[0] = a[i];
                    result[1] = i;
                    result[2] = i;
                }
            }
        }

        return result;
    }
    static void findMaxSubMatrix(vector<vector<int>>& a) {
        int cols = a[0].size();
        int rows = a.size();
        vector<int> currentResult;
        int maxSum = INT_MIN;
        int left = 0;
        int top = 0;
        int right = 0;
        int bottom = 0;

        for (int leftCol = 0; leftCol < cols; leftCol++) {
            vector<int> tmp(rows, 0);

            for (int rightCol = leftCol; rightCol < cols; rightCol++) {
                for (int i = 0; i < rows; i++) {
                    tmp[i] += a[i][rightCol];
                }
                currentResult = kadane(tmp);
                if (currentResult[0] > maxSum) {
                    maxSum = currentResult[0];
                    left = leftCol;
                    top = currentResult[1];
                    right = rightCol;
                    bottom = currentResult[2];
                }
            }
        }
        cout << maxSum << std::endl;
        // std::cout << "MaxSum: " << maxSum <<
        //             ", range: [(" << left << ", " << top <<
        //             ")(" << right << ", " << bottom << ")]" << std::endl;
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> a[j][k];
            }
        }
        Code::findMaxSubMatrix(a);
    }

    return 0;
}
