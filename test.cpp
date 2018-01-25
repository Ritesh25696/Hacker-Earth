CNode* getpos(CNode* start, int n){
    CNode* prev = start;
CNode* next = start->next;

while(true){
    if(prev.value <= n && n <= next->value) break;
    prev=next; next=next->next;
}

CNode* node = new CNode();
node->value = n;
prev->next=node; node->next=next;

return node;

}
