#include <iostream>
#include <string>
using namespace std;

int getPriority(string desig){
    if(desig=="CEO") return 6;
    if(desig=="CTO") return 5;
    if(desig=="CFO") return 4;
    if(desig=="VP")  return 3;
    if(desig=="MGR") return 2;
    if(desig=="EMP") return 1;
    return 0;
}

int main(){
     int size;
           cout<<"Enter number of employees: ";
        cin>>size;

   string names[100], desig[100];
          int countCEO=0, countCTO=0, countCFO=0;

  for(int i=0;i<size;i++){
          cout<<"Enter employee "<<i+1<<" name: ";
       cin>>names[i];

              string des;
          while(true){
                cout<<"Enter designation (CEO/CTO/CFO/VP/MGR/EMP): ";
              cin>>des;

                  if(getPriority(des)==0){
                    cout<<"Invalid designation! Please enter again.\n";
                      continue;
                  }

               if(des=="CEO" && countCEO>0){
                      cout<<"Only 1 CEO allowed. Enter again.\n";
                          continue;
               }

             if(des=="CTO" && countCTO>0){
                cout<<"Only 1 CTO allowed. Enter again.\n";
                    continue;
             }

                  if(des=="CFO" && countCFO>0){
                     cout<<"Only 1 CFO allowed. Enter again.\n";
                         continue;
                  }

             if(des=="CEO")
                    countCEO++;

        if(des=="CTO")
               countCTO++;

                 if(des=="CFO")
                     countCFO++;

                  break;
          }
         desig[i]=des;
  }

       for(int i=1;i<size;i++){
         string keyName=names[i];
              string keyDesig=desig[i];
         int keyPriority=getPriority(keyDesig);
              int j=i-1;

         while(j>=0 && getPriority(desig[j])<keyPriority){
                names[j+1]=names[j];
                desig[j+1]=desig[j];
              j--;
         }

         names[j+1]=keyName;
              desig[j+1]=keyDesig;
       }

    cout<<"Employees sorted by designation priority:\n";
        for(int i=0;i<size;i++){
                cout<<names[i]<<" - "<<desig[i]<<endl;
        }

   return 0;
}
