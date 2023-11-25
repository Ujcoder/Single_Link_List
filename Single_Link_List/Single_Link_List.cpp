#include<iostream>
using namespace std;

struct node
{
	int info;
	node* link;
};
node* head = 0;

//// All Insert Function
void insert_at_begin(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = 0;
	if (head == 0)
		head = p;
	else
	{
		p->link = head;
		head = p;
	}
	return;
}

void insert_at_end(int x)
{
	node* p = 0, * t;
	p = new node;
	p->info = x;
	p->link = 0;
	if (head == 0)
		head = p;
	else
	{
		t = head;
		while (t->link != 0)
			t = t->link;
		t->link = p;
	}
	return;
}

void insert_at_pos(int pos, int x)
{
	node* p = 0, * q = 0, * t;
	int count = 0;
	if (head == 0)
	{
		cout << "LL is empty !....." << endl;
		return;
	}
	if (pos == 1)
	{
		p = new node;
		p->info = x;
		p->link = 0;
		p->link = head;
		head = p;
	}
	else
	{
		t = head;
		count = 1;
		while (count != pos && t != 0)
		{
			q = t;
			t = t->link;
			count++;
		}
		if (t != 0)
		{
			p = new node;
			p->info = x;
			p->link = 0;
			q->link = p;
			p->link = t;
		}
		else
			cout << "Invalid Position........? " << endl;
	}
	return;
}

// All Delete Function
int delete_at_begin()
{
	node* p;
	int x;
	if (head == 0)
	{
		cout << "LL is empty......! " << endl;
		return -1;
	}
	p = head;
	x = head->info;
	head = head->link;
	delete p;
	return x;
}

int delete_at_end()
{
	node* t, * p = 0;
	int x;
	if (head == 0)
	{
		cout << "LL is empty.......!" << endl;
		return -1;
	}
	if (head->link == 0)
	{
		t = head;
		x = head->info;
		head = 0;
	}
	else
	{
		t = head;
		while (t->link != 0)
		{
			p = t;
			t = t->link;
		}
		p->link = 0;
		x = t->info;
	}
	delete t;
	return x;
}

int delete_at_pos(int pos)
{
	node* q = 0, * t;
	int x, count = 0;
	if (head == 0)
	{
		cout << "LL is empyt............! " << endl;
		return -1;
	}
	if (pos == 1)
	{
		x = head->info;
		t = head;
		head = head->link;
		delete t;
		return x;
	}
	t = head;
	count = 1;
	while (count != pos && t != 0)
	{
		q = t;
		t = t->link;
		count++;
	}
	if (t != 0)
	{
		x = t->info;
		q->link = t->link;
		delete t;
		return x;
	}
	else
	{
		cout << "Invalid Position..........? " << endl;
		return -1;
	}
}

int count()
{
	node* t;
	int count = 0;
	t = head;
	while (t != 0)
	{
		t = t->link;
		count++;
	}
	return count;
}

int search(int x)
{
	node* t;
	int found = 0;
	t = head;
	while (t != 0)
	{
		if (t->info == x)
		{
			found = 1;
			break;
		}
		else
			t = t->link;
	}
	return found;
}

void display()
{
	node* t;
	t = head;
	if (head == 0)
	{
		cout << "LL is empty .......! " << endl;
		return;
	}
	cout << "All Elem in LL is : " << endl;
	while (t != 0)
	{
		cout << t->info << endl;
		t = t->link;
	}
	return;
}


int main()
{
	int ch, v, p1, p2, x;
	do
	{
		cout << " 1.Insert_at_begin 2.Insert_at_end 3.Insert_at_pos " << endl;
		cout << " 4.Delete_at_begin 5.Delete_at_end 6.Delete_at_pos" << endl;
		cout <<" 7.Count\n 8.Search\n 9.Display\n 10.Exit\n" << endl;
		cout << " Enter the choice :  ";  cin >> ch;
		switch (ch)
		{
		case 1: cout << "Enter values to insert_at_begin : " << endl;
			cin >> v;     insert_at_begin(v);      break;
		case 2:cout << "Enter values to Insert_at_end : " << endl;
			cin >> v;      insert_at_end(v);    break;
		case 3:cout << "Enter Pos to insert_at_poition : ";
			cin >> p1;    cout << "Enter value : " << endl;
			cin >> v;     insert_at_pos(p1, v);     break;
		case 4: x = delete_at_begin();
			cout << " Value is Deleted  : "<<x << endl;    break;
		case 5: x = delete_at_end();
			cout << " Value is Deleted  : " << x << endl;    break;
		case 6:cout << "Enter Pos to delete_at_position : ";
			cin >> p2;     x = delete_at_pos(p2);
			cout << " Value is Deleted  : " << x << endl;    break;
		case 7:v = count();
			cout << "Total Elem in LL : " << v << endl;    break;
		case 8:cout << "Enter value to search in LL : " << endl;
			cin >> v;     x = search(v);
			if (x == 1)
				cout << "Element is  found  : " << v << endl;
			else
				cout << "Element not found ........! " << endl;
			break;
		case 9:display();     break;
		default:cout << "Exiting..." << endl;
			ch = 10;
		}
	} while (ch != 10);
}