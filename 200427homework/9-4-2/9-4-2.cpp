/* 1952339 ��08 ��ܰ�� */
#include <iostream>
using namespace std;

class student {
private:
    int num;
    float score;
public:
    void display();  //���ѧ�źͳɼ�
    void get(void);  //��������ѧ�źͳɼ�
//���в�����������κ����ݳ�Ա�ͳ�Ա����
};

/* �ڴ˸������Ա����������ʵ�� */

void student::get()
{
    cin >> num >> score;
}

void student::display()
{
    cout << "id: " << num << "   score: " << score << endl;
}

int main()
{
    /* ��ע�⣺�������в������ٶ����κ����͵ı���(����ȫ�ֱ���) */
    student* p, s[5];

    /* ��������5���˵�ѧ�ż��ɼ�
      ��Ҫ�󣺡����������ȷ��������ʾ�����硰�������**����ѧ�źͳɼ��� */
    cout << "�������1����ѧ�źͳɼ�";
    s[0].get();
    cout << "�������2����ѧ�źͳɼ�";
    s[1].get();
    cout << "�������3����ѧ�źͳɼ�";
    s[2].get();
    cout << "�������4����ѧ�źͳɼ�";
    s[3].get();
    cout << "�������5����ѧ�źͳɼ�";
    s[4].get();


      /* �����1��3��5���˵���Ϣ */
    p = s;
    p->display();
    (p + 2)->display();
    (p + 4)->display();

    return 0;
}