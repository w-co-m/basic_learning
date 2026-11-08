#include <stdio.h>
#include <string.h>
/*
int main()
{
    int  n,num[1000]={},count[1000]={};
    scanf("%d",&n);
    for(int  i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
       count[num[i]]++;
    }

    for(int i=0;i<1000;i++)
    {
        int k=0,max=count[0];
        for(int j=0;j<1000;j++)
        {
            if(count[j]>max)
            {
                k=j;max=count[j];
            }
        }
        count[k]=0;
        if(max!=0)
            printf("%d %d\n",k,max);
        else  break;
    }
    return 0;
}
*/
typedef struct {
    int num;
    int count;
} MAX;
void swap(MAX *a, MAX *b) {
    MAX temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    MAX m[1000];
    int n, k[1000];
    memset(m, 0, sizeof(m));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k[i]);
            m[k[i]].num = k[i];
            m[k[i]].count++;
        }
    for (int i = 0; i < 1000; i++) {
        int max_index = i;
        for (int j = i + 1; j < 1000; j++) {
            if (m[j].count > m[max_index].count) {
                max_index = j;
            }
            else if (m[j].count == m[max_index].count && m[j].num < m[max_index].num) {
                max_index = j;
            }
        }
        if (max_index != i) {
            swap(&m[max_index], &m[i]);
        }
    }
    for (int i = 0; i < 1000; i++) {
        if (m[i].count > 0) {
            printf("%d %d\n", m[i].num, m[i].count);
        }
        else {
            break;
        }
    }

    return 0;
}
