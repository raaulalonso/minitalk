# minitalk

 [![Intro](https://img.shields.io/badge/Cursus-Minitalk-success?style=for-the-badge&logo=42)](https://github.com/raaulalonso/minitalk)
 
 [![Stars](https://img.shields.io/github/stars/raaulalonso/minitalk?color=ffff00&label=Stars&logo=Stars&style=?style=flat)](https://github.com/raaulalonso/minitalk)
 [![Size](https://img.shields.io/github/repo-size/raaulalonso/minitalk?color=blue&label=Size&logo=Size&style=?style=flat)](https://github.com/raaulalonso/minitalk)
 [![Activity](https://img.shields.io/github/last-commit/raaulalonso/minitalk?color=red&label=Last%20Commit&style=flat)](https://github.com/raaulalonso/minitalk)
 
In this proyect, there are two programs, client and server. The client sends strings (transformed to binary) to the server via signals and the server then prints them. Client and server only comunicate via UNIX signals.

## Getting Started

### Prerequisites

Before you can start installing minitalk, make sure you have the following prerequisites installed on your computer:

- C Compiler (e.g., GCC)
- Make

### Installation

1. Clone the minitalk repository to your local machine:

   ```shell
   git clone https://github.com/raaulalonso/minitalk.git minitalk
2. Change your current working directory to the project folder:
   
   ```shell
   cd minitalk
3. Compile the proyect using the provided Makefile:

   ```shell
   make

## Running the programs

To launch minitalk, you need to execute the server first with the following command:

   ```shell
   ./server
   ```

Then, in a new shell window, execute the client with the following command:

   ```shell
   ./client [PID] [String]
   ```

Replace [PID] with the process id that the server will print when executed. Also replace [String] with the string you want to send to the server (it can be as long as you like).
The server should print the string correctly and considerably fast.

## Screenshots

![Demo GIF](https://github.com/raaulalonso/minitalk/blob/main/screenshots/ScreenRecording.gif)
