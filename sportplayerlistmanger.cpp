#include <iostream>
#include <string>
using namespace std;

struct Node {
    string playerName;
    int playerNumber;
    Node* next;
};

class PlayerQueue {
private:
    Node* front;
    Node* rear;

public:
    PlayerQueue() {
        front = rear = NULL;
    }

    // Add player to queue
    void enqueue(string name, int number) {
        Node* newNode = new Node;
        newNode->playerName = name;
        newNode->playerNumber = number;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Player added successfully!\n";
    }

    // Remove player from queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Removed Player: " << temp->playerName << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Display players
    void display() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;

        cout << "\n--- Sports Player Queue ---\n";

        while (temp != NULL) {
            cout << "Player Name: " << temp->playerName
                 << " | Player Number: " << temp->playerNumber << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PlayerQueue q;
    int choice, number;
    string name;

    do {
        cout << "\n===== Sports Player Management =====\n";
        cout << "1. Add Player\n";
        cout << "2. Remove Player\n";
        cout << "3. Display Players\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Player Name: ";
            cin >> name;

            cout << "Enter Player Number: ";
            cin >> number;

            q.enqueue(name, number);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
