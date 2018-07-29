int getSum(int a, int b) {
	int carry = a & b;
	int result = a^b;
	while(carry != 0){
		int shiftCarry = carry << 1;
		carry = result & shiftCarry;
		result^=shiftCarry;
	}
	return result;
}
