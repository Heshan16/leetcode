class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz=gas.size(),total=0,maxindex=0,tank=0;
        for(int i=0;i<sz;i++) {
            if((tank=tank+gas[i]-cost[i])<0){
                total+=tank;
                tank=0;
                maxindex=i+1;
            }
        }
        return total+tank<0?-1:maxindex;
    }
};
