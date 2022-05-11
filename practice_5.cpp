#include <iostream>
#include <vector>
using namespace std;
// TASK *1*
int binary_search( int sorted[],int x )
{
    int h = 7;
    int l = 0;
    int m;
    while (l <= h)
    {
        m=(l+h)/2;
        if (sorted[m]< x)
        {
            l=m+1;
        }
        if (sorted[m]> x)
        {
            h=m-1;
        }
        if (sorted[m]==x)
        {
            cout << " nomber : " << m + 1<< endl;
            break;
        }
    }
    return -1;
}
//TASK *2*
// первый способ - перебор всех пар:
struct two_numbers{
    int a = 0;
    int b = 0;
};
template <size_t N>
two_numbers find_terms(int (&arr)[N], int k){
    const size_t s = N;
    int i, j = 0;
    int c, d = 0;
    while(j<s){
        d = arr[j];
        while(i<j){
            c = arr[i];
            i++;
            if( (c+d) == k){
                break;
            }else{
                continue;
            }
        }
        j++;
        if( (c+d) == k){
            break;
        }else{
            i = 0;
            continue;
        }
    }
    two_numbers result;
    result.a = c;
    result.b = d;
    return result;
}
// способ три -  сортировка массива + бинарный поиск:

template <size_t N>
int find_terms_binary(int (&arr)[N], int k)
{
    const size_t s = N;
    int t;
    for (int i = 1; i < s; i++) {                                     // сортировка массива
        t = arr[i];
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            swap(arr[j - 1], arr[j]);
        }
    }                                                                 //бинарный поиск по массиву
    int l=0;
    int h= s-1;
    int m;
    for (int i=0;i<s;i++)
    {
        for(int y=0; y<s; y++) {
            m = (h + l) / 2;
            if ((arr[m] + arr[i]) > k) {
                h = m - 1;
            }
            if ((arr[m] + arr[i]) < k) {
                l = m + 1;
            }
            if ((arr[m] + arr[i]) == k) {
                cout << " chisla :" << arr[m] << " ," << arr[i] << endl;
                break;
            }
        }
    }
}


int main ()
{
    // TASK 2
    int array[] = {0,1, 2, 3, 4, 5, 6, 7, 8};
    int sum = 8;
    two_numbers t_n;
    t_n = find_terms(array, sum);
    cout << "Terms are found: " << t_n.a << " and " << t_n.b << endl; // первый способ
    find_terms_binary(array,sum);// третий способ
    //TASK 1
    int x=7;
    int A[]={1,2,3,4,5,6,7,8};
    //cout << sizeof(A)/sizeof(int) << endl;
    binary_search(A,x);

    return 0;
}