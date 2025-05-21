
# Task Tracker – A Simple CLI-Based Task Management System

A lightweight, terminal-based task manager written in **C++**. This tool helps users **create**, **view**, **search**, **filter**, and **store** tasks efficiently using a file-based approach.

---

## ✨ Features

- Add new tasks with title, description, and deadlines
- Mark tasks as completed
- Display all pending and completed tasks
- Filter tasks by due date
- Search tasks by keywords
- Save tasks to a `.txt` or `.json` file (basic file I/O)
- Modular C++ structure using header and implementation files

---

## 📁 Modules

| Module | Description |
|--------|-------------|
| `main.cpp` | Main entry point with menu and routing |
| `task.hpp` / `task.cpp` | Task class for managing task attributes |
| `file_manager.hpp` / `file_manager.cpp` | Handles reading/writing task data |
| `date_util.hpp` / `date_util.cpp` | Date formatting and validation helpers |
| `search.hpp` / `search.cpp` | Search and keyword matching logic |
| `filter.hpp` / `filter.cpp` | Date-based task filtering |
| `ui.hpp` / `ui.cpp` | Console UI functions (menus, prompts) |
| `test.cpp` | Basic test file for checking functionality |

---

## 🛠️ Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/Task-Tracker-CPP.git
Navigate to the project directory:

bash
Copy
Edit
cd Task-Tracker-CPP
Compile the code:

bash
Copy
Edit
g++ main.cpp task.cpp file_manager.cpp date_util.cpp search.cpp filter.cpp ui.cpp -o task_tracker
Run the application:

bash
Copy
Edit
./task_tracker
🧪 Usage
On launch, you’ll see a menu:

pgsql
Copy
Edit
===== Task Tracker =====
1. Add Task
2. View All Tasks
3. Search Tasks
4. Filter Tasks by Date
5. Mark Task as Completed
6. Exit
To add a task:

Input title, description, and due date (YYYY-MM-DD)

The task will be saved in tasks.txt

Example:

yaml
Copy
Edit
Title: Final Project
Description: Complete project documentation
Due Date: 2025-06-01
You can view, filter, and mark tasks using the menu options.

📦 Sample Task Output
yaml
Copy
Edit
ID: 1
Title: Final Project
Description: Complete project documentation
Due Date: 2025-06-01
Status: Incomplete
-----------------------------
🔧 Dependencies
This project uses standard C++17 and does not rely on any external libraries. It runs on:

Linux

Windows (via MinGW or any C++ compiler)

MacOS (via g++ or clang++)

👤 Author
Developed by abdullah qazi
C++ Version based on the original idea, restructured for CLI C++ implementation.

📄 License
This project is open-source and licensed under the MIT License.





