#pragma once

#include<iostream>
#include<atomic>
#include<optional>
#include<vector>
#include<thread>

using namespace std;

class joining_thread
{
private:
    thread th;

public:
    joining_thread() noexcept = default;
    template<typename T, typename ... Args>
    explicit joining_thread(T &&func, Args &&... args);

    joining_thread(const joining_thread&) = delete;
    joining_thread & operator= (const joining_thread &) = delete;

    joining_thread(joining_thread && other) noexcept;
    joining_thread & operator=(joining_thread && other) noexcept;
    ~joining_thread();

    bool joinable();
    void join();
    void detach();

    std::thread::id get_id() noexcept;
};

template<typename T, typename ... Args>
joining_thread::joining_thread(T &&func, Args &&... args):th(std::forward<T>(func), std::forward<Args>(args)...)
{
}

joining_thread::joining_thread(joining_thread && other) noexcept :th(std::move(other.th))
{
}

joining_thread & joining_thread:: operator=(joining_thread && other) noexcept
{
    if(this != &other)
    {
        if(th.joinable())
            th.join();
        th = std::move(other.th);
    }

    return *this;
}

bool joining_thread::joinable()
{
    return th.joinable();
}

void joining_thread::join()
{
    th.join();
}

void joining_thread::detach()
{
    th.detach();
}

std::thread::id joining_thread::get_id() noexcept
{
    return th.get_id();
}

joining_thread::~joining_thread()
{
    if(th.joinable())
        th.join();
}


void joiningThreadTest()
{
    auto lambda = []()
        {cout<< "thread started";};
    joining_thread jth(lambda);
}

