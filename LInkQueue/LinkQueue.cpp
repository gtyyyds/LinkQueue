#include<iostream>//���������
typedef int DataType;//��int�����
using namespace std;//��׼�����ռ�
class Node//�ڵ���
{
public://����Ȩ��
	friend class LinkQueue;//��ʽ���������ڵ������Ԫ
	Node() {}//�޲ι��캯��
	Node(DataType& data)//�вι��캯��
	{
		this->data = data;//�����Ը�ֵ
		this->next = NULL;
	}
	~Node() {}//��������
private://˽��Ȩ��
	DataType data;//������
	Node* next;//ָ����
};
class LinkQueue//��ʽ������
{
public://����Ȩ��
	LinkQueue()//�޲ι���
	{
		this->initLinkQueue();
	}
	~LinkQueue() {};//��������
	bool initLinkQueue();//�����г�ʼ��
	bool push(DataType& data);//���
	bool pop(DataType& data);//����
	void printLinkQueue();//��������
	int lengthQueue();//���Ӵ�С
private:
	Node* front;//ͷָ��
	Node* rear;//βָ��
};
bool LinkQueue::initLinkQueue()//��ʼ��
{
	this->front = this->rear = new Node;//����һ���µĽڵ㣬���Ұ��½ڵ�ĵ�ַ����ͷָ���βָ��
	if (this->rear == NULL)//�ж�������û�гɹ�
	{
		return false;//ʧ��
	}
	this->front->next = NULL;//��ͷָ���βָ�룬ָ���½ڵ��ָ�����Ϳ�
	return true;//�ɹ�
}
bool LinkQueue::push(DataType& data)
{
	Node* p = new Node(data);//�вι���һ���½ڵ�,���Ұ��µ�ַ����p
	if (p == NULL)//�ж������Ƿ�ɹ�
	{
		return false;//ʧ��
	}
	p->next = NULL;//�½ڵ��ָ����ΪNULL����Ϊ�½ڵ�ǰ��û�нڵ�
	this->rear->next = p;//ԭ��β�ڵ��nextָ���µ�ַ����֤front���Ե���
	this->rear = p;//����β�ڵ�

}
bool LinkQueue::pop(DataType& data)//����
{
	if (this->front == this->rear)//�������Ϊ�գ�ֱ���˳�
	{
		return false;//ʧ��
	}
	Node* p = this->front->next;//����ԭ��ͷ�ڵ�ָ��Ľڵ㣬��ֹ�����ڴ��ͷ��Ҳ���
	data = p->data;//����Ҫɾ��������
	this->front->next = p->next;//����
	if (this->rear == p)//���ɾ���������һ���ڵ�
	{
		this->rear = this->front;//ͷָ���βָ�����
	}
	delete p;//�ͷ�
	return true;
}
void LinkQueue::printLinkQueue()
{
	Node* p = this->front;//��p����front����
	while (p != this->rear)//���ͷָ�벻����βָ��
	{
		p = p->next;//��Ϊp��һ���ڵ㣬��nextָ����ͷ�ڵ㣬����Ҫ�ȵ���
		cout << p->data << " ";//����ڵ�����
	}
	cout << endl;//����
}
int LinkQueue::lengthQueue()
{
	Node* p = this->front;//��p����front����
	int i = 0;
	while (p != this->rear)//���ͷָ�벻����βָ��
	{
		i++;//����
		p = p->next;
	}
	return i;
}
void showMenu()//�˵��������û�����
{
	cout << "  *****************" << endl;
	cout << "  *  �� ʽ �� ��  *" << endl;
	cout << "  *  1����ʼ��    *" << endl;
	cout << "  *  2����  ջ    *" << endl;
	cout << "  *  3����  ջ    *" << endl;
	cout << "  *  4����  ��    *" << endl;
	cout << "  *  5����  ��    *" << endl;
	cout << "  *  0����  ��    *" << endl;
	cout << "  *****************" << endl;
	cout << "����������ѡ��:";
}
int main()
{
	LinkQueue lq;
	int select;//�洢�û�ѡ��
	while (true)
	{
		showMenu();//�˵�
		cin >> select;
		switch (select)
		{
		case 1:
		{
			if (lq.initLinkQueue())
			{
				cout << "��ʼ���ɹ���" << endl;
			}
			else
			{
				cout << "��ʼ��ʧ�ܣ�" << endl;
			}
			system("pause");//ͣ��
			system("cls");//����
		}
			break;
		case 2:
		{
			cout << "������ջ�ĸ�����?" << endl;
			DataType data;
			cin >> data;
			if (lq.push(data))
			{
				cout << data << "��ջ�ɹ�!" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
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
				cout << data << "�ѳ�ջ��" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
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
			cout << "��ʽ���еĳ��ȣ�" << lq.lengthQueue() << endl;
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