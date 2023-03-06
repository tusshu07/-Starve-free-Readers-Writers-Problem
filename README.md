# -Starve-free-Readers-Writers-Problem

Read-Write Lock Example
This code provides an example of how to use a read-write lock to coordinate access to a shared resource between multiple readers and writers.

The code implements two functions:

writer(): This function represents a writer thread that periodically requests permission to write to the shared resource, performs a write operation, and then releases the write lock.

reader(): This function represents a reader thread that periodically requests permission to read from the shared resource, performs a read operation, and then releases the read lock.

The code uses two semaphores to implement the read-write lock:

rw_lock: A binary semaphore used to coordinate access between readers and writers. When a writer requests the lock, it will block until no readers or writers are currently holding the lock. When a reader requests the lock, it will be granted immediately if no writers are currently holding the lock, or it will block until all current writers have finished.

mutex: A binary semaphore used to protect the reader_count variable, which tracks the number of active readers. This semaphore ensures that multiple readers don't attempt to modify reader_count concurrently.

How to run the code
To run the code, you can compile it using a C or C++ compiler and then execute the resulting binary. For example:


gcc -o rwlock rwlock.c
./rwlock

When you run the program, it will start a fixed number of reader and writer threads. The readers and writers will perform their operations indefinitely until you stop the program with Ctrl+C or by killing the process.
