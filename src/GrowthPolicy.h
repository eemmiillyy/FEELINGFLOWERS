#ifndef GrowthPolicy_h
#define GrowthPolicy_h

class GrowthPolicy {
    public:
        GrowthPolicy();
        void setup(float stemGrowthSpeed);
        void computeStemSpeed();
        float getCalculatedStemSpeed();
    private:
        float stemGrowthSpeed_;
};

#endif /* GrowthPolicy_h */
