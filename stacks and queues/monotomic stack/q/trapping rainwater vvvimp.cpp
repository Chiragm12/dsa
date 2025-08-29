#include <iostream>
#include <queue>
using namespace std;
#include<vector>
#include<stack>
#include<map>
    
/*
basically when trapping water min(max_left[i],max_right[i])−height[i]. this will how it'll be, it'll take the minimum height 
between the 2 bulidings and then only fill, so the problem is to find max_left and max right so we do 2 arrays called prefix max 
and suffix max

prefix max[n]-> [2,1,0,5,3] will be [2,2,2,5,5] basically finidng max of subarry from left to right
for suffix it'll be ulta, from right to left-> [1,11,2,10] will be [11,11,10,10]
*/

