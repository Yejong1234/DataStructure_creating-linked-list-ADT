#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

	typedef int element;

	typedef struct ListNode {//노드 구조체 선언
			element data;
			struct ListNode *link;
	
} ListNode;

	typedef struct {
			ListNode *head;// Head pointer
			ListNode *tail;// Tail pointer
			int length;// # of nodes
	
} ListType;


	void init(ListType *list) {//리스트 초기화 함수
			list->head = NULL;
			list->tail = NULL;
			list->length = 0;
	
}

	int is_empty(ListType *list) {
		if (list->head == NULL)//헤드포인터가 비어있으면
					return 1;
		else
					return 0;
	
}//empty인지 알아보는 함수

	int get_length(ListType* list)//길이 리턴 함수
	{
			return list->length;
		}

	ListNode *get_node_at(ListType *list, int pos) {
			int i;
			ListNode *tmp_node = list->head;//tmp_node가 일단 헤드포인터를 가르키도록 한다.
			if (pos < 0)
					return NULL;//패러미터로 받은 인덱스가 0보다 작을 경우
		if (pos > list->length)
					return NULL;
	
				for (i = 0; i < pos; i++) {//원하는 노드에 접근하기 위한 과정
		
						tmp_node = tmp_node->link;
		
	}
			return tmp_node;
	
}

	void add(ListType *list, int position, element data) {//Insert new data at the 'position'
	
			ListNode *p;//임시로 노드 포인터를 담을 것.
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
					list->head = p->link;//맨 앞에것 지우면 뒤의 노드를 헤드로
					free(p);//제거
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
		ListNode *newNode;//새로운 노드
		newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->data = item;

		if (list->head == NULL) {//만약에 아무것도 없는 리스트라면
			list->head = newNode;//head에 새로운 노드값 넣음
			newNode->link = NULL;
			list->tail = newNode;//꼬리도 같은 주소 저장
	}
		else {
			newNode->link = list->head;
			list->head = newNode;
			}
			(list->length)++;//리스트 길이 값 증가
			}

	void add_last(ListType *list, element item) {
		ListNode *newNode;
		newNode = (ListNode*)malloc(sizeof(ListNode));

		newNode->data = item;
		newNode->link = NULL;//새로운 노드의 link에 null 넣음(마지막 노드니까)
	
		list->tail->link = newNode;//기존의 tail주소가 가르키는 마지막 노드 link에 새로운 노드 주소 입력
		list->tail = newNode;//이제 tail은 새로운 노드를 가리킨다.

		(list->length)++;//리스트 길이 값 증가
}

	void delete_first(ListType *list) {
	
		ListNode *removed = list->head;
		list->head = list->head->link;//헤드포인터를 첫번째 노드의 link의 주소로 대체
		free(removed);
		(list->length)--;//리스트 길이 감소
}

	void delete_last(ListType *list) {//맨 마지막의 노드를 지운다.

		ListNode *removed = list->tail;
		ListNode *p = list->head;;//tail전의 노드 주소받기
		while (p->link != list->tail) {//link가 tail이면 tail전의 노드이다!!!!!
			p = p->link;
		
	}
		list->tail = p;//tail에 제거될 전의 노드 주소 저장!!!!
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
