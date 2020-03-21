#include<iostream>
#include<stack>

using namespace std;

typedef struct ListNode {
	int value;
	struct ListNode* next;
}ListNode;

//��ĩβ����һ�����
void addNode(ListNode* head, int value) {

	if (head == nullptr) {
		head = new ListNode();
		head->value = value;
		head->next = nullptr;

		return;
	}

	ListNode* p = head;
	while (p->next != nullptr) {
		p = p->next;
	}

	p->next = new ListNode();
	p = p->next;

	p->value = value;
	p->next = nullptr;
}

//�������ʼ��������
ListNode* init(int arr[], int length) {

	ListNode* head = new ListNode();
	head->value = arr[0];
	head->next = nullptr;

	ListNode* p = head;
	for (int i = 1; i < length; i++) {

		p->next = new ListNode();
		p = p->next;

		p->value = arr[i];
		p->next = nullptr;
	}

	return head;
}

//�����ӡ�������ݣ�������ջ
void printfListReversing(ListNode* head) {

	stack<ListNode*> nodeStack;

	ListNode* p = head;
	while (p != nullptr) {

		nodeStack.push(p);
		p = p->next;
	}

	while (!nodeStack.empty()) {
		cout << nodeStack.top()->value << ",";
		nodeStack.pop();
	}
	cout << endl;
}

int main() {

	int arr[10] = { 10,45,65,78,34,67,89,33,55,66 };
	ListNode* head = init(arr, 10);

	addNode(head, 20);

	if (head == nullptr) {
		cout << "null" << endl;
	}

	//�����ӡ�������ݣ���ջʵ��
	printfListReversing(head);
}