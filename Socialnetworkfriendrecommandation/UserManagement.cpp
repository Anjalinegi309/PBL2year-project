
#include "MyLibrary.h"

SocialNetwork::SocialNetwork() {
    for (int i = 0; i <= MAX_USERS; i++) {
        active[i] = false;

        for (int j = 0; j <= MAX_USERS; j++)
            graph[i][j] = false;
    }
}

void SocialNetwork::addUser(int id, string name) {
    if (id < 1 || id > MAX_USERS) {
        cout << "ID must be between 1 and 100.\n";
        return;
    }

    if (active[id]) {
        cout << "ID already exists.\n";
        return;
    }

    users[id].id = id;
    users[id].name = name;
    active[id] = true;

    cout << "User added.\n";
}

void SocialNetwork::deleteUser(int id) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    for (int i = 1; i <= MAX_USERS; i++)
        graph[id][i] = graph[i][id] = false;

    active[id] = false;
    cout << "User deleted.\n";
}

void SocialNetwork::updateUser(int id, string name) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    users[id].name = name;
    cout << "User updated.\n";
}

void SocialNetwork::searchUser(int id) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    cout << users[id].id << " - "
         << users[id].name << '\n';
}

void SocialNetwork::displayUsers() {
    for (int i = 1; i <= MAX_USERS; i++) {
        if (active[i])
            cout << i << " - " << users[i].name << '\n';
    }
}
