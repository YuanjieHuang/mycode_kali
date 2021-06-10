class TSGAfit : public TSGA  {
public:
    TSGAfit(int size, float pm = 0.0333,float pc = 0.6)
           :TSGA(size, 24, pm, pc){};
    void print();
};
