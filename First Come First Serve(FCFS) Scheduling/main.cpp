#include <iostream>
#include <cstring>

using namespace std;

struct CPU
{
   string process_no;
   int arrival_time;
   int brust_time;
};

void cpu_schudling(CPU elements[],int n)
{
  int complete_time[100],turnaround_time[100],waiting_time[100],i;
  complete_time[1]=elements[1].brust_time;
  for(i=2;i<=n;i++)
  {
      complete_time[i]=elements[i].brust_time+complete_time[i-1];
  }

  for(i=1;i<=n;i++){
    turnaround_time[i]=complete_time[i]-elements[i].arrival_time;
    waiting_time[i]=turnaround_time[i]-elements[i].brust_time;
  }

  cout<<"process_no\tarrival_time\tbrust_time\tcomplete_time\tturnaround_time\t waiting_time"<<endl;
  for(i=1;i<=n;i++)
  {
    cout<<elements[i].process_no<<"\t\t"<<elements[i].arrival_time<<"\t\t"<<elements[i].brust_time<<"\t\t"<<complete_time[i]<<"\t\t"<<turnaround_time[i]<<"\t\t "<<waiting_time[i]<<endl;
  }

}

int main()
{
    int n,i,j;
    cout<<"enter the number of activities:"<<endl;
    cin>>n;
    CPU elements[100],temp;
    cout<<"enter the elements:"<<endl;
    for(i=1;i<=n;i++){

        cin>>elements[i].process_no>>elements[i].arrival_time>>elements[i].brust_time;
    }

    cout<<"elements are:"<<endl;
    cout<<"process_no\tarrival_time\tbrust_time"<<endl;
    for(i=1;i<=n;i++){
         cout<<elements[i].process_no<<"\t\t"<<elements[i].arrival_time<<"\t\t"<<elements[i].brust_time<<endl;
   }

     for(i=1;i<=n;i++){
		for(j=1;j<=n-1;j++){
			if(elements[j].arrival_time > elements[j+1].arrival_time){   //sorting technique
				temp = elements[j];
				elements[j] = elements[j+1];
				elements[j+1] = temp;
			}
		}
	}

    cout<<"elements are after rearrange according to the arrival_time:"<<endl;
    cout<<"process_no\tarrival_time\tbrust_time"<<endl;
	for(i=1;i<=n;i++)
    {
       cout<<elements[i].process_no<<"\t\t"<<elements[i].arrival_time<<"\t\t"<< elements[i].brust_time<<endl;
    }

    cpu_schudling (elements,n);

     return 0;
}
