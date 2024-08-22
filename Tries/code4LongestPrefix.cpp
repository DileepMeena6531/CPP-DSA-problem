#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Node
{
public:
    unordered_map<char, Node *> children;
    bool isEndOfWord;
    Node()
    {
        isEndOfWord = false;
    }
};

class Tries
{
    Node *root;

public:
    Tries()
    {
        root = new Node();
    }

    void insert(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->isEndOfWord = true;
    }

    void helper(Node *root, string &ans, string temp)
    {

        for (auto child : root->children)
        {
            if (child.second->isEndOfWord)
            {
                temp += child.first;
                if (temp.size() == ans.size() && temp < ans || temp.size() > ans.size())
                {
                    ans = temp;
                }
                helper(child.second, ans, temp);
                temp = temp.substr(0,temp.size() - 1);
            }
        }
    }
    string longStriEndOfWord()
    {
        string ans = "";
        helper(root, ans, "");
        return ans;
    }
};

string longestString(vector<string> dict)
{
    Tries tr;
    for (int i = 0; i < dict.size(); i++)
    {
        tr.insert(dict[i]);
    }

    return tr.longStriEndOfWord();
}

int main()
{
    vector<string> dict = {"d", "di", "dil", "dile","dilee", "dileep", "m", "me", "mee", "meen", "meena"};

    cout << longestString(dict);

    return 0;
}