#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum number of tasks
#define MAX_TASKS 100

// Task structure
typedef struct {
    int id;
    char description[100];
    bool completed;
} Task;

// Global variables
Task tasks[MAX_TASKS];
int numTasks = 0;

// Function prototypes
void addTask(char description[]);
void viewTasks();
void markTaskCompleted(int taskId);
void showSecretCommands();

int main() {
    char description[100];
    int choice;
    
    printf("Welcome to the Secret Agent To-Do List Manager!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Show Secret Commands\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter task ID to mark as completed: ");
                int taskId;
                scanf("%d", &taskId);
                markTaskCompleted(taskId);
                break;
            case 4:
                showSecretCommands();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}

// Function to add a task
void addTask(char description[]) {
    if (numTasks < MAX_TASKS) {
        tasks[numTasks].id = numTasks + 1;
        strcpy(tasks[numTasks].description, description);
        tasks[numTasks].completed = false;
        numTasks++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

// Function to view all tasks
void viewTasks() {
    printf("\nTasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. ", tasks[i].id);
        if (tasks[i].completed) {
            printf("[X] ");
        } else {
            printf("[ ] ");
        }
        printf("%s\n", tasks[i].description);
    }
}

// Function to mark a task as completed
void markTaskCompleted(int taskId) {
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            tasks[i].completed = true;
            printf("Task marked as completed!\n");
            return;
        }
    }
    printf("Task not found!\n");
}
// Function to show secret commands
void showSecretCommands() {
    printf("\nSecret Commands:\n");
    printf("1. Enter '007' to activate stealth mode\n");
    printf("2. Enter 'GOLDENEYE' to delete all completed tasks\n");
}
