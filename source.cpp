#include <iostream>
#include <string>
using namespace std;

const int MAXLENGTH = 6;
int key=-1;

struct Data{
	int id;
	string name;
};

struct Queue{
	Data elements[7];
	int front;
	int rear;
};

void MAKENULL(Queue &_init){
	_init.front = 0;
	_init.rear = MAXLENGTH;
}

int addone(int i){
	if(i==MAXLENGTH){
		return 0;
	}
	return (i+1 % MAXLENGTH);
}

bool isEmpty(Queue Q){
	return addone(Q.rear) == Q.front;
}

void Enqueue(Queue &Q, Data data){
	if (addone(addone(Q.rear)) == Q.front) {
		cout<<"\nQueue is Full!\n";
		return;
	}
	
	Q.rear = addone(Q.rear);
	Q.elements[Q.rear] = data;
}

void Dequeue(Queue &Q){
	if (isEmpty(Q))
		return;
	Q.front = addone(Q.front);
}

Data getFirst(Queue Q){
	return Q.elements[Q.front];
}

void printQ(Queue Q){
	if(isEmpty(Q)){
		return;
	}
	cout<<"No.:\t-----\tName:\n";
	while(!isEmpty(Q)){
		Data first = getFirst(Q);
		Dequeue(Q);
		cout<<" "<<first.id<<"\t-----\t"<<first.name<<"\n";
	}
}

Data setData(){
	key++;
	Data d;
	cout<<"Enter Name: ";
	cin>> d.name;
	d.id = key;
	return d;
}

void main(){
	Queue Q;
	MAKENULL(Q);
	char CMD;
	cout<<"-------------\nJUST A QUEUE\n";
	do{
		cout<<"\n1-Enqueue\n2-Dequeue\n3-Print\n4-ANY OTHER INPUT TO EXIT\n";
		cout<<"Command:"; cin>>CMD;
		switch(CMD){
		case '1':
			Enqueue(Q,setData());
			break;
		case '2':
			if(isEmpty(Q)){
				cout<<"\nQueue is Empty!\n";
				break;
			}
			Dequeue(Q);
			break;
		case '3':
			if(isEmpty(Q)){
				cout<<"\nQueue is Empty!\n";
				break;
			}
			printQ(Q);
			break;
		}
	}while(CMD=='1'||CMD=='2'||CMD=='3');
}