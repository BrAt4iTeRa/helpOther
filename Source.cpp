#include <iostream>
#include "Header.h"

int main() {
	intStack* stack = nullptr;
	menu(stack);
}

void menu(intStack*& stack) {
	while (true) {
		std::cout << "enter numbers, if you want stop, press 999\n";
		int numb = checkInputInt();
		if (numb == 999) break;
		stack = createStack(stack, numb);
	}
	printStack(stack);
	intStack* taskStack = changeStackForTask(stack);
	std::cout << std::endl;
	printStack(taskStack);
}

int checkInputInt() {
	std::string stringForInt;
	bool flag;
	do {
		flag = true;
		system("CLS");
		rewind(stdin);
		std::cin >> stringForInt;
		for (int i = 0; i < stringForInt.size(); i++) {
			if (stringForInt[i] < '0' || stringForInt[i] > '9') {
				std::cout << "Wrong input.\n try again\n";
				std::cin.clear();
				while (std::cin.get() != '\0');
				flag = false;
				break;
			}
		}
	} while (!flag);
	int intNumb = atoi(stringForInt.c_str());
	return intNumb;
}

intStack* createStack(intStack* head, int numbForStack) {
	if (head == nullptr) {
		head = new intStack;
		head->next = nullptr;
		head->numb = numbForStack;
		return head;
	}
	intStack* temp = new intStack;
	temp->numb = numbForStack;
	temp->next = head;
	return temp;
}

intStack* recursiveCreateStack(intStack* head, intStack*& task) {
	head = head->next;
	if (head->next != nullptr && head->numb != 0) head = recursiveCreateStack(head, task);
	task = createStack(task, head->numb);
	return head;
}

void printStack(intStack* head) {
	while (head != nullptr) {
		std::cout << head->numb << " ";
		head = head->next;
	}

}

intStack* changeStackForTask(intStack* head) {
	int counter = 0, counterMemory = 0;
	intStack* task = head;
	while (head != nullptr) {
		if (head->next == nullptr) break;
		else if (head->numb == 0) head = head->next;
		else break;
	}
	intStack* temp = head;
	while (true) {
		if (head == nullptr) {
			if (counter > counterMemory) task = temp;
			break;
		}
		else if (head->numb == 0 && counter > counterMemory) {
			task = temp;
			while (head != nullptr) {
				if (head->next == nullptr) break;
				//else if (head->next->numb == 0) head = head->next;
				else if (head->numb == 0) head = head->next;
				else break;
			}
			head = head->next;
			counterMemory = counter;
			counter = 0;
			temp = head;
			continue;
		}
		if (head->numb != 0) counter++;
		head = head->next;
	}
	head = task;
	task = nullptr;
	recursiveCreateStack(head, task);
	task = createStack(task, head->numb);
	/*while (head->numb!=0) {
		task = createStack(task, head->numb);
		head = head->next;
		if (head == nullptr) break;
	}*/
	return task;
}