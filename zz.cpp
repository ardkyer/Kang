#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 조합을 재귀적으로 생성하는 함수
void generate_combinations(int n, int k, int idx, vector<int>& current) {
    if (static_cast<int>(current.size()) == k) {
        if (k == 0) { // k = 0 인 경우 공집합을 출력해야 합니다.
            cout << "00 ";
        }
        for (int i = 0; i < k; i++) {
            printf("%02d", current[i]);
        }
        if (k != 0) cout << " ";
        
        // k+1-부분집합 생성
        for (int i = 1; i <= n; i++) {
            if (find(current.begin(), current.end(), i) == current.end()) {
                vector<int> temp = current;
                temp.push_back(i);
                sort(temp.begin(), temp.end()); // 사전식 순서를 위해 정렬

                for (int j = 0; j <= k; j++) {
                    printf("%02d", temp[j]);
                }
                cout << " ";
            }
        }
        cout << "\n";
        return;
    }

    if (idx > n) return;

    // 현재 원소를 선택하는 경우
    current.push_back(idx);
    generate_combinations(n, k, idx + 1, current);
    current.pop_back();

    // 현재 원소를 선택하지 않는 경우
    generate_combinations(n, k, idx + 1, current);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> current;
    generate_combinations(n, k, 1, current);

    return 0;
}
