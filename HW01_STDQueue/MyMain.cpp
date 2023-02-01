#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <string>
#include "Queue.h";
#include "Alberto.h"
using namespace std;

void wrapper(void);

int main() {
	// Run the testing functions
	wrapper();
	// Check for any memory leaks
	_CrtDumpMemoryLeaks();
	return 0;
}

void wrapper() {
	// --- Simple Queue using Integers --- //
	// Create a queue
	MyQueue<int> queue = MyQueue<int>();
	MyQueue<int> queueTwo = MyQueue<int>();

	// Push items to the queue
	queue.Push(0);
	cout << "Queue just pushed +++++" << endl;
	queue.Push(2);
	cout << "Queue just pushed +++++" << endl;
	queue.Push(1);
	cout << "Queue just pushed +++++" << endl;

	// Print queue
	cout << "Integer Queue Content" << endl;
	queue.Print();

	// Copy Queue
	queueTwo = queue;

	// Pop items from queue
	queue.Pop();
	cout << "Queue just popped -----" << endl;

	// Push items to the queue
	queue.Push(5);
	cout << "Queue just pushed +++++" << endl;
	queue.Push(4);
	cout << "Queue just pushed +++++" << endl;
	queue.Push(3);
	cout << "Queue just pushed +++++" << endl;

	// Print queue
	cout << "Integer Queue Content" << endl;
	queue.Print();

	// Print queueTwo
	cout << "Copied Queue Content" << endl;
	queueTwo.Print();

	// Pop items from queue
	queue.Pop();
	cout << "Queue just popped -----" << endl;
	queue.Pop();
	cout << "Queue just popped -----" << endl;

	// Print queue
	cout << "Integer Queue Content" << endl;
	queue.Print();

	// Clear queue
	unsigned short c = queue.GetSize();
	for (unsigned short x = 0; x < c; x++) {
		queue.Pop();
		cout << "Queue just popped -----" << endl;
	}

	// Print queue
	cout << "Integer Queue Content" << endl;
	queue.Print();


	// --- Complex Queue using Strings --- //
	MyQueue<string> strQueue = MyQueue<string>();
	// Fill queue with string items
	for (unsigned short x = 10; x > 0; x--) {
		strQueue.Push(to_string(x));
		cout << "Queue just pushed +++++" << endl;
		if (x % 2 == 0)
		{
			strQueue.Pop();
			cout << "Queue just popped -----" << endl;
		}
	}
	// Print queue
	cout << "String Queue Content" << endl;
	strQueue.Print();

	MyQueue<string> copyQueue = strQueue;

	strQueue.Pop();
	cout << "Queue just popped -----" << endl;

	// Print queue
	cout << "String Queue Content" << endl;
	strQueue.Print();
	// Print queue
	cout << "Copy String Queue Content" << endl;
	copyQueue.Print();


	// --- Complex Queue using AlbertoClass --- //
	MyQueue<AlbertoClass> albertoQueue = MyQueue<AlbertoClass>();
	// Fill queue with AlbertoClass items
	for (unsigned short i = 30; i < 40; ++i)
	{
		AlbertoClass alberto(i);
		albertoQueue.Push(alberto);
		cout << "Queue just pushed +++++" << endl;
	}
	// Print queue
	cout << "Alberto Queue Content" << endl;
	albertoQueue.Print();

	// Tell user we are waiting for their input
	cout << "Press Enter to finish." << endl;
	// Wait for user input
	getchar();
}