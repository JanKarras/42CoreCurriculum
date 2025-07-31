# 42 Core Curriculum Projects

Welcome to my personal collection of projects from the **42 School Core Curriculum**.
This repository contains C and C++ projects ranging from low-level programming to multi-threading, graphics, and web servers.

Each project is located in its own subdirectory with source code and documentation.

---

## 🗂 Project Overview

| Project                     | Description                                                                 |
|-----------------------------|-----------------------------------------------------------------------------|
| [libft](./libft)            | Custom implementation of standard C library functions                      |
| [ft_printf](./ft_printf)    | Recreation of `printf` with format parsing and variadic arguments          |
| [get_next_line](./get_next_line) | Reads a file line by line using minimal system calls              |
| [pipex](./pipex)            | Process piping and execution, simulating shell behavior                    |
| [PushSwap](./PushSwap)      | Stack sorting algorithm with the smallest possible instruction set         |
| [so_long](./so_long)        | A simple 2D game using MiniLibX (graphics) and tile-based maps             |
| [minishell](./minishell)    | A Unix shell with parsing, execution, environment handling, piping, etc.   |
| [cub3d](./cub3d)            | A basic 3D raycasting engine (Wolfenstein-like) using MiniLibX             |
| [Philosophers](./Philosophers) | Dining philosophers problem: multi-threading & mutexes               |
| [inception](./inception)    | Docker-based system architecture and container orchestration               |
| [webserv](./webserv)        | C++ web server from scratch (RFC-compliant, basic HTTP implementation)     |

---

## 💻 C++ Modules (`CPP/`)

All C++ modules are located inside the [`CPP`](./CPP) directory:

| Module           | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| [CPP00](./CPP/CPP00) | Basics of C++: classes, member functions, std::cout, Orthodox Canonical Form |
| [CPP01](./CPP/CPP01) | Memory allocation (new/delete), references, file I/O                      |
| [CPP02](./CPP/CPP02) | Operator overloading, fixed-point class example                          |
| [CPP03](./CPP/CPP03) | Inheritance, constructors/destructors, virtual functions                 |
| [CPP04](./CPP/CPP04) | Abstract classes and interfaces, dynamic memory                         |
| [CPP05](./CPP/CPP05) | Exception handling, try/catch blocks, custom exception classes           |
| [CPP06](./CPP/CPP06) | Basic file I/O and type conversion                                       |
| [CPP07](./CPP/CPP07) | Templates, function and class templates                                  |
| [CPP08](./CPP/CPP08) | Polymorphism, deep inheritance, dynamic casting                         |
| [CPP09](./CPP/CPP09) | Containers, iterators, std::list manipulation                            |

---

## 🏫 About 42

[42](https://42wolfsburg.de/) is a globally recognized programming school with no teachers or lectures.
Students learn through peer-to-peer collaboration and project-based challenges focused on practical coding skills.

---

## 🛠 How to Use

Navigate into any project and build it using `make` (if applicable):

```bash
cd libft
make
