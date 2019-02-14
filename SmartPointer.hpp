```c
#pragma once

template <class T>
class UniquePtr
{
public:
	// 
	UniquePtr()
	{
		pointer = nullptr;
		use_count = nullptr;
	}
	// 
	UniquePtr(T* p)
	{
		pointer = p;
		p = nullptr;
		use_count = new int;
		*use_count = 1;
	}
	// copy constructor,release "other" object.
	UniquePtr(UniquePtr<T>& other)
	{
		pointer = other.pointer;
		other.pointer = nullptr;
		use_count = other.use_count;
		other.use_count = nullptr;
		//++(*use_count);  // unique pointer
	}
	// move constructor,release "other" object.
	UniquePtr(UniquePtr<T>&& other)
	{
		pointer = other.pointer;
		other.pointer = nullptr;
		use_count = other.use_count;
		other.use_count = nullptr;
		//++(*use_count);  // unique pointer
	}
	//
	UniquePtr<T>& operator=(const UniquePtr<T>& other)
	{
		pointer = other.pointer;
		other.pointer = nullptr;
		use_count = other.use_count;
		other.use_count = nullptr;
		//++(*use_count);  // unique pointer
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
		if (use_count &&
			(--(*use_count) == 0))
		{
			delete pointer;
			pointer = nullptr;
			delete use_count;
			use_count = nullptr;
		}
	}

private:
	T* pointer;
	int* use_count;
};

template <class T>
class SharedPtr
{
public:
	// 
	SharedPtr()
	{
		pointer = nullptr;
		use_count = nullptr;
	}
	// 
	SharedPtr(T* p)
	{
		pointer = p;
		p = nullptr;
		use_count = new int;
		*use_count = 1;
	}
	// copy constructor
	SharedPtr(SharedPtr<T>& other)
	{
		pointer = other.pointer;
		use_count = other.use_count;
		++(*use_count);  // shared pointer
	}
	// move constructor
	SharedPtr(SharedPtr<T>&& other)
	{
		pointer = other.pointer;
		use_count = other.use_count;
		++(*use_count);  // shared pointer
	}
	//
	SharedPtr<T>& operator=(const SharedPtr<T>& other)
	{
		pointer = other.pointer;
		use_count = other.use_count;
		++(*use_count);  // shared pointer
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
	~SharedPtr()
	{
		if (use_count &&
			(--(*use_count) == 0))
		{
			delete pointer;
			pointer = nullptr;
			delete use_count;
			use_count = nullptr;
		}
	}

private:
	T* pointer;
	int* use_count;
};
```
