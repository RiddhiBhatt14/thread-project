#include <iostream>
#include "thread_manager.h"

using namespace std;

int main() {
    int n = 100;
    ThreadManager tm(n);

    auto task = [](int id) {
        cout << "thread " << id << " start\n";
        cout << "thread " << id << " end\n";
    };

    tm.run(task);
    tm.join_all();

    cout << "threads finished: " << tm.get_shared_value() << "\n";
    cout << "done\n";
    return 0;
}
