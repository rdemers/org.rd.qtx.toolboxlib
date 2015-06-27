/** \file QDecNumber.cc
 * Definitions for the class QDecNumber.
 *
 * (C) Copyright by Semih Cemiloglu
 * All rights reserved, see COPYRIGHT file for details.
 *
 * $Id$
 *
 *
 */

#include "QDecNumber.h"
#include <stdlib.h>
#include <QTextStream>
#include "QDecSingle.h"
#include "QDecDouble.h"
#include "QDecQuad.h"
#include "QDecPacked.h"

extern "C" {
 #include "DecNumber/decimal32.h"
 #include "DecNumber/decimal64.h"
 #include "DecNumber/decimal128.h"
}

QDecNumber::QDecNumber(const QDecSingle& s)
{ decSingleToNumber(s.data(), &m_data); } 

QDecNumber::QDecNumber(const QDecDouble& d)
{ decDoubleToNumber(d.data(), &m_data); } 

QDecNumber::QDecNumber(const QDecQuad& q)
{ decQuadToNumber(q.data(), &m_data); } 

QDecNumber::QDecNumber(const QDecPacked& p)
{ *this = p.toQDecNumber(); }


QDecNumber& QDecNumber::fromDouble(double d)
{
  char str[MaxStrSize] = { 0 };

 #if defined(_MSC_VER)
  _snprintf(str, MaxStrSize, "%.*g", QDecNumDigits, d);
 #else
  snprintf(str, MaxStrSize, "%.*g", QDecNumDigits, d);
 #endif
  return fromString(str);
}


double QDecNumber::toDouble() const
{
  char str[MaxStrSize] = { 0 };
  
  decNumberToString(&m_data, str);
  return strtod(str, 0);
}


QTextStream& operator<<(QTextStream& ts, const QDecNumber& n)
{
  ts << n.toString();
  return ts;
}

