#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <Eigen/Dense>
#include "matrixIO.hpp"

using namespace Eigen;

struct matrixIOFixture {
  matrixIOFixture() {

    matrix = MatrixXd(3, 3);
    matrix << 0.680375, 0.59688, -0.329554,
              -0.211234, 0.823295, 0.536459,
              0.566198, -0.604897, -0.444451;
  }

  MatrixXd matrix;
};

BOOST_FIXTURE_TEST_SUITE(matrixIOTests, matrixIOFixture)

BOOST_AUTO_TEST_CASE(matrixIOTests) {

    MatrixXd result = matrixIO::openData("../data/m3.csv", 3);

    BOOST_TEST(matrix(0,0) == result(0,0));
    BOOST_TEST(matrix(0,1) == result(0,1));
    BOOST_TEST(matrix(0,2) == result(0,2));
    BOOST_TEST(matrix(1,0) == result(1,0));
    BOOST_TEST(matrix(1,1) == result(1,1));
    BOOST_TEST(matrix(1,2) == result(1,2));
    BOOST_TEST(matrix(2,0) == result(2,0));
    BOOST_TEST(matrix(2,1) == result(2,1));
    BOOST_TEST(matrix(2,2) == result(2,2));

}
BOOST_AUTO_TEST_SUITE_END()