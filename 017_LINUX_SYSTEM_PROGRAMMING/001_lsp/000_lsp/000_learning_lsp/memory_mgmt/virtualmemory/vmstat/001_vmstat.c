#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to parse /proc/stat for CPU stats
void get_cpu_stats() {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "cpu ", 4) == 0) {
            unsigned long user, nice, system, idle, iowait, irq, softirq, steal;
            sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
                   &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
            printf("CPU Usage: user=%lu nice=%lu system=%lu idle=%lu iowait=%lu\n",
                   user, nice, system, idle, iowait);
            break;
        }
    }
    fclose(file);
}

// Function to parse /proc/meminfo for memory stats
void get_memory_stats() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char key[32];
    unsigned long value;
    char unit[16];
    while (fscanf(file, "%31s %lu %15s", key, &value, unit) == 3) {
        if (strcmp(key, "MemTotal:") == 0 || strcmp(key, "MemFree:") == 0) {
            printf("%s %lu %s\n", key, value, unit);
        }
    }
    fclose(file);
}

// Main function
int main() {
    while (1) {
        printf("\n=== Custom vmstat ===\n");
        get_cpu_stats();
        get_memory_stats();
        sleep(1); // Update every 1 second
    }
    return 0;
}

