#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Task {
private:
    int id;
    string title;
    string description;
    bool isCompleted;
    string creationDate;
    string dueDate;

public:
    Task() {
        id = 0;
        title = "";
        description = "";
        isCompleted = false;
        creationDate = getCurrentDate();
        dueDate = "";
    }

    Task(int taskId, string taskTitle, string taskDesc, string due)
        : id(taskId), title(taskTitle), description(taskDesc), isCompleted(false), dueDate(due) {
        creationDate = getCurrentDate();
    }

    string getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[11];
        sprintf(buffer, "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
        return string(buffer);
    }

    // Setters
    void setTitle(string t) { title = t; }
    void setDescription(string d) { description = d; }
    void setDueDate(string d) { dueDate = d; }
    void markCompleted() { isCompleted = true; }
    void markIncomplete() { isCompleted = false; }

    // Getters
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    bool getStatus() const { return isCompleted; }
    string getCreationDate() const { return creationDate; }
    string getDueDate() const { return dueDate; }

    void displayTask() const {
        cout << "------------- Task ID: " << id << " ---------------" << endl;
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Status: " << (isCompleted ? "✅ Completed" : "❌ Incomplete") << endl;
        cout << "Creation Date: " << creationDate << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "----------------------------------------" << endl;
    }
};
