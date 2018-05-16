#ifndef FRACTIONTEST_H
#define FRACTIONTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../GitCommand/Init.h"

using namespace std;

class inittest : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (inittest);
	CPPUNIT_TEST (initTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void initTest (void);

	private:
		Init* init;
};

#endif
