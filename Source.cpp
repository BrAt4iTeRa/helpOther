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
void printStack(intStack* head) {
	while (head != nullptr) {
		std::cout << head->numb << " ";
		head = head->next;
	}

}
intStack* changeStackForTask(intStack* head) {
	int counter = 0, counterMemory = 0;
	intStack* task = head;
	intStack* temp = head;
	bool flag = true;
	while (head != nullptr) {
		if (head->numb == 0) {
			if (counter > counterMemory) {
				counterMemory = counter;
				task = temp;
				flag = true;
			}
			counter = 0;
			head = head->next;
			continue;
		}
		if (flag) temp = head;
		counter++;
		head = head->next;
		flag = false;
	}
	head = task;
	task = nullptr;
	while (head->numb!=0) {
		task = createStack(task, head->numb);
		head = head->next;
		if (head == nullptr) break;
	}
	return task;
}