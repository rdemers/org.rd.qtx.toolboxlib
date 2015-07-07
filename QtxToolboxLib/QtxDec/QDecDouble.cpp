/**
 * ----------------
 * Class QDecDouble
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
#include "QDecDouble.h"
extern "C" {
 #include "internal/DecNumber/decimal64.h"
}
#include <stdlib.h>
#include <QTextStream>
#include "QDecNumber.h"
#include "QDecPacked.h"
#include "QDecSingle.h"
#include "QDecQuad.h"


QDecDouble& QDecDouble::fromDouble(double d)
{
  char str[MaxStrSize] = { 0 };

 #if defined(_MSC_VER)
  _snprintf(str, MaxStrSize, "%.*g", QDecNumDigits, d);
 #else
  snprintf(str, MaxStrSize, "%.*g", QDecNumDigits, d);
 #endif

  return fromString(str);
}

QDecDouble& QDecDouble::fromHexString(const char* str)
{
  QByteArray ba = QByteArray::fromHex(str);
  int size = sizeof(m_data);
  char* p = (char*)&m_data;
  int i = 0;
  int j = size-1;
  for(; i<size; i++,j--)
    p[j] = ba.at(i);

  return *this;
}

QDecDouble& QDecDouble::fromQDecSingle(const QDecSingle& s)
{
  decSingleToWider(s.data(), &m_data);
  return *this;
}

QDecDouble& QDecDouble::fromQDecNumber(const QDecNumber& n, QDecContext* c)
{
  decDoubleFromNumber(&m_data, n.data(), CXT(c));
  return *this;
}
  
QDecDouble& QDecDouble::fromQDecPacked(const QDecPacked& p)
{
  fromQDecNumber(p.toQDecNumber());
  return *this;
}

QDecDouble& QDecDouble::fromWider(const QDecQuad& q, QDecContext* c)
{
  decDoubleFromWider(&m_data, q.data(), CXT(c));
  return *this;
}

double QDecDouble::toDouble() const
{
  char str[MaxStrSize] = { 0 };
  decDoubleToString(&m_data, str);
  return strtod(str, 0);
}

QDecSingle QDecDouble::toQDecSingle(QDecContext* c) const
{
  decSingle s;
  return decSingleFromWider(&s, &m_data, CXT(c));
}

QDecQuad QDecDouble::toQDecQuad() const
{
  decQuad q;
  return decDoubleToWider(&m_data, &q);
}
  
QDecPacked QDecDouble::toQDecPacked() const
{
  return QDecPacked(toQDecNumber());
}  
  
QDecNumber QDecDouble::toQDecNumber() const
{
  decNumber n;
  return decDoubleToNumber(&m_data, &n);
}

QDecQuad QDecDouble::toWider() const
{
  decQuad q;
  return decDoubleToWider(&m_data, &q);
}

QTextStream& operator<<(QTextStream& ts, const QDecDouble& d)
{
  ts << d.toString();
  return ts;
}


