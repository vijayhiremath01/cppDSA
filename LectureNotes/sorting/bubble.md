we have to use n - 1 iterations and have to compare with adjacent elements and then push the larger elements to last 

for example dry run 
4 1 5 2 3 
first we compare 4 and 1 , 1 and 5 , 5 and 2 , 2 and 3 and for 4 and 1 we compare and psuh largest value to right side for ascending order ! 
even though it is sorted after that also it runs upto n - 1 iteration times 
time complexity for bubble sort is 0(n^2)



// Selection sort 
[1 , 2, 3, 5, 4 ]
_______ _______
sorted  unsorted so we do n - 1 iterations to push n - 1 smallest elements 
here we will push the smallest element to zeroth index then again n - 1 iterations upto for unsorted part ! 
for(int i = 0 ; i < n ; i++) {
    let smallestInddex = i ;
    for(int j = i + 1 ; j < n ; j++) {
        if(arr[j] < arr[smallestIndex]){
            smallestIndex = j ;
        }
        swap(arr[i] , arr[smallIndex])
    }
}