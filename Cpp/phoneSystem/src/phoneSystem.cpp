#include<iostream>
#include<string>
using namespace std;
//menushow
void showMenu()
{
    cout<<"1. add contacters"<<endl;
    cout<<"2. show contacter"<<endl;
    cout<<"3. delete contacters"<<endl;
    cout<<"4. search contacters"<<endl;
    cout<<"5. edit contacters"<<endl;
    cout<<"6. clear all contacters"<<endl;
    cout<<"exit"<<endl;
}
struct Person
{
    string name;
    int age;
    int sex;
    string addr;
    string phone;
}

struct 
int main()
{
    int select = 0;//创建用户选择输入的变量
    while(true){
        showMenu();
        cin>>select;
        switch(select)
        {
            case 0: //exit
                break;
            case 1://add
                break;
            case 2://show
                break;
            case 3://delete
                break;
            case 4://search
                break;
            case 5://edit
                break;
            case 6://clear
                break;
            default:
                break;
            }
        }
    system("pause");
    return 0;
}
