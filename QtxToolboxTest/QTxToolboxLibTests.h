#ifndef QTXTOOLBOXLIBTESTS_H
#define QTXTOOLBOXLIBTESTS_H

/**
 * ------------------------
 * Class QTxToolboxLibTests
 * ------------------------
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

#if defined(_MSC_VER) || defined(__GNUC__)
# pragma once
#endif

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QSet>

// FORWARDS
class QDecContext;
class QDecNumber;

class QDecNumberTests: public QObject
{
    Q_OBJECT
    Q_ENUMS(TestCodes_e)

    public:
        QDecNumberTests(const QStringList& arguments);
  
    enum TestCodes_e
    {
        TC_ignore = 0,
        TC_comment,
        TC_directive ,
        TC_test,
        TC_unknown
    };

    private slots:
        void compound_interest();
        void compressed_formats();
        void packed_decimals();
        void quad_tests();
        void quad_with_number();
        void QDecContext_tests();
        void QDecNumber_abs();
        void QDecNumber_add();
        void QDecimal_size();
        void conversion();
        void regression();
        void test_cases();

    private:
        void procTestFile(const QString& filename);
        int procTestLine(const QString& line, QStringList& tokens);
        int applyTestDirective(const QStringList& tokens, QDecContext& ctx);
        int getDirectivesContext(QDecContext& ctx, bool precision=true);
        void displayDirectivesContext();
        void clearDirectivesContext();
        int opTest(const QStringList& tokens);
        int runTestCase(const QStringList& tokens, const QDecContext& ctx);
        bool token2QDecNumber(const QString& token, const QDecContext& ctx, QDecNumber& num);
        bool QDecNumber2token(QString& token, const QDecNumber& num);

    // Current test file
    QString m_testFile;
    // Test lines (cases + directives)
    QStringList m_testLines;
    // Currently in force directives
    QMap<QString, QString> m_curDirectives;
    // Map of arguments
    QMap<QString, QString> m_argsMap;
    // Set of test cases to be skipped
    QSet<QString> m_skipSet;
};
#endif
