#include "SurveyClass.h"
#include <string>
#include <map>

SurveyClass::SurveyClass(){
members =  new LinkedList();
}
SurveyClass::SurveyClass(const SurveyClass &other){
    members=new LinkedList(*other.members);
}
SurveyClass& SurveyClass::operator=(const SurveyClass& list){
    delete members;
    members=new LinkedList(*list.members);

}
SurveyClass::~SurveyClass(){
cout<<"Destructed";
    if(members)
      delete members;

}

// Adds a new Member object to the linked list
void SurveyClass::addMember(const Member& newMember){
    members->pushTail(newMember);
}
// Calculates and returns the average age for the members of the class.
// The average age can have up to two decimal points..

float SurveyClass::calculateAverageAge(){
    Node *head = members->head;
    if(!head)
        return 0;

    float sum=0;
    int count=0;
    while(head){
        count++;
        sum+=head->data.age;
        head=head->next;
    }

    float avg = sum/count;
    float tempAvg = avg * 1000;
     if((int)tempAvg%10>=5)
         tempAvg += 10-(int)tempAvg%10;
     else{
         tempAvg -= (int)tempAvg%10;
     }
    avg = (int)tempAvg/1000.0;
    return avg;
}
// Finds the most favourite color and returns its name.
// The most favourite color is the color
// which is liked by the highest number of members.
string SurveyClass::findMostFavouriteColor(){
    map<string, int> list;
    int max=0;
    string maxColor = "";
    if(!members->head)
        return "";

    list[members->head->data.color]++;
    max++;
    Node *curr = members->head->next;

    while(curr){
        if(++list[curr->data.color]>max){
            max = list[curr->data.color];
            maxColor = curr->data.color;
        }
        curr = curr->next;
    }
        return maxColor;
    //old
    /*
    int max=0;
    string colorString="";
    string maxColor="";
    Node *head = members->head;
    if(head){
        colorString+=head->data.color;
        maxColor=head->data.color;
        head=head->next;
        max++;
    }
    while(head){
       // cout<<head->data.name<<endl;
        string s=head->data.color;
        colorString+=s;
        int index=0;
        int count=0;
        while(true){
            int temp=colorString.find(s, index);
            if(temp!=-1){
                //cout<<s<<endl;
                count++;
                index=temp+1;
            }
            else
                break;
        }
       // cout<<"count: "<< count<<endl;
        //cout<<"max: "<< max<<endl;
        if(count>max){
           // cout<<"değiştirildi: "<<s<<endl;
            maxColor=s;
            max=count;
        }
        head=head->next;
    }
    return maxColor;
     */
}