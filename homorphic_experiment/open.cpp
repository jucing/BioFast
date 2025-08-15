#include "seal/seal.h"
#include<iostream>
#include <fstream>  
#include <vector> 
#include "utils.h"
using namespace seal;
using namespace std;


long int* mod_message_half( const Plaintext  plain, const std::uint64_t poly_modulus_degree, const std::uint64_t plaintext_modulus, long int *buf)
{
    // long int buf[poly_modulus_degree];
    for (int i=0; i< poly_modulus_degree; i++)
    {
        buf[i] = plain[i];
        // cout<< i<<plaintext_modulus<< int(plaintext_modulus/2) <<endl;
        if (buf[i] > int(plaintext_modulus/2))
        {
            buf[i]= buf[i] - plaintext_modulus; 
        }
        
    }
    return buf;
}



int main() {
    // Create encryption parameters and other necessary components
    EncryptionParameters parms(scheme_type::bfv);
    size_t poly_modulus_degree = 4096;  //4096 8192 16384
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));

    // parms.set_plain_modulus(PlainModulus::CreateModulus(1024));
    long long my_plain_prime = pow(2,24);
    parms.set_plain_modulus(my_plain_prime);
	
    SEALContext context(parms);
    //cout << "----Set encryption parameters and print----" << endl;
	//cout<< "parmas:"<< context.parameter_error_message()<<endl;

    // Set up the encoder, key generator, and encryptor
    print_line(__LINE__);
    cout << "Set encryption parameters and print" << endl;
    print_parameters(context);

    cout << endl;
    cout << "~~~~~~ A naive way to calculate 2(x^2+1)(x+1)^2. ~~~~~~" << endl;


	KeyGenerator  keygen(context);
	PublicKey  pk;
	SecretKey  sk = keygen.secret_key();
	
       auto start = std::chrono::high_resolution_clock::now();  
	keygen.create_public_key(pk);
	auto end = std::chrono::high_resolution_clock::now();  
        std::chrono::duration<double> elapsed = end - start;  
       std::cout << "GenPK Elapsed time: " << elapsed.count()*1000 << " ms\n";

    RelinKeys relin_keys1;
    keygen.create_relin_keys(relin_keys1);



	// pk encrypt 
    Encryptor encryptor(context,pk);
	Evaluator evaluator(context);
	Decryptor decryptor(context,sk);

    // IntegerEncoder encoder;
	
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
        //cout << intArray[i] << " ";  
    }  
    //cout << endl;  
    //cout<<count<<endl;
    //intArray[89]=0;
    
   //int value = -99;
    int sum=0;
    for (int i = 0; i < 512; i++) {  
        sum+=(intArray[i]*intArray[i+512]);
       // cout<<intArray[i]<<" ";
    }  
    
    cout<<"sum:"<<sum<<endl;
  
   // Encode the negative integer as a plaintext polynomial
    Plaintext plain1;
    Plaintext plain2;
   
    size_t coeff_count = parms.poly_modulus_degree();
    plain1.resize(coeff_count);
    plain2.resize(coeff_count);
    std::cout<<"coeff_count"<<coeff_count<<endl;
    
    int n=512;
    for(int i=0; i< poly_modulus_degree ; i++)
    {
    	
    	
    	if(i<n){
    	
    	  plain1[i] = (my_plain_prime+intArray[i])%my_plain_prime;
	  plain2[(poly_modulus_degree-i)%poly_modulus_degree] = (my_plain_prime-intArray[n+i])%my_plain_prime;
    	
    	}
    	
    	
    	
    	else if(i>=n&&i<2*n){
    		
    	   plain1[i] = (my_plain_prime+intArray[i-n])%my_plain_prime;
	  plain2[(poly_modulus_degree-i-n)%poly_modulus_degree] = (my_plain_prime-intArray[i])%my_plain_prime;
    	
    	
    	}
    	/*
    	else if(i>=2*n&&i<3*n){
    		
    	   plain1[i] = (my_plain_prime+intArray[i-2*n])%my_plain_prime;
	  plain2[(poly_modulus_degree-i-2*n)%poly_modulus_degree] = (my_plain_prime-intArray[i-n])%my_plain_prime;
    	
    	
    	}else if(i>=3*n&&i<4*n){
    		
    	   plain1[i] = (my_plain_prime+intArray[i-3*n])%my_plain_prime;
	  plain2[(poly_modulus_degree-i-3*n)%poly_modulus_degree] = (my_plain_prime-intArray[i-2*n])%my_plain_prime;
    	
    	
    	}else if(i>=4*n&&i<5*n){
    		
    	   plain1[i] = (my_plain_prime+intArray[i-4*n])%my_plain_prime;
	  plain2[(poly_modulus_degree-i-4*n)%poly_modulus_degree] = (my_plain_prime-intArray[i-3*n])%my_plain_prime;
    	
    	
    	}*/
    	/*
    	else if(i>=4*n&&i<5*n){
    		
    	   plain1[i] = (my_plain_prime+intArray[i-4*n])%my_plain_prime;
	  plain2[(poly_modulus_degree-i-4*n+poly_modulus_degree)%poly_modulus_degree] = (my_plain_prime-intArray[i-3*n])%my_plain_prime;
    	
    	
    	}*/
    	
    	
    	else{
    	 
    	  plain1[i] = 0;
	  plain2[(poly_modulus_degree-i)%poly_modulus_degree] =0;
	  
    	}
    	
    	
    	
    	
    	/*
    	plain1[i]=1;
    	plain2[i]=1;
	 */ 
        
    }
    plain1[0]=(my_plain_prime+intArray[0])%my_plain_prime;
    plain2[0]=(my_plain_prime+intArray[512])%my_plain_prime;
   

    // plain[0] = static_cast<uint64_t>(-4) % (my_plain_prime);
    // plain[1] = static_cast<uint64_t>(3) % (my_plain_prime);

    // plain[4095] = static_cast<uint64_t>(4) % (my_plain_prime);


    //std::cout<<"plain text is = "<<plain.to_string() <<std::endl;

    // Encrypt the plaintext polynomial to obtain the ciphertext
    Ciphertext encrypted_1,encrypted_2,ct;
    auto start2 = std::chrono::high_resolution_clock::now(); 
    encryptor.encrypt(plain1, encrypted_1);
    auto end2 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed2 = end2 - start2;  
    std::cout << "encryption Elapsed time: " << elapsed2.count()*1000 << " ms\n";  
    
    encryptor.encrypt(plain2, encrypted_2);
    
    Ciphertext ciper;
   
    auto start5 = std::chrono::high_resolution_clock::now();
    evaluator.add(encrypted_1, encrypted_2,ciper);
      auto end5 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed5= end5 - start5;  
    std::cout << "add Elapsed time: " << elapsed5.count()*1000 << " ms\n";  
    
    /*
    Plaintext random;
    random.resize(coeff_count);
     for(int i=0; i< poly_modulus_degree ; i++){
     
     random[i]=1;
     
     }
     
      auto start6 = std::chrono::high_resolution_clock::now();
    evaluator.add_plain_inplace(encrypted_2, random);
      auto end6 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed6= end6 - start6;  
    std::cout << "plain_add Elapsed time: " << elapsed6.count()*1000 << " ms\n";  
    */
    
    /*
      Plaintext randomMul;
      randomMul.resize(coeff_count);
     for(int i=0; i< poly_modulus_degree ; i++){
     
     randomMul[i]=1;
     
     }

   auto start7 = std::chrono::high_resolution_clock::now();
    evaluator.multiply_plain_inplace(encrypted_2, randomMul);
   
    auto end7 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed7= end7 - start7;  
    std::cout << "plain_mul Elapsed time: " << elapsed7.count()*1000 << " ms\n";  
     */
    auto start3 = std::chrono::high_resolution_clock::now(); 
    
    evaluator.multiply(encrypted_1,encrypted_2,ct);
    
    auto end3 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed3 = end3 - start3;  
    std::cout << "cosSim Elapsed time: " << elapsed3.count()*1000 << " ms\n";
    std::cout << "Average one feature cosSim Elapsed time: " << elapsed3.count()*1000/2 << " ms\n";
    evaluator.relinearize_inplace(ct, relin_keys1);

    evaluator.mod_switch_to_next(ct, ct);
    
    

    // evaluator.addinplain(encrypted_1,encrypted_2,ct);
    // evaluator.mod_switch_to_next(ct, ct);

    Plaintext plain_dec;
    
    auto start4 = std::chrono::high_resolution_clock::now(); 
    decryptor.decrypt(ct,plain_dec);
    auto end4 = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> elapsed4 = end4 - start4;  
    std::cout << "decrypt Elapsed time: " << elapsed4.count()*1000<< " ms\n"; 
    
    
    //std::cout<<"plain_dec text is = "<<plain_dec.to_string() <<std::endl;
    //std::cout<<"plain_dec text is = "<< plain_dec[0] <<std::endl;
    //std::cout<<"plain_dec text is = "<< ((1<<16)-plain_dec[0] )<<std::endl;
 
    
    
    //std::cout<<"plain_dec text(last) is = "<< (1<<16)-plain_dec[poly_modulus_degree-512] <<std::endl;
    long int a[poly_modulus_degree];
    mod_message_half( plain_dec, poly_modulus_degree, my_plain_prime,a);
    std::cout<<"value1 after modulus plain_dec text is = "<< a[0]<<std::endl;
    std::cout<<"value2 after modulus plain_dec text is = "<< a[n]<<std::endl;
    /*
    std::cout<<"value3 after modulus plain_dec text is = "<< a[2*n]<<std::endl;
    std::cout<<"value4 after modulus plain_dec text is = "<< a[3*n]<<std::endl;
    std::cout<<"value5 after modulus plain_dec text is = "<< a[4*n]<<std::endl;
    std::cout<<"value6 after modulus plain_dec text is = "<< a[5*n]<<std::endl;
   std::cout<<"value7 after modulus plain_dec text is = "<< a[poly_modulus_degree-n]<<std::endl;
  std::cout<<"value8 after modulus plain_dec text is = "<< a[poly_modulus_degree-2*n]<<std::endl;
	*/
	for(int i=0;i<poly_modulus_degree;i++){
	
	
	//std::cout<<"value"<<i<<" "<<a[i]<<endl;
	
	}
	
	
    stringstream clint_Enc_feature_stream, ct_stram;
    auto size_clint_feature = encrypted_2.save(clint_Enc_feature_stream);
    auto ct_size = ct.save(ct_stram);



    std::cout<<"Before relinearize encryptio- size is = "<<size_clint_feature<<"B" <<std::endl;
    std::cout<<"Average one feature encryptio- size is = "<<size_clint_feature/2<<"B" <<std::endl;
    std::cout<<"After relinearize CT- size is = "<<ct_size <<"B" <<std::endl;
    std::cout<<"error budget = "<<decryptor.invariant_noise_budget(ct) <<std::endl;
    std::cout<<"constant is = "<<hex<<10000-400 <<std::endl;

	






    return 0;
}

