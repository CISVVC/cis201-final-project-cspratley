
//email:cameras5800@student.vvc.edu
//instrutor:Tonning
//developer:cameran spratley
//description:this is a cordinace program that will read a text file and oput the occuraces of words and how may times
//it apears

#include <iostream>

#include <iomanip>

#include <string>

#include <fstream>

#include <ctype.h>

#include <sstream>

using namespace std;

int main()

{

     char file[20];

     //int lines[100][2];

     int i=0,j=0,k=0;

     double line=0;

     string lines[1000];

     string word;

     string concord[1000];

     int count[1000]={0};

     int idx=0;

     cout<<"Enter the text file name: "<<endl;

     //read file name

     cin.get(file,100);

     ifstream ifs;

     //open text file

     ifs.open("text.txt");

     if(!ifs.is_open())

     {

          cout<<"Unable to open file"<<endl;

          return 0;

     }

     string w;//temparary string

     //read all lines

     while(ifs.good())

     {

          getline(ifs,word);//read line by line

          //removing punctations and converting upper case letters to lower case

          for(int i=0;i<word.length();i++)

          {

              if(!isalpha(word.at(i)))

          {

           if(word.at(i)!=' ')

           for(int j=i;j<word.length()-1;j++)

            {

             word.at(j)=word.at(j+1);

             }

                   if(i==word.length()-1)

                        word.at(i)=' ';

              }

              if(!islower(word.at(i)))

              {

                   word.at(i)=tolower(word.at(i));

              }

          }

          istringstream iss(word);

          while(iss>>w) //read each word in each line

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

              {

                   concord[idx]=w;

                   count[idx]=1;

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

                   lines[matchedAt]=lines[matchedAt]+","+numb.str();

              }

          }

         

          line=line+1;

     }

     //print concord

     cout<<std::left<<setw(15)<<"Word"<<setw(3)<<" : "<<"count"<<setw(3)<<" : "<<"Occurences"<<endl;

     cout<<"----------------------------------------------------------------------------"<<endl;

     for(int l=0;l<idx;l++)

          cout<<std::left<<setw(15)<<concord[l]<<setw(5)<<" : "<<count[l]<<setw(3)<<" : "<<lines[l]<<endl;

     system("pause");

     return 0;

}


















