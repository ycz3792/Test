 //货物管理 
#include <iostream>
using namespace std;

class node{
	public:
	int no,num;
	node* next;
	node(int noval=0,int numval=0,node* nextval=NULL){
		no=noval;
		num=numval;
		next=nextval;
	}
	~node(){
	}
};
 
class llist{
	private:
		node* head;
		node* curr;
		node* tail;
		
		void init(){
			head=tail=curr= new node;
		}//初始化 
		
	public:
		llist(){
			init();
		}
		~llist(){
		}
		void insertnode(int noval=1,int numval=0);
		void deletenode();
		void setnum(int numval=0);
		void traversal();
		void update(llist &list1,llist &list2);	
		//c++中对象作为函数参数，做“传递数值”，而非“传递地址”，此处采用引用，“传递地址”。
		//否则的话，只是修改数值，并不会改变对象，即只对链表做“改”，无法完成“增 ”“删 ”操作。 
		//java中对象作为函数参数，做“传递地址”。	
}; 
void llist::insertnode(int noval,int numval){
	curr=head;
	while(curr->no < noval){
		if(curr->next==NULL||curr->next->no >= noval) break;
		//此处判断条件的顺序不能颠倒，因为编译的原因，如果前后颠倒条件，则会无法执行。 
		//因为插入第一个节点时，head->next为null，乱码表示，curr->next->no无法获取，导致条件无法判断，程序无法运行。 
		else curr=curr->next;		
	}
	if(curr->next!=NULL && curr->next->no==noval){//同一个编号不会有两个节点
		curr->next->num+=noval; 
	} 
	else{
    	curr->next=new node(noval,numval,curr->next);
	}
	if(curr==tail)
	tail=curr->next;
	
}//插入节点 
void llist::deletenode(){
	node* temp=curr->next;
	if(tail==curr->next)
	tail=curr;
	curr->next=curr->next->next;
	delete temp;
}//删除当前节点的下一个节点 
void llist::setnum(int numval){
	curr->num+=numval;
}//修改数量 
void llist::traversal(){
	curr=head->next;
	while(curr!=tail){
		int a=curr->no;
		int b=curr->num;
	    cout<<"货号"<<" "<<a<<" "<<"数量"<<" "<<b<<endl;
	    curr=curr->next; 
	} 	
    cout<<"货号"<<" "<<curr->no<<" "<<"数量"<<" "<<curr->num;
    cout<<endl;
}//链表遍历 
void llist::update(llist &list1,llist &list2){//list1是已有货物表 list2是添加货物表 
	if(list1.head->next==NULL){
		list1.head->next=list2.head->next;
	}
		//node* temp=NULL;//记住list1修改或者插入的节点的位置、 
		list1.curr=list1.head->next;
		if(list2.head->next!=NULL){
     		list2.curr=list2.head->next;
	    	while(list2.curr!=NULL){//当前节点不为空		     
	    		while((list1.curr->next!=NULL)&&(list1.curr->no < list2.curr->no)&&(list1.curr->next->no <= list2.curr->no)){
	    			list1.curr=list1.curr->next;
				}
	    		//3种情况跳出循环，list1.curr.no=list2.curr.no，或者；list1.curr.no<list2.curr.no且list1.curr->next->no > list2.curr->no 或者 list.curr=list1.tail 
	    		if(list1.curr->no==list2.curr->no){
     		     	list1.setnum(list2.curr->num);//修改已有节点的值 
     		     	//temp=list1.curr;
    		     	list2.curr=list2.head; //从前往后删除节点 
	    		    list2.deletenode(); //
	    		} 
	    		else{
	     			list1.insertnode(list2.curr->no,list2.curr->num);//插入新的节点 
	    			list1.curr=list1.curr->next;
	    			list2.curr=list2.head;//当前节点为head，删除其下一个节点 
	     			list2.deletenode();
	    		}		    	
				
	     		list2.curr=list2.curr->next;			
	    		//list1.curr=temp;//链表大小有序，从上次插入的节点或者修改的节点开始更新 
	    	}	
    	}
}


int main(int argc, char** argv){
	int a=0,b=0;
	//a表示原有编号数量，b表示更新编号数量 
	cout<<"请输入已有编号个数"<<endl;
	cin>>a; 
	int no[]={0}; 
	int num[]={0};
	cout<<"请输入已有编号"<<endl; 
	for(int i=0;i<a;i++){
		cin>>no[i];
	}
	 
	cout<<"请输入货物数量"<<endl;  
	for(int i=0;i<a;i++){
		cin>>num[i];
	}
	

	llist formerlist;
	for(int i=0;i<a;i++){
		formerlist.insertnode(no[i],num[i]);		
	}
	cout<<"已有的货物表如下"<<endl;
	formerlist.traversal(); //创建已有货物表并显示 
	
	cout<<"请输入添加编号个数"<<endl; 
	cin>>b;
    cout<<"请输入添加编号"<<endl; 
	for(int i=0;i<b;i++)
	cin>>no[i]; 
	cout<<"请输入货物数量"<<endl;  
	for(int i=0;i<b;i++)
	cin>>num[i];
	
	llist laterlist;
	for(int i=0;i<b;i++){
		laterlist.insertnode(no[i],num[i]);
	}

	laterlist.traversal();//创建添加货物表并显示  
	formerlist.update(formerlist,laterlist);
	cout<<"更新后的货物表如下"<<endl; 
	formerlist.traversal(); 
}

