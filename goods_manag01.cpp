 //������� 
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
		}//��ʼ�� 
		
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
		//c++�ж�����Ϊ��������������������ֵ�������ǡ����ݵ�ַ�����˴��������ã������ݵ�ַ����
		//����Ļ���ֻ���޸���ֵ��������ı���󣬼�ֻ�����������ġ����޷���ɡ��� ����ɾ �������� 
		//java�ж�����Ϊ�����������������ݵ�ַ����	
}; 
void llist::insertnode(int noval,int numval){
	curr=head;
	while(curr->no < noval){
		if(curr->next==NULL||curr->next->no >= noval) break;
		//�˴��ж�������˳���ܵߵ�����Ϊ�����ԭ�����ǰ��ߵ�����������޷�ִ�С� 
		//��Ϊ�����һ���ڵ�ʱ��head->nextΪnull�������ʾ��curr->next->no�޷���ȡ�����������޷��жϣ������޷����С� 
		else curr=curr->next;		
	}
	if(curr->next!=NULL && curr->next->no==noval){//ͬһ����Ų����������ڵ�
		curr->next->num+=noval; 
	} 
	else{
    	curr->next=new node(noval,numval,curr->next);
	}
	if(curr==tail)
	tail=curr->next;
	
}//����ڵ� 
void llist::deletenode(){
	node* temp=curr->next;
	if(tail==curr->next)
	tail=curr;
	curr->next=curr->next->next;
	delete temp;
}//ɾ����ǰ�ڵ����һ���ڵ� 
void llist::setnum(int numval){
	curr->num+=numval;
}//�޸����� 
void llist::traversal(){
	curr=head->next;
	while(curr!=tail){
		int a=curr->no;
		int b=curr->num;
	    cout<<"����"<<" "<<a<<" "<<"����"<<" "<<b<<endl;
	    curr=curr->next; 
	} 	
    cout<<"����"<<" "<<curr->no<<" "<<"����"<<" "<<curr->num;
    cout<<endl;
}//������� 
void llist::update(llist &list1,llist &list2){//list1�����л���� list2����ӻ���� 
	if(list1.head->next==NULL){
		list1.head->next=list2.head->next;
	}
		//node* temp=NULL;//��סlist1�޸Ļ��߲���Ľڵ��λ�á� 
		list1.curr=list1.head->next;
		if(list2.head->next!=NULL){
     		list2.curr=list2.head->next;
	    	while(list2.curr!=NULL){//��ǰ�ڵ㲻Ϊ��		     
	    		while((list1.curr->next!=NULL)&&(list1.curr->no < list2.curr->no)&&(list1.curr->next->no <= list2.curr->no)){
	    			list1.curr=list1.curr->next;
				}
	    		//3���������ѭ����list1.curr.no=list2.curr.no�����ߣ�list1.curr.no<list2.curr.no��list1.curr->next->no > list2.curr->no ���� list.curr=list1.tail 
	    		if(list1.curr->no==list2.curr->no){
     		     	list1.setnum(list2.curr->num);//�޸����нڵ��ֵ 
     		     	//temp=list1.curr;
    		     	list2.curr=list2.head; //��ǰ����ɾ���ڵ� 
	    		    list2.deletenode(); //
	    		} 
	    		else{
	     			list1.insertnode(list2.curr->no,list2.curr->num);//�����µĽڵ� 
	    			list1.curr=list1.curr->next;
	    			list2.curr=list2.head;//��ǰ�ڵ�Ϊhead��ɾ������һ���ڵ� 
	     			list2.deletenode();
	    		}		    	
				
	     		list2.curr=list2.curr->next;			
	    		//list1.curr=temp;//�����С���򣬴��ϴβ���Ľڵ�����޸ĵĽڵ㿪ʼ���� 
	    	}	
    	}
}


int main(int argc, char** argv){
	int a=0,b=0;
	//a��ʾԭ�б��������b��ʾ���±������ 
	cout<<"���������б�Ÿ���"<<endl;
	cin>>a; 
	int no[]={0}; 
	int num[]={0};
	cout<<"���������б��"<<endl; 
	for(int i=0;i<a;i++){
		cin>>no[i];
	}
	 
	cout<<"�������������"<<endl;  
	for(int i=0;i<a;i++){
		cin>>num[i];
	}
	

	llist formerlist;
	for(int i=0;i<a;i++){
		formerlist.insertnode(no[i],num[i]);		
	}
	cout<<"���еĻ��������"<<endl;
	formerlist.traversal(); //�������л������ʾ 
	
	cout<<"��������ӱ�Ÿ���"<<endl; 
	cin>>b;
    cout<<"��������ӱ��"<<endl; 
	for(int i=0;i<b;i++)
	cin>>no[i]; 
	cout<<"�������������"<<endl;  
	for(int i=0;i<b;i++)
	cin>>num[i];
	
	llist laterlist;
	for(int i=0;i<b;i++){
		laterlist.insertnode(no[i],num[i]);
	}

	laterlist.traversal();//������ӻ������ʾ  
	formerlist.update(formerlist,laterlist);
	cout<<"���º�Ļ��������"<<endl; 
	formerlist.traversal(); 
}

