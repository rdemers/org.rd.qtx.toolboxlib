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

#include "QDecPacked.h"
#include "QDecNumber.h"
#include "QDecSingle.h"
#include "QDecDouble.h"
#include "QDecQuad.h"

QDecPacked::QDecPacked(const char* str)
{ *this = fromQDecNumber(QDecNumber(str)); }

QDecPacked::QDecPacked(double d)
{ *this = fromQDecNumber(QDecNumber(d)); }

QDecPacked::QDecPacked(const QDecSingle& s)
{ *this = s.toQDecPacked(); }

QDecPacked::QDecPacked(const QDecDouble& d)
{ *this = d.toQDecPacked(); }

QDecPacked::QDecPacked(const QDecQuad& q)
{ *this = q.toQDecPacked(); }

QDecPacked& QDecPacked::fromQDecNumber(const QDecNumber& d)
{
  uint8_t bfr[QDecNumDigits] = { 0 };
  int32_t scale = 0;

  uint8_t* rv = decPackedFromNumber(bfr, QDecNumDigits, &scale, d.data());

  if(rv) {
    m_scale = scale;
    
    char* p = (char*)bfr;
    int i = 0;
    // Skip null bytes at the left
    for(; p[i] == '\0' || i==QDecNumDigits; ++i);

    // Construct byte array from the beginning of BCD bytes
    m_bytes = QByteArray(&p[i], QDecNumDigits-i);
  }

  return *this;
}

QDecNumber QDecPacked::toQDecNumber() const
{
  if(length() > 0) {
    decNumber n;
    return decPackedToNumber(bytesRaw(), length(), &m_scale, &n);
  }
  else
    // Not initialized, return default QDecNumber value
    return QDecNumber();
}

QDecPacked& QDecPacked::fromDouble(double d)
{
  *this = fromQDecNumber(QDecNumber(d));
  return *this;
}

QDecPacked& QDecPacked::fromString(const char* str)
{
  *this = fromQDecNumber(QDecNumber(str));
  return *this;
}

QByteArray QDecPacked::toString() const
{
  return toQDecNumber().toString();
}
