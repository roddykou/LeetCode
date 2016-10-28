#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
/*
Mike -> {Ryan, Mitch}
Ryan -> {Mike}
Mitch -> {Lila}

Mike : 输出 Ryan, Mitch, Lila 这样子。。。
*/

void printRelation(vector<vector<int> >& relation, int person) {
   unordered_set<int> friends;
   queue<int> q;

   for (int f : relation[person]) {
      q.push(f);
      friends.insert(f);
   }

   while(!q.empty()) {
      int f = q.front();
      q.pop();
      for (int ff : relation[f]) {
         if (ff != person && friends.find(ff) == friends.end()) {
            q.push(ff);
            friends.insert(ff);
         }
      }
   }

   for (int f : friends) {
      cout << f << " ";
   }
   cout << endl;
}

int main() {
   /*
         Mike     Ryan     Mitch    Lila

   Mike     1        1        1
   Ryan     1        1        0
   Mitch
   */
   vector<int> mike;
   mike.push_back(1);
   mike.push_back(2);

   vector<int> ryan (1, 0);
   vector<int> mitch (1, 3);

   vector<vector<int> > relation;
   relation.push_back(mike);
   relation.push_back(ryan);
   relation.push_back(mitch);
   relation.push_back(vector<int> ());
   printRelation(relation, 0);
}
