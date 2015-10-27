#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,k=0;
    scanf("%d",&t);
    while (t--)
    {
        k++;
        int n,m,flag=0;
        scanf("%d %d",&n,&m);
        vector<int> graph[n+1];
        for (int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int *color=(int*)calloc(n+1,sizeof(int));
        //memset(color,2,sizeof(color));
        for (int i=0; i<=n; i++)
            color[i]=-1;
        for (int i=1; i<=n; i++)
        {
            if (color[i]==-1)
            {
                queue<int> q;
                q.push(i);
                color[i]=1;
                while (q.size()!=0)
                {
                	std::vector<int> g(color);
                    int parent=q.front();
                    for (int child : graph[parent])
                    {
                        if (color[child]==-1){
                            color[child]=!color[parent];
                            q.push(child);
                        }
                        else if (color[child]==color[parent])
                        {
                            flag=1;
                            break;
                        }
                    }
                    q.pop();
                    if (flag==1)
                        break;
                }


            }
            if (flag==1)
                break;
        }
        /*for (int i=0; i<=n; i++)
            cout<<color[i]<<" ";
        cout<<endl;*/
        printf("Scenario #%d:\n",k);
        if (flag==1)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }
    return 0;
}
