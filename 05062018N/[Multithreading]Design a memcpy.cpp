/*
https://www.nowcoder.com/questionTerminal/9602083ec8d749999d86adf8a725b4f7
memcpy() is used to copy a block of memory from a location to another. 
*/
#include<iostream>
using namespace std;

void *memcpy(void *dst, const void *src, size_t len)
{
    if(NULL == dst || NULL == src){
        return NULL;
    }

    void *ret = dst;

    if(dst <= src || (char *)dst >= (char *)src + len){
//没有内存重叠，从低地址开始复制
        while(len--){
            *(char *)dst = *(char *)src;
            dst = (char *)dst + 1;
            src = (char *)src + 1;
        }
    }else{
//有内存重叠，从高地址开始复制
        src = (char *)src + len - 1;
        dst = (char *)dst + len - 1;
        while(len--){
            *(char *)dst = *(char *)src;
            dst = (char *)dst - 1;
            src = (char *)src - 1;
        }
    }
    return ret;
}

int main(int argc, char *argv[])  
{  
    char buf[100] = "abcdefghijk";  
    memcpy(buf+2, buf, 5);  
    cout<<buf+2; 
    return 0;  
}  
