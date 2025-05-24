#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "task.cpp"

using namespace std;

class FileManager {
private:
    string fileName;

public:
    FileManager(string fname = "tasks.txt") {
        fileName = fname;
    }

    // Save all tasks to file
    void saveTasks(const vector<Task>& tasks) {
        ofstream outFile(fileName);
        if (!outFile) {
            cerr << "❌ Error: Unable to open file for writing!" << endl;
            return;
        }

        for (const auto& task : tasks) {
            outFile << task.getId() << "|"
                    << task.getTitle() << "|"
                    << task.getDescription() << "|"
                    << task.getStatus() << "|"
                    << task.getCreationDate() << "|"
                    << task.getDueDate() << endl;
        }

        outFile.close();
        cout << "✅ Tasks saved successfully." << endl;
    }

    // Load tasks from file
    vector<Task> loadTasks() {
        vector<Task> tasks;
        ifstream inFile(fileName);
        if (!inFile) {
            cerr << "⚠️ Warning: File not found, starting fresh!" << endl;
            return tasks;
        }

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string idStr, title, desc, statusStr, creation, due;

            getline(ss, idStr, '|');
            getline(ss, title, '|');
            getline(ss, desc, '|');
            getline(ss, statusStr, '|');
            getline(ss, creation, '|');
            getline(ss, due, '|');

            int id = stoi(idStr);
            bool status = (statusStr == "1");

            Task task(id, title, desc, due);
            if (status) task.markCompleted();
            else task.markIncomplete();
            
            tasks.push_back(task);
        }

        inFile.close();
        cout << "✅ Tasks loaded successfully." << endl;
        return tasks;
    }
};
