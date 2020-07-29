from typing import List

class Solution:
	def maxArea(self, height: List[int]) -> int:
		max_water = 0
		left = 0
		right = len(height) - 1

		while(left != right):
			local_height = height[left] if height[left] <= height[right] else height[right]

			current_container = (right - left) * (local_height)
			max_water = current_container if current_container > max_water else max_water

			if( height[left] < height[right] ):
				left += 1
			else:
				right -= 1

		return max_water



def main():
	sol = Solution()

	print( sol.maxArea( [1,8,6,2,5,4,8,3,7] ) )

main()
