#pragma once

template <class T>
class UniquePtr
{
public:
	// 
	UniquePtr()
	{
		pointer = nullptr;
	}
	// 
	UniquePtr(T* p)
	{
		pointer = p;
		p = nullptr;
		use_count = 1;
	}
	// move constructor
	UniquePtr(UniquePtr<T>&& that)
	{
		pointer = p;
		p = nullptr;
		++use_count;
	}
	//
	UniquePtr<T>& operator=(const UniquePtr<T>& ptr)
	{
		pointer = ptr;
		++use_count;
	}
	//
	T& operator*()
	{
		return (*pointer);
	}
	//
	T* operator->()
	{
		return pointer;
	}
	// 
	~UniquePtr()
	{
		if (0 == --use_count)
		{
			delete pointer;
		}
	}

private:
	T* pointer;
	int use_count;
};

