#include<iostream>
using namespace std;

/**
* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	//自底向上归并排序
	ListNode* sortList(ListNode* head) {
		int length = 0;
		ListNode* node = head;
		while (node){
			length++;
			node = node->next;
		}
		if (length<2) return head;
		ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
				cout << "strat:" << endl;
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
	}
	//合并2个有序链表
	ListNode* merge(ListNode* l1, ListNode* l2){
		print(l1);
		print(l2);
		ListNode* head = new ListNode();
		ListNode* cur = head;
		while (l1 != nullptr && l2 != nullptr){
			if (l2->val < l1->val) cur->next = l2, l2 = l2->next;
			else cur->next = l1, l1 = l1->next;
			cur = cur->next;
		}
		if (l1 != nullptr) cur->next = l1;
		else cur->next = l2;
		return head->next;
	}
	void print(ListNode* head)
	{
		while (head)
		{
			if (head->next == NULL)
				cout << head->val << "-> NULL";
			else
				cout << head->val << "-> ";
			head = head->next;
		}
		cout << endl;
	}
};

ListNode* create(int n)
{
	auto dummy = new ListNode(0);
	auto pre = dummy;
	for (int i = 0; i < n; i++)
	{
		auto p = new ListNode(0);
		cin >> p->val;
		pre->next = p;
		pre = pre->next;
	}
	return dummy->next;
}
void print(ListNode* head)
{
	while (head)
	{
		if (head->next == NULL)
			cout << head->val << "-> NULL";
		else
			cout << head->val << "-> ";
		head = head->next;
	}
	cout << endl;
}

int main(){
	Solution S;
	ListNode* head = create(4);
	print(head);
	head = S.sortList(head);
	print(head);
	system("pause");
	return 0;
}
