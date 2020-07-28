#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void append(ListNode *&l, int v) {

	if(l == NULL) {
		//if the listnode is null create first entry.
		l = new ListNode(v);

	} else {
		//if the list node is not null, append entry to end.
		ListNode *toAdd = new ListNode(v);
		ListNode *current = l;

		while(current->next != NULL) {
			current = current->next;
		}

		current->next = toAdd;
	
	}

}

int length(ListNode *l) {
	int length = 0;

	while(l->next != NULL) {
		l = l->next;
		length++;
	}

	return ++length;
}

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *sol = NULL;

	int l = (length(l1) <= length(l2)) ? length(l1) : length(l2);
	int ll1 = length(l1);
	int ll2 = length(l2);

	bool remainder = false;

	for(int i = 0; i < l; i++) {
		int sum = l1->val + l2->val;

		l1 = l1->next;
		l2 = l2->next;

		if(remainder) {
			sum++;
			remainder = !(remainder);
		}

		if(sum >= 10) {
			sum = sum - 10;
			remainder = !(remainder);
		}

		append(sol, sum);

	}

	//if the lengths off linked lists is uneven
	if(ll1 != ll2) {
		if(ll1 > ll2) {
			int remaining = ll1 - ll2;
			for(int i = 0; i < remaining; i++) {
				int sum = l1->val;
				l1 = l1->next;
				
				if(remainder) {
					sum++;
					remainder = !(remainder);
				}

				if(sum >= 10) {
					sum = sum - 10;
					remainder = !(remainder);
				} 

				append(sol, sum);

			}
		
		} else {
			int remaining = ll2 - ll1;
			for(int i = 0; i < remaining; i++) {
				int sum = l2->val;
				l2 = l2->next;

				if(remainder) {
					sum++;
					remainder = !(remainder);
				}

				if(sum >= 10) {
					sum = sum - 10;
					remainder = !(remainder);
				} 

				append(sol, sum);
			}
		}
	}
	
	//if there is a remainder after the final operation
	if(remainder) {
		append(sol, 1);
	}

	return sol;
}

void print_node(ListNode *l) {

	std::cout << "(";	

	while(l->next != NULL) {
		std::cout << l->val << " --> ";
		l = l->next;
	}

	std::cout << l->val << ")";
	
}


int main(int argc, char **argv)
{
	// start the list nodes
	ListNode *l1 = NULL, *l2 = NULL, *sol = NULL;

	// add all values to first linked list
	append(l1, 9);
	append(l1, 1);
	append(l1, 6);
	
	// add all values to second list
	append(l2, 0);
//	append(l2, 6);
//	append(l2, 4);
	
	// print first part of equation.
	print_node(l1);
	std::cout << " + ";
	print_node(l2);
	std::cout << " = ";

	// solve
	sol = addTwoNumbers(l1, l2);

	//print solution
	print_node(sol);
	std::cout << "\n";

	return 0;
}
