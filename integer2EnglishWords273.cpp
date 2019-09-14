class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<int>number;
        string temp, ans;
        while (num>0) {
            number.emplace_back(num%10);
            num/=10;
        }
        string digit[4] = {"Thousand","Million","Billion","Trillion"};
        for (int i = 0; i < number.size(); i+=3) {
            temp = "";
            if (i+2 < number.size()) {
                if (number[i+2] == 1) {
                    temp.append("One ");
                } else if (number[i+2] == 2) {
                    temp.append("Two ");
                }  else if (number[i+2] == 3) {
                    temp.append("Three ");
                } else if (number[i+2] == 4) {
                    temp.append("Four ");
                } else if (number[i+2] == 5) {
                    temp.append("Five ");
                } else if (number[i+2] == 6) {
                    temp.append("Six ");
                } else if (number[i+2] == 7) {
                    temp.append("Seven ");
                } else if (number[i+2] == 8) {
                    temp.append("Eight ");
                } else if (number[i+2] == 9) {
                    temp.append("Nine ");
                }
                if (number[i+2] ) temp.append("Hundred ");
            }
            if (i+1 < number.size()) {
                if (number[i+1] == 1) {
                    if (number[i] == 1) {
                        temp.append("Eleven ");
                    } else if (number[i] == 2) {
                        temp.append("Twelve ");
                    }  else if (number[i] == 3) {
                        temp.append("Thirteen ");
                    } else if (number[i] == 4) {
                        temp.append("Fourteen ");
                    } else if (number[i] == 5) {
                        temp.append("Fifteen ");
                    } else if (number[i] == 6) {
                        temp.append("Sixteen ");
                    } else if (number[i] == 7) {
                        temp.append("Seventeen ");
                    } else if (number[i] == 8) {
                        temp.append("Eighteen ");
                    } else if (number[i] == 9) {
                        temp.append("Nineteen ");
                    } else {
                        temp.append("Ten ");
                    }
                } else {
                    if (number[i+1] == 2) {
                        temp.append("Twenty ");
                    }  else if (number[i+1] == 3) {
                        temp.append("Thirty ");
                    } else if (number[i+1] == 4) {
                        temp.append("Forty ");
                    } else if (number[i+1] == 5) {
                        temp.append("Fifty ");
                    } else if (number[i+1] == 6) {
                        temp.append("Sixty ");
                    } else if (number[i+1] == 7) {
                        temp.append("Seventy ");
                    } else if (number[i+1] == 8) {
                        temp.append("Eighty ");
                    } else if (number[i+1] == 9) {
                        temp.append("Ninety ");
                    }
                }
            }
            if (i+1 < number.size() && number[i+1] == 1) {
            } else {
                if (number[i] == 1) {
                    temp.append("One ");
                } else if (number[i] == 2) {
                    temp.append("Two ");
                }  else if (number[i] == 3) {
                    temp.append("Three ");
                } else if (number[i] == 4) {
                    temp.append("Four ");
                } else if (number[i] == 5) {
                    temp.append("Five ");
                } else if (number[i] == 6) {
                    temp.append("Six ");
                } else if (number[i] == 7) {
                    temp.append("Seven ");
                } else if (number[i] == 8) {
                    temp.append("Eight ");
                } else if (number[i] == 9) {
                    temp.append("Nine ");
                }
            }
            if (i/3 && temp.size()) {
                temp.append(digit[i/3-1]);
                temp+=" ";
            }
            ans=temp+ans;
        }
        ans.pop_back();
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<pair<int,string>> v = {
        {1000000000 , "Billion"},
        {1000000 , "Million"},
        {1000 , "Thousand"},
        {100 , "Hundred"},
        {90, "Ninety"},
        {80, "Eighty"},
        {70, "Seventy"},
        {60, "Sixty"},
        {50, "Fifty"},
        {40, "Forty"},
        {30, "Thirty"},
        {20, "Twenty"},
        {19, "Nineteen"},
        {18, "Eighteen"},
        {17, "Seventeen"},
        {16, "Sixteen"},
        {15, "Fifteen"},
        {14, "Fourteen"},
        {13, "Thirteen"},
        {12, "Twelve"},
        {11, "Eleven"},
        {10, "Ten"},
        {9, "Nine"},
        {8, "Eight"},
        {7, "Seven"},
        {6, "Six"},
        {5, "Five"},
        {4, "Four"},
        {3, "Three"},
        {2, "Two"},
        {1, "One"},
    };
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        for(auto itr = v.begin(); itr != v.end(); itr++) {
            if (num >= itr->first) {
                return 
                    ((num >= 100) ? (numberToWords(num/itr->first) + " "):"" )
                    +
                    itr->second
                    +
                    ((num%itr->first != 0) ? (" " + numberToWords(num%itr->first)):"");
            }
        }
        return "";
    }
};
