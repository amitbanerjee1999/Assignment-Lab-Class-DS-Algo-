#include<iostream>
#include<fstream>
using namespace std;
int m[100][100];
int s[100][100];

void matrixchainmultiplication(int p[] , int n)
{

	for(int i=1 ; i<n ; ++i)
	{
		m[i][i]=0;
	}
	for(int len=2 ; len<n ; ++len)
	{
		for(int i=1 ; i<n-len+1 ; ++i)
		{
			int j=i+len-1;
			m[i][j]=INT_MAX;
			for(int k=i ; k<=j-1 ; ++k)
			{
				int cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				
				if(cost<m[i][j]){
					m[i][j]=cost;
					s[i][j]=k;
				}
			}
		}
	}
	
	cout<<"The M Table is: "<<endl;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	
	cout<<"The S Table is: "<<endl;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	
	cout<<"Minimum number of multiplication:"<<endl;
	cout<<m[1][n-1]<<endl;
		
	cout<<endl;

}



void print_optimal_paranthesis(int i , int j)
{
	static char name='A';
	if(i==j)
	{
		cout<<name++;
//		return ;

	} 
	else
	{
		cout<<'(';
		print_optimal_paranthesis(i , s[i][j]);
		print_optimal_paranthesis(s[i][j]+1 , j);
		cout<<')';
	}
}


int main()
{
	
	int n;
	fstream infile;
	infile.open("matrixchainmultiplication.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	infile>>n;
	n++;
	int  p[n];
	for(int i=0 ; i<=n ; ++i)
		infile>>p[i];
		
//	cout<<n<<endl;

	matrixchainmultiplication(p , n);
	
	cout<<"optimal paranthesis is"<<endl;
	print_optimal_paranthesis(1 , n-1);

}

//5
//2 3 5 2 4 3

