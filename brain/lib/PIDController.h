#include <SPI.h>
#include <Arduino.h>

class PID {
private:
    // pid outputs
    double p_output = 0;
    double i_output = 0;
    double d_output = 0;
    // pid constants
    double K_p = 0;
    double K_i = 0;
    double K_d = 0;

    // ranges of
    double integralMax = 0, integralMin = 0; // min and max integral value
    double outputMax = 0, outputMin = 0;     // min and max output value

    // previous values of
    uint64_t previousTime = 0;  // time
    uint32_t sampleTime   = 0;
    int previousError = 0; // errors

public:
    PID(int K_p, int K_i, int K_d);
    ~PID();

    void insertConstants(int K_p, int K_i, int K_d);
    void insertContantP(int K_p);
    void insertContantI(int K_i);
    void insertContantD(int K_d);
    int returnP();
    int returnI();
    int returnD();
    void rangeOfIntegral(int max, int min);
    void rangeOfOutput(int max, int min);
    void setSampleTime(uint32_t newTime);

    int controll(int error);
};
