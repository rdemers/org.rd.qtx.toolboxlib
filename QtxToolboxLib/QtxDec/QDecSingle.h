#ifndef QDECSINGLE_H
#define QDECSINGLE_H

/**
 * ---------------
 * Class QDecSingle
 * ----------------
 *
 * Author  : R. Demers
 * Version : 1.0.0
 * License : LGPL V3 (See file LICENSE in root directory for details).
 *
 * DESCRIPTION
 * -----------
 * TODO
 *
 * WARNING
 * -------
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <QByteArray>
#include <QMetaType>

#include "QDecFwd.h"
#include "QDecContext.h"

extern "C" {
 #include "internal/DecNumber/decSingle.h"
}

// FORWARDS
QT_BEGIN_NAMESPACE
class QTextStream;
QT_END_NAMESPACE


/*!
  \class QDecSingle
  QDecSingle encapsulates decSingle and provides decNumber
  library functions that operates upon decSingle as member functions
  with the same name.
  decimal32 is a 32-bit decimal floating-point representation which
  provides 7 decimal digits of precision in a compressed format.
  decSingle module provides the functions for the decimal32 format;
  this format is intended for storage and interchange only and so
  the module provides utilities and conversions but no arithmetic functions.
 */
class QDECIMAL_EXPORT QDecSingle
{
  // MEMBERS
  //! Embedded decSingle structure
  decSingle m_data;

 public:
  // TYPES
  typedef decSingle* decSinglePtr_t;
  enum {
    MaxStrSize = QDECMAXSTRSIZE
  };

  
  // CREATORS
  //! Default constructor
  QDecSingle() { decSingleZero(&m_data); }
  
  // Default Dtor and Copy Ctor are ok

  // Constructors using decSingle structure
  QDecSingle(decSingle d) : m_data(d) {}
  QDecSingle(const decSingle* p) : m_data(*p) {}
  
  // Conversion constructors using simple types
  QDecSingle(const char* str) { fromString(str); }
  QDecSingle(double d) { fromDouble(d); }
  
  // Conversion constructors using composite types
  QDecSingle(const QDecDouble& d) { fromQDecDouble(d); }
  QDecSingle(const QDecPacked& p) { fromQDecPacked(p); }
  QDecSingle(const QDecNumber& n) { fromQDecNumber(n); }

  //! Copy assignment
  QDecSingle& operator=(const QDecSingle& o)
  { if(this != &o) m_data = o.m_data; return *this; }

  //! Conversion operator to decSingle*
  operator decSinglePtr_t() { return &m_data; }

  
  // ACCESSORS
  const decSingle* data() const
  { return &m_data; }

  // MODIFIERS
  decSingle* data()
  { return &m_data; }


  // UTILITIES & CONVERSIONS
  QDecSingle& fromBCD(int32_t exp, const QByteArray& bcd, int32_t sign) {
    decSingleFromBCD(&m_data, exp, (const uint8_t*)bcd.data(), sign);
    return *this;
  }
  
  QDecSingle& fromDouble(double d);

  QDecSingle& fromPacked(int32_t exp, const QByteArray& pack) {
    decSingleFromPacked(&m_data, exp, (const uint8_t*)pack.data());
    return *this;
  }
  
  QDecSingle& fromPackedChecked(int32_t exp, const QByteArray& pack) {
    decSingleFromPackedChecked(&m_data, exp, (const uint8_t*)pack.data());
    return *this;
  }

  QDecSingle& fromString(const char* str, QDecContext* c = 0) {
    decSingleFromString(&m_data, str, CXT(c));
    return *this; 
  }

  //! Hexadecimal string in network byte order
  QDecSingle& fromHexString(const char* str);

  QDecSingle& fromQDecDouble(const QDecDouble& d, QDecContext* c = 0)
  { return fromWider(d,c); }
  
  QDecSingle& fromQDecNumber(const QDecNumber& n, QDecContext* c = 0);
  
  QDecSingle& fromQDecPacked(const QDecPacked& p);
  
  QDecSingle& fromWider(const QDecDouble& d, QDecContext* c = 0);
  
  int32_t getCoefficient(QByteArray& bcd) const {
    bcd.resize(DECSINGLE_Pmax);
    return decSingleGetCoefficient(&m_data, (uint8_t*)bcd.data());
  }
 
  int32_t getExponent() const
  { return decSingleGetExponent(&m_data); }

  QDecSingle& setCoefficient(const QByteArray& bcd, int32_t sign) {
    decSingleSetCoefficient(&m_data, (const uint8_t*)bcd.data(), sign);
    return *this;
  }
  
  QDecSingle& setExponent(int32_t exp, QDecContext* c = 0 ) {
    decSingleSetExponent(&m_data, CXT(c), exp);
    return *this;
  }

  int32_t toBCD(int32_t& exp, QByteArray& bcd) {
    bcd.resize(DECSINGLE_Pmax);
    return decSingleToBCD(&m_data, &exp, (uint8_t*)bcd.data());
  }

  double toDouble() const;
  
  QByteArray toEngString() const {
    char str[MaxStrSize] = { 0 };
    return decSingleToEngString(&m_data, str);
  }
    
  QByteArray toString() const {
    char str[MaxStrSize] = { 0 };
    return decSingleToString(&m_data, str); 
  }

  int32_t toPacked(int32_t& exp, QByteArray& pack) {
    pack.resize(DECSINGLE_Pmax);
    return decSingleToPacked(&m_data, &exp, (uint8_t*)pack.data());
  }

  QDecDouble toQDecDouble() const;
  
  QDecPacked toQDecPacked() const;
  
  QDecNumber toQDecNumber() const;

  QDecDouble toWider() const;
    
  QDecSingle& zero()
  { decSingleZero(&m_data); return *this; }


  // ARITHMETIC
  // No arithmetic routines defines for QDecSingle

  // NON-COMPUTATIONAL
  
  uint32_t radix() const
  { return decSingleRadix(&m_data); }
  
  const char* version() const
  { return decSingleVersion(); }
   

}; // end class


Q_DECLARE_METATYPE(QDecSingle);


QDECIMAL_EXPORT
QTextStream& operator<<(QTextStream& ts, const QDecSingle& d);


#endif /* Include guard */
