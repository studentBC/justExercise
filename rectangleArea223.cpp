//https://stackoverflow.com/questions/4549544/total-area-of-intersecting-rectangles/28412172
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long l1 = abs(C-A), l2 = abs(D-B), l3 = abs(G-E), l4 = abs(H-F);
        long long sum = l1*l2+l3*l4;
        //if (A < G && C > E && B > H && D < E) return sum;
        //int overlap = abs(min(A,C)-max(E,G))*abs(min(B,D)-max(F,H));
        int left = max (A,E), right = min (C,G), buttom = max (B,F), top = min (D,H);long long overlap = 0;
        long l5 = abs(right-left), l6 = abs(top-buttom);
        if (left < right && buttom < top) {
            //cout << left <<" , " << right <<" , " << top <<" , " << buttom << endl;
            overlap = l5*l6;
        }
        //cout << sum <<" , " <<overlap << endl;
        return sum-overlap;
    }
};
//the fatest solution
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area = 0; 
        int x = 0, y = 0; 
        
        area += (C - A) * (D - B); 
        area += (G - E) * (H - F); 
        
        if (C <= E || A >= G) x = 0; 
        else x = min(C, G) - max(A, E);
        
        if (B >= H || F >= D) y = 0; 
        else y = min(D, H) - max(B, F); 
        
        area -= x * y; 
        
        return area;
    }
};
