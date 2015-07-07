/**
 * ----------------
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

#include "QDecSingle.h"

extern "C"
{
    #include "internal/DecNumber/decimal32.h"
}

#include <stdlib.h>
#include <QTextStream>
#include "QDecNumber.h"
#include "QDecPacked.h"
#include "QDecDouble.h"

QDecSingle& QDecSingle::fromDouble(double d)
{
  char str[MaxStrSize] = {0};

 #if defined(_MSC_VER)
  _snprintf(str, MaxStrSize, "%.*g", QDecNumDigits, d);
 #else
  snprintf(str, MaxStrSize, "%.*g", QDecNumDigits, d);
 #endif

  return fromString(str);
}

QDecSingle& QDecSingle::fromHexString(const char* str)
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

QDecSingle& QDecSingle::fromQDecNumber(const QDecNumber& n, QDecContext* c)
{
  decSingleFromNumber(&m_data, n.data(), CXT(c));
  return *this;
}
  
QDecSingle& QDecSingle::fromQDecPacked(const QDecPacked& p)
{
  fromQDecNumber(p.toQDecNumber());
  return *this;
}
  
QDecSingle& QDecSingle::fromWider(const QDecDouble& d, QDecContext* c)
{
  decSingleFromWider(&m_data, d.data(), CXT(c));
  return *this;
}

double QDecSingle::toDouble() const
{
  char str[MaxStrSize] = {0};
  decSingleToString(&m_data, str);
  return strtod(str, 0);
}

QDecDouble QDecSingle::toQDecDouble() const
{
  return toWider();
}
  
QDecPacked QDecSingle::toQDecPacked() const
{
  return QDecPacked(toQDecNumber());
}
  
QDecNumber QDecSingle::toQDecNumber() const
{
  decNumber n;
  return decSingleToNumber(&m_data, &n);
}

QDecDouble QDecSingle::toWider() const
{
  decDouble d;
  return decSingleToWider(&m_data, &d);
}

QTextStream& operator<<(QTextStream& ts, const QDecSingle& d)
{
  ts << d.toString();
  return ts;
}
