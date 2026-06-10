#include<iostream>
#include<atomic>
#include<optional>
#include<vector>
#include<thread>
#include <mutex>

using namespace std;

template<typename T>
class SingleTon
{
    
    //mutex mxt;
public:
    
    static T* getInstance();
};

template<typename T>
T* SingleTon<T>::getInstance()
{
    static mutex mxt;
    static T *instance = nullptr;
    if(!instance)
    {
        lock_guard<mutex> l(mxt);
        if(!instance)
        {
            instance = new T();
        }
    }

    return instance;
}

template<class T>
void makeConnection( T * connection)
{
    connection = new T();
}

template<class T>
T * getConnection()
{
    static T *connection = nullptr;
    std::once_flag resource_once;

    call_once(resource_once, makeConnection, connection);
    return connection;
}