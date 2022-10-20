class Solution {
public:
    string intToRoman(int num) {
        string roman;
        while(num >= 1000){
            num -= 1000;
            roman.push_back('M');
        }
        while(num >= 900){
            num -= 900;
            roman.push_back('C');
            roman.push_back('M');
        }
        while(num >= 500){
            num -= 500;
            roman.push_back('D');
        }
        while(num >= 400){
            num -= 400;
            roman.push_back('C');
            roman.push_back('D');
        }
        while(num >= 100){
            num -= 100;
            roman.push_back('C');
        }
        while(num >= 90){
            num -= 90;
            roman.push_back('X');
            roman.push_back('C');
        }
        while(num >= 50){
            num -= 50;
            roman.push_back('L');
        }
        while(num >= 40){
            num -= 40;
            roman.push_back('X');
            roman.push_back('L');
        }
        while(num >= 10){
            num -= 10;
            roman.push_back('X');
        }
        while(num >= 9){
            num -= 9;
            roman.push_back('I');
            roman.push_back('X');
        }
        while(num >= 5){
            num -= 5;
            roman.push_back('V');
        }
        while(num >= 4){
            num -= 4;
            roman.push_back('I');
            roman.push_back('V');
        }
        while(num >= 1){
            num -= 1;
            roman.push_back('I');
        }
        return roman;
    }
};