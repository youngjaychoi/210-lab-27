#include <iostream>
#include <map>
#include <tuple>
using namespace std;

using Information = tuple<int, string, string>;

void menu();
void addVillager(map<string, Information> &villagers);
void deleteVillager(map<string, Information> &villagers);
void increaseFriendship(map<string, Information> &villagers);
void decreaseFriendship(map<string, Information> &villagers);
void searchVillager(const map<string, Information> &villagers);
void displayVillagers(const map<string, Information> &villagers);

int main() {
    map<string, Information> villagers;
    int choice;



    return 0;
}

void menu() {
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
}

void addVillager(map<string, Information> &villagers) {
    string name, species, catchphrase;
    int friendshipLevel;

    cout << "Villager name: ";
    cin >> name;
    cout << "Friendship level (0-10): ";
    cin >> friendshipLevel;
    cout << "Species: ";
    cin >> species;
    cout << "Catchphrase: ";
    cin.ignore();
    getline(cin, catchphrase);

    villagers[name] = make_tuple(friendshipLevel, species, catchphrase);
    cout << name << " added" << endl;
}

void deleteVillager(map<string, Information> &villagers) {
    string name;
    cout << "Villager name to delete: ";
    cin >> name;

    if (villagers.erase(name)) {
        cout << name << " deleted" << endl;
    } else {
        cout << name << " not found" << endl;
    }
}

void increaseFriendship(map<string, Information> &villagers) {
    string name;
    cout << "Villager name to increase friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int &level = get<0>(it->second);
        if (level < 10) {
            ++level;
            cout << "Friendship level of " << name << " increased to " << level << endl;
        } else {
            cout << "Friendship level is already 10" << endl;
        }
    } else {
        cout << name << " not found" << endl;
    }
}

void decreaseFriendship(map<string, Information> &villagers) {
    string name;
    cout << "Villager name to decrease friendship: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        int &level = get<0>(it->second);
        if (level > 0) {
            --level;
            cout << "Friendship level of " << name << " decreased to " << level << endl;
        } else {
            cout << "Friendship level is already 0" << endl;
        }
    } else {
        cout << name << " not found" << endl;
    }
}

void searchVillager(const map<string, Information> &villagers) {
    string name;
    cout << "Villager name to search: ";
    cin >> name;

    auto it = villagers.find(name);
    if (it != villagers.end()) {
        cout << "Name: " << it->first << endl;
        cout << "Friendship level: " << get<0>(it->second) << endl;
        cout << "Species: " << 

    }
}

void displayVillagers(const map<string, Information> &villagers) {

}
