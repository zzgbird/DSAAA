void shellSort(elementType *r,int n)
{
    int j,i,gap;
    elementType tmp;
    gap=n/2;
    while(gap>0)
    {
        for(i=gap;i<n;i++)
        {
            j=i-gap;
            while(j>=0)
            {
                if(r[j]>r[j+gap])
                {
                    tmp=r[j];
                    r[j]=r[j+gap];
                    r[j+gap]=tmp;
                    //往前移动一个gap的位置，继续比较
                    j=j-gap;
                }
                //跳出循环
                else j=-1;
            }
        }
        gap/=2;
    }
}