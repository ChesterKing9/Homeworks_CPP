#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <string>

// 1. Number of unique words
unsigned int uniqueWordsCount(const std::string& line) {
    std::unordered_set<std::string> uniqueWords;
    std::istringstream stream(line);
    std::string word;

    while (stream >> word) {
        uniqueWords.insert(word);
    }
    return uniqueWords.size();
}

// 2. most occured word
std::string mostOccuredWord(const std::string& line) {
    std::unordered_map<std::string, int> wordCount;
    std::istringstream stream(line);
    std::string word, mostFrequentWord;
    int maxCount = 0;

    while (stream >> word) {
        wordCount[word]++;
        if (wordCount[word] > maxCount) {
            maxCount = wordCount[word];
            mostFrequentWord = word;
        }
    }
    return mostFrequentWord;
}

// 3. check if brackets are balanced
bool isBalanced(const std::string& line) {
    std::stack<char> brackets;
    for (char c : line) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty()) return false;
            char top = brackets.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
            brackets.pop();
        }
    }
    return brackets.empty();
}

// 4. cycle in linked list
struct Node {
    int value;
    Node* next;
};

bool has_cycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
	// 1 & 2 tests
    std::string line = "Hello Hey Hello Bye Hey";
    std::cout << "Unique Words: " << uniqueWordsCount(line) << std::endl;
    std::cout << "Most Occured Word: " << mostOccuredWord(line) << std::endl;

	// test 3
    std::string bracketsLine = "{ [()][ ] }()";
    std::cout << "Brackets are balanced: " << (isBalanced(bracketsLine) ? "OK" : "NOT OK") << std::endl;

    // test 4
    Node* head = new Node{ 1, nullptr };
    head->next = new Node{ 2, nullptr };
    head->next->next = new Node{ 3, head };
    std::cout << "Cycle in the list: " << (has_cycle(head) ? "YES" : "NO") << std::endl;

    return 0;
}
