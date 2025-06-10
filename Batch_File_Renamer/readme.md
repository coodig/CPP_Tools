# 📁 Batch File Renamer

Batch File Renamer is a simple yet powerful C++ command-line tool to rename multiple files in a directory based on file extension and user-defined base name.

This tool is useful for developers, content creators, and students who often deal with organizing bulk files like images, documents, logs, etc.

---

## 🚀 Features

- Rename all files of a specific extension in a directory.
- Adds sequential numbering to renamed files.
- Color-coded console output for Info, Success, and Error messages.
- Cross-platform support (Linux, Windows).
- Clean modular code with reusable headers.

---

## 🗂️ Folder Structure

    Batch_File_Renamer/
    ├── include/
    │ ├── file_utils.h
    │ └── logger.h
    ├── src/
    │ ├── main.cpp
    │ ├── file_utils.cpp
    │ ├── logger.cpp
    ├── build/ # Output binary will be placed here
    └── README.md


---

## ⚙️ Build & Run

### ✅ Linux / macOS

1. Open terminal and navigate to the project root:

```bash
cd path/to/Batch_File_Renamer
```
2. Compile:
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o build/batch_file_renamer
```

### ✅ Windows (with MinGW or g++ installed)
1. Open Command Prompt / PowerShell and go to project root:
```bash
cd path\to\Batch_File_Renamer
```

2. Compile:
```bash
g++ -std=c++17 -Iinclude src\*.cpp -o build\batch_file_renamer.exe
```

3. Run:
```bash
build\batch_file_renamer.exe
```

## 📸 Example Usage
```bash
Enter directory path: /home/user/Desktop/files
Enter extension : .txt
Enter new base name: notes
```

## 📝 Output:
```bash
[SUCCESS] Renamed: oldfile1.txt -> notes_1.txt
[SUCCESS] Renamed: oldfile2.txt -> notes_2.txt
```

## 🔧Future Enhancements
- Add prefix/suffix to filenames
- Uppercase/lowercase renaming
- Dry-run/preview mode before renaming
- GUI support (Qt or GTK)
- Recursive renaming in subfolders

## 👨‍💻 Author
- Developed by Adarsh <a href="https://github.com/coodig">(coodig-sphare)</a>
- 📧 Email: adarshsharma1350@gmail.com