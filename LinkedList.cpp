#include <iostream>

using std::cout;

class Link
{
  public:
	Link(Link* next, int data):_next(next),_data(data){};
	~Link(){};
	Link * Next(){return _next;};
	int get_data();
  private:
	int _data;
	Link* _next;
};


class List
{
  public:
	List():_head(NULL){};
	~List();
	void add(int data);
	void display();
	Link const * get_head() const {return _head;};
  private:
	Link* _head;
};


void List::add(int data)
{
  Link* temp = new Link(_head,data);
  _head = temp;
}

List::~List()
{
  Link* temp;
  //temp = _head;
  while(_head!=NULL)
  {
  	temp = _head;
	_head = temp->Next();
	delete temp;
	temp = NULL;
  }
}

int Link::get_data()
{
  return _data;
}

void List::display()
{
  Link* temp=NULL;
  temp = _head;
  while(temp != NULL)
  {
  	//temp = _head;
	cout << temp->get_data();
	temp = temp->Next();
	//delete temp;
	//temp = NULL;
  }

}

int main()
{
  List l;
  l.add(10);
  l.add(20);
  l.add(30);
  l.display();
  return 0;
}
