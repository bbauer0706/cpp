#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
Summary of Key Concepts:
    - Threads allow concurrent execution of tasks.
    - Mutexes prevent race conditions by ensuring that only one thread can access shared data at a time.
    - Locks (e.g., std::lock_guard, std::unique_lock) manage mutexes automatically, ensuring that locks are acquired and released safely.
    - Deadlocks can occur if threads wait for each other indefinitely. Use std::lock to avoid deadlocks.
    - Condition variables are used for thread synchronization, allowing threads to wait for certain conditions to be met.
*/

// Shared resource
int counter = 0;

// Mutex to protect the shared resource
mutex mtx, mtx1, mtx2, mtx4;

condition_variable cv;

bool ready = false;

// Function to be executed by the thread
void printHello() {
    cout << "Hello from thread!" << endl;
}

// Function to increment the counter
void incrementCounter() {
    mtx.lock();           // Lock the mutex
    ++counter;            // Critical section: modifying shared resource
    mtx.unlock();         // Unlock the mutex
}

// Function to increment the counter with lock
void incrementCounter_lock_guard() {
    lock_guard<mutex> lock(mtx);  // Lock the mutex automatically
    ++counter;                    // Critical section: modifying shared resource
}

// Function that causes a deadlock
void thread1() {
    lock(mtx1, mtx2);  // Lock both mutexes
    lock_guard<mutex> lg1(mtx1, adopt_lock);  // Adopt the lock
    lock_guard<mutex> lg2(mtx2, adopt_lock);  // Adopt the lock
    cout << "Thread 1: acquired both locks" << endl;
}

void thread2() {
    lock(mtx1, mtx2);  // Lock both mutexes
    lock_guard<mutex> lg1(mtx1, adopt_lock);  // Adopt the lock
    lock_guard<mutex> lg2(mtx2, adopt_lock);  // Adopt the lock
    cout << "Thread 2: acquired both locks" << endl;
}

void print_id(int id) {
    unique_lock<mutex> lck(mtx);
    while (!ready) cv.wait(lck);  // Wait until 'ready' is true
    cout << "Thread " << id << " is working!" << endl;
}

void go() {
    unique_lock<mutex> lck(mtx);
    ready = true;
    cv.notify_all();  // Notify all waiting threads
}

int main() {
    // Create a thread that runs the printHello function
    thread t(printHello);
    
    // Wait for the thread to finish execution before continuing
    t.join();

    cout << "Hello from main!" << endl;

    // Create multiple threads that will increment the counter
    thread t1(incrementCounter);
    thread t2(incrementCounter);
    thread t3(incrementCounter);

    thread t4(incrementCounter_lock_guard);
    thread t5(incrementCounter_lock_guard);
    thread t6(incrementCounter_lock_guard);

    thread t7(thread1);
    thread t8(thread2);

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    cout << "Final counter value: " << counter << endl;

    thread threads[10];
    
    // Create 10 threads
    for (int i = 0; i < 10; ++i) {
        threads[i] = thread(print_id, i);
    }

    cout << "Waiting for threads to be ready..." << endl;
    
    // Call go() after a short delay
    this_thread::sleep_for(2s);
    go();  // Notify all threads to continue
    
    // Wait for all threads to finish
    for (auto& th : threads) th.join();

    return 0;
}
