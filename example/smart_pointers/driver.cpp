#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

class foo
{
public:
	foo() {printf("\tCreating foo\n");}
	~foo() {printf("\tDestroying foo\n");}
};

int main(int argc, char** argv)
{
	foo* ptr = nullptr;
	
	/*{ //NOT ALLOWED: cannot assign to unique ptr, needs reset()
		std::unique_ptr<foo> u_ptr;
		u_ptr = new foo;
	}*/
	
	/*{ //NOT ALLOWED: cannot assign unique ptr to ptr, needs get() or release()
		std::unique_ptr<foo> u_ptr(new foo);
		foo* bar = u_ptr;
	}*/
	
	/*{ //NOT ALLOWED: cannot assign / copy unique ptrs, needs move
		std::unique_ptr<foo> u_ptr1(new foo);
		std::unique_ptr<foo> u_ptr2(u_ptr1);
	}*/
	
	printf("Initializing unique ptr with constructor:\n");
	{
		std::unique_ptr<foo> u_ptr(new foo);
	}
	printf("End of block\n\n");

	printf("Assigning and deleting unique ptr:\n");
	{
		std::unique_ptr<foo> u_ptr;
		printf("Creating instance of object\n");
		ptr = new foo;
		printf("Done, assigning unique_ptr with reset\n");
		u_ptr.reset(ptr);
		printf("Done, deleting object with reset\n");
		u_ptr.reset();
		printf("Done\n");
	}
	printf("End of block\n");
	printf("Value of 'ptr' is still 0x%p and non-zero, we must not destroy it!\n\n", ptr);
	ptr = nullptr;
	
	printf("Release of unique ptr:\n");
	{
		std::unique_ptr<foo> u_ptr(new foo);
		ptr = u_ptr.release();
	}
	printf("End of block\n");
	printf("Deleting object with the C style ptr (unique ptr is already gone)\n");
	delete ptr;
	ptr = nullptr;
	printf("Delete finished\n\n");
	
	printf("Move of unique ptr:\n");
	{
		printf("Creating u_ptr1\n");
		std::unique_ptr<foo> u_ptr1;
		{
			printf("Creating u_ptr2 with object\n");
			std::unique_ptr<foo> u_ptr2(new foo);
			printf("Value of u_ptr1: 0x%p, u_ptr2: 0x%p\n", u_ptr1.get(), u_ptr2.get());
			printf("Moving unique ptr\n");
			u_ptr1 = std::move(u_ptr2);
			printf("Value of u_ptr1: 0x%p, u_ptr2: 0x%p\n", u_ptr1.get(), u_ptr2.get());
		}
		printf("Ending of subblock, u_ptr2 is out of scope\n");
	}
	printf("End of block\n\n");
	
	printf("Shared ptr example\n");
	{
		printf("Creating first shared ptr\n");
		std::shared_ptr<foo> s_ptr1(new foo);
		printf("Use count: %d\n", (int) s_ptr1.use_count());
		{
			printf("Creating second shared ptr for same object\n");
			std::shared_ptr<foo> s_ptr2(s_ptr1);
			printf("Use count: %d\n", (int) s_ptr1.use_count());
		}
		printf("End of subblock, one shared ptr out of scope\n");
		printf("Use count: %d\n", (int) s_ptr1.use_count());
		printf("Generating second instance (again)\n");
		std::shared_ptr<foo> s_ptr2(s_ptr1);
		printf("Use count: %d\n", (int) s_ptr1.use_count());
		
		printf("Resetting first instance to null\n");
		s_ptr1.reset();
		printf("Use count: %d\n", (int) s_ptr2.use_count());
	}
	printf("End of block\n\n");
}
