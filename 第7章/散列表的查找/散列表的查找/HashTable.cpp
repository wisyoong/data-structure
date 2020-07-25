//
//  HashTable.cpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/23.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include "HashTable.hpp"
int hashFunction(int key){ //散列函数
    return key%7;
}
Status initHashTable(HashTable &hashTable,SqList &sqList){ //初始化散列表
    hashTable.baseAddress=new ElemType[sqList.length];
    hashTable.length=sqList.length;
    int i;
    for(i=0;i<sqList.length;i++){ //初始化散列表的键值为-1
        hashTable.baseAddress[i].key=-1;
    }
    return SUCCESS;
}
Status createHashTableByOpenAddressMethod(HashTable &hashTable,SqList &sqList){ //通过开放地址法创建散列表
    int i,index;
    for(i=1;i<=sqList.length;i++){ //把数据填入散列表中
        index=hashFunction(sqList.baseAddress[i].key);
        while(hashTable.baseAddress[index].key!=-1){ //如果当前下标指向的空间已经有数据，则选择下一个下标
               index=hashFunction(index+1);
        }
        hashTable.baseAddress[index]=sqList.baseAddress[i]; //把顺序表中的数据复制到散列表中
    }
    return SUCCESS;
}
Status createHashTableBySecondDetectionMethod(HashTable &hashTable,SqList &sqList){ //通过二次探测法创建散列表
    int i,j,index;
    for(i=1;i<=sqList.length;i++){ //把数据填入散列表中
        index=sqList.baseAddress[i].key;
        for(j=0;j<=hashTable.length;j++){ //生成数列 1，2，3，4，5····
            index=hashFunction(index+(j*j)); //用数列 1，2*2，3*3，4*4···· 生成下一个下标
            if(hashTable.baseAddress[index].key==-1)break; //如果下标为 j的平方 的地方没有数据则停止循环
            index=hashFunction(index-(j*j)); //用数列 -1，-2*2，-3*3，-4*4···· 生成下一个下标
            if(hashTable.baseAddress[index].key==-1)break; //如果下标为 j的平方的负数 的地方没有数据则停止循环
        }
        hashTable.baseAddress[index]=sqList.baseAddress[i]; //把顺序表中的数据复制到散列表中
    }
    return SUCCESS;
}
Status printHashTable(HashTable &hashTable){//输出散列表
    int i;
    for(i=0;i<hashTable.length;i++){
        ElemType column=hashTable.baseAddress[i];
        printf("%d,%s\n",column.key,column.name);
    }
    printf("散列表输出成功\n");
    return SUCCESS;
}
int searchHashTableByOpenAddressMethod(HashTable &hashTable,KeyType key){//在散列表中查找
    int index=hashFunction(key);
    int i=0;
    while(hashTable.baseAddress[index].key!=key){ //如果当前的下标的主键与想查找的下标不一致则继续查找
        index=hashFunction(index+1);
        if(i>=hashTable.length){
            return -1;
        }
    }
    return index;
}
int searchHashTableBySecondDetectionMethod(HashTable &hashTable,KeyType key){ //通过开放地址法在散列表中查找
    int i,index=key;
    for(i=0;i<=hashTable.length;i++){ //生成数列 1，2，3，4，5····
        index=hashFunction(index+(i*i)); //用数列 1，2*2，3*3，4*4···· 生成下一个下标
        if(hashTable.baseAddress[index].key==key)break; //如果下标为 i的平方 的地方的数据的主键 与 所给的主键 相等则停止循环
        index=hashFunction(index-(i*i)); //用数列 -1，-2*2，-3*3，-4*4···· 生成下一个下标
        if(hashTable.baseAddress[index].key==key)break;  //如果下标为 i的平方的负数 的地方的数据的主键 与 所给的主键 相等则停止循环
    }
    return index;
}
