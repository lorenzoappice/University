#include <iostream>
#include "Linked_list.h"

using namespace std;

int main()
{

	Linked_list<int> l1;
	l1.inserimento(4,(l1.size()));
	l1.inserimento(6,(l1.size()));
	l1.inserimento(2,(l1.size()));
	l1.inserimento(3,(l1.size()));
	l1.inserimento(7,(l1.size()));
	l1.inserimento(2,l1.begin());
	l1.inserimento(72,1);
	l1.inserimento(9,(l1.size()));
	l1.inserimento(3,(l1.size()));
	l1.inserimento(11,(l1.size()));
	l1.inserimento(3,(l1.size()));
	l1.inserimento(12,(l1.size()));
	l1.inserimento(8,l1.begin());
	l1.inserimento(15,l1.begin());
	l1.inserimento(8,l1.size());
	l1.inserimento(2,l1.size());
	l1.inserimento(5,l1.size());
	l1.inserimento(6,l1.size());
	l1.inserimento(3,l1.size());

	cout << l1;
	cout <<endl<<"Grandezza lista: "<<l1.size()<<endl;
	cout <<endl<<"elimina elemento: "<<l1.lettura(4)<<endl;
	l1.eliminazione(15);
	cout <<endl<< l1<<endl;
	cout <<"Grandezza lista dopo eliminazione elemento: " <<l1.size()<<endl;
	l1.print();
	return 0;

}
