#ifndef MYQUEUE_1
#define MYQUEUE_1
#include <iostream>
template <typename T> class MyQueue 
{
	// Private variables and methods
	private:
		unsigned short total; // current amount of items in the array
		unsigned short sizeOfArray; // current size of the array
		T* underHoodArray; // the array itself

		/// <summary>
		/// A function to swap two elements in the array
		/// </summary>
		/// <param name="i">the index of element one</param>
		/// <param name="j">the index of element two</param>
		void Swap(int i, int j) {
			// Temporary variable stores item one
			T temp = underHoodArray[i];
			// Set array item one to array item two
			underHoodArray[i] = underHoodArray[j];
			// Set array item two to temporary variable
			underHoodArray[j] = temp;
		};

		/// <summary>
		/// A QuickSort function to sort all objects into an assending order using recursion
		/// Should be O(log n)
		/// </summary>
		/// <param name="low">The bottom index of the current section being sorted</param>
		/// <param name="high">The top index of the current section being sorted</param>
		void QuickSort(int low, int high) {
			// If the bottom is greater than or equal to the top, end the function
			if (low >= high)
				return;
			// Grab the start item of the function
			T start = underHoodArray[low];
			// Counter
			int count = 0;
			// For all items between low + 1 and high
			for (int i = low + 1; i <= high; i++) {
				// If the item is greater than the lowest item
				if (!(underHoodArray[i] > start))
					// increment the counter
					count++;
			}
			// The start index is the low plus the amount of items greater than
			int startIndex = low + count;
			// Swap this item and the low item
			Swap(startIndex, low);
			// Temporary variables
			int i = low;
			int j = high;
			// While low is less than starting index and high is greater than
			while (i < startIndex && j > startIndex) {
				// If the low is lower than the starting item, increment
				while (!(underHoodArray[i] > start))
					i++;
				// If the high is higher than the starting item, increment
				while (underHoodArray[j] > start)
					j--;
				// If the low is still lower than the start, and the high is still higher than, swap the two items
				if (i < startIndex && j > startIndex) {
					Swap(i++, j--);
				}
			}
			// Recurse, seperating the halves between the low and the middle, and the middle and the high
			QuickSort(low, startIndex - 1);
			QuickSort(startIndex + 1, high);
		};
		// Public variables and methods
	public:
		/// <summary>
		/// Default Constructor
		/// </summary>
		MyQueue() {
			// Create a new T array of size one, where T is the templated data type
			underHoodArray = new T[1];
			total = 0;
			sizeOfArray = 1;
		};
		/// <summary>
		/// Parameterized constructor
		/// </summary>
		/// <param name="size">The initial size of the array used to store items</param>
		MyQueue(int size) {
			underHoodArray = new T[size];
			total = 0;
			sizeOfArray = size;
		};

		/// <summary>
		/// Copy Constructor
		/// </summary>
		/// <param name="other">the other queue</param>
		MyQueue(const MyQueue& other) {
			// Because this is a constructor, we don't have to worry about deleting an old Queue, as this queue doesn't exist yet
			// So just copy all the elements of the old Queue
			total = other.total;
			sizeOfArray = other.sizeOfArray;
			underHoodArray = new T[sizeOfArray];

			// And then copy all the elements of the old array into the new one
			for (unsigned short x = 0; x < total; x++) {
				underHoodArray[x] = other.underHoodArray[x];
			}
		};
		/// <summary>
		/// Destructor
		/// </summary>
		~MyQueue() {
			delete[] underHoodArray;
			total = 0;
			sizeOfArray = 0;
			underHoodArray = nullptr;
		};
		/// <summary>
		/// Pushes an item onto the end of the Queue
		/// </summary>
		/// <param name="item">the item to be added to the end of the queue, where T is the template data type</param>
		void Push(T item) {
			// If it'll fit in the current array, just add it to the array
			if (sizeOfArray > total) {
				underHoodArray[total] = item;
				total++;
			}
			// If it won't fit, double it
			else {
				// Double the size
				sizeOfArray *= 2;
				// Create a temporary array to hold the items inside
				T* temp = new T[sizeOfArray];
				// Transfer the objects of one to the other
				for (unsigned short x = 0; x < total; x++) {
					temp[x] = underHoodArray[x];
				}
				// Delete the old array
				delete[] underHoodArray;
				// Set the old array to the new one
				underHoodArray = temp;
				// Just to be sure, set temp to nullptr
				temp = nullptr;
				// Add the new item, this may cause a warning but its inconsistent and nothing could tell me the reason why
				underHoodArray[total] = item;
				// Increment
				total++;
			}

			// See Quicksort above for information -- Starts QuickSort at full size of occupied spaces in the array
			QuickSort(0, total-1);
		};

		/// <summary>
		/// Remove an item from the beginning of the queue
		/// </summary>
		/// <returns>The item removed, where T is the template data type</returns>
		T Pop() {
			// If it's empty return null
			if (this->IsEmpty())
				return T();

			// Grab the first item in the array
			T solution = underHoodArray[0];
			// Move all items over one position
			for (unsigned short x = 0; x < total-1; x++) {
				underHoodArray[x] = underHoodArray[x + 1];
			}
			// Tell the total counter that one item has been removed
			total--;
			// Return the first item in the queue, saved earlier
			return solution;
		};

		/// <summary>
		/// Prints all items in the Queue
		/// </summary>
		void Print() {
			// Surround the information to make clear when it starts and stops
			std::cout << "[";
			// Print all items EXCEPT THE LAST ONE, followed by a comma
			for (unsigned short x = 0; x < total - 1; x++) {
				std::cout << underHoodArray[x] << ", ";
			}
			// Print the last item and then the surrounder, and end line
			std::cout << underHoodArray[total - 1] << "]" << std::endl;
		};
		/// <summary>
		/// Gets the current size of the Queue
		/// </summary>
		/// <returns>the total number of items in the queue</returns>
		int GetSize() {
			return total;
		};

		/// <summary>
		/// Checks whether the Queue has items or not
		/// </summary>
		/// <returns>True if the Queue contains items, false otherwise</returns>
		bool IsEmpty() {
			if (total <= 0)
				return true;
			return false;
		}
		
		/// <summary>
		/// Copy operator
		/// </summary>
		/// <param name="other">The other queue being copied</param>
		/// <returns>a pointer to this queue</returns>
		MyQueue& operator=(const MyQueue& other) {
			// If they're the same thing, they're the same thing
			if (this == &other) {
				return *this;
			}

			// If this isn't a new/null Queue, delete the old stack this had. THIS PREVENTS MEMORY LEAKS
			if (underHoodArray != nullptr) {
				delete[] underHoodArray;
				underHoodArray = nullptr;
			}

			// Set the total and the size to the same as the array to be copied
			total = other.total;
			sizeOfArray = other.sizeOfArray;
			// Create a new array with the same size as the old one
			underHoodArray = new T[sizeOfArray];

			// Copy every element in the old array to the new one
			for (unsigned short x = 0; x < total; x++) {
				underHoodArray[x] = other.underHoodArray[x];
			}

			// Return this 
			return *this;
		};
};

#endif // !MYQUEUE_1
