#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string value) {
        name = value;
        left = right = nullptr;
    }
};

class Stadium {
public:
    Node* root;

    Stadium() {
        root = new Node("Main Entrance");

        root->left = new Node("Block A");
        root->right = new Node("Block B");

        root->left->left = new Node("A1");
        root->left->right = new Node("A2");
        root->right->left = new Node("B1");
        root->right->right = new Node("B2");
    }

    void zigzagTraversal() {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        cout << "\nZigzag Seating Blocks:\n";

        while (!q.empty()) {
            int size = q.size();
            vector<string> level(size);

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                int index = leftToRight
                            ? i : size - 1 - i;

                level[index] = current->name;

                if (current->left)
                    q.push(current->left);

                if (current->right)
                    q.push(current->right);
            }

            for (int i = 0; i < size; i++)
                cout << level[i] << " ";

            cout << endl;
            leftToRight = !leftToRight;
        }
    }

    bool searchBlock(string target) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->name == target)
                return true;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        return false;
    }
};

int main() {
    Stadium stadium;
    int choice;
    string block;

    do {
        cout << "\n=== STADIUM NAVIGATION ===\n";
        cout << "1. Display Seating Blocks\n";
        cout << "2. Search Seating Block\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            stadium.zigzagTraversal();
            break;

        case 2:
            cout << "Enter block name: ";
            cin >> block;

            if (stadium.searchBlock(block))
                cout << "Block found!\n";
            else
                cout << "Block not found!\n";
            break;

        case 3:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}