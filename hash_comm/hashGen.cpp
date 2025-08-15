#include <iostream>  
#include <iomanip>  
#include <openssl/sha.h>  
#include<chrono>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <vector>

#include <algorithm>



/*
//输出为16进制,sha256需要64个字符,消耗64个字节,可读
std::string sha256(const std::string str) {  
    unsigned char hash[SHA256_DIGEST_LENGTH];  
    SHA256_CTX sha256;  
    SHA256_Init(&sha256);  
    SHA256_Update(&sha256, str.c_str(), str.size());  
    SHA256_Final(hash, &sha256);  
    std::stringstream ss;  
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {  
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];  
    }  
    return ss.str();  
}  

*/

//输出为2进制,sha256需要32字节,不可读
std::string sha256(const std::string& str) {

    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;

    SHA256_Init(&sha256);

    SHA256_Update(&sha256, str.c_str(), str.size());

    SHA256_Final(hash, &sha256);

    return std::string(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);

}

 
int main() { 


    std::random_device rd;
    std::mt19937 gen(rd());
 
    // 定义随机数分布范围，例如从1到10
    std::uniform_int_distribution<> distrib(1, 100000000);
    std::uniform_int_distribution<> distribsim(-10000, 10000);
    int n=1;
     
    for(int k=0;k<n;k++){
    
    
    //server generate Hashs
    int thresh=2000;
    int right=10000;
    int p=1;
    int q=1024*1024*16;
    int BYTE=32;
    
    std::cout<<"p="<<p<<std::endl;
    std::cout<<"server generate hashs"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now(); 
    // 生成随机数
    int random = distrib(gen);
    //int random = 0;
    int sim=distribsim(gen);
    //std::cout<<"sim is "<<sim<<std::endl;
    // 输出随机数
    //std::cout << "Random number between 1 and 1000000: " << num << std::endl;
    
    int time=(right-thresh)/p; 
    std::string name=std::to_string(time);
    std::string strArray[time];
    std::string strResult[time];
    int nums[time];
    int startNum=(((thresh+random)%q)/p)%q+1;
    int endNum=(((right+random)%q)/p)%q;
   
    //std::cout<<std::endl;
    //std::cout<<"server generate hashs"<<std::endl;
    //std::cout<<"hashs before shuffle"<<std::endl;
    for(int i=0;i<time;i++){
	nums[i]=(startNum+i)%q;
       strArray[i]=std::to_string(nums[i]);
      //std::cout<<strArray[i]<<std::endl;
      strResult[i]=sha256(strArray[i]);
      //std::cout<<strResult[i]<<std::endl;
    }
  
  //打乱hash的顺序
    //std::cout<<"hashs after shuffle"<<std::endl;
   
    int size = sizeof(strResult) / sizeof(strResult[0]);
 
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(strResult, strResult + size, std::default_random_engine(seed));
 
 /*
    for (int i = 0; i < size; ++i) {
        std::cout << strResult[i] <<std::endl;
    }
    */
    
  
    char charResult[time*BYTE];
    int index=0;

    for(int i=0;i<time;i++){
    
    	for(int j=0;j<BYTE;j++){
    		charResult[index++]=strResult[i][j];
    	
    	}
    
    }
    
      auto end = std::chrono::high_resolution_clock::now();  
      
      
      
      
      
      
      
    std::chrono::duration<double> elapsed = end - start;  
    std::cout << "Generate threshold-right hashs time: " << elapsed.count()*1000<< " ms\n";
    std::cout << "Generate threshold-right hashs space: " << time*BYTE<< " B\n";
    
    
    
    auto start2 = std::chrono::high_resolution_clock::now();
    int simValue=(((sim+random)%q)/p)%q;
    std::string str=std::to_string(simValue);
      //std::cout<str<<std::endl;
    std::string simHash=sha256(str);
    auto end2 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed2 = end2 - start2;  
    std::cout<<std::endl;
    std::cout<<"CSP generate hash"<<std::endl;
    std::cout << "generate sim hash time: " << elapsed2.count()*1000 << " ms\n";
    std::cout << "generate sim hash space: " << BYTE << " B\n";
    
    int flag=0;
    auto start1 = std::chrono::high_resolution_clock::now();
    
    std::string strResult2[time]; // 或者用 std::vector<std::string>
    index = 0;
     //std::cout<<"hashs:"<<std::endl;
    for (int i = 0; i < time; i++) {
      strResult2[i] = std::string(&charResult[index], BYTE); // 直接取 32 字节
      //std::cout<<strResult2[i]<<std::endl;
       index += BYTE;
   }
    
    for(int i=0;i<time;i++){
    	if(simHash==strResult2[i]&&flag==0){
    		flag=1;
    	}
    
    }  
    
    auto end1 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed1 = end1 - start1; 
    std::cout<<std::endl;
    std::cout<<"client get result from hashs"<<std::endl; 
    std::cout << "matching time: " << elapsed1.count()*1000 << " ms\n";
    if(flag==1){
    	std::cout<<"matching sucess"<<std::endl;
    }
    std::cout<<"sim is "<<sim<<std::endl;
    /*
        std::ofstream file("/home/jucing/hash_comm/data/number"+name+".txt", std::ios::app); // 打开文件用于追加
 
    if (file.is_open()) {
        file << elapsed.count()*1000 <<" "; // 将数字写入文件并换行
        file.close(); // 关闭文件
    } else {
        std::cerr << "无法打开文件" << std::endl;
    }*/
    
    }
    return 0;  
}
