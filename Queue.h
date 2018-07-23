#ifndef _QUEUE
#define _QUEUE

#include "List.h"

template <typename T>
class Queue : private DoublyList<T> {

public:
		Queue() : DoublyList<T>() {  }

		virtual void enqueue(T value);
		virtual void dequeue();
		virtual void show();

};

template <typename T>
void Queue<T>::enqueue(T value) {
		DoublyList<T>::insertTail(value);
}

template <typename T>
void Queue<T>::dequeue() {
		DoublyList<T>::removeHead();
}

template <typename T>
void Queue<T>::show() {
		DoublyList<T>::showList();
}

#endif
