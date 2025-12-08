#include <iostream>
#include <thread>
#include <vector>

void work(int id) {
    std::cout << "thread " << id << " start\n";
    std::cout << "thread " << id << " end\n";
}

int main() {
    std::vector<std::thread> t;
    for (int i = 0; i < 5; i++) {
        t.emplace_back(work, i);
    }
    for (auto &x : t) x.join();

    std::cout << "done\n";
    return 0;
}
