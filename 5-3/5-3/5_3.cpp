#include<iostream>

class Array {

	const int dim;
	int* size;

	struct Address {
		int level;
		void* next;
	};
	Address* top;

public:
	Array(int dim, int* array_size) :dim(dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++)size[i] = array_size[i];
	}

	void initialize_address(Address* current) {
		
		if (!current)return;
		
		if(current->level==dim-1){
		
			current -> next = new int[size[current->level]];
			return;
		}// 종료 조건

		current->next = new Address[size[current->level]];

		for(int i = 0; i != size[current->level];i++){
			(static_cast<Address*>(current->next) + i) -> level = current->level + 1; //void를 Address 주소로 변경

			initialize_address(static_cast<Address*>(current->next) + i);
		}
	}

	void delete_address(Address* current) {
		if (!current)return;
		for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
			delete_address(static_cast<Address*>(current->next) + 1);
		}
		if (current->level == dim - 1) {
			delete[]static_cast<int*>(current->next);
		}
		delete[]static_cast<Address*>(current->next);
	}

};