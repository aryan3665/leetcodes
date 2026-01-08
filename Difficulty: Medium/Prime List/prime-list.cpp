// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
  
  int nearestprime(int k){
         int prev=k-1;
      int next=k+1;
      while(true){
   
      if(prev>=2 && isprime(prev))return prev;
      if(isprime(next))return next;
      --prev;
      ++next;
      }
      
      
  }
  bool isprime(int n){
      if(n<=1)return false;
      for(int i=2;i*i<=n;i++){
          if(n%i==0)return false;
      }
      
      return true;
  }
    Node *primeList(Node *head) {
        // code here
        if(!head)return NULL;
        
        Node*curr=head;
        while(curr){
            if(isprime(curr->val)){
                curr=curr->next;
            }
            else{
               int d= nearestprime(curr->val);
               curr->val=d;
               curr=curr->next;
            }
        }
        
        return head;
        
    }
};