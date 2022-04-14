#include<bits\stdc++.h>
#include<unordered_map>

using namespace std;

class RandomizedSet {
private:
	unordered_map<int, int> hash;
	vector<int> nums;
	int delete_num;
	void swap_delete(int i) {
		int size = nums.size();
		nums[i] = nums[size-1];
		nums.pop_back();
	}
public:
	RandomizedSet() {
		delete_num = 0;
	}

	bool insert(int val) {
		if (hash.count(val)) {
			return false;
		}
		hash[val] = nums.size();
		nums.emplace_back(val);
		return true;
	}

	bool remove(int val) {
		if (!hash.count(val)) {
			return false;
		}
		int pos = hash[val];
		hash[nums[nums.size() - 1]] = pos;
		swap_delete(pos);
		hash.erase(val);
		return true;
	}

	int getRandom() {
		int size = hash.size();
		int random_num = rand() % size;
		return nums[random_num];
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet* obj = new RandomizedSet();
* bool param_1 = obj->insert(val);
* bool param_2 = obj->remove(val);
* int param_3 = obj->getRandom();
*/
int main() {
	//Solution solution;
	RandomizedSet* obj = new RandomizedSet();
	bool param_1 = obj->insert(0);
	param_1 = obj->insert(1);
	bool param_2 = obj->remove(0);
	param_1 = obj->insert(2);
	//int param_3 = obj->getRandom();
	param_2 = obj->remove(1);
	//param_1 = obj->insert(2);
	int param_3 = obj->getRandom();
}