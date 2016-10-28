#include <iostream>
#include <cmath>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;

static const string dictionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const int base = dictionary.length();

string int2str(int id) {
	string ret = "";
	while (id > 0) {
		ret += dictionary[id % base];
		id = id / base;
	}
	return ret;
}

int str2int(const string& shortUrl) {
	int ret = 0;
	for (int i = 0; i < shortUrl.length(); i++)
		ret += dictionary.find(shortUrl[i]) * pow(base, i);
	return ret;
}

int main() {
	srand (time(nullptr));
	int randInt = rand() % 99999;
	cout << "random integer is: " << randInt << endl;
	cout << "encoded short url is: " << int2str(randInt) << endl;
	cout << "decoded id is: " << str2int(int2str(randInt)) << endl;
}