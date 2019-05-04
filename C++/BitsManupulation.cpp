#include<iostream>

using namespace std;

// reverse bits in integer
	/*Loop through all the bits of an integer.
	If a bit at ith position is set in the i/p no. then set the bit at (NO_OF_BITS – 1) – i in o/p.
	Where NO_OF_BITS is number of bits present in the given number.*/
int ReverseBits(int num)
{
	int revnum = 0, temp ;
	int NoOfBits = sizeof(num)*8;
	for(int i=0; i<NoOfBits; i++)
	{
		if(num&(1<<i))
			revnum |= (1<< ((NoOfBits-1)-i));
	}
return revnum;
}


//Convert Decimal number into binary number
generate_bits_rec(int num) {

}

generate_bits(int num) {

}

// swap two nibbles in a bytes
unsigned char swap_nibbles(unsigned char c)
{
	unsigned char temp1, temp2;
	temp1 = c & 0x0F;
	temp2 = c & 0xF0;
	temp1=temp1 << 4;
	temp2=temp2 >> 4;
	return(temp2|temp1); //adding the bits
}

//count bits set in an integer?
void countbitset(int number) {
	int count=0;
	for(;n>0; n>>=1) {
		if(n & 1) count++;
	}
	printf("Count bit set result in %d\n", count);
	count=0;
	while(num) {
		count++;
		num = num & (num - 1);// This clears the least significant bit set.
	}
	printf("Count bit set result in %d\n", count);
}



int main()
{
	int x =2;
	cout<<"Reverse Bits "<<ReverseBits(x)<<endl;

	char ch=0x34;
	printf("\nThe exchanged value is %x",swap_nibbles(ch));

	return 0;
}
