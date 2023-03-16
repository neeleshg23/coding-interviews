# include <bits/stdc++.h>

using namespace std;

float distance(int x1, int y1, int x2, int y2){
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

float area(int x1, int y1, int x2, int y2, int x3, int y3){
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

int res(bool p, bool q){
    if (p && q){
        return 3;
    } else if (p){
        return 1;
    } else if (q){
        return 2;
    } else{
        return 4;
    }
}

int points_belong(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int xq, int yq){
    float ab = distance(x1, y1, x2, y2);
    float bc = distance(x2, y2, x3, y3);
    float ac = distance(x1, y1, x3, y3);
 
    // cout << ab << " " << bc << " " << ac << endl;

    // degenerate case
    if ((ab >= bc+ac) || (bc >= ab+ac) || (ac >= ab+bc)){
        return 0;
    }

    bool p = true;
    bool q = true;

    float T = area(x1,y1,x2,y2,x3,y3);

    float A1 = area(xp,yp,x2,y2,x3,y3);
    float A2 = area(x1,y1,xp,yp,x3,y3);
    float A3 = area(x1,y1,x2,y2,xp,yp);

    if (T != A1 + A2 + A3) p = false;

    float B1 = area(xq,yq,x2,y2,x3,y3);
    float B2 = area(x1,y1,xq,yq,x3,y3);
    float B3 = area(x1,y1,x2,y2,xq,yq);

    if (T != B1 + B2 + B3) q = false;

    return res(p,q);
}

int main(){
    cout << points_belong(2,2,7,2,5,4,4,3,7,4) << endl;
    cout << points_belong(0,0,2,0,4,0,2,0,4,0) << endl;
    return 0;
}