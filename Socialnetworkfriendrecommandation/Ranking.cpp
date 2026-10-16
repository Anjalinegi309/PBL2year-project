
#include "MyLibrary.h"

int SocialNetwork::calculateScore(int a, int b) {
    return countMutualFriends(a, b);
}

void SocialNetwork::rankRecommendations(int id) {
    displayRanking(id);
}

void SocialNetwork::displayRanking(int id) {
    if (id < 1 || id > MAX_USERS || !active[id]) {
        cout << "User not found.\n";
        return;
    }

    int candidate[MAX_USERS];
    int score[MAX_USERS];
    int n = 0;

    // Find candidates and calculate scores
    for (int i = 1; i <= MAX_USERS; i++) {
        if (active[i] && i != id && !graph[id][i]) {
            int s = calculateScore(id, i);

            if (s > 0) {
                candidate[n] = i;
                score[n] = s;
                n++;
            }
        }
    }

    // Sort by score, highest first
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (score[j] < score[j + 1]) {
                int temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;

                temp = candidate[j];
                candidate[j] = candidate[j + 1];
                candidate[j + 1] = temp;
            }
        }
    }

    cout << "--- Ranked Recommendations ---\n";

    if (n == 0) {
        cout << "No recommendations available.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". "
             << users[candidate[i]].name
             << " | Mutual friends: " << score[i] << '\n';
    }
}
