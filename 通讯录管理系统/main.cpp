#include <iostream>
#include <string>

using namespace std;

//联系人结构体
struct Person
{
    string m_Name;
    int m_Sex; //性别  1 男   2  女
    int m_Age;
    string m_Phone;
    string m_Addr;
};

#define MAX_SIZE 1000 //最大人数
//通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX_SIZE];
    int m_Size;
};

//显示菜单
void showMenu(){
    cout<<"*********************"<<endl;
    cout<<"**** 1、添加联系人 ****"<<endl;
    cout<<"**** 2、显示联系人 ****"<<endl;
    cout<<"**** 3、删除联系人 ****"<<endl;
    cout<<"**** 4、查找联系人 ****"<<endl;
    cout<<"**** 5、修改联系人 ****"<<endl;
    cout<<"**** 6、清空联系人 ****"<<endl;
    cout<<"**** 0、退出通讯录 ****"<<endl;
    cout<<"*********************"<<endl;
}

//添加联系人
void addPerson(Addressbooks * adbs){
    //判断通讯录是否已满，如果满了就不再添加
    if(adbs->m_Size == MAX_SIZE)
    {
        cout<<"通讯录已满，无法添加"<<endl;
        return ;
    }
    else
    {
        //添加具体联系人

        //姓名
        string name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        adbs->personArray[adbs->m_Size].m_Name = name;
        //性别
        cout<<"请输入性别："<<endl;
        cout<<"1、--- 男"<<endl;
        cout<<"2、--- 女"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
                adbs->personArray[adbs->m_Size].m_Sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;

        }
        //年龄
        cout<<"请输入年龄"<<endl;
        int age=0;
        while(true){
            cin>>age;
            if(age>0 && age<120)
            {
                adbs->personArray[adbs->m_Size].m_Age=age;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        
        }
            
        //电话
        cout<<"请输入联系电话"<<endl;
        string phone;
        cin >> phone;
        adbs->personArray[adbs->m_Size].m_Phone=phone;

        //住址
        cout<<"请输入家庭住址"<<endl;
        string address;
        cin>>address;
        adbs->personArray[adbs->m_Size].m_Addr=address;

        adbs->m_Size++;
        system("clear");
        cout<<"联系人添加成功"<<endl;
    }

}
//显示联系人
void showPerson(Addressbooks *adbs){
    if(adbs->m_Size == 0 )
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<adbs->m_Size;i++)
        {
            cout<<"姓名："<<adbs->personArray[i].m_Name<<"\t";
            cout<<"性别："<<(adbs->personArray[i].m_Sex==1?"男":"女")<<"\t";
            cout<<"年龄："<<adbs->personArray[i].m_Age<<"\t";
            cout<<"电话："<<adbs->personArray[i].m_Phone<<"\t";
            cout<<"住址："<<adbs->personArray[i].m_Addr<<endl;
        }
    }
}
//检测联系人是否存在,存在，则返回数组下标，若不存在，则返回-1
int isExist(Addressbooks * adbs, string name){
    for(int i=0;i<adbs->m_Size;i++){
        //找到用户输入的姓名了
        if(adbs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}
//查找联系人（依据姓名查找）
void findPersonByName(Addressbooks * adbs){
    cout<<"请输入要查找的联系人姓名："<<endl;
    string name;
    cin>>name;
    int ret = isExist(adbs, name);
    if(ret==-1)
    {
        cout<<"查无此人"<<endl;
        return ;
    }
    cout<<"姓名："<<adbs->personArray[ret].m_Name<<"\t";
    cout<<"性别："<<(adbs->personArray[ret].m_Sex==1?"男":"女")<<"\t";
    cout<<"年龄："<<adbs->personArray[ret].m_Age<<"\t";
    cout<<"电话："<<adbs->personArray[ret].m_Phone<<"\t";
    cout<<"住址："<<adbs->personArray[ret].m_Addr<<endl;
    

}
//删除联系人
void delectPerson(Addressbooks * adbs){
    cout<<"请输入要删除联系人的姓名："<<endl;
    string name;
    cin>>name;
    int ret = isExist(adbs, name);
    if(ret==-1)
    {
        cout<<"查无此人"<<endl;
        return ;
    }
    for(int i=ret;i<adbs->m_Size;i++)
    {
        adbs->personArray[i] = adbs->personArray[i+1];
    }
    adbs->m_Size--;

}

void modifyPersonByname(Addressbooks * adbs)
{
    cout<<"请输入要修改的联系人姓名："<<endl;
    string name;
    cin>>name;
    int ret = isExist(adbs, name);
    if(ret==-1)
    {
        cout<<"查无此人"<<endl;
        return ;
    }
    cout<<"请输入姓名"<<endl;
    cin>>name;
    adbs->personArray[ret].m_Name = name;
    //性别
    cout<<"请输入性别："<<endl;
    cout<<"1、--- 男"<<endl;
    cout<<"2、--- 女"<<endl;
    int sex=0;
    while(true)
    {
        cin>>sex;
        if(sex==1||sex==2)
        {
            adbs->personArray[ret].m_Sex = sex;
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;

    }
    //年龄
    cout<<"请输入年龄"<<endl;
    int age=0;
    while(true){
        cin>>age;
        if(age>0 && age<120)
        {
            adbs->personArray[ret].m_Age=age;
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;
    
    }
        
    //电话
    cout<<"请输入联系电话"<<endl;
    string phone;
    cin >> phone;
    adbs->personArray[ret].m_Phone=phone;

    //住址
    cout<<"请输入家庭住址"<<endl;
    string address;
    cin>>address;
    adbs->personArray[ret].m_Addr=address;
    

}

void clearPerson(Addressbooks * adbs)
{
    adbs->m_Size=0;
}
int main(){
    system("clear");
    Addressbooks adbs;
    adbs.m_Size=0;

    int select=0;
    while (true)
    {
        showMenu();
        cin>>select;
        switch (select)
        {
        case 1://1、添加联系人
            addPerson(&adbs);
            break;
        case 2://2、显示联系人
            showPerson(&adbs);
            break;
        case 3://3、删除联系人
            delectPerson(&adbs);
            break;
        case 4://4、查找联系人
            findPersonByName(&adbs);
            break;
        case 5://5、修改联系人
            modifyPersonByname(&adbs);
            break;
        case 6://6、清空联系人
            clearPerson(&adbs);
            break;
        case 0://0、退出通讯录
            cout<<"欢迎下次使用"<<endl;
            return 0;
            break;
        
        default:
            break;
        }
    }

}