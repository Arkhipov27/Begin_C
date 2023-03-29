#include <iostream>

struct LinkedList {
	int data;
	LinkedList* next;
};

LinkedList* insert_after(LinkedList* const current) {
	if (nullptr == current)
		return new LinkedList{ 0, nullptr };
	LinkedList* current_next = new LinkedList{ 0, current->next };
	current->next = current_next;
	return current_next;
}

LinkedList* remove_after(LinkedList* const current) {
	if (nullptr == current)
		return nullptr;
	if (nullptr != current->next) {
		LinkedList* current_next = current->next;
		current->next = current_next->next;
		delete current_next;
	}
	return current->next;
}
void erase(LinkedList* const head) {
	if (nullptr == head)
		return;
	LinkedList* head_next = head->next;
	delete head;
	while (head_next != nullptr) {
		LinkedList* curr = head_next;
		head_next = head_next->next;
		delete curr;
	}
}

LinkedList* ReverseRec(LinkedList* head, LinkedList* prev) {
	if (head->next == nullptr) {
		if (prev == nullptr)
			head->next = nullptr;
		else
			head->next = prev;
		return head;
	}
	LinkedList* new_head = head->next;
	if (prev == nullptr)
		head->next = nullptr;
	else
		head->next = prev;
	return ReverseRec(new_head, head);
}

LinkedList* reverse_rec(LinkedList* const head) {
	return ReverseRec(head, nullptr);
}

LinkedList* reverse_itr(LinkedList* const head) {
	if (nullptr == head)
		return nullptr;
	LinkedList* c_prev = nullptr;
	LinkedList* c = head;
	LinkedList* c_next;
	while (c != nullptr) {
		c_next = c->next;
		c->next = c_prev;
		c_prev = c;
		c = c_next;
	}
	return c_prev;
}

void print_list(LinkedList* head) {
	LinkedList* curr = head;
	while (curr != nullptr) {
		std::cout << curr->data << ' ';
		curr = curr->next;
	}
}

void test(LinkedList* head, int a, int n) {
	int b, val;
	LinkedList* node = head;
	if (a == 1) {
		std::cout << "Enter the serial number of the element after which the element will be inserted (the first number is 1) and its value" << std::endl;
		std::cin >> b >> val;
		if (b < 1 || b > n) {
			std::cout << "Invalid value" << std::endl;
			return;
		}
		for (int i = 0; i < b - 1; i++) {
			node = node->next;
		}
		LinkedList* node_next = insert_after(node);
		node_next->data = val;
		std::cout << "Result of function" << std::endl;
		print_list(head);
	}
	else if (a == 2) {
		std::cout << "Enter the serial number of the element after which the element will be deleted (the first number is 1)" << std::endl;
		std::cin >> b;
		if (b < 1 || b > n) {
			std::cout << "Invalid value" << std::endl;
			return;
		}
		for (int i = 0; i < b - 1; i++) {
			node = node->next;
		}
		remove_after(node);
		std::cout << "Result of function" << std::endl;
		print_list(head);
	}
	else if (a == 3) {
		erase(head);
		std::cout << "The list is deleted" << std::endl;
	}
	else if (a == 4) {
		head = reverse_rec(head);
		std::cout << "Result of function" << std::endl;
		print_list(head);
	}
	else if (a == 5) {
		head = reverse_itr(head);
		std::cout << "Result of function" << std::endl;
		print_list(head);
	}
	else
		std::cout << "The number must be from 1 to 5" << std::endl;
}

int main() {
	int n;
	std::cout << "Enter number of elements in list" << std::endl;
	std::cin >> n;
	LinkedList* head = insert_after(nullptr);
	LinkedList* tmp = head;
	for (int i = 0; i < n; i++) {
		int value;
		std::cin >> value;
		if (i == 0)
			head->data = value;
		else {
			tmp = insert_after(tmp);
			tmp->data = value;
		}
	}
	int a;
	std::cout << "Enter a number from 1 to 5 to check:\n1 - insert_after\n2 - remove_after\n3 - erase\n4 - reverse_rec\n5 - reverse_itr" << std::endl;
	std::cin >> a;
	test(head, a, n);
	if (a != 3)
		erase(head);
	return 0;
}