class Solution {
public:
	string addBinary(string a, string b) {
		int indexA=a.size()-1;
		int indexB=b.size()-1;
		int num=0;
		int bit=0;
		int carry=0;
		string c;
		while(indexA >=0&& indexB>=0)// A&B BOTH HAS VALUE
		{
			num= (a[indexA]-'0')+(b[indexB]-'0')+carry;
			bit=num%2;
			carry=num/2;
			c=(char)(bit + '0') + c;
			indexA--;
			indexB--;
		}

		while(indexA >= 0)
		{
			int num = a[indexA ] - '0' + carry;
			carry = num / 2;
			num %= 2;

			c = (char)(num + '0') + c;

			indexA--;
		}

		while(indexB >= 0)
		{
			int num = b[indexB] - '0' + carry;
			carry = num / 2;
			num %= 2;

			c = (char)(num + '0') + c;

			indexB--;
		}

		if (carry > 0)
			c = (char)(carry + '0') + c;

		return c;
	}
};