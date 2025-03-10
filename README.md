
# Minitalk 42

Minitalk is a project at 42 School where you implement communication between a client and a server
using Unix signals. The client sends messages to the server, and the server decodes and displays the 
messages.

## Requirements
 * A Unix-based OS (Linux/MacOS)
 * C programming language
 * Make

## Setup
Clone the repository :
```
  git https://github.com/BouhcineAmezouar7/minitalk.git
  cd minitalk
```

Compile the project:
  * Mandatory Part : make
  * Bonus Part : make bonus


Run the server in one terminal :
```
  ./server
```
In another terminal, run the client with the server's PID and the message :
```
  ./client <server_pid> <message>
```

## Usage Example

Start the server :
```
  ./server
```
Send a message from the client :
```
  ./client <server_pid> "Hello, Server!"
```
