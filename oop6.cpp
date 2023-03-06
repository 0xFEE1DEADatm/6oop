#include <iostream>
template<typename T>
class List {
	
public:
	List();
	~List();
	int getsize() { return size; }
	void clear();
	void insert(T value, int infex);
	void removeat(int index);
	void print();
	void popfront();
	void pushfront(T data);
	void exp(int index, T data = 0);
	T& operator[](const int index); 

private:
	template<typename T>
	class Node {
	public:
		Node *pnext;
		T data;
		Node(T data = T(), Node* pnext = nullptr) {
			this->data = data;
			this->pnext = pnext;
		}
	};
	Node<T> *head;
	int size;
};
template<typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List() {
	clear();
}
template<typename T>
void List<T>::pushfront(T data) {
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
T& List<T>::operator[](const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) { return current->data; }
		current = current->pnext;
		counter++;
	}
}
template<typename T>
void List<T>::exp(int index, T data) {
	if (data == 0) {
		if (index == 0) { popfront(); }
		else {
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++) {
				previous = previous->pnext;
			}
			Node<T>* toDelete = previous->pnext;
			previous->pnext = toDelete->pnext;
			delete toDelete;
			size--;

		}
	}
	else {
		if (index == 0) { pushfront(data); }
		else {
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++) {
				previous = previous->pnext;
			}
			Node<T>* newNode = new Node<T>(data, previous->pnext);
			previous->pnext = newNode;
			size++;
		}
	}

}
template<typename T>
void List<T>::popfront() {
	Node<T>* temp = this->head;
	head = head->pnext;
	delete temp;
	size--;
}
template<typename T>
void List<T>::clear() {
	while (size) {
		popfront();
	}
}

template<typename T>
void List<T>::insert(T value, int index) {
	if (index == 0) { pushfront(value); }
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pnext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pnext);
		previous->pnext = newNode;
		size++;
	}
}
template<typename T>
void List<T>::removeat(int index) {
	if (index == 0) { popfront(); }
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pnext;
		}
		Node<T>* toDelete = previous->pnext;
		previous->pnext = toDelete->pnext;
		delete toDelete;
		size--;
	
	}
}

template<typename T>
void List<T>::print() {

	Node<T>* current = this->head;
	while (current) {
		std::cout << current->data << "  ";
		current = current->pnext;
	}
}

int main() {

	enum actions {
		 clear, insert, removeat, print, element, exp, endsession
	};

	bool stop = false;
	int choice;

	List<int>lst;
	std::cout << "Enter size of list :\n";
	int numberscount;
	std::cin >> numberscount;
	for (int i = 0; i < numberscount; i++) {
		lst.insert((rand() % 10), i);
	}
	std::cout << " List created!\n";
	lst.print();
	std::cout << std::endl;
	std::cout << "  0 - clear  1 - insert  2 - removeat " << std::endl;
	std::cout << "  3 - print 4 - element 5 - exp  6 - endsession  " << std::endl;
	while (!stop) {
		std::cout << "select action : ";
		std::cin >> choice;
		switch (choice) {
		case actions::exp:
			int index12;
			double value1;
			std::cout << "\nenter index : ";
			std::cin >> index12;
			std::cout << "add or delete ? 1-2 :";
			int ch;
			std::cin >> ch;
			if (ch == 1) {
				std::cout << "\nenter value : ";
				std::cin >> value1;
				std::cout << std::endl;
				lst.exp(index12,value1);
			}
			else {
				lst.exp(index12);
			}
			break;
		case actions::element:
			int ind;
			std::cout << "enter index : ";
			std::cin >> ind;
			std::cout << std::endl << "the " << ind << " element = " << lst[ind] << std::endl;
			break;
		case actions::print:
			lst.print();
			std::cout << std::endl;
			break;
		case actions::insert:
			int index1;
			double value;
			std::cout << "enter index : ";
			std::cin >> index1;
			std::cout << "\nenter value : ";
			std::cin >> value;
			std::cout << std::endl;
			lst.insert(value, index1);
			break;
		case actions::removeat:
			int index2;
			std::cout << "enter index : ";
			std::cin >> index2;
			lst.removeat(index2);
			break;
		case actions::clear:
			lst.clear();
			std::cout << "the list has been removed\n";
			break;
		case actions::endsession:
			std::cout << "cya!";
			stop = true;
			break;
		}	
	}
}



