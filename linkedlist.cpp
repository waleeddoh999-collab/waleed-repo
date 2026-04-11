#include <iostream>
using namespace std ;
struct node
{
    int value;
    node * next ;

};
node * Head = NULL;

void addnumberfrom_end ( int);
void showlinked_list ();
void addnumberfrom_beging ( int);
void addnumberfrom_middle ( int , int );

int main ()
{



int n ;
cout <<"enter how many numbers would you to insert: ";
cin >>n ;
for (int i = 0 ; i < n ; i++){
    
    int k ;
    cout<<"enter number"<<i +1 <<": ";
    cin>>k;
    addnumberfrom_end (k);
}

addnumberfrom_middle ( 4 , 5);

char s ;
cout<<"enter a latter 's' to show numbers: ";
cin>> s ;

if (s == 's')
showlinked_list () ;



}


void addnumberfrom_beging (int value){
    node * newnode = new (node);
    newnode -> value = value; 
    newnode -> next = NULL;
    if (Head == NULL){
    Head = newnode ;
}
else 
{
newnode -> next = Head ;
Head = newnode ;
    
}

}

void addnumberfrom_middle ( int value ,int look4){
    node * newnode = new (node);
    node * temp = Head  ;
    node * prev ;
    newnode -> value = value; 
    newnode -> next = NULL;
 


    while (temp->value != look4){
        prev =  temp ;
        temp = temp->next;
    }
    
    newnode -> next = temp ; 

    prev -> next = newnode ;

}




void addnumberfrom_end (int value){
    node * newnode = new (node);
    node * temp ;
    newnode -> value = value; 
    newnode -> next = NULL;


if (Head == NULL){
    Head = newnode ;
}
else
{
    temp = Head  ;

    while (temp->next != NULL){
    temp = temp->next;
}
temp->next = newnode;
}

}

void showlinked_list (){
node * temp = Head  ;

while (temp != NULL){

        cout<< temp -> value ;
        temp = temp -> next  ;

    }


}