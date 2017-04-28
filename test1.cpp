#include <gtest/gtest.h>
#include <assimp/cimport.h>

// Simple matrix test from utMatrix3x3.cpp
TEST(assimp, basics) {

  aiVector3D res;
  aiMatrix3x3 trafo;

  const double PRECISION = 0.000001;

  // axes test
  aiVector3D axes[] =
      { aiVector3D(1, 0, 0)
      , aiVector3D(0, 1, 0)
      , aiVector3D(0, 0, 1)
      };

  for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
          aiMatrix3x3::FromToMatrix(axes[i], axes[j], trafo);
          res = trafo * axes[i];

          ASSERT_NEAR(axes[j].x, res.x, PRECISION);
          ASSERT_NEAR(axes[j].y, res.y, PRECISION);
          ASSERT_NEAR(axes[j].z, res.z, PRECISION);
      }
  }
}
