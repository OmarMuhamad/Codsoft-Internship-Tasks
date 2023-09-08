// Omar Mohammad
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

int tasks = 0; // store the number of tasks
vector<pair<string, bool>> lst; // vector of pair of string and boolean (status)

void displayList() { // function to print the currents tasks or display them
    cout << "Current Tasks: \n";
    for (auto task : lst) {
        cout << "Task: " << task.first << "   Status: " << ((task.second == false) ? "Pending" : "Done") << '\n';
    }
}
void addTask() {
    string task;
    char status;

    cout << "Enter the task: \n";
    cin.ignore(); // Add this line to consume the previous newline character
    getline(cin, task);

    cout << "Enter the status of task (P for Pending, D for Done): \n";
    cin >> status;

    tasks++;
    lst.push_back(make_pair(task, (status == 'P') ? false : true));
}




void deleteTask() {
    int choice;
    if (tasks == 0) {
        cout << "Empty List\n";
        return;
    }
    displayList();
    while (true) {
        cout << "Enter the number\n";
        cin >> choice;
        if (choice <= tasks) {
            break;
        }
        else {
            cout << "Out of Range\n";
        }

    }
    tasks--;
    int i = 1;
    for (auto task : lst) {
        if (i == choice) {
            break;
        }
        i++;
    }
    lst.erase(lst.begin() + i - 1); // erase the task
}

int main(){
    int choice;
    while (true) {
        cout << "(1) - Add Task\n(2) - View Tasks\n(3) - Remove Task\n(4) - Close To Do List\n";
        cin >> choice;
        if (choice == 1) {
            addTask(); // call add task function with three arguments
        }
        else if (choice == 2) { // if choice is to display Tasks
            displayList(); // call display function
        }
        else if (choice == 3) {
            deleteTask(); // to delete task
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    cout << "Thank you for using To Do List App\n";
}
