/*Complete the functions below*/
int find(int parent[], int i) {
    // add code here
    if(i==parent[i])return i;
    
    return (find(parent,parent[i]));
}

void unionSet(int parent[], int x, int y) {
    // add code here.
    int x_parent=find(parent,x);
    int y_parent=find(parent,y);
    if(x_parent!=y_parent){
        parent[x_parent]=y_parent;
    }
}