:: you dont need to understand this, its js for simplicity

@echo off
set SRC_DIR=src
set BUILD_DIR=build

gcc -o %BUILD_DIR%\makeAWindow %SRC_DIR%\main.c %SRC_DIR%\makeWindow.c -I%SRC_DIR%

if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
)

echo Compilation successful.