#include<stdio.h>
void dfs(int);
int a[10][10],vis[10],exp[10],n,j,m;
void main()
{
 int i,x,y;
 printf("enter the number of vertices\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
 a[i][j]=0;
 }
 vis[j]=0;
 }
 printf("Enter the number of edges\n");
 scanf("%d",&m);
 for(i=1;i<=m;i++)
 {
 printf("Enter an edge\n");
 scanf("%d%d",&x,&y);
 a[x][y]=1;
 }
 j=0;
 for(i=1;i<=n;i++)
 {
 if(vis[i]==0)
 dfs(i);
 }
 printf("The topological sort\n");
 for(i=n-1;i>=0;i--)
 {
6
 printf("%d\t",exp[i]);
 }
}
void dfs(int v)
{
 int i;
 vis[v]=1;
 for(i=1;i<=n;i++)
 {
 if(a[v][i]==1 && vis[i]==0)
 {
 dfs(i);
 }
 }
 exp[j++]=v;
}
