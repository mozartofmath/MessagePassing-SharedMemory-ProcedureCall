# MessagePassing-SharedMemory-ProcedureCall
In this repository, there are 3 folders.

folder "SharedMemory" contains a C program where one server and one client program can chat with eachother. The message is stored in a shared memory between the two processes. They take turns in sending messages. server sends and waits for client, the client recieves sends and waits for server, infinitum. This logic is implemented by using a Deterministic Finite Automaton.

folder "Procedure" contains a c program that calculates and prints the collatz sequence generated by the integer given as input.

folder "MessagePassing" contains one client and one server C program that exchange messages using a message queue.
