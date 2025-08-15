#include <iostream>  
#include <fstream>  
#include <vector>  
  
using namespace std;  
  
int main() {  
    // 打开文件  
    ifstream inputFile("/home/jucing/homorphic_experiment/data.txt");  
  
    // 检查文件是否成功打开  
    if (!inputFile) {  
        cerr << "无法打开文件" << endl;  
        return 1;  
    }  
  
    // 定义整数数组的长度  
    int arrayLength = 1024;  
  
    // 创建整数数组并存储读取的数据  
    vector<int> intArray(arrayLength);  
    int count = 0;  
    int value;  
    while (inputFile >> value) {  
        intArray[count++] = value;  
    }  
  
    // 关闭文件  
    inputFile.close();  
  
    // 输出存储在整数数组中的数据  
    
    for (int i = 0; i < count; i++) {  
        cout << intArray[i] << " ";  
    }  
    cout << endl;  
    int sum=0;
    for (int i = 0; i < 512; i++) {  
        sum+=(intArray[i]*intArray[i+512]);
    }  
   
    cout<<"sum:"<<sum<<endl;
     cout<<count<<endl;
    return 0;  
}
