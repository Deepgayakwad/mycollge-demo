class solution{

     private: 
     void insertAtTail(Node* &head,Node* &tail,int d){
        //  create a new node
        Node* newNode=new Node(d);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
     }
    public:
    Node *copyList(Node *head)
    {
        
        // step-1 create a clone linked list 
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        // create a map
        unordered_map<Node*,Node*>oldToNewNode;
       Node* originalNode=head;
        Node* cloneNode=cloneHead;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            oldToNewNode[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        
        originalNode=head;
        cloneNode=cloneHead;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            
        cloneNode->arb=oldToNewNode[originalNode->arb];
        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
        }
        
      return cloneHead;
    }

};