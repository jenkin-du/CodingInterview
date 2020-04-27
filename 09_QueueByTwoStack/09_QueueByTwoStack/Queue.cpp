#include "Queue.h"

//入队
template<typename T> void Queue<T>::appendTail(const T& node) {
	stack1.push(node);
}

//出队
template<typename T> T Queue<T>::deleteHead() {

	if (stack2.size <= 0) {
		while (stack1 > 0) {
			T& data = stack1.top();
			stack1.pop();

			stack2.push(data);
		}
	}

	if (stack2.size() == 0) {
		throw new exception("queue is empty");
	}

	T head = stack2.top();
	stack2.pop();

	return head;
}