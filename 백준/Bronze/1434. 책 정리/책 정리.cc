#include <iostream>
#include <vector>

using namespace std;

  int main() {
      int N, M;
      cin >> N >> M;

      int boxSum = 0, bookSum = 0;

      for (int i = 0; i < N; i++) {
          int box;
          cin >> box;
          boxSum += box;
      }

      for (int i = 0; i < M; i++) {
          int book;
          cin >> book;
          bookSum += book;
      }

      cout << boxSum - bookSum << endl;

      return 0;
  }