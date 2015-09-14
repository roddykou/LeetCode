#include <iostream>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    if (maxWidth == 0) {
        ret.push_back("");
        return ret;
    }
    int lineStart = 0, lineEnd = 0, lineLen = 0;
    while (lineEnd < words.size()) {
        if (lineLen + words[lineEnd].length() <= maxWidth) {
            lineLen += words[lineEnd].length() + 1;  // An additional space.
            lineEnd++;
        } else {
            lineEnd--;
            int numWords = lineEnd - lineStart + 1;
            string line;
            if (numWords == 1) {
                line += words[lineStart] + string(maxWidth - words[lineStart].length(), ' ');
            } else {
                lineLen = lineLen - numWords;
                int totalSpaces = maxWidth - lineLen;
                int spacesPerWord = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int i = lineStart; i < lineEnd; i++) {
                    line += words[i] + string (spacesPerWord, ' ');
                    if (i - lineStart < extraSpaces)
                        line += ' ';
                }
                line += words[lineEnd];
            }
            lineLen = 0;
            lineStart = lineEnd + 1;
            lineEnd = lineStart;
            ret.push_back(line);
        }
    }
    lineEnd--;
    string line;
    for (int i = lineStart; i < lineEnd; i++)
        line += words[i] + ' ';
    line += words[lineEnd];
    line += string (maxWidth - line.length(), ' ');
    ret.push_back(line);
    return ret;
}

/*
    1234567890123456
    This1234is1234an
    example12of1text
    justification.
 */

int main() {
    vector<string> words;
    // words.push_back("This");
    // words.push_back("is");
    // words.push_back("an");
    // words.push_back("example");
    // words.push_back("of");
    // words.push_back("text");
    // words.push_back("justification.");

    // words.push_back("a");
    // words.push_back("b");
    // words.push_back("c");
    // words.push_back("d");
    // words.push_back("e");

    words.push_back("");

    // vector<string> r = fullJustify(words, 16);
    vector<string> r = fullJustify(words, 2);
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << '|' << endl;
    cout << endl;
}
