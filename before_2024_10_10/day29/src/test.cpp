#include "test.h"

testData::test const& testData::GetTestMsg() const noexcept
{
    return test_msg_;
}

void testData::SetCommonMsg(test const& test_msg) noexcept
{
    test_msg_ = test_msg;
}

std::int64_t testData::GetA() const
{
    return test_msg_.m_a;
}

std::int64_t testData::GetB() const
{
    return test_msg_.m_b;
}

float testData::GetC() const 
{
    return test_msg_.m_c;
}

void testData::SetA(std::int64_t A) noexcept
{
    test_msg_.m_a = A;
}

void testData::SetB(std::int64_t B) noexcept
{
    test_msg_.m_b = B;
}

void testData::SetC(float C) noexcept
{
    test_msg_.m_c = C;
}

void testData::Clear()
{
    memset(&test_msg_, 0, sizeof(test));
}