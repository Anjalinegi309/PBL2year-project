
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct User {
    int id;
    string name;
};

class SocialNetwork {
private:
    User users[MAX + 1];
    bool active[MAX + 1];
    bool graph[MAX + 1][MAX + 1];

public:
    SocialNetwork() {
        for (int i = 0; i <= MAX; i++) {
            active[i] = false;

            for (int j = 0; j <= MAX; j++) {
                graph[i][j] = false;
            }
        }
    }

    bool userExists(int id) {
        return id >= 1 && id <= MAX && active[id];
    }

    // Module 1: Add User
    void addUser(int id, string name) {
        if (id < 1 || id > MAX || active[id]) {
            cout << "Invalid ID or user already exists.\n";
            return;
        }

        users[id].id = id;
        users[id].name = name;
        active[id] = true;

        cout << "User added successfully.\n";
    }

    // Module 2: Display Users
    void displayUsers() {
        for (int i = 1; i <= MAX; i++) {
            if (active[i]) {
                cout << users[i].id << " - "
                     << users[i].name << endl;
            }
        }
    }

    // Module 3: Add Friendship
    void addFriendship(int a, int b) {
        if (!userExists(a) || !userExists(b) || a == b) {
            cout << "Invalid users.\n";
            return;
        }

        if (graph[a][b]) {
            cout << "Already friends.\n";
            return;
        }

        graph[a][b] = true;
        graph[b][a] = true;

        cout << "Friendship added.\n";
    }

    // Module 4: Display Friends
    void displayFriends(int id) {
        if (!userExists(id)) {
            cout << "User not found.\n";
            return;
        }

        cout << "Friends of " << users[id].name << ":\n";

        for (int i = 1; i <= MAX; i++) {
            if (graph[id][i]) {
                cout << users[i].name << endl;
            }
        }
    }

    // Module 5: Count Mutual Friends
    int countMutualFriends(int a, int b) {
        int count = 0;

        if (!userExists(a) || !userExists(b))
            return 0;

        for (int i = 1; i <= MAX; i++) {
            if (graph[a][i] && graph[b][i]) {
                count++;
            }
        }

        return count;
    }

    // Module 6: Recommend Friends
    void recommendFriends(int id) {
        if (!userExists(id)) {
            cout << "User not found.\n";
            return;
        }

        cout << "Friend recommendations:\n";
        bool found = false;

        for (int i = 1; i <= MAX; i++) {
            if (active[i] && i != id && !graph[id][i]) {
                int score = countMutualFriends(id, i);

                if (score > 0) {
                    cout << users[i].name
                         << " | Mutual friends: "
                         << score << endl;
                    found = true;
                }
            }
        }

        if (!found)
            cout << "No recommendations available.\n";
    }

    // Module 7: Rank Recommendations
    void rankRecommendations(int id) {
        if (!userExists(id)) {
            cout << "User not found.\n";
            return;
        }

        int ids[MAX + 1], scores[MAX + 1];
        int n = 0;

        for (int i = 1; i <= MAX; i++) {
            if (active[i] && i != id && !graph[id][i]) {
                int score = countMutualFriends(id, i);

                if (score > 0) {
                    ids[n] = i;
                    scores[n] = score;
                    n++;
                }
            }
        }

        // Bubble Sort: highest score first
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (scores[j] < scores[j + 1]) {
                    int temp = scores[j];
                    scores[j] = scores[j + 1];
                    scores[j + 1] = temp;

                    temp = ids[j];
                    ids[j] = ids[j + 1];
                    ids[j + 1] = temp;
                }
            }
        }

        cout << "Ranked recommendations:\n";

        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". "
                 << users[ids[i]].name
                 << " | Score: " << scores[i] << endl;
        }

        if (n == 0)
            cout << "No recommendations available.\n";
    }
};

int main() {
    SocialNetwork sn;
    int choice, id, a, b;
    string name;

    do {
        cout << "\n===== SOCIAL NETWORK SYSTEM =====\n";
        cout << "1. Add User\n";
        cout << "2. Display Users\n";
        cout << "3. Add Friendship\n";
        cout << "4. Display Friends\n";
        cout << "5. Count Mutual Friends\n";
        cout << "6. Recommend Friends\n";
        cout << "7. Rank Recommendations\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID and name: ";
            cin >> id >> name;
            sn.addUser(id, name);
            break;

        case 2:
            sn.displayUsers();
            break;

        case 3:
            cout << "Enter two user IDs: ";
            cin >> a >> b;
            sn.addFriendship(a, b);
            break;

        case 4:
            cout << "Enter user ID: ";
            cin >> id;
            sn.displayFriends(id);
            break;

        case 5:
            cout << "Enter two user IDs: ";
            cin >> a >> b;
            cout << "Mutual friends: "
                 << sn.countMutualFriends(a, b) << endl;
            break;

        case 6:
            cout << "Enter user ID: ";
            cin >> id;
            sn.recommendFriends(id);
            break;

        case 7:
            cout << "Enter user ID: ";
            cin >> id;
            sn.rankRecommendations(id);
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
