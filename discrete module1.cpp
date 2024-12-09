#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    const int maxstudents = 100;  
    string students[maxstudents];  
    int friendCount[maxstudents] = {0};   
    int studentCount = 0;  
    ifstream file("Friends Dataset.csv");  
    if (!file) {
        cerr << "File could not be opened!" << endl;
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
        string studentname, friendName;
        int count = 0;
 
        getline(dis, studentname, ',');

   
        bool studentExists = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i] == studentname) {
                studentExists = true;
                break;
            }
        }

        if (!studentExists) {
            students[studentCount] = studentname;
            studentCount++;
        }

       
        while (getline(dis, friendName, ',')) {
            count++;
        }

        
        int studentIndex = -1;
        for (int i = 0; i < studentCount; i++) {
            if (students[i] == studentname) {
                studentIndex = i;
                break;
            }
        }
        friendCount[studentIndex] = count;
    }
   
    string mostPopular;
    int maxFriends = 0;
    for (int i = 0; i < studentCount; i++) {
        if (friendCount[i] > maxFriends) {
            maxFriends = friendCount[i];
            mostPopular = students[i];
        }
    }
    
    cout << "The most popular student is " << mostPopular 
         << " with " << maxFriends << " friends." << endl;

    return 0;
}