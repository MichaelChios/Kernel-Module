# Kernel-Module Examples

This repository contains a set of simple Linux kernel module examples used for learning and demonstration purposes. Each module lives under its own directory and includes a `Makefile` for building.

Contents
- **hello-module/** — simple "Hello, world" kernel modules (`hello.c`, `helloV2.c`).
- **kmalloc-module/** — demonstrates dynamic kernel memory allocation (`kmalloc-module.c`).
- **list-children-module/** — examples showing process forking and child listing (`forking.c`, `list-children.c`).
- **list-processes-module/** — lists processes from kernel space (`list-processes.c`).
- **process-mm-module/** — inspects a process's memory layout (contains `process-mm-module.c` and `threads.c`).

Prerequisites
- A Linux environment (a VM like VirtualBox/VMware is recommended when working from Windows).
- Kernel headers matching your running kernel (package name varies by distribution).
- Build tools: `make`, `gcc`, and `binutils` (supplied by `build-essential` on Debian/Ubuntu).

Quick Setup (Debian/Ubuntu)
```bash
sudo apt update
sudo apt install build-essential libelf-dev linux-headers-$(uname -r)
```

Build
1. Change into the module directory you want to build, e.g.:
	 ```bash
	 cd hello-module
	 make
	 ```
2. The build will produce a `.ko` file (kernel object) for the module.

Load / Unload
- Insert the module (requires root):
	```bash
	sudo insmod module_name.ko
	```
- Remove the module:
	```bash
	sudo rmmod module_name
	```
- View kernel messages (helpful for module printk output):
	```bash
	dmesg | tail -n 50
	# or on systemd systems
	journalctl -k --since "5 minutes ago"
	```

Module Notes and Examples
- hello-module: Demonstrates basic `printk()` usage. Build and insmod `hello.ko`, then check `dmesg` for the greeting and unload with `rmmod`.
- kmalloc-module: Shows `kmalloc()` and `kfree()` usage and reports allocation details via `printk()`.
- list-children-module: Contains examples for creating child processes from kernel context (educational — do not use in production).
- list-processes-module: Iterates process lists in kernel space and prints basic info (pid, name).
- process-mm-module: Reads parts of a user process's `task_struct` / mm_struct. The repository includes `threads.c` which can be used to spawn a process for testing; the kernel module accepts a PID parameter when loaded.

Running the `process-mm-module` (example)
1. Start the test user process (from this repo):
	 ```bash
	 gcc -o threads process-mm-module/threads.c
	 ./threads &
	 echo $!  # PID of the test process
	 ```
2. Load the module with the PID (replace <PID> with the number):
	 ```bash
	 sudo insmod process-mm-module/process-mm-module.ko PID=<PID>
	 dmesg | tail -n 50
	 sudo rmmod process-mm-module
	 ```

Cleaning
Run `make clean` inside a module directory to remove build artifacts.

Safety and Notes
- Kernel programming can crash your system. Test in a VM and save work frequently.
- Inspect module source before loading. These examples are for education only.
- Running and building modules requires root privileges.

Troubleshooting
- "Invalid module format" or unresolved symbols: make sure kernel headers match the running kernel.
- Build errors: ensure `make` and appropriate development packages are installed.

References
- `kbuild` and Linux Device Drivers documentation for building modules.

Files
- See each module directory for source, `Makefile`, and README-style comments.

