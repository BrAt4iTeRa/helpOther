#pragma once
struct intStack {
	intStack* next;
	int numb;
};

void menu(intStack*& stack);
int checkInputInt();
intStack* createStack(intStack* head, int numbForStack);
void printStack(intStack* head);
intStack* changeStackForTask(intStack* head);