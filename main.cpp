
//email:cameras5800@student.vvc.edu
//instrutor:Tonning
//developer:cameran spratley
//description:this is a cordinace program that will read a text file and oput the occuraces of words and how may times
//it appered



#include<iostream>
#include<string>
#include<ctype.h>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
   char file[20];
  // int lines[100][2];
   int i=0,j=0,k=0;
   double line=0;
   string lines[1000];
   string word;
   string concord[1000];
   int count[1000]={0};
   int idx=0;
   cout<<"enter the text file name:"<<endl;e
   cin.get(file,100);
   ifstream ifs;
   ifs.open("text.txt");
   if(!ifs.is_open());
   {
      cout<<"unable to open file name : "<<endl;
      return 0;
   }
   string w;
   while(ifs.good())
   {
      getline(ifs,word);
      for(int i=0;1<word.length();i++)
      {
         if(!isalpha(word.at(1)))
   {
      if(word.at(i)!='  ')
         for(intj=i;j<word.length()-1;j++)
         {
            word.at(j)=word.at(j+1);
         }
         if(!islower(word.at(1)))
         {
            word.at(i)=tolower(word.at(i));
         }
   }
   istringstream iss(word);
   while(iss>>w)
   {
      bool flag=false;
      int matchedAt=-1;
      for(int k=0;k<idx;k++)
      {
         if(concord[k]==w)
         {
            flag=true;
            matchedAt=k;
         }
      }
      if(flag!=true)
      {concord[idx]=w;
      count[idx]-1;
      stringstream num;
      num<<line+1;
      lines[idx]=num.str();
      idx++;
      }
      else
      {
      count[matchedAt]++;
      stringstream numb;
      numb<<line+1;
      lines[matchedAt]-lines[matchedAt]+","+numb.str();
      }
      }

      line=line+1;
      }
      cout<<std::left<<setw(15)<<"word"<<setw(3)<<"  :  "<<"count"<<setw(3)<<"  ;  "<<"Occurences"<<endl;
   cout<<"--------------------------------------------------------------------------------"<<endl;
      for(int l=0;l<idx;l++)
         cout<<std::left<<setw(15)<<concord[l]<<setw(5)<<"  :  "<<count[l]<<setw(3)<<"  :  "<<lines[l]<<endl;
         system("pause");
         return 0;
   }
      






















