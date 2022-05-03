
#include <iostream>
#include <exception>
#include <new>
#include <cstdlib>

void*	operator new (size_t size) throw (std::bad_alloc)
{
	std::cout << "Within the operator new:" << size << std::endl;
	if (size == 20)
		throw std::bad_alloc();
	return (malloc(4));
}

class Foo {
public:
	int	const	_nb;
public:
	Foo(void) : _nb(10)			{ std::cout << "Ctor called" << std::endl;	}
	Foo(int const nb) : _nb(nb)	{ std::cout << "Int ctor called" << std::endl; }
	~Foo(void) 					{ std::cout << "Dtor called" << std::endl; 	}
};


int	main(void)
{
	/*
	 * 1. THROWING ALLOCATION
	 * void*	operator new (size_t size) throw(std::bad_alloc);
	 */ 
//	Foo*	a = new Foo;// (Foo*) operator new (sizeof(Foo));
//	Foo*	b = (Foo*) operator new (sizeof(Foo));
//
//	Foo*	c = new Foo[2];// (Foo*) operator new (sizeof(Foo[2]);
//	Foo*	d = (Foo*) operator new (sizeof(Foo[2]));

	/*
	 * 2. NOTHROW ALLOCATION
	 * void*	operator new (size_t size, std::nothrow_t const & nothrow_value) throw();
	 */ 
//	Foo*	e = new (std::nothrow) Foo;
//	Foo*	f = (Foo*) operator new (sizeof(Foo), std::nothrow);
//
//	Foo*	j = new (std::nothrow) Foo[2];
//	Foo*	k = (Foo*) operator new (sizeof(Foo[2]), std::nothrow);
	
	/*
	 * 3. PLACEMENT
	 * void*	operator new (size_t size, void* ptr) throw();
	 */ 
//	std::cout << "1.------------------------------------" << std::endl;
//	Foo		*obj = (Foo*) operator new (sizeof(Foo));
//
//	std::cout << "2.------------------------------------" << std::endl;
//	new (obj) Foo;
//	std::cout << obj->_nb << std::endl;
//
//	std::cout << "3.------------------------------------" << std::endl;
//	new (obj) Foo(10);
//	std::cout << obj->_nb << std::endl;

	/*
	 * versions (1) and (2): REPLACEABLE
	 */
//	Foo*	ptr = (Foo*) operator new (sizeof(Foo));
//	std::cout << "---------------------------" << std::endl;
//	Foo*	ptr1 = new Foo(200);// (char*) operator new (sizeof(char));

	return (0);
}
