
#include "MyLibrary.h"

bool SocialNetwork::isFriend(int a, int b) {
    if (a < 1 || a > MAX_USERS ||
        b < 1 || b > MAX_USERS)
        return false;

    return graph[a][b];
}

void SocialNetwork::addFriendship(int a, int b) {
    if (a < 1 || a > MAX_USERS ||
        b < 1 || b > MAX_USERS ||
        !active[a] || !active[b] || a == b) {
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

void SocialNetwork::removeFriendship(int a, int b) {
    if (!isFriend(a, b)) {
        cout << "Friendship not found.\n";
        return;
    }

    graph[a][b] = false;
    graph[b][a] = false;

    cout << "Friendship removed.\n";
}

void SocialNetwork::displayFriends(int id) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    bool found = false;

    for (int i = 1; i <= MAX_USERS; i++) {
        if (graph[id][i]) {
            cout << users[i].name << " (ID " << i << ")\n";
            found = true;
        }
    }

    if (!found)
        cout << "No friends yet.\n";
}

int SocialNetwork::getFriendCount(int id) {
    int count = 0;

    if (id < 1 || id > MAX_USERS || !active[id])
        return 0;

    for (int i = 1; i <= MAX_USERS; i++) {
        if (graph[id][i])
            count++;
    }

    return count;
}
