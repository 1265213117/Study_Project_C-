#include <iostream>
using namespace std;

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{

    Worker * worker = NULL;
    worker = new Employee(3,"张三",3);
    worker->showInfo();
    worker = new Boss(1,"张三",1);
    worker->showInfo();
    worker = new Manager(2,"张三",2);
    worker->showInfo();
    delete worker;


    // WorkerManager wm;
    // int choice = 0;
    // while (true)
    // {
    //     wm.Show_Menu();
    //     cout<<"请输入您的选择："<<endl;
    //     cin>>choice;

    //     switch (choice)
    //     {
    //     case 0://0、退出管理程序
    //         wm.ExitSystem();
    //         break;
    //     case 1://1、增加职工信息
    //         break;
    //     case 2://2、显示职工信息
    //         break;
    //     case 3://3、删除离职职工
    //         break;
    //     case 4://4、修改职工信息
    //         break;
    //     case 5://5、查找职工信息
    //         break;
    //     case 6://6、按照编号排序
    //         break;
    //     case 7://7、清空所有文档
    //         break;
        
    //     default:
    //         system("clear");
    //         break;
    //     }

    // }
    

    return 0;
}