// filter.cpp
#include "task.h"
#include <vector>
#include <iostream>

using namespace std;

// Function to show all completed tasks
void showCompletedTasks(const vector<Task>& tasks) {
    cout << "------- All Completed Tasks -------" << endl;
    bool found = false;
    for (const auto& task : tasks) {
        if (task.isCompleted()) {
            task.display();
            found = true;
        }
    }
    if (!found) {
        cout << "❌ No completed tasks found." << endl;
    }
}

// Function to show all incomplete tasks
void showIncompleteTasks(const vector<Task>& tasks) {
    cout << "------- All Incomplete Tasks -------" << endl;
    bool found = false;
    for (const auto& task : tasks) {
        if (!task.isCompleted()) {
            task.display();
            found = true;
        }
    }
    if (!found) {
        cout << "❌ No incomplete tasks found." << endl;
    }
}
