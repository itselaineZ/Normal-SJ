/* 1952339 信08 张馨月 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
/* 如果有需要，此处可以添加头文件 */

using namespace std;

/* 允许定义常变量/宏定义，但不允许定义全局变量 */
const int num_all = 13*4+2;
const int num_kind = 13;
const int num_base = 17;
const char poke[] = {'J', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const char clr[] = {3, 4, 5, 6};
/* 可以添加自己需要的函数 */

/***************************************************************************
  函数名称：
  功    能：打印某个玩家的牌面信息，如果是地主，后面加标记
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int print(const char* prompt, const bool landlord, const unsigned long long player)
{
    /* 只允许定义不超过三个基本类型的简单变量，不能定义数组变量、结构体、string等 */
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
        cout << "(地主)";
    putchar(10);
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：发牌
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int deal(unsigned long long* player)
{
    /* 只允许定义不超过十个基本类型的简单变量，不能定义数组变量、结构体、string等 */
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
        cout << dec << "第" << i << "轮结束\n";
        print("甲的牌：", 0, player[0]);
        print("乙的牌：", 0, player[1]);
        print("丙的牌：", 0, player[2]);
        cout << oct << POKE << '\n';
    }
    int landlord;
    putchar(10);
    cout << "请选择一个地主[0-2]";
    cin >> landlord;
    while (cin.fail() || landlord < 0 || landlord > 2) {
        cin.clear();
        cin.ignore(0x3f3f3f3f, '\n');
        cout << "请选择一个地主[0-2]";
        cin >> landlord;
    }
    for (int i = 0; i < num_all; ++i)
        if ((POKE & (1ll << i)) == 0)
            player[landlord] |= 1ll << i;
    return landlord; //此处修改为选定的地主(0-2)
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数，不准修改
 ***************************************************************************/
int main()
{
    unsigned long long player[3] = { 0 }; //存放三个玩家的发牌信息
    int landlord; //返回0-2表示哪个玩家是地主

    cout << "按回车键开始发牌";
    while (getchar() != '\n')
        ;

    landlord = deal(player);
    print("甲的牌：", (landlord == 0), player[0]);
    print("乙的牌：", (landlord == 1), player[1]);
    print("丙的牌：", (landlord == 2), player[2]);

    return 0;
}
