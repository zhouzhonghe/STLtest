#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>

using namespace std;

# define CEHUA 0
# define MEISHU 1
# define YANFA 2

class Worker
{
public:
	string name;
	int salary;
};

void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = "Ա��";
		worker.name += nameSeed[i];

		worker.salary = rand() % 10000 + 10000;//10000~19999
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����������ű��
		int deptID = rand() % 3 ;
		//��Ա�����������
		m.insert(make_pair(deptID, *it));
	}
}
void showWorkerByGourp(multimap<int, Worker>& m)
{
	cout << "�߻�����:" << endl;
	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int count0 = m.count(CEHUA);
	multimap<int, Worker>::iterator pos1 = m.find(MEISHU);
	int count1 = m.count(MEISHU);
	multimap<int, Worker>::iterator pos2 = m.find(YANFA);
	int count2 = m.count(YANFA);
	for (int index = 0;pos != m.end() && index < count0; pos++, index++)
	{
		cout << "������ " << pos->second.name << "\t���ʣ� " << pos->second.salary << endl;
	}
	cout << "---------------------" << endl;
	cout << "�������ţ�" << endl;
	for (int index = 0; pos != m.end() && index < count0; pos++, index++)
	{
		cout << "������ " << pos->second.name << "\t���ʣ� " << pos->second.salary << endl;
	}
	cout << "---------------------" << endl;
	cout << "�з����ţ�" << endl;
	for (int index = 0; pos != m.end() && index < count0; pos++, index++)
	{
		cout << "������ " << pos->second.name << "\t���ʣ� " << pos->second.salary << endl;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	//1.����Ա��
	vector<Worker>workers;
	creatWorker(workers);


	//2.Ա������
	multimap<int, Worker>mWorkers;
	setGroup(workers, mWorkers);
	showWorkerByGourp(mWorkers);
	/*for (vector<Worker>::iterator it = workers.begin(); it != workers.end(); it++)
	{
		cout << it->name << "\t" << it->salary << endl;
	}*/
	return 0;

}