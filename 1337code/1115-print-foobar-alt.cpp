
/*
1115. Print FooBar Alternately

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
*/

# include <iostream>
# include <mutex>
# include <functional>
# include <thread>

using namespace std;
class FooBar {
private:
	int n;

public:
	// note: double lock/unlock on std::mutex has undefined behaviour
	std::mutex foo_mutex;
	std::mutex bar_mutex;
	FooBar(int n) {
		this->n = n;
	}

	void foo(function<void()> printFoo) {
		for (int i = 0; i < n; i++) {
			// printFoo() outputs "foo". Do not change or remove this line.
			bar_mutex.lock();
			printFoo();
			foo_mutex.unlock();
		}
	}

	void bar(function<void()> printBar) {
		for (int i = 0; i < n; i++) {
			// printBar() outputs "bar". Do not change or remove this line.
			foo_mutex.lock();
			printBar();
			bar_mutex.unlock();
		}
	}
};

int main(void) {
	FooBar foobar(5);
	std::thread t1(foobar.foo);
	std::thread t2(foobar.bar);
	t1.join();
	t2.join();


}