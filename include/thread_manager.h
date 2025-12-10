#pragma once
#include <thread>
#include <vector>
#include <functional>
#include <mutex>


using namespace std;

class ThreadManager{
public:
    ThreadManager(int n);
    void run(function<void(int)> func);
    void join_all();
    int get_shared_value();


private:
    vector<thread> threads;
    mutex m;
    int shared_value;
    void wrap_task(function<void(int)> func, int id);


};
