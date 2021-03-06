#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

#include <memory>
#include <utility>

#include "../include/polynomial.h"

using finite_field::is_zero;
using finite_field::poly_add;
using finite_field::poly_const_mul;
using finite_field::poly_mul;
using finite_field::poly_sub;
using finite_field::poly_zp;
using finite_field::polynomial;

using std::make_pair;
using std::unique_ptr;

class polynomial_test : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(polynomial_test);

	CPPUNIT_TEST(test_poly_zp_poly);
	CPPUNIT_TEST(test_poly_zp_const);
	CPPUNIT_TEST(test_poly_zp_zero);

	CPPUNIT_TEST_SUITE_END();

	public:

	protected:
		void test_poly_zp_poly(void)
		{
			int x[] = {1,2,3,4,0,0,0};
			polynomial o;
			o.swap(poly_zp(x, 7, 11));
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", (unsigned)3, o.second);

			unsigned* p = o.first.get();

			for (int i = 0 ; i < o.second ; i++)
				CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong coeff", (unsigned)(i + 1), p[i]);
		}
		void test_poly_zp_const(void)
		{
			int x[] = {1,0,0,0,0};
			polynomial o;
			o.swap(poly_zp(x, 5, 11));

			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", (unsigned)0, o.second);
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong coeff", (unsigned)1, o.first.get()[0]);
		}
		void test_poly_zp_zero(void)
		{
			int x[] = {0,0,0,0,0};
			polynomial o;
			o.swap(poly_zp(x, 5, 11));
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong degree", (unsigned)0, o.second);
			CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong coeff", (unsigned)0, o.first.get()[0]);
		}
		void test_poly_add(void)
		{

		}

	private:
};
