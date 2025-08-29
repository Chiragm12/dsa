class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int sizee=arr.size();
        d=d%sizee;
        vector<int>temp(sizee);

        for(int i=0;i<arr.size();i++){
            temp[(i-d+sizee)%sizee]=arr[i];
        }
        for(int i=0;i<sizee;i++){
            arr[i]=temp[i];
        }
    }
};

//make sure u add the size of the temp array.

class Solution {
public:
    // Utility function to reverse elements in a range [start, end]
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    // Function to rotate array by d elements to the left
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // Normalize d if d > n

        // Step 1: Reverse the first d elements
        reverse(arr, 0, d - 1);
        // Step 2: Reverse the remaining n - d elements
        reverse(arr, d, n - 1);
        // Step 3: Reverse the whole array
        reverse(arr, 0, n - 1);
    }
};
