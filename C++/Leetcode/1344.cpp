/*
1344. 时钟指针的夹角
    给你两个数 hour 和 minutes 。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。
*/

/*
    数学计算
    时钟上的每一格是360/60=6度；
    1）分针走过的度数 = minutes * 6
    2）时针走过的度数 = （hour % 12 + 因分针移动导致的偏移量=minutes/60）* 5 * 6
    利用（分针走过的度数 - 时钟走过的度数），即得所求。
*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6;
        double hourAngle = ((minutes * 1.0) / 60 + (hour % 12)) * 5.0 * 6.0;
        
        double res = fabs(minAngle - hourAngle);
        return min(fabs(res), fabs(360.0 - res)); // 注意是求两针夹角的最小值
    }
};