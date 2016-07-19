//#ifndef COMBINATIONSUM_H
//#define COMBINATIONSUM_H
//
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//class CombinationSum {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		std::sort(candidates.begin(), candidates.end());
//		
//        
//    }
//
//
//private:
//	int T;
//	std::vector<int> C;
//	std::queue<int> solution;
//	
//	void helper(int target, const vector<int>& candidates, int which) {
//		// print solution
//		if ( target == 0 ) {
//			printSolution();
//		}
//		if ( target < candidates[which] || which > candidates.size() - 1) {
//			clearSolution();
//		}
//		
//		int remaining = target;
//		
//		while ( remaining > 0 ) {
//			helper();
//		}
//	}
//	
//	void printSolution() {
//		std::cout << "[";
//		while(!solution.empty()) {
//			std::cout << solution.front() << ",";
//			solution.pop();
//		}
//		std::cout << "] ";
//	}
//	
//	void clearSolution() {
//		while(!solution.empty()) {
//			solution.pop();
//		}
//	}
//};
//
//#endif // COMBINATIONSUM_H
