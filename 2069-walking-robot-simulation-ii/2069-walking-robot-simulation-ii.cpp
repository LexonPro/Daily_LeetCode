class Robot {
    int w, h, pos, p;
    bool moved;
    string dir[4] = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        pos = 0;
        p = 2 * (w + h - 2);
        moved = false;
    }

    void step(int num) {
        moved = true;
        pos = (pos + num) % p;
    }

    vector<int> getPos() {
        if (pos < w) return {pos, 0};
        if (pos < w + h - 1) return {w - 1, pos - (w - 1)};
        if (pos < 2 * w + h - 2) return {w - 1 - (pos - (w + h - 2)), h - 1};
        return {0, h - 1 - (pos - (2 * w + h - 3))};
    }

    string getDir() {
        if (!moved) return dir[0];
        if (pos > 0 && pos < w) return dir[0];
        if (pos >= w && pos < w + h - 1) return dir[1];
        if (pos >= w + h - 1 && pos < 2 * w + h - 2) return dir[2];
        return dir[3];
    }
};