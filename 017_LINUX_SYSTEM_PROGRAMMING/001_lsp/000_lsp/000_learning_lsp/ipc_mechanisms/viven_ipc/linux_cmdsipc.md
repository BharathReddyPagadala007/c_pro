

### System V IPC Commands (all part of the `ipcs` and `ipcrm` utilities, usually in the `util-linux` package)

| Command                        | IPC Type                  | Purpose |
|--------------------------------|---------------------------|------------------------------------------------|
| `ipcs`                         | All                       | Show summary of all IPC facilities |
| `ipcs -m`                      | Shared Memory             | List shared memory segments |
| `ipcs -m -d`                   | Shared Memory             | Show details (size, creator, etc.) |
| `ipcs -m -p`                   | Shared Memory             | Show creator (cpid) and last operator (lpid) |
| `ipcs -q`                      | Message Queues            | List message queues |
| `ipcs -s`                      | Semaphores                | List semaphore sets |
| `ipcs -a`                      | All                       | Default: show all with full details |
| `ipcs -t`                      | All                       | Show last operation times |
| `ipcs -l`                      | All                       | Show kernel limits |
| `ipcs -u`                      | All                       | Show usage summary |
| `ipcrm -m <shmid>`             | Shared Memory             | Remove a specific shared memory segment |
| `ipcrm -M <shmid_key>`         | Shared Memory             | Remove by key |
| `ipcrm -q <msqid>`             | Message Queue             | Remove a specific message queue |
| `ipcrm -Q <msgkey>`            | Message Queue             | Remove by key |
| `ipcrm -s <semid>`             | Semaphore                 | Remove a specific semaphore set |
| `ipcrm -S <semkey>`            | Semaphore                 | Remove by key |
| `ipcrm --all` or `ipcrm -a`    | All                       | Remove all IPC objects (be careful!) |

### POSIX IPC Commands/Tools

POSIX IPC objects live in a virtual filesystem (usually mounted as `ipc` or under `/dev/shm`).

| Command / Tool                  | Purpose |
|---------------------------------|-----------------------------------------------------|
| `ipcs -m` (still works)         | Some distributions also show POSIX shm with System V |
| `ls /dev/shm/`                  | List POSIX shared memory files |
| `cat /proc/sysvipc/shm`         | Kernel view of System V shared memory |
| `cat /proc/sysvipc/msg`         | Kernel view of System V message queues |
| `cat /proc/sysvipc/sem`         | Kernel view of System V semaphores |
| `ipcmk -M <size>`               | Create a shared memory segment (System V) |
| `ipcmk -Q`                      | Create a message queue (System V) |
| `ipcmk -S <nsems>`              | Create a semaphore set (System V) |

### Other Useful Related Commands

| Command                         | Description |
|---------------------------------|-----------------------------------------------------------------------------------|
| `lsns --type ipc`               | List IPC namespaces (very useful with containers) |
| `unshare --ipc`                 | Run a command in a new IPC namespace |
| `nsenter --ipc=<pid>`           | Enter the IPC namespace of another process |
| `shm_open`, `shm_unlink`        | Not commands, but system calls — you use them in C programs for POSIX shm |
| `mq_open`, `mq_unlink`          | POSIX message queues (again, library calls, not shell commands) |
| `semctl`, `msgctl`, etc.        | Used inside C programs, not directly from shell |

### Quick Cheat Sheet (most commonly used)

```bash
# Show everything
ipcs -a

# Show only shared memory
ipcs -m

# Remove a specific shared memory segment (find ID with ipcs -m)
ipcrm -m 12345

# Remove by key
ipcrm -M 0x00001234

# Remove all message queues (dangerous!)
ipcrm --all=q

# List POSIX shared memory files
ls -l /dev/shm/

# See IPC inside a specific namespace (e.g., a container)
lsns -t ipc
nsenter --ipc=/run/container/ipc/ns123 ipcs
```

These are essentially **all** the user-space Linux commands directly related to IPC mechanisms as of 2025.
