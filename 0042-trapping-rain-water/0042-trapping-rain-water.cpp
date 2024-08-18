class Solution {
public:
    int trap(vector<int>& height) {
     int n=height.size();
     int leftmax[n];
     leftmax[0]=height[0];
     for(int i=1;i<n;i++){
        int temp=max(leftmax[i-1],height[i]);
        leftmax[i]=temp;
     }
     int rightmax[n];
     rightmax[n-1]=height[n-1];
     for(int i=n-2;i>=0;i--){
        int temp=max(rightmax[i+1],height[i]);
        rightmax[i]=temp;
     }
     int water=0;
     for(int i=1;i<n-1;i++){
        water+=min(leftmax[i],rightmax[i])-height[i];
     }
     return water;
        
    }
};