// 希尔排序C语言实现
void ShellSort(int A[], int N)
{
    int i, j, Increment;
    int Tmp;
    for(Increment = N/2, Increment > 0; Increment /= 2)
    {
        for(i = Increment; i < N; i++)
        {
            Tmp = A[i];
            for(j = i; j >= Increment; j -= Increment)
            {
                if(A[j] < A[j-Increment])
                    A[j] = A[j-Increment]
                else 
                    j = -1; // break 跳出循环
            }
            A[j] = Tmp;
        }
    }

}