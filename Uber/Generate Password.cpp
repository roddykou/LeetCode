#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(string& str, int index, unordered_map<char, vector<char>>& dict,
         vector<string>& ret) {
   if (index == str.length())
      ret.push_back(str);

   for (int i = index; i < str.length(); i++) {
      if (dict.find(str[i]) != dict.end()) {
         char origin = str[i];
         for (char c : dict[origin]) {
            str[i] = c;
            dfs(str, i + 1, dict, ret);
            cout << "pushing back " << str << endl;
         }
         str[i] = origin;
         break;   // break the loop so that we always replace the char
      }
   }
}

vector<string> generatePassword(string& str, unordered_map<char, vector<char>>& dict) {
   vector<string> ret = vector<string> ();
   dfs(str, 0, dict, ret);
   return ret;
}

int main() {
   unordered_map<char, vector<char>> dict;
   dict['a'] = vector<char> ();
   dict['a'].push_back('A');
   dict['a'].push_back('1');
   dict['a'].push_back('@');

   dict['s'] = vector<char> ();
   dict['s'].push_back('S');
   dict['s'].push_back('7');
   dict['s'].push_back('8');

   string pwd = "password";
   vector<string> result = generatePassword(pwd, dict);
   for (string str : result)
      cout << str << endl;
}