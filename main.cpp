#include <iostream>
#include "Queue.h"

int main() {
		Queue<int> queue;
		queue.enqueue(25);
		queue.enqueue(36);
		queue.enqueue(79);

		queue.enqueue(999);
		queue.dequeue();
		queue.enqueue(879);
		queue.dequeue();
		queue.show();
}
