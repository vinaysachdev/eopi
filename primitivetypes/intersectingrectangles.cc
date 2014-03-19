#include <iostream>

struct Rectangle {
    int x, y, width, height;
};

// shamelessly copied the code from book. Solution is beautiful
bool is_intersect(const Rectangle & R, const Rectangle & S) {
    return (R.x <= S.x + S.w && S.x <= R.x + R.w 
            && R.y <= S.y + S.h && S.y <= R.y + R.h);
}

Rectangle intersecting_Rectangle(const Rectangle & R, const Rectangle & S) {
    if(is_intersect(R, S)) {
        return {max(R.x, S.x), max(R.y, S.y),
                min(R.x + R.width, S.x + S.width) - max(R.x, S.x),
                min(R.y + R.height, S.y + S.height) - max(R.y, S.y)};
    } else {
        return {0, 0, -1, -1};
    }
}
