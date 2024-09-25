class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> res;
    // max heap to store the closest points
    priority_queue<pair<double, int>> pq;

    for (int i = 0; i < points.size(); ++i) {
        double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        pq.push({dist, i});
        if (pq.size() > k) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        res.push_back(points[pq.top().second]);
        pq.pop();
    }

    return res;
}
};