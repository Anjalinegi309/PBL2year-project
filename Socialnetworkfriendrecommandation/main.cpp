
#include "MyLibrary.h"

int main() {
    SocialNetwork sn;
    int choice, id, a, b;
    string name;

    do {
        cout << "\n===== SOCIAL NETWORK =====\n";
        cout << "1. Add User\n";
        cout << "2. Delete User\n";
        cout << "3. Update User\n";
        cout << "4. Search User\n";
        cout << "5. Display Users\n";
        cout << "6. Add Friendship\n";
        cout << "7. Remove Friendship\n";
        cout << "8. Display Friends\n";
        cout << "9. Friend Count\n";
        cout << "10. Mutual Friends\n";
        cout << "11. Analyze Connections\n";
        cout << "12. BFS Traversal\n";
        cout << "13. Friends of Friends\n";
        cout << "14. Generate Recommendations\n";
        cout << "15. Rank Recommendations\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
            break;

        switch (choice) {
        case 1:
            cout << "Enter ID (1-100): ";
            cin >> id;
            cout << "Enter name: ";
            getline(cin >> ws, name);
            sn.addUser(id, name);
            break;

        case 2:
            cout << "Enter ID: ";
            cin >> id;
            sn.deleteUser(id);
            break;

        case 3:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter new name: ";
            getline(cin >> ws, name);
            sn.updateUser(id, name);
            break;

        case 4:
            cout << "Enter ID: ";
            cin >> id;
            sn.searchUser(id);
            break;

        case 5:
            sn.displayUsers();
            break;

        case 6:
            cout << "Enter two IDs: ";
            cin >> a >> b;
            sn.addFriendship(a, b);
            break;

        case 7:
            cout << "Enter two IDs: ";
            cin >> a >> b;
            sn.removeFriendship(a, b);
            break;

        case 8:
            cout << "Enter user ID: ";
            cin >> id;
            sn.displayFriends(id);
            break;

        case 9:
            cout << "Enter user ID: ";
            cin >> id;
            cout << "Friend count: "
                 << sn.getFriendCount(id) << '\n';
            break;

        case 10:
            cout << "Enter two IDs: ";
            cin >> a >> b;
            sn.displayCommonConnections(a, b);
            break;

        case 11:
            cout << "Enter user ID: ";
            cin >> id;
            sn.analyzeConnections(id);
            break;

        case 12:
            cout << "Enter starting ID: ";
            cin >> id;
            sn.bfsTraversal(id);
            break;

        case 13:
            cout << "Enter user ID: ";
            cin >> id;
            sn.getFriendsOfFriends(id);
            break;

        case 14:
            cout << "Enter user ID: ";
            cin >> id;
            sn.generateRecommendations(id);
            break;

        case 15:
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
