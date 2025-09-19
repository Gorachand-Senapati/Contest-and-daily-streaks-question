class Spreadsheet {
public:
  vector<vector<int>>sheets;
    Spreadsheet(int rows) {
        sheets.assign(rows,vector<int>(26,0));//initialise row and col 26 because A-Z
    }
    
    void setCell(string cell, int value) {
        int col= cell[0]-'A';//bcz "A12" A is col and 12 is row so A-A=0 so 1st col
        int row= stoi(cell.substr(1))-1;//sting to intiger so "STOI"and for 0 based index so -1
        sheets[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col= cell[0]-'A';//bcz "A12" A is col and 12 is row so A-A=0 so 1st col
        int row= stoi(cell.substr(1))-1;//sting to intiger so "STOI"and for 0 based index so -1
        sheets[row][col]=0;
    }
    //extra fuction for know or make  left or right intiger or not
    int solve(string s){
        if(isdigit(s[0])){
            return stoi(s);
        }
        int col= s[0]-'A';//bcz "A12" A is col and 12 is row so A-A=0 so 1st col
        int row= stoi(s.substr(1))-1;//sting to intiger so "STOI"and for 0 based index so -1
        return sheets[row][col];//the value
    }
    
    int getValue(string formula) { //=x+y 1st want remove =
        string s= formula.substr(1); //x+y
        int plusIdx= s.find('+');//find + index so know the + left and right value
        string left= s.substr(0,plusIdx);//0 to plusIdx string get
        string right= s.substr(plusIdx+1);//after + string
        return solve(left) + solve(right);
    }
    
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */