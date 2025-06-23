# Create testing_logs directory if not exists
# $logDir = "\Log_Cleaner\testing_logs"
$logDir = "C:\Users\nehab\Desktop\c++ tools\Log_Cleaner\testing_logs"
if (-not (Test-Path $logDir)) {
    New-Item -ItemType Directory -Path $logDir | Out-Null
}

# Helper function to create log file and set last modified date
function New-LogFile {
    param (
        [string]$FileName,
        [int]$DaysOld
    )
    $fullPath = Join-Path $logDir $FileName
    "Dummy log for $FileName" | Out-File -Encoding UTF8 $fullPath
    $targetDate = (Get-Date).AddDays(-$DaysOld)
    (Get-Item $fullPath).LastWriteTime = $targetDate
}

# Create dummy log files
New-LogFile -FileName "new_today_1.log" -DaysOld 0
New-LogFile -FileName "new_today_2.log" -DaysOld 0
New-LogFile -FileName "new_today_3.log" -DaysOld 0
New-LogFile -FileName "old_35.log" -DaysOld 35
New-LogFile -FileName "old_40.log" -DaysOld 40
New-LogFile -FileName "old_60.log" -DaysOld 60

Write-Host "Dummy log files created in '$logDir'."
