// test.cpp
#include <iostream>
#include "task_manager.h"
#include "date_util.h"
using namespace std;

void runTests() {
    TaskManager tm;

    cout << "\n--- Running Tests ---\n";

    // Test 1: Add a task
    Task task1(1, "Test Task", "Testing task addition", getCurrentDate(), "2025-12-31", false);
    tm.addTask(task1);
    cout << "Test 1 - Add Task: ";
    cout << (tm.getAllTasks().size() == 1 ? "✅ Passed" : "❌ Failed") << endl;

    // Test 2: Mark task completed
    tm.markTaskCompleted(1);
    cout << "Test 2 - Mark Task Completed: ";
    cout << (tm.getAllTasks()[0].completed == true ? "✅ Passed" : "❌ Failed") << endl;

    // Test 3: Update task
    tm.updateTask(1, "Updated Title", "Updated Description");
    cout << "Test 3 - Update Task: ";
    cout << (tm.getAllTasks()[0].title == "Updated Title" ? "✅ Passed" : "❌ Failed") << endl;

    // Test 4: Delete task
    tm.deleteTask(1);
    cout << "Test 4 - Delete Task: ";
    cout << (tm.getAllTasks().empty() ? "✅ Passed" : "❌ Failed") << endl;

    cout << "--- Tests Completed ---\n";
}

int main() {
    runTests();
    return 0;
}
