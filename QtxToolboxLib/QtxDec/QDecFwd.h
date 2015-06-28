#ifndef QDECFWD_H
#define QDECFWD_H

/**
 * -------------
 * Class QDecFwd
 * -------------
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

#include <QtCore/QtGlobal>

#ifndef DECNUMDIGITS
//! Work with up to 80 digits as default, resulting in 64 bytes
//! decNumber structure.
# define DECNUMDIGITS 80
#endif

//! Digits of decimal precision for QDecNumber, decNumber.
//! This is set at compile time via DECNUMDIGITS macro.
const int QDecNumDigits = DECNUMDIGITS;

//! Digits of decimal precision for QDecSingle, decSingle, decimal32
const int QDecSingleDigits = 7;

//! Digits of decimal precision for QDecDouble, decDouble, decimal64
const int QDecDoubleDigits = 16;

//! Digits of decimal precision for QDecQuad, decQuad, decimal128
const int QDecQuadDigits = 34;

#ifndef QDECMAXSTRSIZE
//! Maximum length of a conversion string
# define QDECMAXSTRSIZE 512
#endif


extern "C" {
 #if !defined(int32_t)
  #if defined(_MSC_VER) 
   /* MS Visual C */
   #include <VCpp_stdint.h>
  #else
   /* C99 standard integers */
   #include <stdint.h>      
   /* For unknown compilers, you can use portable stdint.h */
   //include <Port_stdint.h> 
  #endif
 #endif

 #include "DecNumber/decContext.h"
 #include "DecNumber/decNumber.h"
}

// Prepare for shared library usage.
// See Q_DEC_EXPORT from Qt documentation for details.

#ifdef QDECIMAL_SHARED
# if(QDECIMAL_SHARED > 1)
#  define QDECIMAL_EXPORT Q_DECL_EXPORT
# else
#  define QDECIMAL_EXPORT Q_DECL_IMPORT
# endif
#else
# define QDECIMAL_EXPORT /* no-op */
#endif

class QDECIMAL_EXPORT QDecContext;
class QDECIMAL_EXPORT QDecNumber;
class QDECIMAL_EXPORT QDecPacked;
class QDECIMAL_EXPORT QDecSingle;
class QDECIMAL_EXPORT QDecDouble;
class QDECIMAL_EXPORT QDecQuad;

#endif /* Include guard */
