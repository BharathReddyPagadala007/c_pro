Below is a **practical cheat-sheet** of **Linux commands** and **system calls** that directly interact with the three virtual filesystems:

| Filesystem | Purpose | Typical paths | Common commands | Relevant system calls |
|------------|---------|---------------|-----------------|-----------------------|
| **`/proc`** | Process & kernel runtime information (procfs) | `/proc/<pid>/`, `/proc/sys/`, `/proc/cpuinfo`, `/proc/meminfo` | `cat`, `ls`, `ps`, `top`, `lsof`, `grep`, `echo … > …` | `open()`, `read()`, `write()`, `ioctl()`, `getdents64()`, `mmap()` |
| **`/dev`** | Device nodes (devtmpfs + udev) | `/dev/null`, `/dev/zero`, `/dev/random`, `/dev/sda`, `/dev/tty` | `dd`, `mknod`, `mkfifo`, `cat`, `echo`, `udevadm` | `open()`, `read()`, `write()`, `ioctl()`, `poll()`, `mmap()`, `mknod()`, `mkfifo()` |
| **`/sys`** | Sysfs – kernel objects, drivers, power, buses | `/sys/class/`, `/sys/devices/`, `/sys/module/`, `/sys/block/` | `cat`, `echo … > …`, `ls`, `find`, `udevadm` | `open()`, `read()`, `write()`, `ioctl()`, `getdents64()` |

---

## 1. `/proc` – Process & Kernel Runtime Info

### Everyday commands
```bash
# Kernel / hardware
cat /proc/cpuinfo
cat /proc/meminfo
cat /proc/loadavg
cat /proc/uptime
cat /proc/version
cat /proc/cmdline

# Per-process
cat /proc/<pid>/status
cat /proc/<pid>/cmdline
cat /proc/<pid>/fd/
cat /proc/<pid>/maps
cat /proc/<pid>/smaps
cat /proc/<pid>/environ

# Tunables
cat /proc/sys/kernel/hostname
echo newhost > /proc/sys/kernel/hostname

# Network
cat /proc/net/dev
cat /proc/net/tcp
```

### System calls you’ll hit
| Call | Typical use in `/proc` |
|------|------------------------|
| `open()` / `openat()` | Open any `/proc` file |
| `read()` | Read `cpuinfo`, `meminfo`, etc. |
| `write()` | Change tunables (`echo … > …`) |
| `ioctl()` | `PR_SET_NAME`, `PR_GET_PDEATHSIG`, etc. |
| `getdents64()` | `ls /proc/<pid>/fd` |
| `mmap()` | Map `/proc/<pid>/mem` (with `PTRACE_ATTACH` first) |

### Example C snippet
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("/proc/uptime", O_RDONLY);
    char buf[128];
    ssize_t n = read(fd, buf, sizeof(buf)-1);
    buf[n] = '\0';
    printf("uptime: %s\n", buf);
    close(fd);
    return 0;
}
```

---

## 2. `/dev` – Device Nodes

### Everyday commands
```bash
# Classic null/zero/random
dd if=/dev/zero of=zero.bin bs=1M count=10
cat /dev/urandom | head -c 64 | xxd

# Block devices
lsblk
cat /dev/sda1 > image.img          # raw read
dd if=disk.img of=/dev/sdb bs=4M   # raw write

# Character devices
stty -F /dev/ttyS0 115200
echo "test" > /dev/ttyUSB0

# FIFOs
mkfifo /tmp/mypipe
cat /tmp/mypipe &
echo hello > /tmp/mypipe
```

### System calls you’ll hit
| Call | Typical use in `/dev` |
|------|-----------------------|
| `open()` | Open device node |
| `read()` / `write()` | Data transfer |
| `ioctl()` | Device-specific control (`TCGETS`, `BLKGETSIZE64`, etc.) |
| `poll()` / `select()` | Wait for I/O readiness |
| `mmap()` | Direct memory mapping (e.g., `/dev/fb0`) |
| `mknod()` | Create special file (rarely needed with udev) |
| `mkfifo()` | Create named pipe |

### Example: raw block read
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("/dev/sda1", O_RDONLY);
    char buf[512];
    ssize_t n = read(fd, buf, sizeof(buf));
    printf("Read %zd bytes\n", n);
    close(fd);
    return 0;
}
```

---

## 3. `/sys` – Kernel Object Hierarchy

### Everyday commands
```bash
# CPU scaling
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
echo performance > /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor

# Block devices
cat /sys/block/sda/queue/scheduler
echo noop > /sys/block/sda/queue/scheduler

# Modules
ls /sys/module/
cat /sys/module/usbhid/parameters/mousepoll

# Power
cat /sys/power/state
echo mem > /sys/power/state

# Devices
cat /sys/class/net/eth0/speed
```

### System calls you’ll hit
| Call | Typical use in `/sys` |
|------|-----------------------|
| `open()` / `openat()` | Open attribute file |
| `read()` | Read current value |
| `write()` | Change attribute |
| `getdents64()` | Enumerate subdirs (`ls /sys/class/net`) |

### Example: change CPU governor
```c
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor",
                  O_WRONLY);
    const char *gov = "performance";
    write(fd, gov, strlen(gov));
    close(fd);
    return 0;
}
```

---

## Quick Reference Table (one-liners)

| Goal | `/proc` | `/dev` | `/sys` |
|------|---------|--------|--------|
| **Read CPU info** | `cat /proc/cpuinfo` | — | `cat /sys/devices/system/cpu/online` |
| **Read memory stats** | `cat /proc/meminfo` | — | — |
| **Change hostname** | `echo new > /proc/sys/kernel/hostname` | — | — |
| **Zero-fill file** | — | `dd if=/dev/zero of=file bs=1M` | — |
| **Get random bytes** | — | `head -c 32 /dev/urandom` | — |
| **Set scheduler** | — | — | `echo cfq > /sys/block/sda/queue/scheduler` |
| **List open FDs of PID** | `ls -l /proc/<pid>/fd` | — | — |
| **Create FIFO** | — | `mkfifo /tmp/pipe` | — |
| **Get network speed** | `cat /proc/net/dev` | — | `cat /sys/class/net/eth0/speed` |

---

### TL;DR
- **`/proc`** → `open/read/write` + `ioctl` for process & kernel tunables.  
- **`/dev`** → full I/O syscall suite (`read/write/ioctl/poll/mmap`).  
- **`/sys`** → simple `open/read/write` on attribute files; no `ioctl` in most cases.

