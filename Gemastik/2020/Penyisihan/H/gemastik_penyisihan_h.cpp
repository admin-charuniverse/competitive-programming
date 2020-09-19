#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m , q;
  cin >> n >> m >> q;

  int arrInput[n][m];
  int arrSum[n][m];
  int result[q];

  for(int i = 0; i < n; i++) {
    long sum = 0;
    for(int j = 0; j < m; j++) {
      cin >> arrInput[i][j];

      sum += arrInput[i][j];
      arrSum[i][j] = 0;
      arrSum[i][j] = sum;
    }
  }

  for(int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    result[i] = 0;

    x1 -= 1; y1 -= 1; x2 -= 1; y2 -= 1;

    if(y1 == 0) {
      for(int j = x1; j <= x2; j++) {
        result[i] += arrSum[j][y2];
      }
    } else {
      for(int j = x1; j <= x2; j++) {
        result[i] += (arrSum[j][y2] - arrSum[j][y1]) + arrInput[j][y1];
      }
    }
  }

  for(int i = 0; i < q; i++) {
    cout << result[i] << endl;
  }

  return 0;
}