/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char *tbuf;
    int tnum;
    Solution() {
        tbuf = (char*) malloc(4 * sizeof(char));
        tnum = 0;
    }
    int read(char *buf, int n) {
        char *buf4 = (char*) malloc(4 * sizeof(char));
        int result = 0, total = 0;
        if (tnum == 0) {
            result = read4(buf4);
        } else {
            result = tnum;
            for (int i = 0; i < tnum; i++) {
                buf4[i] = tbuf[i];
            }
            tnum = 0;
        }
        while (result != 0) {
            for (int i = 0; i < result; i++) {
                buf[total + i] = buf4[i];
                if (total + i + 1 == n) {
                    for (int j = i + 1; j < result; j++) {
                        tbuf[tnum] = buf4[j];
                        tnum++;
                    }
                    return n;
                }
            }
            total += result;
            result = read4(buf4);
        }
        return total;
    }
};
