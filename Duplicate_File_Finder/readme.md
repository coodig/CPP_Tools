# 🔍 Duplicate File Finder (CLI Tool)

A C++ command-line utility that helps you scan a folder for **duplicate files** using hashing.  
Built using **C++17**, **Object-Oriented Design**, and the **filesystem library**.

---

## 📁 Features

- ✅ Recursively scans a directory for duplicate files.
- 🔐 Uses SHA-256 content hashing to ensure accuracy.
- 👀 Displays groups of duplicate files clearly.
- 🗂️ **Interactively delete or move** duplicates (new!).
- 💡 Lightweight, fast, and no external dependencies.

---

## 🛠️ Folder Structure

    DuplicateFileFinder/
    ├── include/
    │ ├── DuplicateFinder.h
    │ └── FileHasher.h
    ├── src/
    │ ├── main.cpp
    │ ├── DuplicateFinder.cpp
    │ └── FileHasher.cpp
    ├── build/
    │ └── duplicate_finder.exe (output)


### 📦 Build

```bash
g++ src/main.cpp src/DuplicateFinder.cpp src/FileHasher.cpp -Iinclude -o build/duplicate_finder.exe -std=c++17
```

### ▶️ Run
```bash
cd build
./duplicate_finder.exe
```

On Windows:
```bash
duplicate_finder.exe
```

## 🧪 How It Works
1. User provides a directory path.

2. Tool recursively scans all files inside it.

3. It computes a content hash of each file using SHA-256.

4. Files with identical hashes are considered duplicates.

5. Duplicates are shown group-wise.

6. User can:

- ❌ Delete duplicates (keeping one)

- 📁 Move duplicates to a duplicates/ folder

- ⏭️ Skip the group

## 📸 Sample Output

```bash
📂 Enter directory path: test_data/

🔍 Duplicate Files Found:

Hash: abc123...
  [1] test_data/a.jpg
  [2] test_data/copy_a.jpg

Action? (d = delete, m = move, s = skip): m
📁 Moved: test_data/copy_a.jpg → test_data/duplicates/copy_a.jpg
```

## 🧭 Roadmap / Future Updates
- 🧠 Auto-delete mode with dry-run preview

- 📁 Move to custom destination directory (not fixed duplicates/)

- 🪟 GUI version using Qt/ImGui

- 📝 Logging support (optional Logger class)

- 🧪 Unit Tests for hashing, scanning, deletion

- 🖼️ Duplicate image similarity detection (not just hash)

- 🌐 Multi-threaded optimization for large datasets

## 👨‍💻 Author
Made with <a href="https://github.com/coodig">Coodig-Sphare</a> by Adarsh
