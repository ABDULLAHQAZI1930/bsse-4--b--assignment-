📄 Here's a sample developer_guide.md for your C++ Task Manager project:
markdown
Copy
Edit
# Developer Guide – CLI Task Manager (C++)

## 📌 Overview
This project is a Console-Based Task Manager system written in C++. It supports adding, viewing, updating, deleting, filtering, and saving tasks via a command-line interface.

---

## 🧱 Project Structure

| File | Purpose |
|------|---------|
| `main.cpp` | Entry point, handles user input and routing |
| `task.hpp / task.cpp` | Defines the Task class and task attributes |
| `file_manager.hpp / file_manager.cpp` | Handles reading/writing tasks from a text/JSON file |
| `date_util.hpp / date_util.cpp` | Validates and formats dates |
| `search.hpp / search.cpp` | Searches tasks by ID or keyword |
| `filter.hpp / filter.cpp` | Filters tasks by status (completed/incomplete) |
| `ui.hpp / ui.cpp` | Console menus and input prompts |
| `test.cpp` | Contains test cases for various modules |

---

## ⚙️ How to Build and Run

1. **Compile:**
   ```bash
   g++ -o task_manager main.cpp task.cpp file_manager.cpp date_util.cpp search.cpp filter.cpp ui.cpp test.cpp
Run:

bash
Copy
Edit
./task_manager
🧪 Testing
Run unit tests using:

bash
Copy
Edit
g++ -o test_runner test.cpp task.cpp file_manager.cpp date_util.cpp search.cpp filter.cpp ui.cpp
./test_runner
Tests are currently basic and check core functionalities like task creation, update, and file saving.

📂 Task Storage
Tasks are stored in a simple text or JSON file.

You can change the filename/path in file_manager.cpp.

📈 Future Improvements (Optional)
Add task priorities or tags

Use a proper database instead of files

Improve error handling

Add sorting options (by due date, name)













