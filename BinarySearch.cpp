#include<iostream>
#include<unordered_map>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#define MAX_NUM 100
using namespace std;
/*1.其中/2操作可以用右移1位(>>1)来替换,但是由于移位操作运算符优先级比较低，所以一定要加上括号
2.写成int mid = left + ((right - left) >> 1);
*/
/*找到数组中key的位置*/
int BinSearch_1(vector<int> nums,int key)
{
    if(nums.empty())
        return -1;
    int len = nums.size();
    int left = 0, right = len - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == key)
            return mid;
        else if(nums[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
/*找到数组中第一个key出现的位置*/
int BinSearch_2(vector<int> nums, int key)
{
    if(nums.empty())
        return -1;
    int len = nums.size();
    int left = 0,right = len - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] >= key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if(left < len && nums[left] == key)
    return left;
}
/*找到数组中最后一个key出现的位置*/
int BinSearch_3(vector<int> nums,int key)
{
    if(nums.empty())
        return -1;
    int len = nums.size();
    int left = 0,right = len - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] <= key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if(right >= 0 && nums[right] == key)
        return right;
    return -1;

}
/*找出数组中最后一个小于等于key的元素的位置*/
int BinSearch_4(vector<int> nums,int key)
{
    if(nums.empty())
        return -1;
    int len = nums.size();
    int left =0 ,right = len -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] <= key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}
/*找出数组中第一个大于等于key的元素的位置*/
int BinSearch_5(vector<int> nums, int key)
{
    if(nums.empty())
        return -1;
    int len = nums.size();
    int left = 0,right = len - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] >= key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
int main()
{
    vector<int> a = {1,3,3,3,3,3,5};
    //vector<int> b;
    cout<<"**"<<BinSearch_5(a,5)<<"**"<<endl;

}
