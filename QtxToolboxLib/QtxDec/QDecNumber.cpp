/**
 * ----------------
 * Class QDecNumber
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
#include "QDecNumber.h"
#include <stdlib.h>
#include <QTextStream>
#include "QDecSingle.h"
#include "QDecDouble.h"
#include "QDecQuad.h"
#include "QDecPacked.h"

extern "C" {
 #include "internal/DecNumber/decimal32.h"
 #include "internal/DecNumber/decimal64.h"
 #include "internal/DecNumber/decimal128.h"
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

