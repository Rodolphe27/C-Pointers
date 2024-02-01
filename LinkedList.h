#ifndef LiskedList_H_
#define LiskedList_H_


namespace fhdo_pk2
{
template <class T>
class Iterator{
	public:
		
		virtual bool hasNext()  =0 ;
		virtual  T next()=0;
};


template <class T> class LinkedList{
	private:
	   struct Node{
	   T data;
	   Node *next;
       Node( T& value):data{value},next{nullptr}{}
       };

		Node *head;
		Node *tail;

	public:

	

	class ListIterator : public Iterator<T> {
    private:
        Node* current;
	public:
        ListIterator(Node* start) : current(start) {}
        bool hasNext()  override {
            return current != nullptr;
        }
	    T next() override {
             
	
                T value = current->data;
                current = current->next;
                return value;
             // oder eine Ausnahme werfen
            
        }
    };
		LinkedList();
	   ~LinkedList();
		LinkedList(const LinkedList &other);
        int append(T text);
	    int insert(T text, int pos);
		//int index_of(T text);
		T first();
		T last();
		int remove(int pos);
		T get(int pos);
		void visit_all(void (*work)(T t));

		Iterator<T> *iterator(){
			return new ListIterator(head);}

	
};


template <class T>
LinkedList<T>::LinkedList():head{nullptr},tail{nullptr}{}

template <typename T>
LinkedList<T>::~LinkedList(){
	Node *current = head;
	Node *next;
	while(current != nullptr){
		next = current ->next;
		//delete current->data;
		delete current;
		current = next;		 
	}
	// head = nullptr;
	// tail = nullptr;
}

template <typename T> 
LinkedList<T>::LinkedList(const LinkedList &other){
	head =tail= nullptr;
	Node * current = other.head;
	while(current){
		append(current->data);
		current = current->next;
		}	
}
template <typename T>
int LinkedList<T>::append(T text){
	Node *newNode = new Node{text};
    
	if (head == nullptr){
		head =tail= newNode;
		return 1;
	}
	else{ 
		tail ->next = newNode;
		tail = newNode;
		return 1;
	}
	return 0;
}
template <typename T>
int LinkedList<T>::insert(T text , int pos){
	Node *newNode = new Node{text};
	if(head ==nullptr){
		head =tail= newNode;
	}
	else if (pos>=0){
		Node *current = head;
		for(int i = 0; i<pos-1 && current->next!= nullptr; i++){
				current=current->next;
			}
			newNode->next = current ->next;
			current ->next = newNode;
		
		if (current->next == nullptr){
			tail = newNode;
		}
	}
	
	return 1;
}
template <typename T>
int LinkedList<T>::remove(int pos){
	if(head == nullptr){
		return 0;
	}

	if(pos==0){//lösche das erste Elemente
		Node *temp = head;
		head = head->next;
		delete temp;
		return 1;
	}
    if(pos>0){
	Node *current = head;
	Node *prev = nullptr;
	
	//durchlaufe bis pos
	for(int i=0; i<pos && current->next != nullptr; i++){
		prev = current;
		current = current->next;

	}
	prev->next = current->next;
	
	
	if (current->next == nullptr){
		tail = prev;
    }
		delete current;
		return 1;
}
	return 0;
	
}
template <typename T>
T LinkedList<T>::get(int pos){
	Node *current = head;
	for(int i = 0; i<pos && current != nullptr; i++){
		current = current->next;
	}
	return (current == nullptr) ? T() : current->data;
}



/*template <typename T>
int LinkedList<T>::index_of(T text){
	Node *current = head;
	int pos = 0;
	while(current != nullptr){
		if(std::strcmp(current->data, text) == 0){
			return pos;
		}
		current = current->next;
		pos++;
	}
	return -1;
}
*/
template <typename T>
T LinkedList<T>::first(){
	return(head == nullptr)? T() :head->data;
}

template <typename T>
T LinkedList<T>::last(){
	return (head == nullptr)? T(): tail->data;
}
/*template <typename T>
void LinkedList<T>::visit_all(void (work)(T t)){
	Node *current = head;
	while(current){
		work(current->data);
		current = current->next;
	}
}*/
}

#endif // LiskedList_H_
