//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.lang.*;


class Array {

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		  
		    //size of array
		    int n = Integer.parseInt(br.readLine().trim());
		    int arr[] = new int[n];
		    String inputLine[] = br.readLine().trim().split(" ");
		    
		    //adding elements to the array
		    for(int i=0; i<n; i++){
		        arr[i] = Integer.parseInt(inputLine[i]);
		    }
		    
		    Solution obj = new Solution();
		    
		    //calling trappingWater() function
		    System.out.println(obj.trappingWater(arr, n));
		}
	}
}


// } Driver Code Ends

class Solution{

 static long trappingWater(int arr[], int n) { 
        //calculate left max boundary-array
        int leftmax[]=new int[n];
        leftmax[0]=arr[0];
        for(int i=1;i<n;i++){
            leftmax[i]=Math.max(arr[i],leftmax[i-1]);
        }
        //calculate right max boundary-array
        int rightmax[]=new int[n];
        rightmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]=Math.max(arr[i],rightmax[i+1]);
        }
        //Calculating trapped water
        long trapwater=0;
        for(int i=0;i<n;i++){
            int waterlevel=Math.min(leftmax[i],rightmax[i]);
            trapwater+=waterlevel-arr[i];
        }
        return trapwater;
    } 
}

