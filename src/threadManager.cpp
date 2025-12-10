#include "threadManager.h"


ThreadManager::ThreadManager(int n) : shared_value(0){threads.reserve(n);}

void ThreadManager::wrap_task(function<void(int)> func, int id){
    func(id);
    lock_guard<mutex> lock(m);
    shared_value++;

}

void ThreadManager::run(function<void(int)> func){
    int n = threads.capacity();
    for (int i = 0; i < n; i++){
        threads.emplace_back(&ThreadManager::wrap_task, this, func, i);
    }
}

void ThreadManager::join_all(){
    for (auto &t : threads){
        if (t.joinable()) t.join();}
}


int ThreadManager::get_shared_value(){
    lock_guard<mutex> lock(m);
    return shared_value;
    
}
