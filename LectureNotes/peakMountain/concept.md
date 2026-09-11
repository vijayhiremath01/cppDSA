Here we are going to discuss about peak index in mountain array 
Its like a mountain where the peak is the highest point and the sides are decreasing and increasing respectively
at left side of the elements are going to increase like arr[i-1] < arr[i]
at right side of the elements are going to decrease like arr[i] > arr[i+1]
and the peak index is the index where arr[i] is greater than both arr[i-1] and arr[i+1]

the first approch to solve this problem will be linear search
we will traverse the array and check if the current element is greater than both its neighbors
if it is then we will return the index of the current element
the time complexity will be 0(n)

aah the index of the 0 and n - 1 will not be our answer or peaks element  if it is then there will be no mountain array

we have figure out whether our mid lies on left(increasing side) or right (decreasing side)
if mid is on left side then we will move our start to mid + 1
if mid is on right side then we will move our end to mid - 1

psuedo code 
while(start <= end ){
    find mid 
    if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
        retrun mid ;
    } 
    if(arr[mid] > arr[mid - 1 ]){
        start = mid + 1 ;
    }else {
        end = mid - 1 ; 
    }
}

aaah to solve this problem 
1.we will ignore the start and end index as they are not our answer
2.we dont want unnecessary checks like mid - 1 or mid + 1 as they might go out of bounds
 
