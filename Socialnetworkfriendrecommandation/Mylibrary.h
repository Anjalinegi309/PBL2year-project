
#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_USERS = 100;

// User structure
struct User {
    int id;
    string name;
};

// Our own queue for BFS
struct MyQueue {
    int data[MAX_USERS + 1];
    int front, rear;

    void init() {
        front = 0;
        rear = -1;
    }

    bool empty() {
        return front > rear;
    }

    void push(int x) {
        if (rear < MAX_USERS)
            data[++rear] = x;
    }

    int pop() {
        if (empty())
            return -1;

        return data[front++];
    }
};

// Shared social network class
class SocialNetwork {
private:
    User users[MAX_USERS + 1];
    bool active[MAX_USERS + 1];
    bool graph[MAX_USERS + 1][MAX_USERS + 1];

public:
    SocialNetwork();

    // Samiksha
    void addUser(int id, string name);
    void deleteUser(int id);
    void updateUser(int id, string name);
    void searchUser(int id);
    void displayUsers();

    // Shivam
    void addFriendship(int a, int b);
    void removeFriendship(int a, int b);
    void displayFriends(int id);
    bool isFriend(int a, int b);
    int getFriendCount(int id);

    // Rashi
    int countMutualFriends(int a, int b);
    void displayCommonConnections(int a, int b);
    void analyzeConnections(int id);
    void networkTraversal(int start);

    // Abhay
    void bfsTraversal(int start);
    void getFriendsOfFriends(int id);
    void generateRecommendations(int id);

    // Ridham
    int calculateScore(int a, int b);
    void rankRecommendations(int id);
    void displayRanking(int id);
};

#endif
