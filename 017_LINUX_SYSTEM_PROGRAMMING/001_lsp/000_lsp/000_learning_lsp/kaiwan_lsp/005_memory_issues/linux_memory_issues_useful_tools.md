
---

### **Exercise 1: Basic Memory Usage**
1. **Check System Memory Usage**
   - Command: `free -h`
   - **Task**: Identify the following:
     - Total, used, and free memory.
     - Amount of memory being used as cache.
   - **Question**: What does the "available" column represent?

2. **Explore `/proc/meminfo`**
   - Command: `cat /proc/meminfo | head -n 10`
   - **Task**: Find and understand:
     - Total and free memory.
     - Buffers and cached memory.
   - **Question**: How does the `Cached` value relate to the `free -h` output?

---

### **Exercise 2: Process Memory Consumption**
1. **Identify Top Memory-Consuming Processes**
   - Command: `ps aux --sort=-%mem | head -n 10`
   - **Task**: Note down the processes consuming the most memory.
   - **Question**: Which application is at the top? Is it expected?

2. **Analyze Memory Usage with `top`**
   - Command: `top` (press `M` to sort by memory usage).
   - **Task**: Observe changes in memory usage over a minute.
   - **Question**: What’s the difference between `RES` and `VIRT` memory?

---

### **Exercise 3: Debugging Memory Leaks**
1. **Simulate a Memory Leak**
   - **Task**: Write a simple C program to allocate memory in a loop without freeing it. Run it and observe its impact on system memory.
   ```c
   #include <stdlib.h>
   #include <unistd.h>

   int main() {
       while (1) {
           malloc(1024 * 1024); // Allocate 1MB
           sleep(1);
       }
       return 0;
   }
   ```
   - Compile: `gcc -o memleak memleak.c`
   - Run: `./memleak`

2. **Diagnose the Leak**
   - Command: `top` or `htop` (filter for the process name `memleak`).
   - **Task**: Watch its memory usage increase over time.
   - **Question**: How does the `RES` value change?

3. **Fix the Leak**
   - Modify the program to free allocated memory. Observe how memory usage stabilizes.

---

### **Exercise 4: Handling OOM (Out of Memory)**
1. **Simulate OOM**
   - **Task**: Write a program that allocates all available memory.
   ```c
   #include <stdlib.h>

   int main() {
       while (malloc(1024 * 1024)); // Keep allocating 1MB blocks
       return 0;
   }
   ```
   - Compile: `gcc -o oom oom.c`
   - Run: `./oom`

2. **Check OOM Logs**
   - Command: `dmesg | grep -i oom`
   - **Task**: Identify which process was killed by the OOM killer.
   - **Question**: Why was the specific process chosen for termination?

---

### **Exercise 5: Dropping Cache**
1. **View Current Cache Usage**
   - Command: `free -h`
   - **Task**: Note the "cached" value.

2. **Clear Cache**
   - Command: `sync; echo 3 > /proc/sys/vm/drop_caches`
   - **Task**: Run `free -h` again and compare.
   - **Question**: How much memory was freed?

---

### **Exercise 6: Analyzing Kernel Memory**
1. **View Kernel Slab Usage**
   - Command: `slabtop`
   - **Task**: Identify the top consumers of slab memory.
   - **Question**: What is `dentry` and why might it be consuming memory?

2. **Check Kernel Memory Fragmentation**
   - Command: `cat /proc/buddyinfo`
   - **Task**: Observe the fragmentation levels.
   - **Question**: What does the number of free blocks in each column indicate?

---

### **Exercise 7: Performance Monitoring**
1. **Analyze Virtual Memory Statistics**
   - Command: `vmstat 1 10`
   - **Task**: Monitor the output for 10 seconds and interpret the columns.
   - **Question**: What does the `si` and `so` column indicate?

2. **Profile an Application**
   - Command: `strace -c ./oom`
   - **Task**: Observe the number of system calls related to memory allocation.
   - **Question**: How many calls to `mmap` or `brk` were made?

---

### **Exercise 8: Tuning Memory Parameters**
1. **Adjust Swappiness**
   - Command: `echo 10 > /proc/sys/vm/swappiness`
   - **Task**: Observe system behavior before and after this change.
   - **Question**: How does this affect swapping under load?

2. **Control Cache Pressure**
   - Command: `echo 50 > /proc/sys/vm/vfs_cache_pressure`
   - **Task**: Measure the impact on file system performance.

---

### **Exercise 9: Preventive Actions**
1. **Set OOM Score Adjustment**
   - Command: `echo 100 > /proc/<pid>/oom_score_adj`
   - **Task**: Test how the OOM killer prioritizes processes with this adjustment.
   - **Question**: What does a higher score imply?

2. **Use cgroups to Limit Memory**
   - **Task**: Create a cgroup and limit memory for a process.
   ```bash
   mkdir -p /sys/fs/cgroup/memory/test_group
   echo 100M > /sys/fs/cgroup/memory/test_group/memory.limit_in_bytes
   echo $$ > /sys/fs/cgroup/memory/test_group/cgroup.procs
   ```
   - **Question**: What happens if a process exceeds the limit?

---

