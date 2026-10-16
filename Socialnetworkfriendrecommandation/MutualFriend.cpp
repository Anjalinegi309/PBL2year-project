
#include "MyLibrary.h"

int SocialNetwork::countMutualFriends(int a, int b) {
    int count = 0;

    if (a < 1 || a > MAX_USERS ||
        b < 1 || b > MAX_USERS ||
        !active[a] || !active[b])
        return 0;

    for (int i = 1; i <= MAX_USERS; i++) {
        if (graph[a][i] && graph[b][i])
            count++;
    }

    return count;
}

void SocialNetwork::displayCommonConnections(int a, int b) {
    if (a < 1 || a > MAX_USERS ||
        b < 1 || b > MAX_USERS ||
        !active[a] || !active[b]) {
        cout << "User not found.\n";
        return;
    }

    int count = 0;

    cout << "Mutual friends:\n";

    for (int i = 1; i <= MAX_USERS; i++) {
        if (graph[a][i] && graph[b][i]) {
            cout << users[i].name << '\n';
            count++;
        }
    }

    cout << "Total mutual friends: " << count << '\n';
}

void SocialNetwork::analyzeConnections(int id) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    cout << "User: " << users[id].name << '\n';
    cout << "Direct friends: " << getFriendCount(id) << '\n';

    for (int i = 1; i <= MAX_USERS; i++) {
        if (graph[id][i]) {
            cout << users[i].name
                 << " | Mutual friends: "
                 << countMutualFriends(id, i) << '\n';
        }
    }
}

void SocialNetwork::networkTraversal(int start) {
    bfsTraversal(start);
}
