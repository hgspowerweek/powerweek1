#ifndef BENCH_H
#define BENCH_H

class class_virtual
{
public:
	virtual void foo(int* ptr);
};

class class_basic
{
public:
	void foo(int* ptr);
};

class class_inline
{
public:
	void foo(int* ptr) {*ptr = 1;}
};

class class_derived : public class_virtual
{
public:
	virtual void foo(int* ptr);
};

#endif
