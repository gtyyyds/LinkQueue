#include<iostream>//输入输出流
typedef int DataType;//给int起别名
using namespace std;//标准命名空间
class Node//节点类
{
public://公共权限
	friend class LinkQueue;//链式队列类作节点类的友元
	Node() {}//无参构造函数
	Node(DataType& data)//有参构造函数
	{
		this->data = data;//给属性赋值
		this->next = NULL;
	}
	~Node() {}//析构函数
private://私有权限
	DataType data;//数据域
	Node* next;//指针域
};
class LinkQueue//链式队列类
{
public://公共权限
	LinkQueue()//无参构造
	{
		this->initLinkQueue();
	}
	~LinkQueue() {};//析构函数
	bool initLinkQueue();//链队列初始化
	bool push(DataType& data);//入队
	bool pop(DataType& data);//出队
	void printLinkQueue();//遍历链队
	int lengthQueue();//链队大小
private:
	Node* front;//头指针
	Node* rear;//尾指针
};
bool LinkQueue::initLinkQueue()//初始化
{
	this->front = this->rear = new Node;//创建一个新的节点，并且把新节点的地址赋给头指针和尾指针
	if (this->rear == NULL)//判断申请有没有成功
	{
		return false;//失败
	}
	this->front->next = NULL;//把头指针和尾指针，指向新节点的指针域滞空
	return true;//成功
}
bool LinkQueue::push(DataType& data)
{
	Node* p = new Node(data);//有参构造一个新节点,并且把新地址返给p
	if (p == NULL)//判断申请是否成功
	{
		return false;//失败
	}
	p->next = NULL;//新节点的指针域为NULL，因为新节点前面没有节点
	this->rear->next = p;//原理尾节点的next指向新地址，保证front可以迭代
	this->rear = p;//更新尾节点

}
bool LinkQueue::pop(DataType& data)//出队
{
	if (this->front == this->rear)//如果队列为空，直接退出
	{
		return false;//失败
	}
	Node* p = this->front->next;//保存原来头节点指向的节点，防止后面内存释放找不到
	data = p->data;//保存要删除的数据
	this->front->next = p->next;//迭代
	if (this->rear == p)//如果删除的是最后一个节点
	{
		this->rear = this->front;//头指针和尾指针相等
	}
	delete p;//释放
	return true;
}
void LinkQueue::printLinkQueue()
{
	Node* p = this->front;//让p代替front迭代
	while (p != this->rear)//如果头指针不等于尾指针
	{
		p = p->next;//因为p是一个节点，其next指的是头节点，所以要先迭代
		cout << p->data << " ";//输出节点数据
	}
	cout << endl;//换行
}
int LinkQueue::lengthQueue()
{
	Node* p = this->front;//让p代替front迭代
	int i = 0;
	while (p != this->rear)//如果头指针不等于尾指针
	{
		i++;//计数
		p = p->next;
	}
	return i;
}
void showMenu()//菜单，方便用户操作
{
	cout << "  *****************" << endl;
	cout << "  *  链 式 队 列  *" << endl;
	cout << "  *  1、初始化    *" << endl;
	cout << "  *  2、入  栈    *" << endl;
	cout << "  *  3、出  栈    *" << endl;
	cout << "  *  4、遍  历    *" << endl;
	cout << "  *  5、长  度    *" << endl;
	cout << "  *  0、退  出    *" << endl;
	cout << "  *****************" << endl;
	cout << "请输入您的选项:";
}
int main()
{
	LinkQueue lq;
	int select;//存储用户选择
	while (true)
	{
		showMenu();//菜单
		cin >> select;
		switch (select)
		{
		case 1:
		{
			if (lq.initLinkQueue())
			{
				cout << "初始化成功！" << endl;
			}
			else
			{
				cout << "初始化失败！" << endl;
			}
			system("pause");//停顿
			system("cls");//清屏
		}
			break;
		case 2:
		{
			cout << "你想入栈哪个数据?" << endl;
			DataType data;
			cin >> data;
			if (lq.push(data))
			{
				cout << data << "入栈成功!" << endl;
			}
			else
			{
				cout << "入栈失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			DataType data;
			if (lq.pop(data))
			{
				cout << data << "已出栈！" << endl;
			}
			else
			{
				cout << "出栈失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			lq.printLinkQueue();
			system("pause");
			system("cls");
		}
			break;
		case 5:
		{
			cout << "链式队列的长度：" << lq.lengthQueue() << endl;
			system("pause");
			system("cls");
		}
			break;
		default:
		{
			system("pause");
			return 0;
		}
			break;
		}
	}
}