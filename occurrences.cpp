#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct node {
	int data;
	node* next;
};
class linkedlist {
	node* head;
public:

	linkedlist() {
		head = nullptr;
	}
	bool isempty() {
		return head == nullptr;
	}
	void insert(int pos, int value) { //time = O(n) space =O(1)
		if (pos < 0) {
			cout << "invalid position";
			return;
		}
		node* p2 = head;//بيشاور عند الهيد
		node* p = new node;// عملت نود جديدة
		p->data = value;//اديت النود الجديدة القيمة اللي عايزة اضيفها  
		if (pos == 0) {// لو هضيف ف مكان اول نود

			p->next = head;//خليت النود الجديدة تشاور ع اللي كان بيشاور عليه الهيد
			head = p; // خليت الهيد تشاور ع النود
		}
		else {

			for (int i = 0; i < pos - 1 && p2;++i) { // لو مش هضيف ف اول نود همشي ف لوب لحد م اوصل للبوسيشن اللي عايزه اضيف فيه
				p2 = p2->next;//هحرك البوينتر 
			}
			if (p2) { //  null لو البوينتر مش 
				p->next = p2->next;//هخلي النود ال هضيفها تشاور ع اللي كانت النود اللي قبلها بتشاور عليه 
				p2->next = p;//هخلي النود اللي قبلها تشاور ع النود الجديدة

			}
			else { //null لو البوينتر بيساوي  
				cout << "invalid position";//اليوزر مدخلش بوسيشن صح
				delete p;//هنمسح البوينتر
				return;
			}
		}
	}
	void implement() { //time = O(n) space=O(1)
		node* p = head;
		while (p != nullptr) {//هلف ع الليست لحد م اوصل لاخر نود
			cout << p->data << " ";//هطبع الداتا
			p = p->next;//هحرك البوينتر
		}
		cout << "\n";
	}
	void occurrences(int element) { //time=O(n) space=O(1)
		node* p = head;
		node* d = nullptr;
		while (p != nullptr) {//هتشك لو وصلت لاخر نود
			if (p->data == element) {// لو الايليمنت بيساوي الداتا اللي ف النود
				if (d == nullptr) {//لو الايليمنت بيساوي الداتا بتاعت اول نود
					head = head->next;//هحرك الهيد
					delete p;//همسح البوينتر اللي كان بيشاور ع الهيد القديمة
					p = head;//هخلي البوينتر يشاور ع الهيد الجديدة
				}
				else {//مش اول نود
					d->next = p->next;//هخلي الديتشاور ع اللي كان بيشاور عليه البوينتر نفس فكرة الديليت
					delete  p;//همسح البوينتر
					p = d->next;//هخلي يشاور ع اللي بتشاور عليه الدي
				}
			}
			else {//لو الداتا اللي ف النود مش بتساوي الايليمنت هكمل حركة بقا عادي
				d = p;
				p = p->next;
			}
		}
	}
};

int main() {
	linkedlist* ob = new linkedlist;
	ob->insert(0, 4);
	ob->insert(1, 1);
	ob->insert(2, 2);
	ob->insert(3, 3);
	ob->insert(4, 1);
	ob->insert(5, 4);
	ob->insert(6, 4);
	ob->insert(7, 5);
	ob->insert(8, 4);
	ob->implement();
	ob->occurrences(4);
	ob->implement();


}
