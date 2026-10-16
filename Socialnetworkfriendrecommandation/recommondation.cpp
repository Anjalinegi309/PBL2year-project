
#include "MyLibrary.h"

void SocialNetwork::bfsTraversal(int start) {
    if (start < 1 || start > MAX_USERS || !active[start]) {
        cout << "User not found.\n";
        return;
    }

    bool visited[MAX_USERS + 1] = {};
    MyQueue q;
    q.init();

    q.push(start);
    visited[start] = true;

    cout << "BFS: ";

    while (!q.empty()) {
        int current = q.pop();
        cout << current << " ";

        for (int i = 1; i <= MAX_USERS; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << '\n';
}

void SocialNetwork::getFriendsOfFriends(int id) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    bool found = false;

    for (int friendId = 1; friendId <= MAX_USERS; friendId++) {
        if (!graph[id][friendId])
            continue;

        for (int candidate = 1; candidate <= MAX_USERS; candidate++) {
            if (active[candidate] &&
                graph[friendId][candidate] &&
                candidate != id &&
                !graph[id][candidate]) {
                cout << users[candidate].name
                     << " (ID " << candidate << ")\n";
                found = true;
            }
        }
    }

    if (!found)
        cout << "No friends-of-friends found.\n";
}

void SocialNetwork::generateRecommendations(int id) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    bool found = false;

    cout << "Suggested friends:\n";

    for (int candidate = 1; candidate <= MAX_USERS; candidate++) {
        if (!active[candidate] ||
            candidate == id ||
            graph[id][candidate])
            continue;

        int score = countMutualFriends(id, candidate);

        if (score > 0) {
            cout << users[candidate].name
                 << " | Mutual friends: " << score << '\n';
            found = true;
        }
    }

    if (!found)
        cout << "No recommendations available.\n";
}
