#include "linked_list.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
linked_list <int> a(5);
a.set_data(0,3);
a.sort();
a.push_at(10, 100);
a.pop_at(0);
a.print_list();





return 0;
}