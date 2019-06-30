#include <math.h>
#include "lc.h"
#include <QDebug>




/*
void lc::SetZero_L(uint8_t x)
{
  if(x==0)
    Zero_L = 0;
  else
    Zero_L = round_ex(((GetInductance(frequency, calC_cal, calL_cal) - CorrectionL)/1000), 2);
}




double lc::GetRealInductance()
{
  auto l = GetInductance(frequency, calC_cal, calL_cal);
  qDebug() << l;
  double data = round_ex( ((GetInductance(frequency, calC_cal, calL_cal)-double(CorrectionL))/1000), 2 );
  if(data < Zero_L) Zero_L = data;
  return data - Zero_L;
}*/

double lc::GetAdaptiveCapacitance(double pf)
{
  double result;
  if (pf > 100000)
    { //µF
      result = round_ex((pf/1000000),2);
      prefixC = 2;
    }
  else if(pf > 1000)
    { //nF
      result = round_ex((pf/1000),2);
      prefixC = 1;
    }
  else if(pf > 0.1)
    { //pF
      result = pf;
      prefixC = 0;
    }

  result = round_ex(result,2);
  if ( IfNANorINF( result ) )
    result = -1; //-1, если в result не число

  return result;
}

double lc::GetAdaptiveInductance(double mh)
{
  double result;
  if (mh>1000)
    { //mH
      result = round_ex((mh/1000),2);
      prefixL = 1;
    }
  else if(mh>0.01)
    { //µH
      result = mh;
      prefixL = 0;
    }

  result = round_ex(result,2);
  if(IfNANorINF(result))
    result = -1; //-1, если в result не число

  return result;
}

double lc::round_ex(double Value, uint8_t Digits)
{
  double x2=Value*pow(10,Digits);
  return (x2 - floor(x2)>=0.5 ? ceil(x2) : floor(x2))/pow(10,Digits);
}


