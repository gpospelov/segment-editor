/******************************************************************************
 *
 * Project       : QML playground
 *
 * Author        : Gennady Pospelov (IO)
 *
 *****************************************************************************/

#include <gtest/gtest.h>

#include <segment-editor/segment_model.h>

using namespace mvvm;

class SegmentModelTestsTests : public ::testing::Test
{
};

TEST_F(SegmentModelTestsTests, InitialState)
{
  SegmentModel model;
  EXPECT_EQ(1, 1);
}
