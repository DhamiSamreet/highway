#include<iostream>
#include<stdlib.h>
using namespace std;
class node1 {
    private:
        int r;
        float x;
        int d;
        float t;//t stored here is the time at which car enters or leaves
    public:
        int height;
        node1* left;
        node1* right;
        int getr(){
            return r;
        }
        float getx(){
            return x;
        }
        float gett(){
            return t;
        }
        int getd(){
            return d;
        }
        void read(node1* node,int r,float x,float t,int d){
            node->r=r;
            node->x=x;
            node->t=t;
            node->d=d;
        }
        void readr(node1* node,int r){
            node->r=r;
        }
};
class node2 {
    private:
        int r;
        float x;
        int d=1;
        float t;
    public:
        int height;
        node2 *left;
        node2 *right;
        int getr(){
            return r;
        }
        float getx(){
            return x;
        }
        int getd(){
            return d;
        }
        float gett(){
            return t;
        }
        void read(node2* node,int r,float x,float t){
            node->r=r;
            node->x=x;
            node->t=t;
        }
        void readr(node2* node,int r){
            node->r=r;
        }
};
class node3 {
    private:
        int r;
        float x;
        float t;
        int d=0;
    public:
        int height;
        node3 *left;
        node3 *right;
        int getr(){
            return r;
        }
        float getx(){
            return x;
        }
        int getd(){
            return d;
        }
        float gett(){
            return t;
        }
        void read(node3* node,int r,float x,float t){
            node->r=r;
            node->x=x;
            node->t=t;
        }
        void readr(node3* node,int r){
            node->r=r;
        }
};
//using 3 trees
//tree1: for registration number
//tree2: for cars going left to right direction
//tree3: for cars going right to left direction
node1* head1=NULL;
node2* head2=NULL;
node3* head3=NULL;
//useful information for avl tree 
int height1(node1 *node){
    if(node==NULL){
        return 0;
    }
    else{
        return node->height;
    }
}
int height2(node2 *node){
    if(node==NULL){
        return 0;
    }
    else{
        return node->height;
    }
}
int height3(node3 *node){
    if(node==NULL){
        return 0;
    }
    else{
        return node->height;
    }
}
int bigger(int p,int q){
    if(p>q){
        return p;
    }
    else{
        return q;
    }
}
int diff1(node1 *node){
    if(node==NULL){
        return 0;
    }
    else{
        return height1(node->left)-height1(node->right);
    }
}
int diff2(node2 *node){
    if(node==NULL){
        return 0;
    }
    else{
        return height2(node->left)-height2(node->right);
    }
}
int diff3(node3 *node){
    if(node==NULL){
        return 0;
    }
    else{
        return height3(node->left)-height3(node->right);
    }
}

node1 *leftrotate1(node1 *a){
	node1 *y=a->right;
	node1 *t1=y->left;
	a->right=t1;
	y->left=a;
    a->height = bigger(height1(a->left),height1(a->right)) + 1;  
    y->height = bigger(height1(y->left),height1(y->right)) + 1;
	return y;
}
node1 *rightrotate1(node1 *y){
	node1 *a=y->left;
	node1 *t2=a->right;
	y->left=t2;
	a->right=y;
    y->height = bigger(height1(y->left),height1(y->right)) + 1;
    a->height = bigger(height1(a->left),height1(a->right)) + 1;
	return a;
}
node2 *leftrotate2(node2 *a){
	node2 *y=a->right;
	node2 *t1=y->left;
	a->right=t1;
	y->left=a;
    a->height = bigger(height2(a->left),height2(a->right)) + 1;  
    y->height = bigger(height2(y->left),height2(y->right)) + 1;
	return y;
}
node2 *rightrotate2(node2 *y){
	node2 *a=y->left;
	node2 *t2=a->right;
	y->left=t2;
	a->right=y;
    y->height = bigger(height2(y->left),height2(y->right)) + 1;
    a->height = bigger(height2(a->left),height2(a->right)) + 1;
	return a;
}
node3 *leftrotate3(node3 *a){
	node3 *y=a->right;
	node3 *t1=y->left;
	a->right=t1;
	y->left=a;
    a->height = bigger(height3(a->left),height3(a->right)) + 1;  
    y->height = bigger(height3(y->left),height3(y->right)) + 1;
	return y;
}
node3 *rightrotate3(node3 *y){
	node3 *a=y->left;
	node3 *t2=a->right;
	y->left=t2;
	a->right=y;
    y->height = bigger(height3(y->left),height3(y->right)) + 1;
    a->height = bigger(height3(a->left),height3(a->right)) + 1;
	return a;
}
node1 *find1(node1 *node,int r){
    if(node==NULL){
        return NULL;
    }
    else if(node->getr()==r){
        return node;
    }
    else if(node->getr() > r){
        find1(node->left,r);
    }
    else{
        find1(node->right,r);
    }
}
node2 *find2(node2 *node,float x,float currt){
    if(node==NULL){
        return NULL;
    }
    if(node->getx()==x){
        return node;
    }
    find2(node->left,x,currt);
    find2(node->right,x,currt);
}
node3 *find3(node3 *node,float x,float currt){
    if(node==NULL){
        return NULL;
    }
    if(node->getx()==x){
        return node;
    }
    find3(node->left,x,currt);
    find3(node->right,x,currt);
}
node1* newNode1(int r,float x,float currt,int d)  
{  
    node1* node = new node1(); 
    node->read(node,r,x,currt,d);
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}  
node2* newNode2(int r,float currt,float x)  
{  
    node2* node = new node2(); 
    node->read(node,r,x,currt);
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}
node3* newNode3(int r,float currt,float x)  
{  
    node3* node = new node3(); 
    node->read(node,r,x,currt);
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; // new node is initially 
                      // added at leaf  
    return(node);  
}
node1 *insert1(node1 *node,int r,float x,float t,int d){
        if (node==NULL){
            return newNode1(r,x,t,d);
        }
        if(node->getr() > r){
            node->left=insert1(node->left,r,x,t,d);
        }
        else{
            node->right=insert1(node->right,r,x,t,d);
        }
        node->height=1+bigger(height1(node->right),height1(node->left));
        int b=diff1(node);
        if(b>1 && r < node->left->getr()){
            return rightrotate1(node);
        }
        if(b<-1 && r > node->right->getr()){
            return leftrotate1(node);
        }
        if(b>1 && r > node->left->getr()){
            node->left=leftrotate1(node->left);
            return rightrotate1(node);
        }
        if(b<-1 && r < node->right->getr()){
            node->right=rightrotate1(node->right);
            return leftrotate1(node);
        }
        return node;
}
node2 *insert2(node2 *node,int r,float x,float currt){
        if (node==NULL){
            return newNode2(r,x,currt);
        }
        if((node->getx())+(currt-(node->gett())) > x){
             node->left=insert2(node->left,r,x,currt);
        }
        else{
            node->right=insert2(node->right,r,x,currt);
        }
        node->height=1+bigger(height2(node->right),height2(node->left));
        int b=diff2(node);
        if(b>1 && x < node->left->getx()){
            return rightrotate2(node);
        }
        if(b<-1 && x > node->right->getx()){
            return leftrotate2(node);
        }
        if(b>1 && x > node->left->getx()){
            node->left=leftrotate2(node->left);
            return rightrotate2(node);
        }
        if(b<-1 && x < node->right->getx()){
            node->right=rightrotate2(node->right);
            return leftrotate2(node);
        }
        return node;
}
node3 *insert3(node3 *node,int r,float x,float currt){
    
        if (node==NULL){
            return newNode3(r,x,currt);
        }
        if((node->getx())-(currt-(node->gett())) > x){
            node->left=insert3(node->left,r,x,currt);
        }
        else{
            node->right=insert3(node->right,r,x,currt);
        }
        node->height=1+bigger(height3(node->right),height3(node->left));
        int b=diff3(node);
        if(b>1 && x < node->left->getx()){
            return rightrotate3(node);
        }
        if(b<-1 && x > node->right->getx()){
            return leftrotate3(node);
        }
        if(b>1 && x > node->left->getx()){
            node->left=leftrotate3(node->left);
            return rightrotate3(node);
        }
        if(b<-1 && x < node->right->getx()){
            node->right=rightrotate3(node->right);
            return leftrotate3(node);
        }
        return node;
}
node1 *delete1(node1 *node,int r,float t,float x,int d){
    if(find1(node,r)!=NULL){
        if (node==NULL){
            return node;
        }
        if(node->getr() > r){
            return node->left=delete1(node->left,r,t,x,d);
        }
        else if(node->getr() < r){
            return node->right=delete1(node->right,r,t,x,d);
        }
        else{
            if(node->left==NULL && node->right==NULL){
                node1 *temp=NULL;
                temp=node;
                node=NULL;
            }
            else if(node->left==NULL){
                node1 *temp=node->right;
                *node=*temp;
                return temp;
            }
            else if(node->left==NULL){
                node1 *temp=node->right;
                *node=*temp;
                return temp;
            }
            else{
                node1 *current=node;
                while(current->left!=NULL){
                    current=current->left;
                }
                node->readr(current,current->getr());
                node->right=delete1(node,current->getr(),current->gett(),current->getx(),current->getd());
            }
        }
        if(node==NULL){
            return node;
        }
        node->height=1+bigger(node->left->height,node->right->height);
        int b=diff1(node);
        if(b>1 && r < node->left->getr()){
            return rightrotate1(node);
        }
        if(b<-1 && r > node->right->getr()){
            return leftrotate1(node);
        }
        if(b>1 && r > node->left->getr()){
            node->left=leftrotate1(node->left);
            return rightrotate1(node);
        }
        if(b<-1 && r < node->right->getr()){
            node->right=rightrotate1(node->right);
            return leftrotate1(node);
        }
        return node;
    }
}
node2 *delete2(node2 *node,int r,float t,float x){
    if(find2(node,x,t)!=NULL){
        if (node==NULL){
            return node;
        }
        if(node->getx() > x){
            return node->left=delete2(node->left,r,t,x);
        }
        else if(node->getx() < x){
            return node->right=delete2(node->right,r,t,x);
        }
        else{
            if(node->left==NULL && node->right==NULL){
                node2 *temp=NULL;
                temp=node;
                node=NULL;
            }
            else if(node->left==NULL){
                node2 *temp=node->right;
                *node=*temp;
                return temp;
            }
            else if(node->left==NULL){
                node2 *temp=node->right;
                *node=*temp;
                return temp;
            }
            else{
                node2 *current=node;
                while(current->left!=NULL){
                    current=current->left;
                }
                node->readr(current,current->getr());
                node->right=delete2(node,current->getr(),current->gett(),current->getx());
            }
        }
        if(node==NULL){
            return node;
        }
        node->height=1+bigger(node->left->height,node->right->height);
        int b=diff2(node);
        if(b>1 && x < node->left->getx()){
            return rightrotate2(node);
        }
        if(b<-1 && x > node->right->getx()){
            return leftrotate2(node);
        }
        if(b>1 && x > node->left->getx()){
            node->left=leftrotate2(node->left);
            return rightrotate2(node);
        }
        if(b<-1 && x < node->right->getx()){
            node->right=rightrotate2(node->right);
            return leftrotate2(node);
        }
        return node;
    }
}
node3 *delete3(node3 *node,int r,float t,float x){
    if(find3(node,x,t)!=NULL){
        if (node==NULL){
            return node;
        }
        if(node->getx() > x){
            return node->left=delete3(node->left,r,t,x);
        }
        else if(node->getx() < x){
            return node->right=delete3(node->right,r,t,x);
        }
        else{
            if(node->left==NULL && node->right==NULL){
                node3 *temp=NULL;
                temp=node;
                node=NULL;
            }
            else if(node->left==NULL){
                node3 *temp=node->right;
                *node=*temp;
                return temp;
            }
            else if(node->left==NULL){
                node3 *temp=node->right;
                *node=*temp;
                return temp;
            }
            else{
                node3 *current=node;
                while(current->left!=NULL){
                    current=current->left;
                }
                node->readr(current,current->getr());
                node->right=delete3(node,current->getr(),current->gett(),current->getx());
            }
        }
        if(node==NULL){
            return node;
        }
        node->height=1+bigger(node->left->height,node->right->height);
        int b=diff3(node);
        if(b>1 && x < node->left->getx()){
            return rightrotate3(node);
        }
        if(b<-1 && x > node->right->getx()){
            return leftrotate3(node);
        }
        if(b>1 && x > node->left->getx()){
            node->left=leftrotate3(node->left);
            return rightrotate3(node);
        }
        if(b<-1 && x < node->right->getx()){
            node->right=rightrotate3(node->right);
            return leftrotate3(node);
        }
        return node;
    }
}
int count2(node2* node,int r,float t,int count){
    if(node==NULL){
        return 0;
    }
    else if (node->left==NULL && node->right==NULL){
        return count++;
    }
    else if(node->left!=NULL && node->right==NULL){
        count++;
        return count2(node->right,r,t,count);
    }
    else if(node->left!=NULL && node->right==NULL){
        count++;
        return count2(node->left,r,t,count);
    }
    else{
        return count2(node->right,r,t,count)+count2(node->left,r,t,count);
    }
    return count;
}
int count3(node3* node,int r,float t,int count){
    if(node==NULL){
        return 0;
    }
    else if (node->left==NULL && node->right==NULL){
        return count+1;
    }
    else if(node->left!=NULL && node->right==NULL){
        count++;
        return count3(node->right,r,t,count);
    }
    else if(node->left!=NULL && node->right==NULL){
        count++;
        return count3(node->left,r,t,count);
    }
    else{
        return count3(node->right,r,t,count)+count3(node->left,r,t,count);
    }
    return count;
}

//functions given in main question
int insert(int r,float x,float t,int d){
        head1=insert1(head1,r,t,x,d);
        if(d==0){
            head3=insert3(head3,r,x,t);
        }
        else if(d==1){
            head2=insert2(head2,r,x,t);
        }
        return 1;
    //}
}
int remove(int r,float t){
    if(find1(head1,r)==NULL){
        return 0;
    }
    else{
        float x=find1(head1,r)->getx();
        float d=find1(head1,r)->getd();
        head1=delete1(head1,r,t,x,d);
        if(d==1){
        head2=delete2(head2,r,t,x);
        }
        else if(d==0){
        head3=delete3(head3,r,t,x);
        }
        return 1;
    }
}
int find_immediate_left(int r,float t){
    node1 *temp=find1(head1,r);
    float t1=temp->gett();
    float x1=find1(head1,r)->getx();
    int d1=find1(head1,r)->getd();
    if(d1==1){
        node2* temp=find2(head2,x1,t);
        if(temp->left==NULL){
            return -1;
        }
        while(1){
            if(temp->right==NULL){
                break;
            }
             temp=temp->right;
        }
        int r2;
        float y2;
        int r1=temp->getr();
        float y1=x1-temp->getx();
        free(temp);
        x1=x1+t-t1;
        node3* temp1=head3;
        if((((temp1->getx())-(t-temp1->gett()))-x1)<0){
            temp1=temp1->left;
            while(temp1->right!=NULL){
                if(((temp1->getx())-(t-temp1->gett())-x1)<=(temp1->right->getx())-(t-temp1->right->gett())-x1){
                    int r2=temp1->getr();
                    break;
                }
                else{
                    temp1=temp1->right;
                }
            }
            if(temp1->right==NULL){
                int r2=temp->getr();
            }
        }
        else{
            temp1=temp1->right;
            while(temp1->left!=NULL){
                if(((temp1->getx())-(t-temp1->gett())-x1)<=(temp1->left->getx())-(t-temp1->left->gett())-x1){
                    int r2=temp1->getr();
                    float y2=x1-(temp1->getx())+(t-temp1->gett());
                    break;
                }
                else{
                    temp1=temp1->left;
                }
            }
            if(temp1->left==NULL){
                int r2=temp1->getr();
            }
            free(temp1);
        }
        if(y2>y1){
            return r1;
        }
        else{
            return r2;
        }
    }
    else{
        node3* temp=find3(head3,x1,t);
        if(temp->left==NULL){
            return -1;
        }
        temp=temp->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        int r2;
        float y2;
        int r1=temp->getr();
        float y1=x1-temp->getx();
        free(temp);
        x1=x1+t-t1;
        node2* temp2=head2;
        if((((temp2->getx())-(t-temp2->gett()))-x1)<0){
            temp2=temp2->left;
            while(temp2->right!=NULL){
                if(((temp2->getx())-(t-temp2->gett())-x1)<=(temp2->right->getx())-(t-temp2->right->gett())-x1){
                    r2=temp2->getr();
                    break;
                }
                else{
                    temp2=temp2->right;
                }
            }
            if(temp2->right==NULL){
                r2=temp2->getr();
            }
        }
        else{
            temp2=temp2->right;
            while(temp2->left!=NULL){
                if(((temp2->getx())-(t-temp2->gett())-x1)<=(temp2->left->getx())-(t-temp2->left->gett())-x1){
                    r2=temp2->getr();
                    y2=x1-(temp2->getx())+(t-temp2->gett());
                    break;
                }
                else{
                    temp2=temp2->left;
                }
            }
            if(temp2->left==NULL){
                r2=temp2->getr();
            }
            free(temp2);
            
        }
        if(y2>y1){
            return r1;
        }
        else{
            return r2;
        }
        
    }
}
int find_immediate_right(int r,float t){
    float t1=find1(head1,r)->gett();
    float x1=find1(head1,r)->getx();
    int d1=find1(head1,r)->getd();
    if(d1==1){
        node2* temp=find2(head2,x1,t);
        if(temp->right==NULL){
            return -1;
        }
        temp=temp->right;
        while(temp->left!=NULL){
            temp->left;
        }
        int r2;
        float y2;
        int r1=temp->getr();
        float y1=x1-temp->getx();
        x1=x1+t-t1;
        node3* temp3=head3;
        if((((temp3->getx())-(t-temp3->gett()))-x1)<0){
            temp3=temp3->right;
            while(temp3->left!=NULL){
                if(((temp3->getx())-(t-temp3->gett())-x1)<=(temp3->left->getx())-(t-temp3->left->gett())-x1){
                    r2=temp3->getr();
                    break;
                }
                else{
                    temp3=temp3->left;
                }
            }
            if(temp3->left==NULL){
                r2=temp3->getr();
            }
        }
        else{
            temp3=temp3->left;
            while(temp3->right!=NULL){
                if(((temp3->getx())-(t-temp3->gett())-x1)<=(temp3->right->getx())-(t-temp3->right->gett())-x1){
                    r2=temp3->getr();
                    y2=x1-(temp3->getx())+(t-temp3->gett());
                    break;
                }
                else{
                    temp3=temp3->right;
                }
            }
            if(temp3->right==NULL){
                r2=temp3->getr();
            }
            free(temp3);
            free(temp);
        }
        if(y2>y1){
            return r1;
        }
        else{
            return r2;
        }
    }
    else{
        node3* temp=find3(head3,x1,t);
        if(temp->right==NULL){
            return -1;
        }
        temp=temp->right;
        while(temp->left!=NULL){
            temp->left;
        }
        int r2;
        float y2;
        int r1=temp->getr();
        float y1=x1-temp->getx();
        x1=x1+t-t1;
        node2* temp4=head2;
        if((((temp4->getx())-(t-temp4->gett()))-x1)<0){
            temp4=temp4->right;
            while(temp4->left!=NULL){
                if(((temp4->getx())-(t-temp4->gett())-x1)<=(temp4->left->getx())-(t-temp4->left->gett())-x1){
                    r2=temp4->getr();
                    break;
                }
                else{
                    temp4=temp4->left;
                }
            }
            if(temp4->left==NULL){
                r2=temp4->getr();
            }
        }
        else{
            temp4=temp4->left;
            while(temp4->right!=NULL){
                if(((temp4->getx())-(t-temp4->gett())-x1)<=(temp4->right->getx())-(t-temp4->right->gett())-x1){
                    r2=temp->getr();
                    y2=x1-(temp->getx())+(t-temp->gett());
                    break;
                }
                else{
                    temp4=temp4->right;
                }
            }
            if(temp4->right==NULL){
                r2=temp4->getr();
            }
            free(temp);
            free(temp4);
        }
        if(y2>y1){
            return r1;
        }
        else{
            return r2;
        }
    }
}
int count_left(int r,float t){
    int count=0;
    float t1=find1(head1,r)->gett();
    float x1=find1(head1,r)->getx();
    int d1=find1(head1,r)->getd();
    if (d1==1){
        count=count2(find2(head2,x1,t)->left,r,t,0);
        node3* node=head3;
        if((node->getx()-t+t1)<(x1+t-t1)){
            count=count+count3(node->left,r,t,count);
            while(1){
                if(node->right!=NULL){
                    if((node->right->getx()-t+t1)<(x1+t-t1)){
                        count=count+count3(node->left,r,t,count);
                        node=node->right;
                    }
                }
                else{
                    break;
                }
            }
            return count;
        }
        else{
            while((node->getx()-t+t1)<(x1+t-t1)){
                node=node->left;
            }
            while((node->right->getx()-t+t1)<(x1+t-t1)){
                count=count+count3(node->left,r,t,count);
                node=node->right;
            }
            return count;
        }
    }
    else{
        count=count3(find3(head3,x1,t)->left,r,t,0);
        node2* node=head2;
        if((node->getx()+t-t1)<(x1-t+t1)){
            count=count+count2(node->left,r,t,count);
            while(1){
                if(node->right!=NULL){
                    if((node->right->getx()-t+t1)<(x1+t-t1)){
                        count=count+count2(node->left,r,t,count);
                        node=node->right;
                    }
                }
                else{
                    break;
                }
            }
            return count;
        }
        else{
            while((node->getx()-t+t1)<(x1+t-t1)){
                node=node->left;
            }
            while((node->right->getx()-t+t1)<(x1+t-t1)){
                count=count+count2(node->left,r,t,count);
                node=node->right;
            }
            return count;
        }
    }
}
int count_right(int r,float t){
    int count=0;
    float t1=find1(head1,r)->gett();
    float x1=find1(head1,r)->getx();
    int d1=find1(head1,r)->getd();
    if (d1==1){
        count=count2(find2(head2,x1,t)->right,r,t,0);
        node3* node=head3;
        if((node->getx()-t+t1)<(x1+t-t1)){
            count=count+count3(node->right,r,t,count);
            while(1){
                if(node->left!=NULL){
                    if((node->left->getx()-t+t1)<(x1+t-t1)){
                        count=count+count3(node->right,r,t,count);
                        node=node->left;
                    }
                }
                else{
                    break;
                }
            }
            return count;
        }
        else{
            while((node->getx()-t+t1)<(x1+t-t1)){
                node=node->right;
            }
            while((node->left->getx()-t+t1)<(x1+t-t1)){
                count=count+count3(node->right,r,t,count);
                node=node->left;
            }
            return count;
        }
    }
    else{
        count=count3(find3(head3,x1,t)->right,r,t,0);
        node2* node=head2;
        if((node->getx()+t-t1)<(x1-t+t1)){
            count=count+count2(node->right,r,t,count);
            while(1){
                if(node->left!=NULL){
                    if((node->left->getx()-t+t1)<(x1+t-t1)){
                        count=count+count2(node->right,r,t,count);
                        node=node->left;
                    }
                }
                else{
                    break;
                }
            }
            return count;
        }
        else{
            while((node->getx()-t+t1)<(x1+t-t1)){
                node=node->right;
            }
            while((node->left->getx()-t+t1)<(x1+t-t1)){
                count=count+count2(node->right,r,t,count);
                node=node->left;
            }
            return count;
        }
    }
}


//below function is getting segmentation fault



/*int number_of_crossing(int getr(),float gett()){
    float t1=find1(head1,r)->gett();
    float x1=find1(head1,r)->getx();
    int d1=find1(head1,r)->d;
    int counta=0,countb=0;
    if(d1==1){
        node2* node=head2;
        if((node->getx()+gett()-t1)<(x1-gett()+t1)){
            counta=counta+count2(node->right,getr(),gett(),counta);
            while((node->left->getx()-gett()+t1)<(x1+gett()-t1)){
                counta=counta+count2(node->right,getr(),gett(),counta);
                node=node->left;
            }
            counta=counta+1;
        }
        else{
            while((node->getx()-gett()+t1)<(x1+gett()-t1)){
                node=node->right;
            }
            while((node->left->getx()-gett()+t1)<(x1+gett()-t1)){
                counta=counta+count2(node->right,getr(),gett(),counta);
                node=node->left;
            }
            counta=counta+1;
        }
        if((node->getx()+gett())<(x1-gett())){
            countb=countb+count2(node->right,getr(),gett(),countb);
            while((node->left->getx()-gett())<(x1+gett())){
                countb=countb+count2(node->right,getr(),gett(),countb);
                node=node->left;
            }
            countb= countb+1;
        }
        else{
            while((node->getx()-gett())<(x1+gett())){
                node=node->right;
            }
            while((node->left->getx()-gett())<(x1+gett())){
                countb=countb+count2(node->right,getr(),gett(),countb);
                node=node->left;
            }
            return countb+1;
        }
        return countb-counta;
    }
    
    else{
        node3* node=head3;
        if((node->getx()+gett()-t1)<(x1-gett()+t1)){
            counta=counta+count3(node->right,getr(),gett(),counta);
            while((node->left->getx()-gett()+t1)<(x1+gett()-t1)){
                counta=counta+count3(node->right,getr(),gett(),counta);
                node=node->left;
            }
            counta=counta+1;
        }
        else{
            while((node->getx()-gett()+t1)<(x1+gett()-t1)){
                node=node->right;
            }
            while((node->left->getx()-gett()+t1)<(x1+gett()-t1)){
                counta=counta+count3(node->right,getr(),gett(),counta);
                node=node->left;
            }
            counta=counta+1;
        }
        if((node->getx()+gett())<(x1-gett())){
            countb=countb+count3(node->right,getr(),gett(),countb);
            while((node->left->getx()-gett())<(x1+gett())){
                countb=countb+count3(node->right,getr(),gett(),countb);
                node=node->left;
            }
            countb= countb+1;
        }
        else{
            while((node->getx()-gett())<(x1+gett())){
                node=node->right;
            }
            while((node->left->getx()-gett())<(x1+gett())){
                countb=countb+count3(node->right,getr(),gett(),countb);
                node=node->left;
            }
            return countb+1;
        }
        return countb-counta;
    }
}*/
int main(){
    int n,i,k;
    cin >> n;
    for(i=0;i<n;i++){
        int a[10];
        cin >> a[0];
        int j;
        if(a[0]==1){
            for(j=1;j<=4;j++){
                cin >> a[j];
            }
            k=insert(a[1],a[2],a[3],a[4]);
            if (k==0){
                cout << "invalid input"<<endl;
            }
        }
        else if(a[0]==2){
            cin >> a[1];
            cin >> a[2];
            k=remove(a[1],a[2]);
            if(k==0){
                cout << "invalid input" <<endl;
            }
        }
        
        else if(a[0]==3){
            for(j=1;j<=2;j++){
                cin >> a[j];
            }
            k=find_immediate_left(a[1],a[2]);
            cout << k <<endl;
        }
        else if(a[0]==4){
            cin >> a[1];
            cin >> a[2];
            k=find_immediate_right(a[1],a[2]);
            cout << k<< endl;
        }
        else if(a[0]==5){
            cin >> a[1];
            cin >> a[2];
            k=count_left(a[1],a[2]);
            cout << k <<endl;
        }
        else if(a[0]==6){
            cin >> a[1];
            cin >> a[2];
            k=count_right(a[1],a[2]);
            cout << k <<endl;
        }
        /*else if(a[0]==7){
            cin >> a[1];
            cin >> a[2];
            k=number_of_crossing(a[1],a[2]);
            cout << "part 7 not done" <<endl;
        }*/
        else{
            cout <<"invalid input"<<endl;
        }
    }
}