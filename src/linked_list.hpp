#include "node.hpp"
#include <new>
#include <iostream>

using namespace std;

template <typename t> class linked_list{
private:
	int node_count = 0;
	node<t> head;
    node<t> tail;
public:

	linked_list(t data){    //initial data for the starting point of the node
		node<t>* new_node = new node<t>;
		new_node->set_data(data);
		new_node->set_next(tail);
		new_node->set_last(head);
		head.set_next(*new_node);
		tail.set_last(*new_node);
	}

	void push(t data){  //  the push funtion allows the user to push data in to the linked list
		node_count++;
		node<t>* new_node = new node<t>;
		node<t>* current = tail.get_last();
		new_node->set_data(data);
		current->set_next(*new_node);
		tail.set_last(*new_node);
		new_node->set_last(*current);
		new_node->set_next(tail);
	}

	void pop(){
		node_count--;
		node<t>* removal = tail.get_last();
		node<t>* new_last = removal->get_last();
		new_last->set_next(tail);
		tail.set_last(*new_last);
		delete removal;
	}

	node<t>* at(int n){  //This function is desinged to allow the user to retrive a value of a certian node
		node<t> *current = head.get_next();
			for(int i = 0; i < n; i++){
				current = current->get_next();
			}
		return current;
	}

	void set_data(int n, t data){   // This funtion is desinged to set the value of a specific node in the linked list
		node<t> *current = head.get_next();
			for(int i = 0; i < n; i++){
				current = current->get_next();
			}
		current->set_data(data);
	}

	void print_list(){    // This function prints the current list for testing
		node<t> current = *head.get_next();
		for(int i = 0; i <= node_count; i++){
			cout<<current.get_data()<<endl;
			current = *current.get_next();
		}
	}

	bool is_in(t test_data){
		node<t> current = *head.get_next();
		for(int i = 0; i <= node_count; i++){
			if(current.get_data() == test_data){return true;}
			current = *current.get_next();
		}
		return false;
	}

	void sort(){  // Sorting algorythim taken from geeksforgeeks
		for(int i = 0; i < node_count-1; i++){
			for(int j = 0; j < node_count-i-1; j++){
				node<t> *node1 = this->at(j);
				node<t> *node2 = this->at(j+1);
				if(node1->get_data() > node2->get_data()){
					t temp = node1->get_data();
					node1->set_data(node2->get_data());
					node2->set_data(temp);
				}
			}
		}
	}

	void push_at(t data, int n){
		if(n < node_count){
		node<t>* current = head.get_next();
			for(int i = 1; i < n; i++){
				current = current->get_next();
			}
			node<t> *next = current->get_next();
			node<t>* new_node = new node<t>;
			new_node->set_data(data);
			new_node->set_last(*current);
			new_node->set_next(*next);
			next->set_last(*new_node);
			current->set_next(*new_node);
			node_count++;
		}
		else{
			this->push(data);
		}
	}

	void pop_at(int n){
		if(n < node_count){
			node<t>* remove = head.get_next();
			for(int i = 1; i < n; i++){
				remove = remove->get_next();
			}
			node<t> *new_last = remove->get_last();
			node<t> *new_next = remove->get_next();
			new_last->set_next(*new_next);
			new_next->set_last(*new_last);
			delete remove;
			node_count--;
		}
	}



};