/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1; 
        // dirn = 0 ->left to right
        //        1=top to down
        //        2= right->left
        //        3 = down to top
        vector<vector<int>>mat(m,vector<int>(n,-1));
        int dirn = 0;
        ListNode* ptr = head;
        while(top<=down && left<=right ){
            if(dirn==0){
                // const = row
                // order = left to right 
                for(int i =left;ptr!=NULL&& i<=right;++i){
                    mat[top][i]=ptr->val;
                        ptr =ptr->next;
                }
                top++;
            }
            if(dirn ==1){
                // const = col
                // order =  top to bottom 
                for(int i =top;ptr!=NULL && i<=down;++i){
                    mat[i][right]=ptr->val;
                    if(ptr!=NULL)
                        ptr =ptr->next;
                }
                right--;
            }
            if(dirn==2){
                // const = row
                // order =  right to left 
                for(int i =right;ptr!=NULL && i>=left;--i){
                    mat[down][i]=ptr->val;
                   
                        ptr =ptr->next;
                }
                down--;
            }
            if(dirn == 3){
                // const = col
                // order =  down to top 
                for(int i =down;ptr!=NULL && i>=top;--i){
                    mat[i][left]=ptr->val;
                        ptr =ptr->next;
                }
                left++;
            }
            dirn= (dirn+1)%4;
        }
        return mat;
    }
};