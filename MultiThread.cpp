// MultiThread.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <string>

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

// 问题2：传入引用参数
void callable_with_arguments(double d, std::string const& s)
{
	std::cout << "d = " << d << ", s = " << s.c_str() << std::endl;
}
void run_thread_callable_with_arguments(float param)
{
	char buf[1024] = { 0 };
	sprintf_s(buf, "%f", param);
	std::thread t(callable_with_arguments, 3.14, std::string(buf));
	t.detach();
}


int main()
{
	run_thread_update_data();
	run_thread_callable_with_arguments(1.2);

    return 0;
}

