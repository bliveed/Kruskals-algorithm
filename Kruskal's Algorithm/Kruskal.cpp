#include<iostream>
#include<string.h>
#include <fstream>
#define MAX 100
using namespace std;

ofstream inFile("input.txt");
ofstream outFile("output.txt");

class spanTree
{
  
  int spanNode[MAX][MAX],cost[MAX][MAX],numNodes,maxCost;
public:
  int maxEdge = 100;
  spanTree();
  void add();
  int Position(int[]);
  void Kruskal();
};

spanTree::spanTree()
{
  numNodes=0;
  for(int i=0;i<10;i++)
  for(int j=0;j<10;j++)
  {
     cost[i][j] = 999;
   }
}

int spanTree::Position(int key[])
{
  int i;
  for(i=0;i<maxEdge;i++)
  	if((spanNode[i]) == 0)
    	return i;
return -1;     
}

void spanTree::add()
{
  int wei,i,j,edgeNum,first[MAX],second[MAX],fiNode,seNode;
  
	cout<<"Number of nodes: ";  
	cin>>numNodes;
	
	cout<<"Number of edges: "; //For how many edges will be between nodes in total
	cin>>maxEdge;
	
	cout<<"Maximum cost of edges: "; //For limiting all weigts in array
	cin>>maxCost;
	
	  edgeNum = maxEdge;
	
	if(numNodes > 0 && maxEdge > 0){
		
		inFile<<numNodes<<"    ";
		inFile<<maxEdge<<"    ";
		inFile<<maxCost<<endl;

		  do
		  {
		    cout<<"Please enter 1st node: ";
			cin>>fiNode;
			
			                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             	
			cout<<"Please enter 2nd node: ";
			cin>>seNode;
		    
		    cout<<"Please enter cost between 1st and 2nd node: ";
		    cin>>wei;
		    
		   	if(fiNode> numNodes || fiNode == numNodes || fiNode<0){
					cout<<"Your first node is not acceptable!"<<endl;
					
				}
				else if(seNode> numNodes || seNode == numNodes || seNode<0){
					cout<<"Your second node is not acceptable!"<<endl;
					
				}
				else if(fiNode == seNode){
					cout<<"First and second node must be different! Try again..."<<endl;
					
				}
				else if(wei>maxCost){
					cout<<"Your cost can not bigger than Maximum cost ..."<<endl;
					
				}
				else{
					
						--edgeNum;
						
						first[i] = fiNode;
						second[i] = seNode;
						
						i=Position(first);
			    		j=Position(second);
			    		
			    		cost[i][j]=cost[j][i]=wei;
			    		
			    		inFile<<first[i]<<"    ";
			    		inFile<<second[j]<<"    ";	
			    		inFile<<wei<<endl;
			    		
			    		cout<<"Succesfully added..."<<endl;
					
				}
		  }while(edgeNum>0);
		
	}
		else
			cout<<"Your node number or edge number can not be 0"<<endl;
}

void spanTree::Kruskal()
{
  int i,j,node[maxEdge]={0},x,y,min,gr=1,flag=0,temp,d;
  while(flag==0)
  {
    min=999;
     for(i=0;i<maxEdge;i++)
      {
	  
      for(j=0;j<maxEdge;j++)
         {
        if(cost[i][j]<min)
            {
	          min=cost[i][j];
	          x=i;
	          y=j;
            }
         }
     }
     
    if(node[x]==0 && node[y]==0)
    {
      node[x]=node[y]=gr;
      gr++;
    }
    else if(node[x]!=0 && node[y]==0)
      node[y]=node[x];
    else if(node[x]==0 && node[y]!=0)
      node[x]=node[y];
    else
    {
      if(node[x]!=node[y])
      {
        d=node[x];
        for(i=0;i<maxEdge;i++)
        {
          if(node[i]==d)
          node[i]=node[y];
        }
      }
    }
    cost[x][y]=cost[y][x]=999;
    
    outFile<<"\n\t"<<node[x]<<"\t\t"<<node[y]<<"\t\t"<<min;
    
    temp=node[0]; flag=1;
       for(i=0;i<maxEdge;i++)
       {
         if(temp!=node[i])
         {
         flag=0;
         break;
         }
       }

  }
}

int main()
{
  spanTree minTree;
  minTree.add();
  minTree.Kruskal();
  cout<<"\n\n\nThe Minimum Spanning tree is in the output.txt file";
return 0;
}
