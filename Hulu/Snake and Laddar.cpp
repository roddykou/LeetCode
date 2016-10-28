#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
struct Cell {
   int index, step;
   Cell (int i, int s) : index(i), step(s) {}
};

// index here starts from 1
int solve(int destIndex, unordered_map<int, int> jumps) {
   queue<Cell> q;
   vector<bool> visited (destIndex + 1, false);
   
   Cell start (1, 0);
   q.push(start);
   visited[1] = true;

   while (!q.empty()) {
      Cell current = q.front();
      q.pop();

      for (int i = 1; i <= 6; i++) {
         Cell next (current.index + i, current.step + 1);

         if (next.index > destIndex)
            break;

         if (jumps.find(next.index) != jumps.end())
            next.index = jumps[next.index];

         if (visited[next.index])
            continue;

         if (next.index == destIndex)
            return next.step;

         visited[next.index] = true;
         q.push(next);
      }
   }

   return -1;
}

int main() {
   // snake and laddar
   unordered_map<int, int> jumps1;
   jumps1[3] = 23;
   jumps1[5] = 16;
   jumps1[20] = 33;
   jumps1[35] = 25;

   cout << solve(36, jumps1) << endl;

   unordered_map<int, int> jumps2;
   jumps2[9] = 11;
   jumps2[16] = 14;

   cout << solve(25, jumps2) << endl;
}