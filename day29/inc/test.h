#ifndef __TEST_H_
#define __TEST_H_

#include <cstdint>
#include <string.h>

class testData
{
    public:
        struct alignas(8) test
        {
            std::int64_t m_a = 0;
            std::int64_t m_b = 0;;
            float m_c = 0.0;
        };

        testData() noexcept : test_msg_{} {}
        virtual ~testData() noexcept = default;
        testData(testData const&) = default;
        testData& operator=(testData const&) = default;
        testData(testData&&) = default;
        testData& operator=(testData&&) = default;

        test const& GetTestMsg() const noexcept;
        void SetCommonMsg(test const& test_msg) noexcept;

        std::int64_t GetA() const;
        std::int64_t GetB() const;
        float GetC() const;

        void SetA(std::int64_t A) noexcept;
        void SetB(std::int64_t B) noexcept;
        void SetC(float C) noexcept;

        void Clear();
    
    private:
        test test_msg_;
};

#endif