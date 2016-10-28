#include <stdlib.h>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Task {
public:
   Task(int id) : _id (id) {};
   void execute() { cout << "running task: " << _id << endl; }
   void addDependency(Task *task) { _dependencies.push_back(task); }
   vector<Task *> getDependencies() { return _dependencies; }
private:
   int _id;
   vector<Task *> _dependencies;
};

void runDfs(vector<Task *> tasks, unordered_set<Task *>& executed,
            unordered_set<Task *>& parents) {
   for (Task *task : tasks) {
      if (parents.find(task) != parents.end()) {
         cout << "Cycle detected!!!" << endl;
         exit (EXIT_FAILURE);
      }
      if (executed.find(task) == executed.end()) {
         parents.insert(task);
         runDfs(task->getDependencies(), executed, parents);
         parents.erase(task);
         task->execute();
         executed.insert(task);
      }
   }
}

void run(vector<Task *>& tasks) {
   unordered_set<Task *> executed, parents;
   runDfs(tasks, executed, parents);
}

int main() {
   /*
         1 -> 2
         \   ^
         \  /
         v
          3
   */
   Task one (1);
   Task two (2);
   Task three (3);

   one.addDependency(&three);
   one.addDependency(&two);
   // two.addDependency(&one);
   three.addDependency(&two);

   vector<Task *> tasks;
   tasks.push_back(&one);
   tasks.push_back(&two);
   tasks.push_back(&three);

   run(tasks);
}
