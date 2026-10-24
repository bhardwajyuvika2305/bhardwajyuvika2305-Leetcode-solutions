/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.*/

// Solution :- 

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int overallMax = 1;

        for (int i = 0; i < n; ++i) {
            std::unordered_map<long long, int> slopeMap;
            int duplicates = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                // Reduce the fraction using GCD
                int gcdVal = std::gcd(dx, dy);
                dx /= gcdVal;
                dy /= gcdVal;

                // Normalize signs to ensure consistent map keys
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                // Pack dx and dy into a single 64-bit key
                long long key = ((long long)dx << 32) | (unsigned int)dy;

                slopeMap[key]++;
                localMax = std::max(localMax, slopeMap[key]);
            }

            overallMax = std::max(overallMax, localMax + duplicates + 1);
        }

        return overallMax;
    }
};

