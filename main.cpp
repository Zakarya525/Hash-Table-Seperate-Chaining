#include <iostream>
using namespace::std;

class Item{
	public:
		int data;
		int key;
		Item* next;
	
		Item(int data){
			this->data = data;
			next = NULL;
		}
		
		int getData(){
			return data;
		}
};

class List{
	public:
		Item* head;
		
		List(){
			head = NULL;
		}
	
		void insertFirst(Item* i){
			if(head == NULL){
				head = i;
			}
			else{
				i->next = head;
				head = i;
			}
		}
		
		Item* search(int key){
			if(head == NULL){
				return NULL;
			}
			Item* current = head;
			while(current != NULL){
				
				if(current->data == key){
					return current;
				}
				
				current = current->next;
			}
			return NULL;
		}
		
		void deleteItem(int key){
			if(head == NULL){
				return;
			}
			
			Item* current = head;
			Item* previous = head;
			while(current->next != NULL and current->key != key){
				cout<<current->data<<" ";
				previous = current;
				current = current->next;
			
			}
			if(current == NULL){
				cout<<"Data not found"<<endl;
				return;
			}
			previous->next = current->next;
			cout<<"Item with key "<<current->key<<" has been deleted."<<endl;
			delete current;
		}
};

class HashTable{
	List* hashArray[10];
	
	public:
		HashTable(){
			for(int i = 0; i < 10; i++){
				hashArray[i] = new List();
			}
		}
		
		int hashFunction(int data){
			return data % 10;
		}
		
		void insert(Item* i){
			
			int hashValue = hashFunction(i->data);
			
			hashArray[hashValue]->insertFirst(i);
			
			cout<<i->data<<" inserted at index "<<hashValue<<endl;
		}
		
		void search(int key){
			
			int hashValue = hashFunction(key);
			
			Item* s = hashArray[hashValue]->search(key);
			
			
			if(s){
				cout<<"Found "<<s->data<<endl;
				return;
			}
			else{
				cout<<"Not found";
			}
		}
		
		void deleteData(int key){
			
			int hashValue = hashFunction(key);
			
			Item* s = hashArray[hashValue]->search(key);
			
		
			if(s){
				hashArray[hashValue]->deleteItem(key);
				return;
			}
			else{
				cout<<"Not found";
			}
		}
};

int main(int argc, char** argv) {
	HashTable* table = new HashTable();
	
	table->insert(new Item(34));
	table->insert(new Item(33));
	table->insert(new Item(31));
	table->insert(new Item(64));
	table->insert(new Item(12));
	table->insert(new Item(123));
	table->insert(new Item(1432));
	table->insert(new Item(141));
	
	table->search(34);
	
	table->deleteData(64);
	
	return 0;
}
