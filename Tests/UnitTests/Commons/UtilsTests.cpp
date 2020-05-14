// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Utils/TestUtils.hpp>
#include "doctest_proxy.hpp"

#include <Rosetta/Common/Utils.hpp>

#include <random>

TEST_CASE("[Base64] - Decode")
{
    auto decoded = DecodeBase64("AQIDBA==");

    CHECK_EQ(decoded.size(), 4u);
    CHECK_EQ(decoded[0], 1);
    CHECK_EQ(decoded[1], 2);
    CHECK_EQ(decoded[2], 3);
    CHECK_EQ(decoded[3], 4);
}