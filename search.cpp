// search.cpp
#include "task.h"
#include <vector>
#include <iostream>

using namespace std;

// Function to search for a task by ID
Task* searchTaskById(vector<Task>& tasks, int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            return &task;
        }
    }
    return nullptr; // Not found
}

// Function to display search result
void searchTask(const vector<Task>& tasks, int id) {
    bool found = false;
    for (const auto& task : tasks) {
        if (task.getId() == id) {
            task.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ No task found with ID: " << id << endl;
    }
}
