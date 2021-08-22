typedef char ALLELE;		//基因类型
typedef struct  { 
    ALLELE *chrom;
    float fitness;		//适应度
}INDIVIDUAL;		//个体定义

class Tpopulation  {		//群体类定义
public:
    int size;		//群体大小
    int lchrom;	 
    float sumfitness, average;
    INDIVIDUAL *fmin, *fmax;
    INDIVIDUAL *pop;
public:
    TPopulation(int popsize, int strlength);
    ~TPopulation();
    inline INDIVIDUAL &Individual(int i)  { return pop[i];};
    void FillFitness();		//评价函数
    virtual void Statistics();		//统计函数
};

class TSGA : public Tpopulation  {	//TSGA类派生于群体类
public:
    float pcross;		//交叉概率
    float pmutation;		//变异概率
    int gen;		//代数计数器
public:
    TSGA(int size, int strlength, float pm = 0.03, float pc = 0.6):
    TPopulation(size, strlength)
    { gen = 0;　　pcross = pc;　　pmutation = pm; };
    virtual INDIVIDUAL& Select();
    virtual void Crossover(INDIVIDUAL &parent1, INDIVIDUAL &parent2
                           ,INDIVIDUAL &child1, INDIVIDUAL &child2);
    virtual ALLELE Mutation(ALLELE alleleval);
    virtual void Generate();	//产生下一代
};
