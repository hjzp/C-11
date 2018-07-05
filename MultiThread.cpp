// MultiThread.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <string>
#include <iostream>

using namespace std;

// 线程传参问题

// 问题1：传入引用参数
void update_data(int& n)
{
	n *= 2;
}
void run_thread_update_data()
{
	int n = 100;
	std::thread t(update_data, std::ref(n)); // std::ref()将引用传给线程函数，不用ref()编译报错
	t.join();
	std::cout << n << std::endl;
}

// 问题2：将局部变量传入线程
void callable_with_arguments(double d, std::string const& s)
{
	std::cout << "d = " << d << ", s = " << s.c_str() << std::endl;
}
void run_thread_callable_with_arguments(float param)
{
	char buf[1024] = { 0 };
	sprintf_s(buf, "%f", param);
	std::thread t(callable_with_arguments, 3.14, std::string(buf)); // 最好不要直接传入局部变量buf，而是用string(buf)构造对象
	t.detach();		// 不等待线程结束，局部变量被释放，如果直接将局部变量传入线程，可能会有问题。使用join()方法等待线程结束，肯定没问题
}

// 条件变量


class Class1
{
public:
	void task(int n)
	{
		cout << "MyThread1::task(), n = " << n << endl;
	}
};
