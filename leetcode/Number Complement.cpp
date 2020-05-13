class Solution {
public:
    int findComplement(int num) {
        int val = 1;
        while(val<num)  val = (val<<1)+1;
        val ^=num;
        return val;
    }
};