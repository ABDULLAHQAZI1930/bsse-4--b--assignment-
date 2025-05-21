#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

// Structure for Task
struct Task {
    int id;
    string title;
    string description;
    string creationDate;
    string dueDate;
    bool completed;
};

// Helper function to get current date
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    return string(buffer);
}

// UI Class
class UIManager {
public:
    void displayMenu() {
        cout << "\n--- Task Manager Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. Show All Tasks\n";
        cout << "3. Update Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Mark Task as Completed\n";
        cout << "6. Mark Task as Incomplete\n";
        cout << "7. Show Completed Tasks\n";
        cout << "8. Show Incomplete Tasks\n";
        cout << "9. Exit\n";
    }

    string getInput(const string& prompt) {
        cout << prompt;
        string input;
        getline(cin, input);
        return input;
    }

    void showMessage(const string& msg) {
        cout << msg << endl;
    }
};

// Task Manager Class
class TaskManager {
private:
    vector<Task> tasks;
    int taskCounter = 0;

public:
    void addTask(const string& title, const string& desc, const string& dueDate) {
        Task task;
        task.id = ++taskCounter;
        task.title = title;
        task.description = desc;
        task.creationDate = getCurrentDate();
        task.dueDate = dueDate;
        task.completed = false;
        tasks.push_back(task);
        cout << "Task added successfully ✅" << endl;
    }

    void showTasks(const vector<Task>& list) {
        for (const auto& task : list) {
            cout << "\nID: " << task.id << "\nTitle: " << task.title
                 << "\nDescription: " << task.description
                 << "\nDue Date: " << task.dueDate
                 << "\nCreated On: " << task.creationDate
                 << "\nCompleted: " << (task.completed ? "Yes" : "No") << endl;
        }
    }

    void showAllTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        showTasks(tasks);
    }

    Task* findTask(int id) {
        for (auto& task : tasks) {
            if (task.id == id)
                return &task;
        }
        return nullptr;
    }

    void updateTask(int id, const string& title, const string& desc) {
        Task* task = findTask(id);
        if (task) {
            task->title = title;
            task->description = desc;
            cout << "Task updated successfully ✅" << endl;
        } else {
            cout << "Task not found ❌" << endl;
        }
    }

    void deleteTask(int id) {
        auto it = remove_if(tasks.begin(), tasks.end(), [id](Task& task) { return task.id == id; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "Task deleted successfully ✅" << endl;
        } else {
            cout << "Task not found ❌" << endl;
        }
    }

    void markCompleted(int id) {
        Task* task = findTask(id);
        if (task) {
            task->completed = true;
            cout << "Task marked as completed ✅" << endl;
        } else {
            cout << "Task not found ❌" << endl;
        }
    }

    void markIncomplete(int id) {
        Task* task = findTask(id);
        if (task) {
            task->completed = false;
            cout << "Task marked as incomplete ✅" << endl;
        } else {
            cout << "Task not found ❌" << endl;
        }
    }

    void showCompletedTasks() {
        vector<Task> completed;
        for (const auto& task : tasks) {
            if (task.completed) completed.push_back(task);
        }
        cout << "\n--- Completed Tasks ---\n";
        showTasks(completed);
    }

    void showIncompleteTasks() {
        vector<Task> incomplete;
        for (const auto& task : tasks) {
            if (!task.completed) incomplete.push_back(task);
        }
        cout << "\n--- Incomplete Tasks ---\n";
        showTasks(incomplete);
    }
};

// Main Application
int main() {
    TaskManager manager;
    UIManager ui;
    string input;

    while (true) {
        ui.displayMenu();
        input = ui.getInput("Enter your choice: ");
        int choice = stoi(input);

        switch (choice) {
            case 1: {
                string title = ui.getInput("Title: ");
                string desc = ui.getInput("Description: ");
                string due = ui.getInput("Due Date (YYYY-MM-DD): ");
                manager.addTask(title, desc, due);
                break;
            }
            case 2:
                manager.showAllTasks();
                break;
            case 3: {
                int id = stoi(ui.getInput("Enter task ID to update: "));
                string title = ui.getInput("New Title: ");
                string desc = ui.getInput("New Description: ");
                manager.updateTask(id, title, desc);
                break;
            }
            case 4: {
                int id = stoi(ui.getInput("Enter task ID to delete: "));
                manager.deleteTask(id);
                break;
            }
            case 5: {
                int id = stoi(ui.getInput("Enter task ID to mark as completed: "));
                manager.markCompleted(id);
                break;
            }
            case 6: {
                int id = stoi(ui.getInput("Enter task ID to mark as incomplete: "));
                manager.markIncomplete(id);
                break;
            }
            case 7:
                manager.showCompletedTasks();
                break;
            case 8:
                manager.showIncompleteTasks();
                break;
            case 9:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
