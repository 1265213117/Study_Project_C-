#pragma once
#include <iostream>
#include <fstream>
using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    //构造函数
    WorkerManager();

    //展示菜单
    void Show_Menu();

    //退出系统
    void ExitSystem();

    //记录职工人数
    int m_EmpNum;

    //职工数组指针
    Worker ** m_EmpArray;

    //标志文件是否为空
    bool m_FileIsEmpty;

    //添加职工
    void Add_Emp();

    //保存文件
    void save();
    
    //析构函数
    ~WorkerManager();

};