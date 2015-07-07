#ifndef QDECPACKED_H
#define QDECPACKED_H

/**
 * ----------------
 * Class QDecPacked
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

#include "QDecFwd.h"
extern "C" {
 #include "internal/DecNumber/decPacked.h"
}


/*!
  \class QDecPacked
  QDecPacked augments decPacked by encapsulating reference counted byte
  array and scale of the decimal point as members variables, thus, freeing up
  user of this class from memory management and keeping track of scale value.
  The decPacked format is the classic packed decimal format implemented
  by IBM S/360 and later machines, where each digit is encoded as
  a 4-bit binary sequence (BCD) and a number is ended by a 4-bit
  sign indicator. The decPacked module accepts variable lengths,
  allowing for very large numbers (up to a billion digits), and also
  allows the specification of a scale.
 */
class QDECIMAL_EXPORT QDecPacked
{
  // MEMBERS
  //! Byte array containing BCD sequence
  QByteArray m_bytes;
  //! Scale of the decimal number (point)
  int32_t m_scale;

 public:
  // CREATORS
  //! Default constructor
  QDecPacked() : m_scale(0) {}
  QDecPacked(int32_t length, int32_t scale = 0)
      : m_bytes(length,'\0'), m_scale(scale)  {}
  QDecPacked(const QByteArray& bytes, int32_t scale = 0)
      : m_bytes(bytes), m_scale(scale) {}

  // Default copy constructor and destructor are ok to use
  
  // Conversion constructors using simple types
  QDecPacked(const char* str);
  QDecPacked(double d);
  
  // Conversion constructors using composite types
  QDecPacked(const QDecNumber& d)  { fromQDecNumber(d); }
  QDecPacked(const QDecSingle& s);
  QDecPacked(const QDecDouble& d);
  QDecPacked(const QDecQuad& d);

  // ACCESSORS
  const char* data() const
  { return m_bytes.data(); }

  QByteArray bytes() const
  { return m_bytes; }

  const uint8_t* bytesRaw() const
  { return reinterpret_cast<const uint8_t*>(m_bytes.data()); }

  int32_t length() const
  { return m_bytes.size(); }
    
  int32_t scale() const
  { return m_scale; }

  QByteArray toString() const;

  
  // MODIFIERS
  uint8_t* bytesRaw()
  { return reinterpret_cast<uint8_t*>(m_bytes.data()); }

  QDecPacked& fromDouble(double d);

  QDecPacked& fromString(const char* str);

  void setLength(int32_t length)
  { m_bytes.resize(length); }
  
  void setScale(int32_t scale)
  { m_scale = scale; }

  // CONVERSIONS
  QDecNumber toQDecNumber() const;
  QDecPacked& fromQDecNumber(const QDecNumber& d);


}; // end class





#endif /* Include guard */
