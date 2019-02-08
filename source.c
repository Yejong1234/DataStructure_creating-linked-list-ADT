#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

	typedef int element;

	typedef struct ListNode {//��� ����ü ����
			element data;
			struct ListNode *link;
	
} ListNode;

	typedef struct {
			ListNode *head;// Head pointer
			ListNode *tail;// Tail pointer
			int length;// # of nodes
	
} ListType;


	void init(ListType *list) {//����Ʈ �ʱ�ȭ �Լ�
			list->head = NULL;
			list->tail = NULL;
			list->length = 0;
	
}

	int is_empty(ListType *list) {
		if (list->head == NULL)//��������Ͱ� ���������
					return 1;
		else
					return 0;
	
}//empty���� �˾ƺ��� �Լ�

	int get_length(ListType* list)//���� ���� �Լ�
	{
			return list->length;
		}

	ListNode *get_node_at(ListType *list, int pos) {
			int i;
			ListNode *tmp_node = list->head;//tmp_node�� �ϴ� ��������͸� ����Ű���� �Ѵ�.
			if (pos < 0)
					return NULL;//�з����ͷ� ���� �ε����� 0���� ���� ���
		if (pos > list->length)
					return NULL;
	
				for (i = 0; i < pos; i++) {//���ϴ� ��忡 �����ϱ� ���� ����
		
						tmp_node = tmp_node->link;
		
	}
			return tmp_node;
	
}

	void add(ListType *list, int position, element data) {//Insert new data at the 'position'
	
			ListNode *p;//�ӽ÷� ��� �����͸� ���� ��.
			p = (ListNode*)malloc(sizeof(ListNode));
			p->data = data;
	
				int i;
	
				ListNode *ori_head = list->head;
	
				if (position == 1) {
					p->link = ori_head;
					list->head = p;
					return;
		
	}
		for (int i = 1; i < position - 1; i++) {
					ori_head = ori_head->link;
		
	}
		p->link = ori_head->link;
			ori_head->link = p;
	
}
	void delete(ListType *list, int pos) {
			int i;
			if (list->head == NULL)
				return;
	
			ListNode *p = list->head;
	
				if (pos == 0) {
					list->head = p->link;//�� �տ��� ����� ���� ��带 ����
					free(p);//����
					return;
		
	}
	
				else {
					for (i = 1; i < pos - 1; i++) {
							p = p->link;
			
		}
		
	}
			ListNode *next_p = p->link->link;
			free(p->link);
			p->link = next_p;
	
}

	element get_entry(ListType *list, int pos) {
			ListNode *p = list->head;
			int i;
			if (pos == 0)
					return(p->data);
			else {
				for (i = 0; i < pos; i++) {
					p = p->link;
			
		}
				return (p->data);
		
	}
	
}

	void display(ListType *list) {
		ListNode *p = list->head;
		while (p != NULL) {
			printf("%d ", p->data);
			p = p->link;
		
	}
	
}

	int is_in_list(ListType *list, element item) {
		ListNode *p;
		p = list->head;
		while ((p != NULL)) {
			if (p->data == item)
				break;
				p = p->link;
	}
		if (p == NULL)
			return TRUE;
			else
			return FALSE;
}

	void add_first(ListType *list, element item) {
		ListNode *newNode;//���ο� ���
		newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->data = item;

		if (list->head == NULL) {//���࿡ �ƹ��͵� ���� ����Ʈ���
			list->head = newNode;//head�� ���ο� ��尪 ����
			newNode->link = NULL;
			list->tail = newNode;//������ ���� �ּ� ����
	}
		else {
			newNode->link = list->head;
			list->head = newNode;
			}
			(list->length)++;//����Ʈ ���� �� ����
			}

	void add_last(ListType *list, element item) {
		ListNode *newNode;
		newNode = (ListNode*)malloc(sizeof(ListNode));

		newNode->data = item;
		newNode->link = NULL;//���ο� ����� link�� null ����(������ ���ϱ�)
	
		list->tail->link = newNode;//������ tail�ּҰ� ����Ű�� ������ ��� link�� ���ο� ��� �ּ� �Է�
		list->tail = newNode;//���� tail�� ���ο� ��带 ����Ų��.

		(list->length)++;//����Ʈ ���� �� ����
}

	void delete_first(ListType *list) {
	
		ListNode *removed = list->head;
		list->head = list->head->link;//��������͸� ù��° ����� link�� �ּҷ� ��ü
		free(removed);
		(list->length)--;//����Ʈ ���� ����
}

	void delete_last(ListType *list) {//�� �������� ��带 �����.

		ListNode *removed = list->tail;
		ListNode *p = list->head;;//tail���� ��� �ּҹޱ�
		while (p->link != list->tail) {//link�� tail�̸� tail���� ����̴�!!!!!
			p = p->link;
		
	}
		list->tail = p;//tail�� ���ŵ� ���� ��� �ּ� ����!!!!
		free(removed);
		p->link = NULL;

		(list->length)--;
	
}

	int main(void)
	{
		ListType list1;
		init(&list1);
		add_first(&list1, 20);
		add_last(&list1, 30);
		add_first(&list1, 10);
		add_last(&list1, 40);
		add(&list1, 2, 70);
		display(&list1);
	
		printf("\n");
	
		delete(&list1, 2);
		delete_first(&list1);
		delete_last(&list1);
		display(&list1);

		printf("\n%s\n", is_in_list(&list1, 20) == 0 ? "TRUE" : "FALSE");
		printf("%d\n", get_entry(&list1, 0));
		
		return 0;
		}
