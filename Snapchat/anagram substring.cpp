#include <iostream>
#include <vector>

using namespace std;

void solution(const string& s, const string& p) {
   int diff = 0;
   vector<int> table (26, 0);

   for (int i = 0; i < p.length(); i++) {
      table[p[i] - 'A']++;
      table[s[i] - 'A']--;
   }

   for (int i = 0; i < table.size(); i++) {
      if (table[i] != 0) {
         diff++;
      }
   }

   if (diff == 0) cout << "0" << " ";

   for (int i = p.length(); i < s.length(); i++) {
      table[s[i - p.length()] - 'A']++;
      if (table[s[i - p.length()] - 'A'] == 1)  diff++;
      if (table[s[i - p.length()] - 'A'] == 0)  diff--;

      table[s[i] - 'A']--;
      if (table[s[i] - 'A'] == -1)  diff++;
      if (table[s[i] - 'A'] == 0)   diff--;

      // cout << "diff: " << diff << endl;
      // for (int j = 0; j < 5; j++)
      //    cout << table[j] << " ";
      // cout << endl;
      if (diff == 0) cout << i - p.length() + 1 << " ";
   }
   cout << endl;
}

int main() {
   // string s = "BACDEABCDA";
   // string p = "ABCD";
   string s = "AAABABAA";
   string p = "AABA";
   solution(s, p);
}
