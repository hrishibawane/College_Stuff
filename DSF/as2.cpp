#include <iostream>
#include <cstdlib>
using namespace std;

struct Patient
{
    int regno, age;
    string name;
    Patient* next;
};

class Queue
{
public:
    Patient *f, *r;
    Queue(){f=r=NULL;}
    void enqueue(Patient* p);
    void dequeue();
    bool isempty();
};

void Queue :: enqueue(Patient* p)
{
    p->next = NULL;
    if(f==NULL)
    {
        f = r = p;
        return;
    }
    r->next = p;
    r = p;
}

void Queue :: dequeue()
{
    Patient* temp = f;
    if(f==r) r=r->next;
    f=f->next;
    delete temp;
}

bool Queue :: isempty() {return (f==NULL && r==NULL);}

class PQ
{
public:
    Queue q[3];
    void arrival();
    void service();
    void print();
};

void PQ :: arrival()
{
	Patient *p = new Patient;
	int ptype, rn, a;
	//string nm;
	cout<<"Enter reg no: "; cin>>p->regno;
	cout<<"Enter name: "; cin>>p->name;
	cout<<"Enter age: "; cin>>p->age;
	cout<<"Enter patient type(0: serious, 1: medium, 2: general): ";
	cin>>ptype;

	if(ptype<3) q[ptype].enqueue(p);
	else cout<<"Wrong patient type\n";

}

void PQ :: service()
{
	int i=0;
	while(i<3 && q[i].isempty())
		i++;

	if(i<3)
	{
		Patient *p = q[i].f;
		cout<<p->regno<<"\t"<<p->name<<"\t"<<p->age<<endl;
		q[i].dequeue();
	}

}

void PQ :: print()
{
	cout<<"Serious Patients:\n";
	Patient *p = q[0].f;
	while(p!=NULL)
	{
		cout<<p->regno<<"\t"<<p->name<<"\t"<<p->age<<endl;
		p=p->next;
	}

	cout<<"Medium Illness Patients:\n";
	p = q[1].f;
	while(p!=NULL)
	{
		cout<<p->regno<<"\t"<<p->name<<"\t"<<p->age<<endl;
		p=p->next;
	}

	cout<<"General Patients:\n";
	p = q[2].f;
	while(p!=NULL)
	{
		cout<<p->regno<<"\t"<<p->name<<"\t"<<p->age<<endl;
		p=p->next;
	}
}

int main()
{
    PQ pq;
    int ch;
    while(1)
    {
    	cout<<"\n1. Arrival of Patient\n2. Service of Patient\n3. Print\n4. Quit\n";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1: pq.arrival(); break;
    		case 2: pq.service(); break;
    		case 3: pq.print(); break;
    		case 4: return 0;
    	}
    }
}



