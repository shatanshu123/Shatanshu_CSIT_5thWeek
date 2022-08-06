class Solution {
public:
    vector<int> findSmallestSetOfVertices (int numberOfNodes, vector<vector<int>>& edges)
{
	vector<int> indegree (numberOfNodes, 0);

	for (int i = 0; i < edges.size(); ++i)
	{
		++indegree[edges[i][1]];
	}

	vector<int> smallestSetOfVertices;

	for (int currentNode = 0; currentNode < numberOfNodes; ++currentNode)
	{
		if (indegree[currentNode] == 0)
		{
			smallestSetOfVertices.push_back (currentNode);
		}
	}

	return smallestSetOfVertices;
}
};