#include "Header.h"

//FIX_ME: функция больше не нужна + неверное название функции
/*void insert_sort(std::vector<int>& w, std::vector<int>& p) {
    for (int i = 1; i < w.size(); i++) {
        int temp = i;
        while (temp - 1 >= 0 && w[temp] < w[temp - 1]) {
            std::swap(w[temp], w[temp - 1]);
            std::swap(p[temp], p[temp - 1]);
            temp--;
        }

    }
}
*/

//FIX_ME: функция возвращает значение ценности + неверное название функции
/*int backpack(int W, std::vector<int>& wt, std::vector<int>& val, int n) {

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1));
    // Çàïîëíåíèå òàáëèöû
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // íåò ïðåäìåòîâ èëè âåñ ðþêçàêà ðàâåí 0
            else if (wt[i - 1] <= w)
                // Âûáîð ìåæäó âêëþ÷åíèåì è èñêëþ÷åíèåì òåêóùåãî ïðåäìåòà
                dp[i][w] = std::max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                dp[i - 1][w]);
            else
                // Òåêóùèé ïðåäìåò íå âìåùàåòñÿ â ðþêçàê
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
*/
int backpack(int capacity, const std::vector<int>& weights,
  const std::vector<int>& profit, std::vector<int>& chosen_indices,
  int& total_weight) {

  int n = static_cast<int>(weights.size());
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int w = 0; w <= capacity; ++w) {
      if (weights[i - 1] <= w) {
        dp[i][w] = std::max(profit[i - 1] + dp[i - 1][w - weights[i - 1]],
          dp[i - 1][w]);
      }
      else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  int w = capacity;
  total_weight = 0;
  chosen_indices.clear();

  for (int i = n; i > 0; --i) {
    if (dp[i][w] != dp[i - 1][w]) {
      chosen_indices.push_back(i);
      total_weight += weights[i - 1];
      w -= weights[i - 1];
    }
  }

  std::reverse(chosen_indices.begin(), chosen_indices.end());
  return dp[n][capacity];
}

bool ReadPositiveInt(std::ifstream& file, int& value,
  const std::string& errorMsg) {
  if (!(file >> value)) {
    std::cout << errorMsg << "\n";
    return false;
  }
  if (value <= 0) {
    std::cout << "Îøèáêà: Çíà÷åíèå äîëæíî áûòü ïîëîæèòåëüíûì\n";
    return false;
  }
  return true;
}
