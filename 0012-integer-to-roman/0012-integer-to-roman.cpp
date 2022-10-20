class Solution {
public:
    string intToRoman(int num) {
        string str;
        while(num)
        {
            if(num >= 1000)
            {
                str.push_back('M');
                num -= 1000;
            }
            else if(num >= 900)
            {
                str += "CM";
                num -= 900;
            }
            else if(num >= 500)
            {
                str.push_back('D');
                num -= 500;
            }
            else if(num >= 400)
            {
                str += "CD";
                num -= 400;
            }
            else if(num >= 100)
            {
                str.push_back('C');
                num -= 100;
            }
            else if(num >= 90)
            {
                str += "XC";
                num -= 90;
            }
            else if(num >= 50)
            {
                str.push_back('L');
                num -= 50;
            }
            else if(num >= 40)
            {
                str += "XL";
                num -= 40;
            }
            else if(num >= 10)
            {
                str.push_back('X');
                num -= 10;
            }
            else if(num>=9)
            {
                str += "IX";
                num -= 9;
            }
            else if(num >= 5)
            {
                str.push_back('V');
                num -= 5;
            }
            else if(num >= 4)
            {
                str += "IV";
                num -= 4;
            }
            else if(num>=1)
            {
                str.push_back('I');
                num -= 1;
            }
        }
        return str;
    }
};