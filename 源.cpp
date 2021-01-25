/*
* 项目:链循环的建立于基本操作
* 创作时间 2020/12/10
* 学习目标:创建队列，读取队首元素，弹出队首元素，清空队列，销毁队列，读取队尾元素
* 作者:鲁永庆
* front始终指向头节点，rear始终指向队尾元素
*/
#include"iostream"
#include"cstdlib"
#include"string"
#include<queue>
using namespace std;
typedef struct que
{
	int data;
	que* next;
}qnode,*qnode1;
typedef struct
{
	qnode1 front;
	qnode1 rear;
}linkq;
void push(linkq* Q);
void creatl(linkq* Q);
bool pop(linkq* Q);
int get(linkq* Q);
int get_rear(linkq* Q);
void clear(linkq* Q);
int main()
{
	linkq* Q=new linkq;
	creatl(Q);
	for (int i = 1; i <= 3; i++)
	{	
		push(Q);
	}
	clear(Q);
		int x;
		x = get(Q);
		cout << x << ends;
		//pop(Q);
}
void creatl(linkq* Q)
{
	Q->front = Q->rear = new qnode;
	Q->front->next =Q->front;
}
void push(linkq* Q)
{
	int x;
	cout << "请输入入队元素\n";
	cin >> x;
	qnode1 p = new qnode;
	p->data = x;
	p->next = Q->front;
	Q->rear->next = p;
	Q->rear = p;
}
int get(linkq* Q)
{
	if (Q->front->next == Q->front)
	{
		cout << "该链表为空\n";
		return 0;
	}
	int p;
	p=Q->front->next->data;
	return p;
}
bool pop(linkq* Q)
{
	if (Q->front->next == Q->front)
		return false;
	qnode1 p;
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	delete p;
	return true;
}
int get_rear(linkq* Q)
{
	int p;
	p = Q->rear->data;
	return p;
}
void clear(linkq* Q)
{
	qnode1 p, q;
	p = Q->front->next;
	while(p!=Q->front)
	{
		q = p;
		p = p->next;
		delete q;
	}
	Q->rear = Q->front;
	Q->front->next = Q->front;
}
bool destory_l(linkq* Q)
{
	qnode1 p, q;
	p = Q->front->next;
	while (p != Q->front)
	{
		q = p;
		p = p->next;
		delete q;
	}
	delete p;
	return true;
}
bool empty_Q(linkq* Q)
{
	if (Q->front->next == Q->front)
		return true;
	else
		return false;
}


