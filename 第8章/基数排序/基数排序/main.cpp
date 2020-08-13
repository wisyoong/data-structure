//
//  main.cpp
//
//  Created by 熊智宏 on 2020/7/30.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include <iostream>
#include "SqList.hpp"
int main(){
    SqList sqList;
       initSqList(sqList);
       
    //添加数据
    ElemType elem;
    elem.key=160;
    elem.name="张三";
    insertElem(sqList,1,elem);
    elem.key=12;
    elem.name="李四";
    insertElem(sqList,2,elem);
    elem.key=140;
    elem.name="王五";
    insertElem(sqList,3,elem);
    elem.key=18;
    elem.name="丘六";
    insertElem(sqList,4,elem);
    elem.key=1300;
    elem.name="李华";
    insertElem(sqList,5,elem);
    elem.key=11;
    elem.name="李花";
    insertElem(sqList,6,elem);
    printSqList(sqList);
    printf("\n");

    radixSort(sqList); //基数排序
    printSqList(sqList); //输出顺序表
    return 0;
}
