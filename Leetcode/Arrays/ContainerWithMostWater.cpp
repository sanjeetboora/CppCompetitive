//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area =0;
        int left =0;
        int right= height.size()-1;
        
        while(left < right){
            area = max(area, min(height[left], height[right])*(right-left) );
            
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
        
    }
};


// Proof1:

// You have two heights H_left and H_right, and H_right < H_left, then we know we have two choices, we want to move one of them. If we move the larger one, we cannot increase the height for the simple reason that we are always limited by the shortest, and we would be decreasing j-i, the width as well.

// To clarify: let's say we kept the shortest forever, what would happen? Well, j-i would decrease, and either we come across a taller block, which doesn't matter because our shorter one we kept only mattered, or we find a shorter one, in which case that one matters.

// Either way we end up with a smaller area, so we must move the shorter one because moving the larger one cannot give an increase in area.

// Proof2:

// 1. case hi <= hj:
// -> we can prove that j is the best choice(within the range from i to j) for i
// -> for any k(i < k < j):
// area(i, j) == min(hi, hj)*(j-i) == hi*(j-i) > hi*(k-i) >= min(hi,hk)*(k-i) == area(i, k)

// then we have area(i, j) > area(i, k)


// -> it means j is the best choice for i, area(i,j)= largest_area_involves_i
// -> so, max_area_of_range(i, j) == max(max_area_of_range(i+1, j), largest_area_involves_i)

// 2. case hi >= hj:
// -> similarly, we can prove that max_area_of_range(i, j) == max(max_area_of_range(i+1, j), area(i, j))



