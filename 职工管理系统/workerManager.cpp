#include "workerManager.h"

WorkerManager::WorkerManager(){

    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    if(!ifs.is_open())//文件不存在
    {
        cout<<"文件不存在"<<endl;
        this->m_EmpNum =0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray =NULL;
        ifs.close();
        return ;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof())//文件存在，数据为空
    {
        cout<<"文件为空！"<<endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return ;
    }

    //文件存在且记录不为空
    int num = this->get_EmpNum();
    cout<<"职工人数为："<<num<<endl;
    this->m_EmpNum = num;

    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->init_Emp();

}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;
    int num=0;
    while(ifs>>id&&ifs>>name&&ifs>>dId)
    {

        num++;
    }
    return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int index =0;
    while(ifs>>id && ifs>>name && ifs>>dId)
    {
        Worker * worker = NULL;
        if(dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if(dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else if(dId == 3)
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
}

void WorkerManager::Add_Emp()
{
    cout<<"请输入添加职工数量："<<endl;

    int addNum = 0;
    cin>>addNum;

    if(addNum>0)
    {
        int newSize = this->m_EmpNum + addNum;
        Worker ** newSpace = new Worker*[newSize];
        if(this->m_EmpArray !=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for(int i=0;i<addNum;i++)
        {
            int id;
            string name;
            int dSelect;
            cout<<"请输入第"<<i+1<<"个新职工的编号："<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新职工的姓名："<<endl;
            cin>>name;
            cout<<"请选择该职工的岗位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cin>>dSelect;
            Worker * worker = NULL;
            switch(dSelect)
            {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }
            newSpace[this->m_EmpNum+i] = worker; 
        }

        delete[] this->m_EmpArray;

        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        cout<<"成功添加"<<addNum<<"名新职工"<<endl;

        this->m_FileIsEmpty = false;


        this->save();
    }
    else
    {
        cout<<"输入有误"<<endl;
    }
}

void WorkerManager::Show_Menu()
{
    cout<<"***************************************"<<endl;
    cout<<"********* 欢迎使用职工管理系统 ********"<<endl;
    cout<<"*********** 0、退出管理程序 ***********"<<endl;
    cout<<"*********** 1、增加职工信息 ***********"<<endl;
    cout<<"*********** 2、显示职工信息 ***********"<<endl;
    cout<<"*********** 3、删除离职职工 ***********"<<endl;
    cout<<"*********** 4、修改职工信息 ***********"<<endl;
    cout<<"*********** 5、查找职工信息 ***********"<<endl;
    cout<<"*********** 6、按照编号排序 ***********"<<endl;
    cout<<"*********** 7、清空所有文档 ***********"<<endl;
    cout<<"***************************************"<<endl;
    cout<<endl;
}


void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for(int i=0;i<this->m_EmpNum;i++)
    {
        ofs <<this->m_EmpArray[i]->m_Id<<" "
        <<this->m_EmpArray[i]->m_Name<<" "
        <<this->m_EmpArray[i]->m_DeptId<<endl;
    }

    ofs.close();
}

void WorkerManager::show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"数据文件不存在或记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<this->m_EmpNum;i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
}

int WorkerManager::isExist(int id)
{
    int index = -1;

    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

void WorkerManager::del_Emp(){
    if(this->m_FileIsEmpty)
    {
        cout<<"数据文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入想要删除的职工的编号："<<endl;
        int id;
        cin>>id;
        int ret = this->isExist(id);
        if(ret!=-1)
        {
            for(int i=ret;i<this->m_EmpNum-1;i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();
            cout<<"删除成功"<<endl;
        }
        else
        {
            
            cout<<"删除失败，未找到该职工"<<endl;
        }
    }
}

void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"数据文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入修改职工的编号"<<endl;
        int id;
        cin>>id;

        int ret = this->isExist(id);
        if(ret != -1)
        {
            delete this->m_EmpArray[ret];
            int newId = 0;
            string newName="";
            int dSelect=0;
            cout<<"查到:"<<id<<"号职工，请输入新职工号："<<endl;
            cin >> newId;
            cout<<"请输入新职工姓名："<<endl;
            cin >>newName;
            cout<<"请输入新职工岗位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cin>>dSelect;

            Worker * worker = NULL;
            switch(dSelect)
            {
                case 1:
                    worker = new Employee(newId,newName,1);
                    break;
                case 2:
                    worker = new Manager(newId,newName,2);
                    break;
                case 3:
                    worker = new Boss(newId,newName,3);
                    break;
                default:
                    break;
            }

            this->m_EmpArray[ret] = worker;
            cout<<"修改成功"<<endl;
            this->save();
        }
        else
        {
            cout<<"查无此人"<<endl;
        }
    }
}


void WorkerManager::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"数据文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入查找的方式："<<endl;
        cout<<"1、按职工编号查询"<<endl;
        cout<<"2、按职工姓名查询"<<endl;
        int select = 0;
        cin>>select;
        if(select == 1)
        {
            int id;
            cout<<"请输入查找的职工编号："<<endl;
            cin >> id;
            int ret = this->isExist(id);
            if(ret != -1)
            {
                cout<<"查找成功，该职工信息如下："<<endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout<<"查无此人"<<endl;
            }
        }
        else if(select == 2)
        {
            string name;
            cout<<"请输入查找的姓名："<<endl;
            cin >> name;

            bool flag = false;
            for (int i=0;i<this->m_EmpNum;i++)
            {
                if(this->m_EmpArray[i]->m_Name == name)
                {
                    cout<<"查找成功，职工信息如下："<<endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag == false)
            {
                cout<<"查无此人"<<endl;

            }
        }
        else
        {
            cout<<"输入选项有误"<<endl;
        }
    }
}


void WorkerManager::Sort_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"数据文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入排序的方式："<<endl;
        cout<<"1、按职工编号升序"<<endl;
        cout<<"2、按职工编号降序"<<endl;

        int select =0;
        cin>>select;

        for(int i=0;i<this->m_EmpNum;i++)
        {
            int minOrMax = i;
            for(int j=i+1;j<this->m_EmpNum;j++)
            {
                if(select == 1)
                {
                    if(this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else
                {
                    if(this->m_EmpArray[minOrMax]->m_Id<this->m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }
            if(i!=minOrMax)
            {
                Worker * temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax] = temp;
            }
        }

    this->save();
    cout<<"排序成功，排序后结果为："<<endl;
    this->show_Emp();
    }
}


void WorkerManager::Clean_File()
{
    cout<<"确认清空?"<<endl;
    cout<<"1、确认"<<endl;
    cout<<"2、返回"<<endl;

    int select =0;
    cin>>select;

    if(select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if(this->m_EmpArray != NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                if(this->m_EmpArray[i] !=NULL)
                {
                    delete this->m_EmpArray[i];

                }
            }
            this->m_EmpNum =0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout<<"清空成功"<<endl;
    }
}

void WorkerManager::ExitSystem(){
    cout<<"欢迎下次使用"<<endl;
    exit(0);
}

WorkerManager::~WorkerManager(){

    if(this->m_EmpArray != NULL)
    {
        for(int i=0;i<this->m_EmpNum;i++)
            {
                if(this->m_EmpArray[i] !=NULL)
                {
                    delete this->m_EmpArray[i];

                }
            }
    }

}