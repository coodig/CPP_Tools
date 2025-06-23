
# LogCleaner Tool

LogCleaner एक lightweight और cross-platform C++ tool है जिसका उपयोग आप किसी directory में मौजूद पुराने `.log` files को scan, view और optionally delete करने के लिए कर सकते हैं। यह tool file age threshold (in days) के आधार पर काम करता है।

---

## Features

- ✅ Scan `.log` files recursively from a directory
- ✅ Filter files older than N days
- ✅ Show list of old log files
- ✅ Optional delete confirmation
- ✅ Lightweight & fast (uses std::filesystem)
- ✅ Cross-platform (Windows/Linux/macOS)

---

## Folder Structure

```bash
LogCleaner/
├── include/
│   └── LogCleaner.h
├── src/
│   ├── main.cpp
│   └── logcleaner.cpp
├── bin/
│   └── LogCleaner.exe (after build)
└── README.md
```

---

## How to Build

Use the following g++ command (C++17 or higher required):

### Windows

```bash
g++ src/main.cpp src/logcleaner.cpp -Iinclude -std=c++17 -o bin/LogCleaner.exe
```

### Linux/macOS

```bash
g++ src/main.cpp src/logcleaner.cpp -Iinclude -std=c++17 -o bin/LogCleaner
```

Make sure the bin/ directory exists before building, or create it:

```bash
mkdir -p bin
```

---

## How to Use

Run the tool from terminal or PowerShell:

```bash
# Windows
./bin/LogCleaner.exe

# Linux/macOS
./bin/LogCleaner
```

It will prompt:

```
Enter directory path: C:\Users\Adarsh\Logs
Enter age in days: 30
```

Tool will:

1. Recursively scan for `.log` files in that directory.
2. Filter files older than given days (30 in above example).
3. Ask for confirmation before deleting:
   ```
   Do you really want to delete all these files? (y/n)
   ```

---

## Example

Suppose you have a folder `C:\Logs` with many `.log` files.

Run:

```bash
./bin/LogCleaner.exe
```

And input:

```
Enter directory path: C:\Logs
Enter age in days: 15
```

Tool will show the list of `.log` files older than 15 days, and then optionally delete them.

---

## Optional: Generate Dummy .log Files for Testing

You can use the provided PowerShell script (optional):

📁 Create a new file named generate_logs.ps1:

```powershell
param(
    [string]$TargetDir = ".\test_logs",
    [int]$TotalFiles = 10
)

if (!(Test-Path $TargetDir)) {
    New-Item -ItemType Directory -Path $TargetDir | Out-Null
}

for ($i = 1; $i -le $TotalFiles; $i++) {
    $file = "$TargetDir\logfile_$i.log"
    Set-Content -Path $file -Value "Dummy log content"

    # Set LastWriteTime to simulate older dates
    $daysOld = Get-Random -Minimum 5 -Maximum 60
    $oldTime = (Get-Date).AddDays(-$daysOld)
    (Get-Item $file).LastWriteTime = $oldTime
}
```

Run it like:

```powershell
.\generate_logs.ps1 -TargetDir .\logs -TotalFiles 20
```

---

## ⚠️ Known Issues / Disclaimer

❗ On some platforms (especially Windows with older GCC or MinGW versions), the file age calculation using std::filesystem::last_write_time() may give incorrect values like "74510 days". This is caused by non-standard time_point conversions between file_time_type and system_clock.

🛠️ If you still face incorrect date readings, make sure to use GCC 11+ or MSVC 2019+ and C++17 standard.

---


