#pragma once

#include <TRingBuffer.hpp>
#include <cmath>
#include <stdint.h>
#include <QDebug>

using frequency_t = double;
using refC_t = unsigned int;
using refL_t = unsigned int;



class lc {
public:
    lc(void)
        : frequency{}
        , refC_calC{}
        , refL_calC{}
        , refC_calL{}
        , refL_calL{}
        , Zero_C{}
        , Zero_L{}
        , prefixC{}
        , prefixL{}
        , _ref{}
    {}

    enum ESet : uint8_t { HARD, SOFT, SOFT_C, SOFT_L, HARD_C, HARD_L };

    template<ESet E>
    struct TTag
    {};

    template<ESet E, typename... A>
    inline bool Set(A... arg)
    {
        return Set(TTag<E>{}, arg...);
    }

    inline refC_t Get_refC_calC(void) { return (refC_calC); }

    inline refL_t Get_refL_calC(void) { return (refL_calC); }

    inline refC_t Get_refC_calL(void) { return (refC_calL); }

    inline refL_t Get_refL_calL(void) { return (refL_calL); }

    //void SetFrequency(uint8_t a, uint8_t b, uint8_t c);     // Установка значения частоты из набора байт
    template<typename A, typename B, typename C>
    inline void SetFrequency(A a, B b, C c)
    {
        frequency = ((b << 8) + a) * 256 / 0.36 + c; //Рассчитываем частоту
    }

    inline frequency_t GetFrequency(void) { return (frequency); }

    template<typename F1, typename F2, typename LC, typename T>
    inline double GetRef(F1 freq1, F2 freq2, LC lc, T t)
    {
        double resultLC = (1.0 / (4.0 * (pi * pi) * lc))
                          * (1.0 / (freq2 * freq2) - 1.0 / (freq1 * freq1)) * pow(10.0, 21.0);
        _ref.put(resultLC);
        auto d = _ref.getD();
        auto m = _ref.getM();
        if (d < m * t)
            return (m);
        else
            return (double{});
    }

    template<typename F, typename LC>
    inline auto GetLC(F freq, LC lc) // Возвращает значение емкости в pF
    {
        return ((1.0 / (4.0 * (pi * pi) * (freq * freq) * lc)) * std::pow(10, 21));
    }

    double GetCapacitance(void) { return (GetLC(frequency, refL_calC) - refC_calC); }

    double GetInductance(void) { return (GetLC(frequency, refC_calL) - refL_calL); }

    double GetAdaptiveCapacitance(double pf);
    double GetAdaptiveInductance(double mh);

    uint8_t GetPrefixC(void) { return prefixC; }
    uint8_t GetPrefixL(void) { return prefixL; }

private:
    static constexpr double pi = 3.14159265358979323846;
    double round_ex(double Value, uint8_t Digits);

    template<typename T>
    inline auto _isNaN(T x)
    {
        return (x != x);
    }

    template<typename T>
    inline auto _isInF(T x)
    {
        return (!_isNaN(x) && _isNaN(x - x));
    }

    //true - если число NAN или INF
    template<typename T>
    inline auto IfNANorINF(T x)
    {
        return (_isNaN(x) || _isInF(x));
    }

private:
    inline bool Set(TTag<HARD>, refC_t cc, refL_t lc, refC_t cl, refL_t ll)
    {
        refC_calC = cc;
        refL_calC = lc;
        refC_calL = cl;
        refL_calL = ll;
        return true;
    }

    inline bool Set(TTag<HARD_C>, refC_t cc, refL_t lc)
    {
        refC_calC = cc;
        refL_calC = lc;
        return true;
    }

    inline bool Set(TTag<HARD_L>, refC_t cl, refL_t ll)
    {
        refC_calL = cl;
        refL_calL = ll;
        return true;
    }

    template<typename T>
    inline bool reasonable(T v)
    {
        return (std::numeric_limits<T>::min() + 10 < v) && (v < std::numeric_limits<T>::max() - 10);
    }

    template<typename F, typename... T>
    inline bool reasonable(F f, T... v)
    {
        return (reasonable(f) && reasonable(v...));
    }

    template<typename... A>
    inline bool Set(TTag<SOFT>, A... arg)
    {
        if (reasonable(arg...))
            return (Set(TTag<HARD>{}, arg...));
        return false;
    }

    template<typename... A>
    inline bool Set(TTag<SOFT_C>, A... arg)
    {
        if (reasonable(arg...))
            return (Set(TTag<HARD_C>{}, arg...));
        return false;
    }

    template<typename... A>
    inline bool Set(TTag<SOFT_L>, A... arg)
    {
        if (reasonable(arg...))
            return (Set(TTag<HARD_L>{}, arg...));
        return false;
    }

    frequency_t frequency; // Значение частоты в Hz
    refC_t refC_calC;      // true capicatance + Stray Capicatance
    refL_t refL_calC; // Установленные значения CALc и CALl (значения в eeprom)
    refC_t refC_calL;
    refL_t refL_calL; // Откалиброванные значения CALc, CALl и CorrectionL (значения в eeprom)
    double Zero_C;
    double Zero_L;   // Установка нуля
    uint8_t prefixC; //0-pF, 1-nF, 2-µF  // Значение измеряемой величины
    uint8_t prefixL; //0-µH, 1-mH
    Kernel::System::TRingBufferStatistic<double, 100> _ref;
};

using TMeasure = lc;
