#ifndef NODE_HPP
#define NODE_HPP
#include <cstddef>

using namespace std;
    template <typename t> class node{
    private:
        t data;
        node *next;
        node *last;
	public:

		void set_next(node &new_next){
			this->next = &new_next;
		}

		void set_last(node &new_last){
			this->last = &new_last;
		}

		node(){
			this-> next = NULL;
			this-> last = NULL;
		}

		node* get_next(){
			node* temp_next = next;
			return temp_next;
		}

		node* get_last(){
			node* temp_last = last;
			return temp_last;
		}

		t get_data(){
			t temp_data = this->data;
			return temp_data;
		}

		void set_data(t data){
			this->data = data;
		}

};





#endif //NODE_HPP
