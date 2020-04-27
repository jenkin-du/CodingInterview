
#ifndef _FILE_QUEUE_H_
#define _FILE_QUEUE_H_

#include<stack>

using namespace std;

template <typename T> class Queue {
public:
	Queue(void);
	~Queue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

#endif // !_FILE_QUEUE_H_
