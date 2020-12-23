/* 1952339 ��08 ��ܰ�� */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
/* �������Ҫ���˴��������ͷ�ļ� */

using namespace std;

/* �����峣����/�궨�壬����������ȫ�ֱ��� */
const int num_all = 13*4+2;
const int num_kind = 13;
const int num_base = 17;
const char poke[] = {'J', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const char clr[] = {3, 4, 5, 6};
/* ��������Լ���Ҫ�ĺ��� */

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡĳ����ҵ�������Ϣ������ǵ���������ӱ��
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int print(const char* prompt, const bool landlord, const unsigned long long player)
{
    /* ֻ�����岻���������������͵ļ򵥱��������ܶ�������������ṹ�塢string�� */
    cout << prompt;
    if (1ll & player)
        cout << "RJ ";
    if ((1ll << (num_all - 1)) & player)
        cout << "BJ ";
    for (int i = 1; i < num_all-1; ++i)
        if (player & (1ll << i)){
           if(i%num_kind == 0)
               cout << clr[i / num_kind-1] << poke[13] << ' ';
            else
               cout << clr[i / num_kind] << poke[i % num_kind] << ' ';
        }
    if (landlord)
        cout << "(����)";
    putchar(10);
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int deal(unsigned long long* player)
{
    /* ֻ�����岻����ʮ���������͵ļ򵥱��������ܶ�������������ṹ�塢string�� */
    srand((unsigned int)time(0));
    unsigned long long POKE = 0ull;
    for (int i = 1; i <= num_base; ++i) {
        for (int j = 0; j < 3; ++j) {
            int t = rand() % num_all;
            while (POKE & (1ll << t)) {
                t = rand() % num_all;
            }
            player[j] |= (1ll << t);
            POKE |= (1ll << t);
        }
        cout << dec << "��" << i << "�ֽ���\n";
        print("�׵��ƣ�", 0, player[0]);
        print("�ҵ��ƣ�", 0, player[1]);
        print("�����ƣ�", 0, player[2]);
        cout << oct << POKE << '\n';
    }
    int landlord;
    putchar(10);
    cout << "��ѡ��һ������[0-2]";
    cin >> landlord;
    while (cin.fail() || landlord < 0 || landlord > 2) {
        cin.clear();
        cin.ignore(0x3f3f3f3f, '\n');
        cout << "��ѡ��һ������[0-2]";
        cin >> landlord;
    }
    for (int i = 0; i < num_all; ++i)
        if ((POKE & (1ll << i)) == 0)
            player[landlord] |= 1ll << i;
    return landlord; //�˴��޸�Ϊѡ���ĵ���(0-2)
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main��������׼�޸�
 ***************************************************************************/
int main()
{
    unsigned long long player[3] = { 0 }; //���������ҵķ�����Ϣ
    int landlord; //����0-2��ʾ�ĸ�����ǵ���

    cout << "���س�����ʼ����";
    while (getchar() != '\n')
        ;

    landlord = deal(player);
    print("�׵��ƣ�", (landlord == 0), player[0]);
    print("�ҵ��ƣ�", (landlord == 1), player[1]);
    print("�����ƣ�", (landlord == 2), player[2]);

    return 0;
}
