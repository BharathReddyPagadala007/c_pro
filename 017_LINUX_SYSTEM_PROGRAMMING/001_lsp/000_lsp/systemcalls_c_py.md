 Comprehensive table listing common **Linux system calls** in both **C** and **Python**:
---

| **System Call**  | **C Equivalent** | **Python Equivalent** |
|------------------|-----------------|-----------------------|
| **Process Management** | | |
| `fork()` | `pid_t pid = fork();` | `os.fork()` |
| `execve()` | `execve("/bin/ls", argv, envp);` | `os.execve("/bin/ls", ["ls"], os.environ)` |
| `exit()` | `_exit(0);` | `os._exit(0)` |
| `waitpid()` | `waitpid(pid, &status, 0);` | `os.waitpid(pid, 0)` |
| **File Management** | | |
| `open()` | `fd = open("file.txt", O_RDWR);` | `fd = os.open("file.txt", os.O_RDWR)` |
| `read()` | `read(fd, buf, 100);` | `os.read(fd, 100)` |
| `write()` | `write(fd, "Hello", 5);` | `os.write(fd, b"Hello")` |
| `close()` | `close(fd);` | `os.close(fd)` |
| `lseek()` | `lseek(fd, 0, SEEK_SET);` | `os.lseek(fd, 0, os.SEEK_SET)` |
| `unlink()` | `unlink("file.txt");` | `os.unlink("file.txt")` |
| **Directory Management** | | |
| `mkdir()` | `mkdir("newdir", 0755);` | `os.mkdir("newdir", 0o755)` |
| `rmdir()` | `rmdir("dir");` | `os.rmdir("dir")` |
| `chdir()` | `chdir("/home");` | `os.chdir("/home")` |
| `getcwd()` | `getcwd(buf, sizeof(buf));` | `os.getcwd()` |
| `opendir()` | `DIR *d = opendir(".");` | `os.scandir(".")` |
| **Permissions & Ownership** | | |
| `chmod()` | `chmod("file.txt", 0644);` | `os.chmod("file.txt", 0o644)` |
| `chown()` | `chown("file.txt", uid, gid);` | `os.chown("file.txt", uid, gid)` |
| `umask()` | `umask(022);` | `os.umask(0o22)` |
| **Time Management** | | |
| `sleep()` | `sleep(5);` | `time.sleep(5)` |
| `usleep()` | `usleep(500000);` | `time.sleep(0.5)` |
| `gettimeofday()` | `gettimeofday(&tv, NULL);` | `time.time()` |
| **Signals** | | |
| `kill()` | `kill(pid, SIGTERM);` | `os.kill(pid, signal.SIGTERM)` |
| `signal()` | `signal(SIGINT, handler);` | `signal.signal(signal.SIGINT, handler)` |
| `raise()` | `raise(SIGINT);` | `os.kill(os.getpid(), signal.SIGINT)` |
| **Memory Management** | | |
| `mmap()` | `mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);` | `mmap.mmap(fd, 4096, mmap.MAP_PRIVATE, mmap.PROT_READ | mmap.PROT_WRITE)` |
| `munmap()` | `munmap(ptr, 4096);` | `mem.close()` |
| `brk()` | `brk(ptr + 4096);` | `ctypes.CDLL(None).brk(ptr + 4096)` |
| **Inter-Process Communication (IPC)** | | |
| `pipe()` | `pipe(fd);` | `os.pipe()` |
| `mkfifo()` | `mkfifo("fifo", 0666);` | `os.mkfifo("fifo", 0o666)` |
| `shmget()` | `shmget(1234, 4096, IPC_CREAT | 0666);` | `sysv_ipc.SharedMemory(1234, size=4096, flags=sysv_ipc.IPC_CREAT)` |
| `shmat()` | `shmat(shmid, NULL, 0);` | `shm.attach()` |
| `msgget()` | `msgget(1234, IPC_CREAT | 0666);` | `sysv_ipc.MessageQueue(1234, sysv_ipc.IPC_CREAT)` |
| `semget()` | `semget(1234, 1, IPC_CREAT | 0666);` | `sysv_ipc.Semaphore(1234, sysv_ipc.IPC_CREAT)` |
| **Networking** | | |
| `socket()` | `socket(AF_INET, SOCK_STREAM, 0);` | `socket.socket(socket.AF_INET, socket.SOCK_STREAM)` |
| `bind()` | `bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));` | `sock.bind(("localhost", 8080))` |
| `listen()` | `listen(sockfd, 5);` | `sock.listen(5)` |
| `accept()` | `accept(sockfd, (struct sockaddr *)&addr, &addrlen);` | `conn, addr = sock.accept()` |
| `connect()` | `connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));` | `sock.connect(("localhost", 8080))` |
| `send()` | `send(sockfd, msg, len, 0);` | `sock.send(b"Hello")` |
| `recv()` | `recv(sockfd, buf, len, 0);` | `sock.recv(1024)` |

---

