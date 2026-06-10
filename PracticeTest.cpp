
#include<thread>
#include<chrono>
#include "CuriousRecursiveTemplatePattern.h"
#include "Joining_thread.h"

extern void crtp();
extern void joiningThreadTest();
extern void readWriterProblem();
int main()
{
    //crtp();
    //joiningThreadTest();
    readWriterProblem();
    return 0;
}