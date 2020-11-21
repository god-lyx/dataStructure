#include<iostream>
#include<string>
#include"sqlist.h"

class Student:SqList{
    private:
    int series=0;
    std::string name="";
    int Chinese=0;
    int English=0;
    int Math=0;
    float Average=(Chinese+English+Math) /3;
    int Total = Chinese + English + Math;

    public:
    Student();
    
};