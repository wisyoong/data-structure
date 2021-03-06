//
//  HashTable.hpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/23.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp
#include "SqList.hpp"
#include "global.h"
typedef struct{
    ElemType *baseAddress;
    int length;
}HashTable;

int hashFunction(int key,int length); //散列函数
Status initHashTable(HashTable &hashTable,SqList &sqList); //初始化散列表
Status createHashTableBySecondDetectionMethod(HashTable &hashTable,SqList &sqList); //通过二次探测法创建散列表
Status printHashTable(HashTable &hashTable); //输出散列表
int searchHashTableBySecondDetectionMethod(HashTable &hashTable,KeyType key); //通过开放地址法在散列表中查找
#endif /* HashTable_hpp */ 

