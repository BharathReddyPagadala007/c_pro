The **init process** in Linux is the **first user-space process** started by the kernel during system boot, with **PID 1**. It serves as the **parent of all other processes** (orphaned processes are re-parented to it) and is responsible for **system initialization**, **starting essential services**, and **managing system states** (like booting, shutdown, or recovery).

---

### Key Features of the Init Process

| Feature | Description |
|--------|-------------|
| **PID** | Always `1` |
| **Parent** | None (kernel starts it directly) |
| **Never dies** | If killed, the system panics or reboots |
| **Orchestrates boot** | Starts daemons, mounts filesystems, sets up networking, etc. |

---

### Traditional Init vs. Modern Init Systems

There are different **init systems** that implement the init process:

| Init System | Description | Example |
|------------|-----------|--------|
| **SysVinit** | Classic, script-based (`/etc/init.d/`) | Debian 6, CentOS 5 |
| **Upstart** | Event-based, replaced SysVinit | Ubuntu 6.10–14.10 |
| **systemd** | Modern, parallel, service manager (most common today) | Ubuntu 16.04+, Fedora, RHEL 7+, Debian 8+ |
| **OpenRC** | Lightweight, used in Gentoo, Alpine | Gentoo, Alpine Linux |

---

### What Does Init Do? (General Tasks)

1. **Runs startup scripts** (depending on the init system)
2. **Starts system services** (SSHD, cron, logging, etc.)
3. **Sets the default runlevel/target**
4. **Manages system shutdown/reboot**
5. **Adopts orphaned processes**

---

### Example: systemd (Most Common Today)

```bash
$ ps -p 1 -o comm=
systemd
```

- Binary: `/lib/systemd/systemd`
- Config: `/etc/systemd/system/`, unit files (`.service`, `.target`, etc.)
- Check status: `systemctl status`

---

### Example: SysVinit (Legacy)

```bash
$ ps -p 1 -o comm=
init
```

- Scripts in: `/etc/init.d/`
- Runlevels: `0` (halt), `1` (single-user), `6` (reboot), etc.
- Controlled via: `/etc/inittab`

---

### How to Check Your Init

```bash
# Check PID 1
ps -p 1

# Or
cat /proc/1/comm
```

---

### Fun Fact
> If the init process crashes or is killed, the kernel triggers a **kernel panic**:
> ```
> "No init found. Try passing init= option to kernel."
> ```

---

### Summary

| Term | Meaning |
|------|--------|
| **Init process** | PID 1, mother of all processes |
| **Role** | Boot system, start services, manage runlevels |
| **Modern standard** | `systemd` |
| **Legacy** | `SysVinit`, `Upstart` |

---

