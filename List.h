#ifndef _LIST_QUEUE
#define _LIST_QUEUE


template <typename T>
class DoublyList {

public:		
		DoublyList();
		~DoublyList();
		virtual void insertHead(T element);
		virtual void insertTail(T element);
		virtual void removeHead();
		virtual void removeTail();
		virtual bool isEmpty();
		virtual void showList();

private:		
		struct Node {
				T value;
				Node* next;
				Node* prev;
		};		

		Node* m_head;
		int m_size;

};

template <typename T>
DoublyList<T>::DoublyList() : m_head(nullptr), m_size(0) {

}

template <typename T>
DoublyList<T>::~DoublyList() {
		m_head = nullptr;
		std::cout << "Destructor is invoked " << std::endl;
}

template <typename T>
void DoublyList<T>::insertHead(T element) {

		Node* node = new Node;
		node->value = element;
		node->next = m_head;
		node->prev = nullptr;

		if( !isEmpty() ) {
				m_head->prev = node;
		}

		m_head = node;
		++m_size;
}

template <typename T>
void DoublyList<T>::insertTail(T element) {

		if( isEmpty() ) {
				DoublyList<T>::insertHead(element);
				return;
		}

		Node* node = new Node;
		Node* tmp = m_head;

		while(tmp->next) {
				tmp = tmp->next;
		}

		tmp->next = node;
		node->next = nullptr;
		node->value = element;
		node->prev = tmp;

}

template <typename T>
void DoublyList<T>::removeHead() {

		if( isEmpty() ) {
				std::cout << " List is empty can not remove " << std::endl;
				return;
		}

		Node* tmp = m_head;		
		tmp->next->prev = nullptr;
		m_head = tmp->next;
		delete tmp;
		tmp = nullptr;		
}

template <typename T>
void DoublyList<T>::removeTail() {
		if( isEmpty() ) {
				std::cout << " List is empty can not remove " << std::endl;
				return;
		}
		Node* tmp = m_head;
		while(tmp->next) {
				tmp = tmp->next;
		}

		tmp->prev->next = nullptr;
		delete tmp;
		tmp = nullptr;
}



template <typename T>
void DoublyList<T>::showList() {
		if( isEmpty() ) {
				std::cout << " List is empty can not show" << std::endl;
				return;
		}

		Node* tmp = m_head;
		int ix = 1;
		while(tmp) {
				std::cout << ix << "  " << tmp->value  << std::endl;
				ix++;
				tmp = tmp->next;		
		}
}

template <typename T>
bool DoublyList<T>::isEmpty() {
		return (!m_size) ? true : false;
}		


#endif
