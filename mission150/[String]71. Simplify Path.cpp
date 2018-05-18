/*
归下类的话，有四种字符串：
1. "/"：为目录分隔符，用来分隔两个目录。
2. "."：当前目录
3. ".."：上层目录
4. 其他字符串：目录名
*/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        int i=0;
        while(i < path.size()){
            //======>跳过开头
            while(path[i]=='/' && i<path.size()) i++; 
            if(i==path.size())  break;//如果全是///
            
            //======>找到每个词
            int start=i;
            while(path[i] !='/' && i<path.size()) i++; //找到每个词的end
            int end=i-1;
            string element = path.substr(start, end-start+1);//取出每个词
            
            //======>判断是..的情况
            if(element==".."){//去上层目录
                if(dir.size()>0)    
                    dir.pop_back();
            }
            //======>判断是非.的情况，什么都不需要干，直接开始寻找下一个element
            else if(element !=".")  //.就什么都不做，非.就存进一个词
                dir.push_back(element);
        }
        //======>如果一个词都没有
        if(dir.size()==0)   return "/";
        
        //======>将词+/，串起来
        string simpPath;
        for(int i=0; i<dir.size(); i++){
            simpPath += "/" + dir[i];
        }
        return simpPath;
    }
};