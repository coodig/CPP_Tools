# Auto File Organizer

A simple and efficient command-line tool written in C++ that automatically organizes files in a specified directory into categorized folders based on their extensions.

## Features

- Automatically detects and categorizes files such as images, videos, documents, archives, and applications.
- Creates subfolders for each extension inside main categories.
- Works cross-platform (Windows, Linux, macOS).
- Minimal and fast utility for everyday use.

## Folder Structure Example

Suppose your `Downloads` folder has mixed files:

    Downloads/
    ├── file1.jpg
    ├── file2.png
    ├── doc1.pdf
    ├── video1.mp4
    ├── setup.exe

After running the tool:

    Downloads/
    ├── Images/
    │ ├── jpg/
    │ │ └── file1.jpg
    │ └── png/
    │ └── file2.png
    ├── Documents/
    │ └── pdf/
    │ └── doc1.pdf
    ├── Videos/
    │ └── mp4/
    │ └── video1.mp4
    ├── Applications/
    │ └── exe/
    │ └── setup.exe

## Supported File Types

| Category      | Extensions                                |
|---------------|--------------------------------------------|
| Images        | .jpg, .jpeg, .png, .gif                    |
| Videos        | .mp4, .mkv, .avi                           |
| Documents     | .pdf, .docx, .txt                          |
| Archives      | .zip, .rar                                 |
| Applications  | .exe, .apk                                 |
| Others        | All unsupported or unknown extensions      |

## How to Use

### Step 1: Build the Tool

Navigate to the `src` directory and compile:

#### On Linux/macOS:

```bash
g++ -std=c++17 -o organizer main.cpp ../../common/file_utils.cpp ../../common/logger.cpp

./organizer /path/to/your/target/folder

```

#### On Windows (using MinGW or similar):

```sh
g++ -std=c++17 -o organizer.exe main.cpp ..\..\common\file_utils.cpp ..\..\common\logger.cpp

organizer.exe "C:\Users\yourname\Downloads"
```

## Disclaimer : Make sure you're in the src folder while compiling.

### Step 2: Run the Tool

On Linux/macOS:
```sh
./organizer /path/to/your/target/folder
```
On Windows (Command Prompt or PowerShell):
```sh
organizer.exe "C:\Users\yourname\Downloads"
```
## Example
- Windows: cmd

```sh
.\organizer.exe "E:\desktop 23-10-24\camerea"
```
- Linux/macOS:

```sh 
./organizer ~/Downloads
```

## Imp : You can pass any directory path as an argument. It will organize all files inside that directory.

## Notes

- The tool only moves files present in the specified directory, not inside nested subfolders.

- If a file cannot be moved, it will display an error message but continue processing other files.

- No files are deleted.

## Future Improvements

- Recursive file organization (handle nested folders).

- Configurable categories via JSON or YAML file.

- Drag-and-drop GUI version (planned).

# All Pull Requests are welcomed...

# <p style="color: red;"><strong>This project is currently under development. Some features may be incomplete or unstable.</strong></p>
