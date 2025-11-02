Below is a **complete, step-by-step walkthrough** of the **Linux kernel boot process** — from power-on to a working user-space (init process, PID 1).  
Everything is shown with **real commands**, **files**, and **diagrams** you can verify on any modern Linux box.

---

## Overview (One-Line Summary)

```
Power On → BIOS/UEFI → Bootloader (GRUB) → Kernel Image → initramfs → Root FS → init (PID 1) → Login
```

---

## Detailed Boot Stages

| Stage | What Happens | Key Files / Tools |
|------|--------------|-------------------|
| **1. Firmware (BIOS / UEFI)** | POST, hardware init, finds boot device | N/A |
| **2. Bootloader** | Loads kernel + initramfs into RAM | `GRUB`, `systemd-boot`, `rEFInd` |
| **3. Kernel Decompression** | Kernel self-extracts | `vmlinuz-*` |
| **4. Kernel Initialization** | Early setup (CPU, memory, console) | `setup_arch()`, `start_kernel()` |
| **5. initramfs (optional)** | Temporary root, loads drivers, assembles real root | `initrd.img-*`, `dracut`, `mkinitcpio` |
| **6. Switch to Real Root** | Pivot root, mount real `/` | `switch_root` |
| **7. init (PID 1)** | Starts services, reaches default target | `systemd`, `SysVinit`, etc. |

---

## 1. Firmware – BIOS / UEFI

- **BIOS**: Legacy 16-bit, reads MBR (first 512 bytes).
- **UEFI**: 64-bit, uses GPT + EFI System Partition (ESP).
- Loads **bootloader** from:
  - MBR (BIOS)
  - `/EFI/BOOT/BOOTx64.EFI` (UEFI)

---

## 2. Bootloader – GRUB2 (Most Common)

```bash
# GRUB config
/etc/grub.d/
/etc/default/grub   ← GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"

/boot/grub/grub.cfg ← GENERATED! Do NOT edit manually
```

### GRUB Boot Flow
1. **Stage 1** – `/boot/grub/i386-pc/boot.img` (MBR)
2. **Stage 1.5** – Core image in sector gap
3. **Stage 2** – `/boot/grub/i386-pc/core.img` → full GRUB shell
4. Loads `grub.cfg` → shows menu
5. Executes:
   ```bash
   linux /vmlinuz-xxxx root=UUID=xxx ro quiet
   initrd /initrd.img-xxxx
   boot
   ```

---

## 3. Kernel Image (`vmlinuz`)

- **Compressed** (`xz`, `gzip`, `zstd`)
- **Self-decompressing** stub → real kernel
- File: `/boot/vmlinuz-<version>`

```bash
file /boot/vmlinuz-6.8.0-51-generic
# → Linux kernel x86 boot executable zstd compressed ...
```

---

## 4. Kernel Initialization (C code in `init/main.c`)

```c
start_kernel()
 ├─ setup_arch()           // CPU, memory, interrupts
 ├─ parse_early_param()    // kernel cmdline args
 ├─ trap_init()
 ├─ mm_init()
 ├─ sched_init()
 ├─ rest_init() → kernel_init() → kernel_init_freeable()
```

### Early Console Output
```bash
dmesg | head
[    0.000000] Linux version 6.8.0-51-generic ...
[    0.000000] Command line: BOOT_IMAGE=/vmlinuz-... root=UUID=...
```

---

## 5. initramfs – Temporary Root (Optional but Standard)

### Why?
- Load **storage drivers** (NVMe, RAID, LVM, LUKS)
- Assemble **encrypted root**, **LVM**, **btrfs**
- Mount real root **before** switching

### Tools
| Distro | Tool |
|-------|------|
| Ubuntu, Fedora | `dracut` |
| Arch | `mkinitcpio` |
| Debian | `initramfs-tools` |

### Inside initramfs
```bash
lsinitramfs /boot/initrd.img-6.8.0-51-generic | head
# scripts/, bin/, lib/, etc/, init ← shell script
```

`init` script does:
```sh
mount -t proc proc /proc
mount -t sysfs sys /sys
parse cmdline (root=, cryptdevice=, etc.)
load modules (nvme, dm-crypt, btrfs...)
decrypt → open LUKS → activate LVM
mount real root to /sysroot
exec switch_root /sysroot /sbin/init
```

---

## 6. Switch to Real Root

```c
pivot_root() or switch_root binary
```

Now:
- `/` = real root (e.g., `/dev/sda2`)
- Old initramfs is unmounted
- Kernel executes **init** from real root

---

## 7. init Process (PID 1)

```bash
$ ps -p 1 -o comm=
systemd
```

### systemd Example
```bash
systemctl get-default
# graphical.target

journalctl -b -0   # full boot log
```

### SysVinit (Legacy)
```bash
cat /etc/inittab
# id:5:initdefault:  → runlevel 5
```

---

## Full Boot Timeline (Example Output)

```bash
$ systemd-analyze
Startup finished in 2.184s (kernel) + 3.792s (userspace) = 5.976s

$ systemd-analyze blame | head -5
2.103s plymouth-quit-wait.service
1.892s networkd-wait-online.service
1.201s dev-nvme0n1p2.device
...
```

---

## Visual Boot Flow

```
┌─────────────┐
│   Power On  │
└─────┬───────┘
      ▼
┌─────────────┐   BIOS/UEFI firmware
│   Firmware  ├─────────────────────► POST, load bootloader
└─────┬───────┘
      ▼
┌─────────────┐   GRUB2
│ Bootloader  ├──────┐
└─────┬───────┘      │
      ▼              ▼
┌─────────────┐  ┌───────────┐
│   Kernel    │  │ initramfs │
│  vmlinuz    │  │  initrd   │
└─────┬───────┘  └─────┬─────┘
      ▼              ▼
   Kernel Init    Module Load
      ▼              ▼
   Mount Real Root (pivot_root)
      ▼
┌─────────────┐
│  init (PID1)│ → systemd / SysVinit
└─────┬───────┘
      ▼
  Services → Login Prompt
```

---

## Key Files & Commands Cheat Sheet

| Purpose | Command / File |
|-------|----------------|
| See bootloader config | `cat /boot/grub/grub.cfg` |
| Kernel cmdline | `cat /proc/cmdline` |
| Kernel version | `uname -r` |
| Init process | `ps -p 1 -o comm=` |
| Boot messages | `dmesg` or `journalctl -b` |
| initramfs contents | `lsinitramfs /boot/initrd.img-*` |
| Regenerate initramfs | `sudo update-initramfs -u` (Debian) <br> `sudo dracut -f` (Fedora) |
| Regenerate GRUB | `sudo grub-mkconfig -o /boot/grub/grub.cfg` |

---

## Common Boot Parameters (in GRUB)

| Parameter | Meaning |
|---------|--------|
| `ro` | Mount root read-only (fsck later) |
| `quiet` | Suppress most log messages |
| `splash` | Show Plymouth boot splash |
| `nomodeset` | Disable KMS (fix display issues) |
| `init=/bin/sh` | Boot directly to shell (recovery) |
| `systemd.unit=rescue.target` | Single-user mode |

Edit in GRUB: press `e` → modify line → `Ctrl+X` to boot.

---

## Summary Table

| Stage | Executable | PID | Purpose |
|------|------------|-----|--------|
| Firmware | BIOS/UEFI | — | Hardware init |
| Bootloader | GRUB | — | Load kernel |
| Kernel | `vmlinuz` | — | Core OS |
| initramfs | `init` (shell) | 1 (temp) | Prepare real root |
| Real init | `systemd` / `init` | 1 | Start services |

---

**You now know exactly how Linux goes from power button to login prompt.**

Want a **deep dive into any stage** (e.g., `systemd` targets, `initramfs` scripting, kernel cmdline parsing)? Just ask!
