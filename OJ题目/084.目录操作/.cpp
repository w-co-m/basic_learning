#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to split a path into components
void splitPath(char* path, char result[][201], int* count) {
    *count = 0;
    int len = strlen(path);
    int start = 0;
    int i;
    
    // Handle root directory
    if (len == 1 && path[0] == '/') {
        strcpy(result[0], "");
        *count = 1;
        return;
    }
    
    // Skip leading slash for processing
    if (path[0] == '/') start = 1;
    
    int current = start;
    int resultIndex = 0;
    
    for (i = start; i <= len; i++) {
        if (i == len || path[i] == '/') {
            if (i > current) {
                strncpy(result[resultIndex], path + current, i - current);
                result[resultIndex][i - current] = '\0';
                resultIndex++;
            }
            current = i + 1;
        }
    }
    
    *count = resultIndex;
}

// Function to join path components
void joinPath(char result[][201], int count, char* output) {
    if (count == 0) {
        strcpy(output, "/");
        return;
    }
    
    strcpy(output, "/");
    
    for (int i = 0; i < count; i++) {
        strcat(output, result[i]);
        if (i < count - 1) {
            strcat(output, "/");
        }
    }
}

void processCdCommand(char* currentPath, char* command, char* resultPath) {
    // Remove "cd " prefix
    char targetPath[201];
    strcpy(targetPath, command + 3);
    
    char currentParts[100][201];
    int currentCount;
    splitPath(currentPath, currentParts, &currentCount);
    
    if (strcmp(targetPath, "..") == 0) {
        // Move up one directory
        if (currentCount == 0 || (currentCount == 1 && strlen(currentParts[0]) == 0)) {
            strcpy(resultPath, "/"); // Already at root, do nothing
        } else {
            if (currentCount > 0) {
                currentCount--;
            }
            joinPath(currentParts, currentCount, resultPath);
        }
    } else if (targetPath[0] == '/') {
        // Absolute path
        strcpy(resultPath, targetPath);
        
        // Normalize the path
        char tempParts[100][201];
        int tempCount;
        splitPath(resultPath, tempParts, &tempCount);
        
        // Handle .. in absolute path
        char normalizedParts[100][201];
        int normalizedCount = 0;
        
        for (int i = 0; i < tempCount; i++) {
            if (strcmp(tempParts[i], "..") == 0) {
                if (normalizedCount > 0) {
                    normalizedCount--;
                }
                // If at root, ignore ..
            } else if (strcmp(tempParts[i], ".") != 0) { // Ignore current directory '.'
                strcpy(normalizedParts[normalizedCount], tempParts[i]);
                normalizedCount++;
            }
        }
        
        joinPath(normalizedParts, normalizedCount, resultPath);
    } else {
        // Relative path
        char targetParts[100][201];
        int targetCount;
        splitPath(targetPath, targetParts, &targetCount);
        
        // Process each part of the target path
        for (int i = 0; i < targetCount; i++) {
            if (strcmp(targetParts[i], "..") == 0) {
                if (currentCount > 0) {
                    currentCount--;
                }
                // If already at root, stay at root
            } else if (strcmp(targetParts[i], ".") != 0) { // Ignore current directory '.'
                strcpy(currentParts[currentCount], targetParts[i]);
                currentCount++;
            }
        }
        
        joinPath(currentParts, currentCount, resultPath);
    }
}

int main() {
    char currentPath[201];
    char line[201];
    
    // Read initial current directory
    fgets(currentPath, sizeof(currentPath), stdin);
    
    // Remove newline if present
    int len = strlen(currentPath);
    if (currentPath[len-1] == '\n') {
        currentPath[len-1] = '\0';
    }
    
    while (fgets(line, sizeof(line), stdin)) {
        // Remove newline if present
        len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        if (strcmp(line, "pwd") == 0) {
            printf("%s\n", currentPath);
            break;
        } else if (strncmp(line, "cd ", 3) == 0) {
            char newPath[201];
            processCdCommand(currentPath, line, newPath);
            strcpy(currentPath, newPath);
        }
    }
    
    return 0;
}