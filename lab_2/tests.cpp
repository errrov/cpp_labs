#include <gtest/gtest.h>
#include "structs.h"

TEST(Square_site, FailureCheck) {
  lab2::Descartes_list tes;
  //tes.set_n(3 * sqrt(2));
  double error = 0.001;
  ASSERT_NEAR(3, tes.return_square_size(), error);
}

TEST(Center_Distance,FailureCheck) {
  lab2::Descartes_list tes;
  double error = 0.001;
  ASSERT_NEAR(0.723395,tes.center_distance(),error);
}

TEST(VertexCurvRadius,FailureTest) {
  lab2::Descartes_list tes;
  double error = 0.001;
  ASSERT_NEAR(0.375,tes.vertex_radius_of_curvature(),error);
}

TEST(KnotCurvRadius, FailureTest) {
  lab2::Descartes_list tes;
  double error = 0.001;
  ASSERT_NEAR(2.12132,tes.knot_radius_of_curvature(),error);
}

TEST(LoopArea, FailureTest) {
  lab2::Descartes_list tes;
  double error = 0.001;
  ASSERT_NEAR(1,tes.loop_area(),error);
}

TEST(DiametreValue, FailureTest) {
  lab2::Descartes_list tes;
  double error = 0.001;
  ASSERT_NEAR(1.3625,tes.diameter_value(), error);
}

TEST(DiameterDistance, FailureTest) {
  lab2::Descartes_list tes;
  double error = 0.01;
  ASSERT_NEAR(1.73205,tes.diameter_distance(),error);
}
