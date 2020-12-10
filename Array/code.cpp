// C++ program to find the sum 
// and product of k smallest and 
// k largest prime numbers in an array 
#include <bits/stdc++.h> 
using namespace std; 
  
vector<bool> SieveOfEratosthenes(int max_val) 
{ 
    // Create a boolean vector "prime[0..n]". A 
    // value in prime[i] will finally be false 
    // if i is Not a prime, else true. 
    vector<bool> prime(max_val + 1, true); 
    for (int p = 2; p * p <= max_val; p++) { 
  
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
  
            // Update all multiples of p 
            for (int i = p * 2; i <= max_val; i += p) 
                prime[i] = false; 
        } 
    } 
    return prime; 
} 
  
// Function that calculates the sum 
// and product of k smallest and k 
// largest prime numbers in an array 
void primeSumAndProduct(int arr[], int n, int k) 
{ 
    // Find maximum value in the array 
    int max_val = *max_element(arr, arr + n); 
  
    // Use sieve to find all prime numbers 
    // less than or equal to max_val 
    vector<bool> prime = SieveOfEratosthenes(max_val); 
  
    // Set 0 and 1 as non-primes as 
    // they don't need to be 
    // counted as prime numbers 
    prime[0] = false; 
    prime[1] = false; 
  
    // Max Heap to store all the prime numbers 
    priority_queue<int> maxHeap; 
  
    // Min Heap to store all the prime numbers 
    priority_queue<int, vector<int>, greater<int>>  
        minHeap; 
  
    // Push all the prime numbers  
    // from the array to the heaps 
    for (int i = 0; i < n; i++) 
        if (prime[arr[i]]) { 
            minHeap.push(arr[i]); 
            maxHeap.push(arr[i]); 
        } 
    long long int minProduct = 1 
        , maxProduct = 1 
        , minSum = 0 
        , maxSum = 0; 
    while (k--) { 
  
        // Calculate the products 
        minProduct *= minHeap.top(); 
        maxProduct *= maxHeap.top(); 
  
        // Calculate the sum 
        minSum += minHeap.top(); 
        maxSum += maxHeap.top(); 
  
        // Pop the current minimum element 
        minHeap.pop(); 
  
        // Pop the current maximum element 
        maxHeap.pop(); 
    } 
  
    cout << "Sum of k-minimum prime numbers is " 
         << minSum << "\n"; 
    cout << "Sum of k-maximum prime numbers is " 
         << maxSum << "\n"; 
    cout << "Product of k-minimum prime numbers is " 
         << minProduct << "\n"; 
    cout << "Product of k-maximum prime numbers is " 
         << maxProduct; 
} 
  
// Driver code 
int main() 
{ 
  
    int arr[] = { 4, 2, 12, 13, 5, 19 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    int k = 3; 
  
    primeSumAndProduct(arr, n, k); 
  
    return 0; 
} 
