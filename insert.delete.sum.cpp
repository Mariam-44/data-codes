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
	void del(int pos) { //time= O(n) space = O(1)
		if (isempty()) {
			cout << "nothing to delete";
			return;
		}
		if (pos < 0) {
			cout << "invalid position";
		}
		node* p = head;//بوينتر عند الهيد 
		if (pos == 0) {//لو همسح اول نود
			head = head->next;//الهيد هتبدأ ع النود اللي كانت بتشاور عليها
			delete p;//هنمسح البوينتر اللي عند الهيد القديمة عشان تتمسح
		}
		else {
			node* d = nullptr;
			for (int i = 0; i < pos && p;++i) {//لو مش هضيف ف اول مكان همشي ف لوب لحد م اوصل للبوسيشن
				d = p; //هخلي الدي تشاور تقف ف المكان اللي كان فيه البوينتر
				p = p->next;//هحرك البوينتر 
			}
			if (p != nullptr) {//لو البوسيشن صحيح
				d->next = p->next;//  هخلي الدي تشاور ع اللي كان بيشاور عليه البويننتر->النود اللي بعد النود اللي عايزة امسحها
				delete p;//همسح البوينتر اللي واقف ع النود اللي عايزة امسحها 
			}
			else
				cout << "invalid position";

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
	int sum(node* t) { //time=O(n) space=O(n)
		if (t == nullptr)//هتشك لو وصلت لاخر نود
			return 0;
		return t->data + sum(t->next);//هحط الداتا بتاعت النود وهنده ع الفانكشن بعد م حركت البوينتر للنود اللي بعدها
	}
	node* gethead() {
		return head;
	}
	
};

int main() {
	linkedlist* ob = new linkedlist;
	cout << "before inserting new nodes\n";
	ob->insert(0, 35);
	ob->insert(1, 45);
	ob->insert(2, 65);
	ob->insert(3, 75);
	ob->implement();
	cout << "after inserting new nodes\n";
	ob->insert(0, 25);
	ob->insert(3, 55);
	ob->implement();
	cout << "after deleting two nodes \n";
	ob->del(0);
	ob->del(4);
	ob->implement();
	cout << "sum = " << ob->sum(ob->gethead());
	
}
