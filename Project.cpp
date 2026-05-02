#include <iostream>
#include<string>
using namespace std ;
struct Task
{
    int id;
    string description;
    bool status = false ; 
    Task * next ;

};
Task * Head = NULL;
int ID = 1 ;
void AddTask (string);
void Display ();
void MarkDone (int);
void DeleteTask (int);
void SearchTask(int);
int main ()
{
int choice ;

cout<<"1. Add Task"<<endl<<"2. Display Tasks"<<endl<<"3. Mark Task as Done"<<endl<<"4. Delete Task"
<<endl<<"5. Search Task"<<endl<<"6. Exit"<<endl;

bool inprogres = true ;

int id ;
string description ;

while (inprogres){
    do{
        cout<<"Enter your choice : ";
        cin >> choice ;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }

    }while ( choice < 1 || choice > 6);
    switch (choice){
        case 1:
            cout<<"Description of task : ";
            cin.ignore();
            getline(cin,description) ;
            AddTask(description);
            break;
        case 2 :
            Display () ;
            break;
        case 3 :
            cout<<"Id of task you want mark it done : ";
            cin>>id;
            MarkDone(id);
            break;
        case 4 :
            cout<<"Id of task you want delete : ";
            cin>>id;
            DeleteTask(id);
            break;
        case 5 :
            cout<<"Id of task you want searched : ";
            cin>>id;
            SearchTask(id);
            break;
        case 6 :
            inprogres = false ;
            break;
}
}
}


void AddTask (string description){
    Task * newTask = new Task;
    Task * temp ;
    newTask -> description = description; 
    newTask -> next = NULL;
    newTask -> id = ID ;
    ID ++ ;
if (Head == NULL)
    Head = newTask ;
else
{
    temp = Head  ;
    while (temp->next != NULL){
        temp = temp->next;
}
temp->next = newTask;
}
}

void Display (){
    if (Head == NULL){
        cout<<"Empty list please add a task"<<endl;
        return ;
    }
Task * temp = Head  ;
while (temp != NULL){
        cout<<"TaskID : "<<temp->id<<endl ;
        cout<<"Description : "<<temp->description<<endl ;
        cout<<"Status : ";
        if(temp ->status == false )
            cout<<"Inprogres";
        else
            cout<<"Done";
        cout<<endl<<"-------------------"<<endl;
        temp = temp-> next  ;
    }
}


void MarkDone (int id){
    if (Head == NULL){
        cout<<"Empty list please add a task"<<endl;
        return ;
    }
    Task * temp = Head  ;
    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL){
        cout << "Not Found\n";
        return;
    }

    temp -> status = true;
}
void DeleteTask (int id){
    if (Head == NULL){
        cout<<"Empty list please add a task"<<endl;
        return ;
    }
    Task * temp = Head ;
    Task * prev; 
    while (temp != NULL && temp->id != id){
        prev =  temp ;
        temp = temp->next;
    }
    if (temp == NULL){
        cout << "Not Found\n";
        return;
    }
    if (temp == Head)
        Head = temp->next;
    else
        prev -> next = temp -> next ;
}


void SearchTask(int id){
    if (Head == NULL){
        cout<<"Empty list please add a task"<<endl;
        return ;
    }
    Task * temp = Head  ;
    while (temp != NULL && temp->id != id)
        temp = temp->next;

    if (temp == NULL){
        cout << "Not Found\n";
        return;
    }
    cout<<"TaskID : "<<temp->id<<endl ;
    cout<<"Description : "<<temp->description<<endl ;
    cout<<"Status : ";
    if(temp ->status == false )
        cout<<"Inprogres";
    else
        cout<<"Done";
    cout<<endl;
}