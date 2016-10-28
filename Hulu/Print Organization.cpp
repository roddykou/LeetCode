#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
	string name;
	vector<Person *> children;

public:
	Person(string str) : name(str) {}
	void addChild(Person *person) { children.push_back(person); }
};

enum Position
{
	first,
	regular,
	last
};

void printOrg(Person *person, string prefix, Position position) {
	if (person == nullptr)	return;

	string connector = position == last ? "┗" : (position == first ? "" : "┣");
	cout << prefix << connector << person->name << endl;

	if (person->children.size() > 0) {
		prefix += position == last ? " " : (position == first ? "" : "┃");
		for (int i = 0; i < person->children.size() - 1; i++)
			printOrg(person->children[i], prefix, regular);
		printOrg(person->children[person->children.size() - 1], prefix, last);
		
	}
}

int main() {
	// cout << "┣┗┃" << endl;

	Person a ("1");
	Person aa ("1.1");
	Person ab ("1.2");
	Person ac ("1.3");
	Person aaa ("1.1.1");
	Person aaaa ("1.1.1.1");
	Person aba ("1.2.1");
	Person abb ("1.2.2");
	Person aca ("1.3.1");

	a.addChild(&aa);
	a.addChild(&ab);
	a.addChild(&ac);
	aa.addChild(&aaa);
	aaa.addChild(&aaaa);
	ab.addChild(&aba);
	ab.addChild(&abb);
	ac.addChild(&aca);

	printOrg(&a, "", first);
}