#pragma once
#include<iostream>
#include <string>
#include <string_view>
#include <vector>
using std::string;
using std::vector;
using std::string_view;
class Split{
public:
    Split(string buffer){
        this->buffer=buffer;
    }
    void Spilt_With_Char(const char symbol){
        string_view view=buffer;    
        for(int i=0;i<view.size();i++){
            int beg=i;
            i = view.find(symbol,beg);
            string_view sub_view = view.substr(beg,i-beg);
            result.push_back(sub_view);
            if(i==string::npos) break;
        }
    }

    void Spilt_With_Str(const string symbol){
        string_view view=buffer;
        size_t len=symbol.length();
        for(int i=0;i<view.size();i++){
            int beg=i;
            i = view.find(symbol,beg);
            string_view sub_view = view.substr(beg,i-beg);
            result.push_back(sub_view);
            if(i==string::npos) break;
            i+=len-1;
        }
    }

    void Set_Buffer(string buffer){
        this->buffer=buffer;
    }

    void Clean_Buffer(){
        buffer.clear();
    }

    vector<string_view> Get_Result(){
        return result;
    }
private:
    void Clean_Result(){
        result.clear();
    }

private:
    /*
    result提供查看字符串的视图，这样，原字符串不会受到影响，只是相当于将buffer分隔查看
    */

    string buffer;
    vector<string_view> result;
};