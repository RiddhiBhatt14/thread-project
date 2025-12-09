#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void work(int id) {
    cout << "thread " << id << " start\n";
    cout << "thread " << id << " end\n";
}

int main() {
    vector<thread> t;
    for (int i = 0; i < 5; i++) {
        t.emplace_back(work, i);
    }
    for (auto &x : t) x.join();
    cout << "done\n";
    return 0;
}
