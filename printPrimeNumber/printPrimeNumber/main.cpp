//
//  main.cpp
//  printPrimeNumber
//
//  Created by 舒子琪 on 2020/2/21.
//  Copyright © 2020 舒子琪. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//判断输入数字是否为素数
//返回值
//0:非素数
//1:素数

int checkPrimeNumber(int i){
    
    int n =2 ;
    
    for (n ; n <= sqrt(i); n++) {
        
        if (i % n == 0) {
            
            return 0;
        }
    }
    return 1;

}

int main()
{

    int totalNum = 100;
    
    for(int i = 1; i < totalNum; i++){
        
        //判断数字
        int res = checkPrimeNumber(i);
        
        if (res == 1){
    
            cout << "the number is:" << i << endl;
    
        }
        
    }
    system("pause");
    
    return 0;
}
