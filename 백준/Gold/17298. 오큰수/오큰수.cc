#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    int* ans = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans[i] = -1; // 초기값 -1로 설정
    }
    stack<int> st;
    st.push(0); // 첫 번째 원소를 스택에 삽입
    for (int i = 1; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) { // 스택이 비어있지 않고, 스택의 top이 i번째 원소보다 작으면
            ans[st.top()] = a[i]; // top의 오큰수를 i번째 원소로 갱신
            st.pop(); // top을 제거
        }
        st.push(i); // i번째 원소를 스택에 삽입
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    delete[] a;
    delete[] ans;
    return 0;
}
