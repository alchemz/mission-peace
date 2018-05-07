void*Memcpy(void *dst, const void *src, size_t size);  
   
int main(intargc, char *argv[])  
{  
    char buf[100] = "abcdefghijk";  
    memcpy(buf+2, buf, 5);  
    //Memcpy(buf+2, buf, 5);  
    printf("%s\n", buf+2);  
   
         return 0;  
}  
   
void*Memcpy(void *dst, const void *src, size_t size)  
{  
    char *psrc;  
    char *pdst;  
          
    if(NULL == dst || NULL == src)  
    {  
        return NULL;  
    }  
          
    if((src < dst) && (char *)src +size > (char *)dst) // 自后向前拷贝  
    {  
        psrc = (char *)src + size - 1;  
        pdst = (char *)dst + size - 1;  
        while(size--)  
        {  
            *pdst-- = *psrc--;  
        }  
    }  
    else  
    {  
        psrc = (char *)src;  
        pdst = (char *)dst;  
        while(size--)  
        {  
            *pdst++ = *psrc++;  
        }  
    }  
          
    return dst;  
}

链接：https://www.nowcoder.com/questionTerminal/9602083ec8d749999d86adf8a725b4f7
来源：牛客网

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