// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <tuple>

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

	// 右值引用 (Rvalue Referene)！！！


    return 0;
}

