// struct TrieNode{
//     public:
//         bool end;
//         string data;
//         vector<TrieNode*>children;
//         // TrieNode(string &s=""):data(s),end(false){};
//         TrieNode(string &str = ""){
//             data = str;
//             end = false;
//         }
//         // getChar
//         TrieNode * containsKey(string str){
//             for(auto child : children){
//                 if(child->data==str)return child;
//             }
//             return NULL;
//         }
//         // puts
//         void puts(TrieNode* node,string str) {
//             node->data=str;
//             children.push_back(node);
//         }

//         //setEnd
//         void setEnd(){
//             end = true;
//         }
        
//         // isEnd()
//         void isEnd(){
//             return end;
//         }
// }
// class Trie{
//     TrieNode * root;
//     public:
//         Trie(){
//             root = new TrieNode(); // initaliation
//         }
//         Trie * node = root
//         // insert folder
//         void insert(string word){
//             for(auto str : word){
//                 string s = "";
//                 int i = 1;
//                 while(i<str.size()){
//                     if(str[i]=='/')break;
//                     s+=str[i];
//                 }


//                if(node->containskey(s)){
//                     node=node->gets(s);
//                }
//                node->puts(node)

//             }
//         }
//         // isFolder present first end mill wo hi ans
// }
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
      sort(folder.begin(),folder.end());
      vector<string>ans;
      ans.push_back(folder[0]);

      for(int i =1;i<folder.size();++i){
        string root  = ans.back()+'/';
        string prefix = folder[i].substr(0,root.size());
        if(root==prefix)continue;
        ans.push_back(folder[i]);
      }
      return ans;
    }
};