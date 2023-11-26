#include <iostream>
#include <cctype>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    Node *next[26];
    int endmark;
};

Node *createNode()
{
    Node *newNode = new Node();
    newNode->endmark = 0;
    for (int i = 0; i < 26; i++)
    {
        newNode->next[i] = NULL;
    }
    return newNode;
}

Node *root = createNode();

void insert(string s)
{
    Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if (temp->next[c] == NULL)
        {
            temp->next[c] = createNode();
        }
        temp = temp->next[c];
    }
    temp->endmark++;
}

Node *search(string s)
{
    Node *temp = root;
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if (temp->next[c] == NULL)
            return NULL;
        temp = temp->next[c];
    }
    return temp;
}

int countEndmark(string s)
{
    Node *x = search(s);
    if (x == NULL)
        return 0;
    else
    {
        int cnt = 0;
        queue<Node *> q;
        q.push(x);
        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            cnt += cur->endmark;
            for (int i = 0; i < 26; i++)
            {
                if (cur->next[i] != NULL)
                    q.push(cur->next[i]);
            }
        }
        return cnt;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        insert(s);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << countEndmark(s) << endl;
    }
    return 0;
}