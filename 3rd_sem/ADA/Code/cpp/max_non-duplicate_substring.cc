/* Devansh (202308503) */
#include<iostream>
#include<string>
#include<unordered_map>

std::string max_non_duplicate_substring(const std::string& s);
bool is_non_duplicate_string(const std::string& s);
int camparison = 0;
int main(){
    std::string s = "qjsdgiuegcwdicbk"; //qjsdgiue
    std::string sub_s = max_non_duplicate_substring(s);
    std::cout<<"max non-duplicate substirng : "<<sub_s<<std::endl;
    std::cout<<" Camparison : "<<camparison<<std::endl;
    return 0;    
}

std::string max_non_duplicate_substring(const std::string& s){
    int s_len = s.length();
    if(s_len <= 1)return s;

    // start max len. substring and decresase one by one.
    for(int len = s_len; len >= 1; --len){

        for(int start = 0; start+len < s_len; ++start){
            std::string sub_s = s.substr(start, len);

            if(is_non_duplicate_string(sub_s))return sub_s; 
        }
    }

    return "";
}

bool is_non_duplicate_string(const std::string& s){
    std::unordered_map<char, int> umap;

    // Check for any character with more than 1 occurrence
    for(const char &c: s){
        camparison++;
        umap[c]++;
        if(umap[c]>1) return false;
    }
    return true;
}
