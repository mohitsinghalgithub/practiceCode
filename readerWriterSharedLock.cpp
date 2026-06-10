#include<iostream>
#include<thread>
#include <shared_mutex>

using namespace std;

class ReaderWriter
{
    int shared_data = 0;
    shared_mutex mxt;
public:
    ReaderWriter() = default;

    void reader();
    void writer();
};


void ReaderWriter::reader()
{
    std::shared_lock<shared_mutex> lock(mxt);
    cout<<"reader value:  " << shared_data << endl;
}


void ReaderWriter::writer()
{
    std::lock_guard<shared_mutex> lock(mxt);
    shared_data++;
}

void readWriterProblem()
{
    ReaderWriter rw;
    thread reader1(&ReaderWriter::reader, &rw);
    thread reader2(&ReaderWriter::reader, &rw);
    thread reader3(&ReaderWriter::reader, &rw);

    thread writer1(&ReaderWriter::writer, &rw);
    thread writer2(&ReaderWriter::writer, &rw);
    thread writer3(&ReaderWriter::writer, &rw);

    std::this_thread::sleep_for(std::chrono::seconds(10));
}