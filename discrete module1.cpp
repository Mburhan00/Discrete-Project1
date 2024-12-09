 #include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    const int maximumfriends = 100;
    string friends[maximumfriends];
    int counts[maximumfriends] = {0};
    int totalFriends = 0;

    ifstream file("Friends Dataset.csv");
    if (!file) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }
    string line;
    bool Headerrow = true;
    while (getline(file, line)) {
        if (Headerrow) {
            Headerrow = false;
            continue;
        }
        stringstream dis(line);
        string studentName;
        getline(dis, studentName, ',');

        string friendName;
        while (getline(dis, friendName, ',')) {
            bool found = false;
            for (int i = 0; i < totalFriends; i++) {
                if (friends[i] == friendName) {
                    counts[i]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                friends[totalFriends] = friendName;
                counts[totalFriends] = 1;
                totalFriends++;
            }
        }
    }
    string mostPopular;
    int maxCount = 0;
    for (int i = 0; i < totalFriends; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            mostPopular = friends[i];
        }
    }
    cout << "The most popular student is " << mostPopular 
         << " with " << maxCount << " mentions." << endl;

    return 0;
}