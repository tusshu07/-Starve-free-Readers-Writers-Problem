// Variables used by both readers and writers
int reader_count = 0;
semaphore rw_lock = 1, mutex = 1;

// Writer thread function
void writer() {
    while (true) {
        // Request permission to write
        acquire_write_lock();

        // Perform the write operation

        // Release the write lock
        release_write_lock();
    }
}

// Reader thread function
void reader() {
    while (true) {
        // Request permission to read
        acquire_read_lock();

        // Perform the read operation

        // Release the read lock
        release_read_lock();
    }
}

// Helper function to acquire the write lock
void acquire_write_lock() {
    wait(rw_lock);
}

// Helper function to release the write lock
void release_write_lock() {
    signal(rw_lock);
}

// Helper function to acquire the read lock
void acquire_read_lock() {
    wait(mutex);
    reader_count++;
    if (reader_count == 1) {
        wait(rw_lock);
    }
    signal(mutex);
}

// Helper function to release the read lock
void release_read_lock() {
    wait(mutex);
    reader_count--;
    if (reader_count == 0) {
        signal(rw_lock);
    }
    signal(mutex);
}
