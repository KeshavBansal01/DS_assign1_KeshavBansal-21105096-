                   ////Name= Keshav Bansal/////
                   ////Sid = 21105096 ECE G2///
                   //// Assignment N0. 1 ////
                   ////Family linked list////

//////////////////////////////////////////////////////////////////


#include<bits/stdc++.h>
using namespace std;



// Node of  linked list containing data is named as member here and contain  : Name and age of family members 
 
struct member
{
    string name;
    int age;
    member *previous;
    member *next;

};

class family
{ 
    
   member *tail=NULL;
   member *head=NULL;

   public:

 //Lets write a function to add new members from front//
    
    void member_front(string name,int age)
    {
        member *person = new member();
        person->age = age;
        person->name = name;
        if(tail==NULL)
            tail=person;
        if(head==NULL)
           person->previous=NULL;
        else
           {person->previous=head;
            head->next= person;}

        person->next=NULL;
        head=person;

    }




 ////Lets write a function to add new members from back or tail////
        void member_back(string name,int age)
    {
        member *person = new member();
        person->age = age;
        person->name = name;
        if(head==NULL)
            head=person;
        if(tail==NULL)
           person->next=NULL;
        else
           {person->next=tail;
           tail->previous=person;}

        person->previous=NULL;
        tail=person;

    }




    
    void deleteFromTail(int n)//The number of members to be deleted is n////
    {
        cout<<endl;

        if(head==NULL)
          { cout<<"No members are left in the list.";
            return;
          }

        if(head==tail)
        {
            cout<<head->name<<" is deleted.";
            member *temp = head;
             delete temp;
            head=NULL;
            tail=NULL;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            member *temp = tail;
            tail= tail->next;
            tail->previous=NULL;
            cout<<temp->name<<", ";
            delete temp;
            
        }

        cout<<"is deleted.";

    }




    void deleteFromHead(int n)//n is the number of members to be deleted
    {
        cout<<endl;
        if(head==NULL)
          { cout<<"NO members are left in the list.";
            return;
          }


        if(head==tail)
        {
            cout<<head->name<<" is deleted.";
             member *temp = head;
             delete temp;
            head=NULL;
            tail=NULL;
            return;
        }
        

        for(int i=0;i<n;i++)
        {
            member *temp = head;
            head=head->previous;
            head->next=NULL;
            cout<<temp->name<<", ";
            delete temp;
            
        }

        cout<<"is deleted.";

    }



////TO Simultaneously remove and store the member at head////
    member* popHead()
    {   
        if(head==NULL)
           {cout<<"no members left in the list.";
           return 0;}

        if(head==tail)
        {
           
            member *temp = head;
            head=NULL;
            tail=NULL;
            return temp ;
        }

        member *temp= head;
        head=head->previous;
        head->next=NULL;
        temp->previous=NULL;

        return temp;
    }



////To Simultaneously remove and store the member at tail////

    member* popTail()
    {
        if(head==NULL)
           {cout<<"No members are  left in the list.";
           return 0;}

        if(head==tail)
        {
           
            member *temp = head;
            head=NULL;
            tail=NULL;
            return temp ;
        }

        member* temp= tail;
        tail=tail->next;
        tail->previous=NULL;
        temp->next=NULL;
        
        return temp;
    }



////Way to show family starting from tail////
    void displayFromTail()
    {
        cout<<endl;
         if(head==NULL)
           {cout<<"no members left in the list."; 
           return;}
        
        member* temp = tail;
        cout<<"Tail <-->";
        while(temp!=NULL)
        {
            cout<<"("<<temp->name<<","<<temp->age<<")";
            cout<<"<-->";

            temp=temp->next;
        }
        cout<<"Head";
    }


//// Way to show family starting from head///

    void displayFromHead()
    {  cout<<endl;
         if(head==NULL)
           {cout<<"No  members are  left in the list.";
           return;}
        member* temp = head;
        cout<<"Head<-->";
        while(temp!=NULL)
        {
            cout<<"("<<temp->name<<","<<temp->age<<")";
            cout<<"<-->";

            temp=temp->previous;
        }
        cout<<"Tail";
    }

};





int main()
{ 
    family Bansal;
    Bansal.member_front("Keshav",7);
    Bansal.member_front("Aman",18);
    Bansal.member_front("Swapnil",25);
    Bansal.member_front("Shantanu",35);
    Bansal.member_back("Jai",10);
    Bansal.displayFromHead();
    cout<<endl;
    Bansal.displayFromTail();
    cout<<endl;
    Bansal.deleteFromHead(2);
    Bansal.displayFromHead();
    Bansal.displayFromTail();
   
    cout<<endl<<Bansal.popTail()->name;
    Bansal.displayFromTail();
    return 0;
}

//////Bonus Question/////
//As there are only two ways to transverse, we can link different members in a family using linked list only accoring to their ages else there are many cases to be 
// considered 
//like elder and younger in the hierarchy like the elder one on the head and the younger one on the tail....