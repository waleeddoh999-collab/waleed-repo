#include<iostream>
using namespace std;
class rectangle{
private: 
    float width ;
    float lenth;
public:
    void putlenth (float len){
        lenth = len ;
    }
    void putwidth (float wid){
        width = wid ;
    }
    float getarea (){
        return width * lenth;
    }


};
int main(){

rectangle box ;
box.putlenth(10);
box.putwidth(23);
cout << "the area is "<< box.getarea(); 










}