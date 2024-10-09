#include <iostream>
#include <thread>
using namespace std;

void thread_1()
{
    cout << "���߳�1 " << std::this_thread::get_id() << endl;
}

void thread_2(int x)
{
    cout << "x:" << x << endl;
    cout << "���߳�2 " << std::this_thread::get_id() << endl;
}

int main()
{
    thread first(thread_1); // �����̣߳����ã�thread_1()
    thread second(thread_2, 100); // �����̣߳����ã�thread_2(100)
    thread third(thread_2,3);//������3���̣߳�����thread_2������
    std::cout << "���߳�\n";

    first.join(); //����˵������̵߳ķ�ʽ            
    second.join();
    std::cout << "���߳̽���.\n";//����join���
    return 0;
}
