#include <iostream>
using namespace std;

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        wm.Show_Menu();
        cout<<"请输入您的选择："<<endl;
        cin>>choice;

        switch (choice)
        {
        case 0://0、退出管理程序
            wm.ExitSystem();
            break;
        case 1://1、增加职工信息
            wm.Add_Emp();
            break;
        case 2://2、显示职工信息
            wm.show_Emp();
            break;
        case 3://3、删除离职职工
            wm.del_Emp();
            break;
        case 4://4、修改职工信息
            break;
        case 5://5、查找职工信息
            break;
        case 6://6、按照编号排序
            break;
        case 7://7、清空所有文档
            break;

        default:
            system("clear");
            break;
        }

    }


    return 0;
}
