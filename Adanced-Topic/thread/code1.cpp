#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void work() {

    cout << "1. Worker thread started" << endl;

    this_thread::sleep_for(chrono::seconds(3));

    cout << "2. Worker thread finished work" << endl;
}

int main() {

    cout << "A. Main: before creating thread" << endl;

    thread t1(work);

    cout << "B. Main: thread created" << endl;

    this_thread::sleep_for(chrono::seconds(1));

    cout << "C. Main: doing something" << endl;

    t1.join();

    cout << "D. Main: thread has finished" << endl;

    return 0;
}