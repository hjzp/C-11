// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <tuple>

#include "SmartPointer.hpp"

using namespace std;

int main()
{
	// vector使用相关
	vector<int> vec{ 1,2,3,4,5 };

	for (auto i : vec)
	{
		std::cout << i << std::endl;
	}

	for each (auto i in vec)
	{
		std::cout << i << std::endl;
	}

	// using 关键字等价于 typedef
	typedef double DB;
	DB f = 1.0;
	cout << f << endl;

	using DB1 = double;
	DB1 ff = 1.1;
	cout << ff << endl;

	// 新增一些转换函数
	string str = to_string(ff);
	cout << str << endl;

	// 居然也有元组类型，使用时需要包含头文件"#include <tuple>"
	std::tuple<int, double, std::string> t(64, 128.0, "Caroline");
	using my_tuple = std::tuple<int, int, double>;
	my_tuple tt = { 1, 1, 1.0 };
	tt = make_tuple(2, 2, 2.0);
	cout << std::get<0>(tt) << endl;

	///////////////////////////////////////////////////////////////
	// TODO:
	// TODO_1: 右值、右值引用的理解 (Rvalue Referene)，x&&

	// 智能指针：独占式
	UniquePtr<int> u1(new int(10));
	cout << "*u1 = " << *u1 << endl;
	UniquePtr<int> u2 = u1;
	cout << "*u2 = " << *u2 << endl;
	UniquePtr<int> u3(u2);
	// 智能指针：共享式
	SharedPtr<int> s1(new int(20));
	cout << "*s1 = " << *s1 << endl;
	SharedPtr<int> s2 = s1;
	cout << "*s2 = " << *s2 << endl;
	SharedPtr<int> s3(s2);
	
	// TODO_3: 多线程与互斥同步
	cout << "-----------------Thread--------------->>" << endl;
	run_thread_update_data();
	run_thread_callable_with_arguments(1.2);	// 内部没有等待线程结束，打印结果顺序随机
	cout << "-----------------Thread---------------<<" << endl;
	
	cout << "-----------------Thread call class function--------------->>" << endl;
	Class1 cls1;
	std::thread thread1(&Class1::task, cls1, 11);
	thread1.join();
	cout << "-----------------Thread call class function---------------<<" << endl;

	///////////////////////////////////////////////////////////////


    return 0;
}

